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
#ifndef __CCNET_SOCKET_H__
#define __CCNET_SOCKET_H__

#include "cocos2d.h"
#include "CCNetMacros.h"
#include "CCInetAddress.h"
#include "CCBuffer.h"
#include <string>

NS_CC_BEGIN

/**
 * enum   : CCSocketStatus
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : socket status define
 */
enum CCSocketStatus
{
	eSocketConnected			=  1,
	eSocketConnecting			=  2,
	eSocketDisconnected			=  3,
	eSocketConnectFailed		=  4,
	eSocketConnectTimeout		=  5,
	eSocketReceive				=  6,
	eSocketIoClosed				=  0,
	eSocketIoError				= -1,
	eSocketCreateFailed			= -2,
};

/**
 * calss  : CCSocket
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : socket manager object
 */
class CCSocket
{
public:
	CCSocket();
	virtual ~CCSocket();
	bool ccInit();
	int  ccRead(char* _buff, int _len);
	int  ccWrite(char* _buff, int _len);
	int  ccIsConnected();
	bool ccIsReadable();
	bool ccIsWritable();
	void ccClose();
	bool ccConnect();
	void ccDisconnect();
	void setInetAddress(const CInetAddress& oInetAddress);

protected:
	SOCKET m_uSocket;
	CInetAddress m_oInetAddress;
};


NS_CC_END

#endif //__CCNET_SOCKET_H__