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
#ifndef __CCNET_MACROS_H__
#define __CCNET_MACROS_H__

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
typedef unsigned int          SOCKET;
#ifndef INVALID_SOCKET
#define INVALID_SOCKET  (SOCKET)(~0)
#endif
#ifndef SOCKET_ERROR
#define SOCKET_ERROR            (-1)
#endif
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <windows.h>
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#endif

#ifndef USING_PACKAGE_HEAD_LENGTH
#define USING_PACKAGE_HEAD_LENGTH 1
#endif
#ifndef SOCKET_SOTIMEOUT
#define SOCKET_SOTIMEOUT 30.0f
#endif
#ifndef SOCKET_READ_BUFFER_SIZE
#define SOCKET_READ_BUFFER_SIZE 8192
#endif
#ifndef MEMORYTYPE_REVERSE
#define MEMORYTYPE_REVERSE 1
#endif
#ifndef HANDLE_ON_SINGLE_FRAME
#define HANDLE_ON_SINGLE_FRAME 1
#endif
#ifndef CCBUFFER_ORGINAL_SIZE
#define CCBUFFER_ORGINAL_SIZE 512
#endif

#ifndef SINGLE_DELEGATE_INSTANCE_FUNC
#define SINGLE_DELEGATE_INSTANCE_FUNC(_CLASS_) \
static _CLASS_* sharedDelegate() \
{ \
	static _CLASS_* pRet = NULL; \
	if( !pRet ) pRet = new _CLASS_(); \
	return pRet; \
}
#endif //SINGLE_DELEGATE_INSTANCE_FUNC

#endif //__CCNET_MACROS_H__