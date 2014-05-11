/****************************************************************************
Copyright (c) 2014 Lijunlin - Jason lee

Created by Lijunlin - Jason lee on 2014

jason.lee.c@foxmail.com
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "CCSocket.h"

NS_CC_BEGIN

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
static bool bStartup = false;
#endif

CCSocket::CCSocket()
: m_uSocket(INVALID_SOCKET)
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
if( !bStartup ) 
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	bStartup = true;
}
#endif
}

CCSocket::~CCSocket()
{
	ccClose();
}

bool CCSocket::ccInit()
{
	if( m_uSocket != INVALID_SOCKET )
	{
		ccClose();
	}

	m_uSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if( m_uSocket == INVALID_SOCKET )
	{
		CCLOGERROR("create socket failed");
		return false;
	}

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	unsigned long ul = 1;
	int nRet = ioctlsocket(m_uSocket, FIONBIO, (unsigned long*)&ul);
	if( nRet == SOCKET_ERROR )
	{
		CCLOGERROR("set unblocking failed");
		ccClose();
		return false;
	}
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	int nFlags = fcntl(m_uSocket, F_GETFL, 0);
    int nRet = fcntl(m_uSocket, F_SETFL, nFlags | O_NONBLOCK);
	if( nRet == SOCKET_ERROR )
	{
		CCLOGERROR("set unblocking failed");
		ccClose();
		return false;
	}
#endif

	int nNoDelay = 1;
	if( setsockopt(m_uSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&nNoDelay, sizeof(nNoDelay)) == SOCKET_ERROR )
	{
		CCLOGERROR("set nodelay failed");
		ccClose();
		return false;
	}

	return true;
}

void CCSocket::ccClose()
{
	if( m_uSocket != INVALID_SOCKET )
	{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
		closesocket(m_uSocket);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
		close(m_uSocket);        
#endif
		m_uSocket = INVALID_SOCKET;
	}
}

bool CCSocket::ccConnect()
{
#if 1 // runtime error on ios
	CCAssert(strlen(m_oInetAddress.getIp()) && m_oInetAddress.getPort() != 0, "_connect");
#endif

	if( m_uSocket == INVALID_SOCKET )
	{
		if(!ccInit())
		{
			return false;
		}
	}

	int nRet = ::connect(m_uSocket, m_oInetAddress, m_oInetAddress.getLength());
	if( nRet == 0 )
	{
		return true;
	}
	else
	{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
		int nError = WSAGetLastError();
		if( nError ==  WSAEWOULDBLOCK )
		{
			return true;
		}
		else
		{
			return false;
		}
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
		if( nRet == SOCKET_ERROR && errno == EINPROGRESS )
		{
			return true;
		}
		else
		{
			return false;
		}
#endif
	}
}

void CCSocket::ccDisconnect()
{
	if( m_uSocket != INVALID_SOCKET )
	{
#if 0
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
		shutdown(m_uSocket, SD_BOTH);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
        shutdown(m_uSocket, SHUT_RDWR);
#endif
#endif
		ccClose();
	}
}

void CCSocket::setInetAddress(const CInetAddress& oInetAddress)
{
	m_oInetAddress = oInetAddress;
}

int CCSocket::ccRead(char* _buff, int _len)
{
	if( m_uSocket == INVALID_SOCKET )
		return eSocketIoError;

	return ::recv(m_uSocket, _buff, _len, 0);
}

int CCSocket::ccWrite(char* _buff, int _len)
{
	if( m_uSocket == INVALID_SOCKET )
		return eSocketIoError;

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	return ::send(m_uSocket, _buff, _len, 0);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
    return ::send(m_uSocket, _buff, _len, SO_NOSIGPIPE);
#endif
}

bool CCSocket::ccIsReadable()
{
	fd_set	fd;
	struct timeval tv;

	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);

	tv.tv_sec = 0;
	tv.tv_usec = 0;

	if( select((int)(m_uSocket + 1), &fd, NULL, NULL, &tv) > 0 )
	{
		if( FD_ISSET(m_uSocket, &fd) )
		{
			return true;
		}
	}

	return false;
}

bool CCSocket::ccIsWritable()
{
	fd_set	fd;
	struct timeval tv;

	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);

	tv.tv_sec = 0;
	tv.tv_usec = 0;

	if( select((int)(m_uSocket + 1), NULL, &fd, NULL, &tv) > 0 )
	{
		if( FD_ISSET(m_uSocket, &fd) )
		{
			return true;
		}
	}

	return false;
}

int CCSocket::ccIsConnected()
{
	fd_set	fd;
	struct timeval tv;

	FD_ZERO(&fd);
	FD_SET(m_uSocket, &fd);

	tv.tv_sec = 0;
	tv.tv_usec = 0;

	if( select((int)(m_uSocket + 1), NULL, &fd, NULL, &tv) > 0 )
	{
		if( FD_ISSET(m_uSocket, &fd) )
		{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )

			return eSocketConnected;

#elif( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )

			int nError;
			socklen_t len = sizeof(nError);
			if( getsockopt(m_uSocket, SOL_SOCKET, SO_ERROR, &nError, &len) < 0 )
			{
				return eSocketConnectFailed;
			}
			if( nError == ECONNREFUSED || nError == ETIMEDOUT )
			{
				return eSocketConnectFailed;
			}
			return eSocketConnected;

#endif
		}
	}
	return eSocketConnecting;
}

NS_CC_END