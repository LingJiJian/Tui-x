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
#ifndef __CCNET_INETADDRESS_H__
#define __CCNET_INETADDRESS_H__

#include "cocos2d.h"
#include "CCNetMacros.h"
#include <string>

NS_CC_BEGIN

// dns parse
static std::string domainToIP(const char* pDomain)
{
	struct hostent* h = gethostbyname(pDomain);
	if( h != NULL ) 
	{
		unsigned char* p = (unsigned char *)(h->h_addr_list)[0];
		if( p != NULL )
		{
			char ip[16] = {0};
			sprintf(ip, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
			return ip;
		}
	}
	return "";
}

/**
 * calss  : CCInetAddress
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : address define
 */
class CInetAddress : public sockaddr_in
{
public:
	CInetAddress();
	CInetAddress(const char* ip, unsigned short port);
	CInetAddress(const struct sockaddr* addr);
	virtual ~CInetAddress(void);

public:
	operator struct sockaddr*();
	operator const struct sockaddr*() const;
	const char* getHostAddress() const;
	const char* getIp() const;
	unsigned short getPort() const;
	void setIp(const char* ip);
	void setIp(unsigned int ip);
	void setPort(unsigned short port);
	void setHost(const char* name);

public:
	int getLength();
};

NS_CC_END


#endif //__CCNET_INETADDRESS_H__