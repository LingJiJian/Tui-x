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
#include "CCInetAddress.h"

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	#pragma comment(lib, "Ws2_32.lib")
#endif

NS_CC_BEGIN

CInetAddress::CInetAddress()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	sin_len = sizeof(struct sockaddr_in);
	sin_family = AF_INET;
	sin_addr.s_addr = INADDR_ANY;
	sin_port = 0;
	memset(sin_zero, 0, 8);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	sin_family = AF_INET;
	sin_addr.s_addr = INADDR_ANY;
	sin_port = 0;
	memset(sin_zero, 0, 8);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	sin_family = AF_INET;
	sin_addr.s_addr = INADDR_ANY;
	sin_port = 0;
	memset(sin_zero, 0, 8);
#endif
}

CInetAddress::CInetAddress(const char* ip, unsigned short port)
{
	sin_family = AF_INET;
	sin_addr.s_addr = inet_addr(ip);
	sin_port = htons(port);
	memset(sin_zero, 0, 8);
}

CInetAddress::CInetAddress(const struct sockaddr * addr)
{
	memcpy(&this->sin_family, addr, sizeof(struct sockaddr));
}

CInetAddress::~CInetAddress(void)
{
	
}

CInetAddress::operator struct sockaddr*()
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	return (struct sockaddr *)(&this->sin_family);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	return (struct sockaddr *)(&this->sin_family);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	return (struct sockaddr *)(&this->sin_len);
#endif
}

CInetAddress::operator const struct sockaddr*() const
{
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	return (const struct sockaddr *)(&this->sin_family);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	return (const struct sockaddr *)(&this->sin_family);
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	return (const struct sockaddr *)(&this->sin_len);
#endif
}

const char* CInetAddress::getHostAddress() const
{
	static char addr[64];
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	sprintf_s(addr, 64, "%s:%u", inet_ntoa(sin_addr), getPort());
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	snprintf(addr, 64, "%s:%u", inet_ntoa(sin_addr), getPort());
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	snprintf(addr, 64, "%s:%u", inet_ntoa(sin_addr), getPort());
#endif
	return addr;
}

const char* CInetAddress::getIp() const
{
	return inet_ntoa(sin_addr);
}

unsigned short CInetAddress::getPort() const
{
	return ntohs(sin_port);
}

void CInetAddress::setIp(const char* ip)
{
	sin_addr.s_addr = inet_addr(ip);
}

void CInetAddress::setIp(unsigned int ip)
{
	sin_addr.s_addr = ip;
}

void CInetAddress::setPort(unsigned short port)
{
	sin_port = htons(port);
}

void CInetAddress::setHost(const char* name)
{
	hostent* h = gethostbyname(name);
	if( h != NULL )
	{
		sin_addr.s_addr = *((u_long *)h->h_addr_list[0]);
	}
}

int CInetAddress::getLength() 
{ 
	return sizeof(sockaddr_in); 
}

NS_CC_END