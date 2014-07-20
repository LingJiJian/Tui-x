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
#ifndef __CCNET_BUFFER_H__
#define __CCNET_BUFFER_H__

#include "cocos2d.h"
#include "CCNetMacros.h"
#include <string>

NS_CC_BEGIN

/**
 * calss  : CCBuffer
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : the bytes buffer
 */
class CBuffer : public Ref
{
public:
	CBuffer();
	explicit CBuffer(unsigned int n_capacity);
	CBuffer(const char* p_data, unsigned int u_len);
	virtual ~CBuffer();
	static CBuffer* create();
	static CBuffer* create(unsigned int n_capacity);
	static CBuffer* create(const char* p_data, unsigned int u_len);
	Ref* copy();

public:
	unsigned int length() const;
	unsigned int capacity() const;
	bool empty() const;
	char* data() const;
	void clear();

public:
	unsigned int getWriterIndex() const;
	unsigned int getContentSize() const;
	unsigned int getReadableSize() const;
	unsigned int getReaderIndex() const;
	unsigned int getBufferSize() const;
	void discardReadContent();
	void skipData(unsigned int u_len);
	void moveWriterIndexToFront();
	void moveWriterIndexToBack();
	void moveReaderIndexToFront();
	void moveReaderIndexToBack();
	void markReaderIndex();
	void resetReaderIndex();
	void reset();
	void setReaderIndex(unsigned int u_pos);
	void setWriterIndex(unsigned int u_pos);
	void moveLeft(unsigned int u_len);
	void moveRight(unsigned int u_len);
	bool isReadable() const;
	bool isReadable(unsigned int u_len) const;

public:
	void writeData(const char* p_data, unsigned int u_len);
	void writeLengthAndData(const char* p_data, unsigned int u_len);
	void writeChar(char data);
	void writeUChar(unsigned char data);
	void writeShort(short data);
	void writeUShort(unsigned short data);
	void writeInt(int data);
	void writeUInt(unsigned int data);
	void writeLongLong(long long data);
	void writeULongLong(unsigned long long data);
	void writeFloat(float data);
	void writeDouble(double data);
	void writeString(const char* p_data);
	void writeLengthAndString(const char* p_data);

public:
	// warning: need to delete[]
	char* readWholeData();

public:
	CBuffer* readData(unsigned int u_len);
	void readData(char* p_out_data, unsigned int u_len);
	char readChar();
	unsigned char readUChar();
	short readShort();
	unsigned short readUShort();
	int readInt();
	unsigned int readUInt();
	long long readLongLong();
	unsigned long long readULongLong();
	float readFloat();
	double readDouble();
	std::string readString(unsigned int u_len);
	std::string readLengthAndString();

protected:
	inline void _reallocBufferSizeInChanged(unsigned int u_len);
	inline void _reallocBufferSize();

protected:
	char* _p_buffer;
	unsigned int _u_write_pos;
	unsigned int _u_read_pos;
	unsigned int _u_mark_pos;
	unsigned int _u_content_size;
	unsigned int _u_buffer_size;
	
};

NS_CC_END

#endif //__CCNET_BUFFER_H__