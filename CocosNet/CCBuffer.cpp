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
#include "CCBuffer.h"
#include <stdlib.h>
#include <algorithm>

NS_CC_BEGIN

#ifndef JASON_LEE_LANGUAGE
#define JASON_LEE_LANGUAGE
#define BEGIN_IF(con) if(con) {
#define BEGIN_ELSE_IF(con) } else if(con) {
#define BEGIN_ELSE } else {
#define END_IF }
#define BEGIN_WHILE_TRUE while(true) {
#define BEGIN_WHILE(con) while(con) {
#define END_WHILE }
#define BEGIN_DO_WHILE do {
#define END_DO_WHILE(con) } while(con);
#define END_DO_WHILE_TRUE } while(true);
#define BEGIN_FOR(a,con,c) for(a;con;c) {
#define BEGIN_FOR_TRUE(a,c) for(a;true;c) {
#define END_FOR }
#define DO_CONTINUE continue
#define DO_BREAK break
#define DO_ASSIGN(n,v) n = v
#define DO_ASSERT(c,m) CCAssert(c,m)
#define DO_RETURN_R(r) return r
#define DO_RETURN_FLASE return false
#define DO_RETURN_TRUE return true
#define DO_RETURN_NULL return NULL
#define DO_RETURN_Z return 0
#define DO_RETURN return
#define R_FALSE false
#define R_TRUE true
#define TO_SHORT(a) ((short)a)
#define TO_USHORT(a) ((unsigned short)a)
#define TO_INT(a) ((int)a)
#define TO_UINT(a) ((unsigned int)a)
#define IAA(a) a++
#define AAI(a) ++a
#define ISS(a) a--
#define SSI(a) --a
#define CA(a,b) (a + b)
#define CS(a,b) (a - b)
#define CM(a,b) (a * b)
#define CD(a,b) (a / b)
#define LX(a,b) (a < b)
#define LD(a,b) (a > b)
#define LE(a,b) (a == b)
#define LXE(a,b) (a <= b)
#define LDE(a,b) (a >= b)
#define LNE(a,b) (a != b)
#define LQ(a,b) (a && b)
#define LH(a,b) (a || b)
#define AA(a,b) (a += b)
#define AS(a,b) (a -= b)
#define AM(a,b) (a *= b)
#define AD(a,b) a = a / b
#define MAXA(a,b) a = (((a) < (b)) ? (b) : (a))
#define MINA(a,b) a = (((a) < (b)) ? (a) : (b))
#define QV(a) *(a)
#define QZ(a) &(a)
#endif //JASON_LEE_LANGUAGE

CBuffer::CBuffer()
: _p_buffer(NULL)
, _u_write_pos(0)
, _u_read_pos(0)
, _u_content_size(0)
, _u_buffer_size(CCBUFFER_ORGINAL_SIZE)
, _u_mark_pos(0)
{
	DO_ASSIGN(_p_buffer, (char*) malloc(_u_buffer_size));
}

CBuffer::CBuffer(unsigned int n_capacity)
: _p_buffer(NULL)
, _u_write_pos(0)
, _u_read_pos(0)
, _u_content_size(0)
, _u_mark_pos(0)
{
	DO_ASSIGN(_u_buffer_size, n_capacity);
	DO_ASSIGN(_p_buffer, (char*) malloc(_u_buffer_size));
}

CBuffer::CBuffer(const char* p_data, unsigned int u_len)
: _p_buffer(NULL)
, _u_read_pos(0)
, _u_mark_pos(0)
{
	DO_ASSERT(p_data && LD(u_len, 0), "p_data && u_len > 0");

	DO_ASSIGN(_u_buffer_size, u_len);
	DO_ASSIGN(_u_write_pos, u_len);
	DO_ASSIGN(_u_content_size, u_len);
	DO_ASSIGN(_p_buffer, (char*) malloc(u_len));

	memcpy(_p_buffer, p_data, u_len);
}

CBuffer::~CBuffer()
{
	CC_SAFE_FREE(_p_buffer);
}

CBuffer* CBuffer::create()
{
	DO_ASSIGN(CBuffer* pRet, new CBuffer());
	pRet->autorelease();
	DO_RETURN_R(pRet);
}

CBuffer* CBuffer::create(unsigned int n_capacity)
{
	DO_ASSIGN(CBuffer* pRet, new CBuffer(n_capacity));
	pRet->autorelease();
	DO_RETURN_R(pRet);
}

CBuffer* CBuffer::create(const char* p_data, unsigned int u_len)
{
	DO_ASSIGN(CBuffer* pRet, new CBuffer(p_data, u_len));
	pRet->autorelease();
	DO_RETURN_R(pRet);
}

Ref* CBuffer::copy()
{
	BEGIN_IF(LD(_u_content_size, 0))
	DO_ASSIGN(CBuffer* p_buf, new CBuffer(_p_buffer, _u_content_size));
	DO_RETURN_R(p_buf);
	BEGIN_ELSE
	DO_RETURN_NULL;
	END_IF
}

unsigned int CBuffer::getWriterIndex() const
{
	DO_RETURN_R(_u_write_pos);
}

unsigned int CBuffer::getContentSize() const
{
	DO_RETURN_R(_u_content_size);
}

unsigned int CBuffer::getReadableSize() const
{
	DO_RETURN_R(CS(_u_content_size, _u_read_pos));
}

unsigned int CBuffer::getReaderIndex() const
{
	DO_RETURN_R(_u_read_pos);
}

unsigned int CBuffer::getBufferSize() const
{
	DO_RETURN_R(_u_buffer_size);
}

void CBuffer::discardReadContent()
{
	BEGIN_IF(LD(_u_read_pos, 0))
	moveLeft(_u_read_pos);
	END_IF
}

void CBuffer::skipData(unsigned int u_len)
{
	BEGIN_IF(LXE(CA(_u_read_pos, u_len), _u_content_size))
	AA(_u_read_pos, u_len);
	BEGIN_ELSE
	AA(_u_read_pos, (CS(_u_content_size, _u_read_pos)));
	END_IF
}

void CBuffer::moveWriterIndexToFront()
{
	DO_ASSIGN(_u_write_pos, 0);
}

void CBuffer::moveWriterIndexToBack()
{
	DO_ASSIGN(_u_write_pos, _u_content_size);
}

void CBuffer::moveReaderIndexToFront()
{
	DO_ASSIGN(_u_read_pos, 0);
}

void CBuffer::moveReaderIndexToBack()
{
	DO_ASSIGN(_u_read_pos, _u_content_size);
}

void CBuffer::reset()
{
	moveWriterIndexToFront();
	moveReaderIndexToFront();
	DO_ASSIGN(_u_mark_pos, 0);
	DO_ASSIGN(_u_content_size, 0);
}

void CBuffer::markReaderIndex()
{
	DO_ASSIGN(_u_mark_pos, _u_read_pos);
}

void CBuffer::resetReaderIndex()
{
	DO_ASSIGN(_u_read_pos, _u_mark_pos);
}

void CBuffer::setReaderIndex(unsigned int u_pos)
{
	DO_ASSERT(LXE(u_pos, _u_content_size), "LXE(u_pos, _u_content_size)");
	DO_ASSIGN(_u_read_pos, u_pos);
}

void CBuffer::setWriterIndex(unsigned int u_pos)
{
	DO_ASSERT(LXE(u_pos, _u_content_size), "LXE(u_pos, _u_content_size)");
	DO_ASSIGN(_u_write_pos, u_pos);
}

void CBuffer::moveLeft(unsigned int u_len)
{
	BEGIN_IF(LE(_u_content_size, 0))
	DO_RETURN;
	END_IF
	DO_ASSERT(LNE(u_len, 0), "LNE(u_len, 0)");
	BEGIN_IF(LDE(u_len, _u_content_size)) clear();
	BEGIN_ELSE
	BEGIN_FOR(DO_ASSIGN(unsigned int i, u_len), LX(i, _u_content_size), AAI(i))
	DO_ASSIGN(QV(CA(_p_buffer, CS(i, u_len))), QV(CA(_p_buffer, i)));
	DO_ASSIGN(QV(CA(_p_buffer, i)), 0);
	END_FOR
	DO_ASSIGN(_u_write_pos, TO_UINT(MAX(0, CS(TO_INT(_u_write_pos), TO_INT(u_len)))));
	DO_ASSIGN(_u_read_pos, TO_UINT(MAX(0, CS(TO_INT(_u_read_pos), TO_INT(u_len)))));
	DO_ASSIGN(_u_mark_pos, TO_UINT(MAX(0, CS(TO_INT(_u_mark_pos), TO_INT(u_len)))));
	DO_ASSIGN(_u_content_size, CS(_u_content_size, u_len));
	END_IF
}

void CBuffer::moveRight(unsigned int u_len)
{
	BEGIN_IF(LE(_u_content_size, 0))
	DO_RETURN;
	END_IF
	_reallocBufferSizeInChanged(u_len);
	BEGIN_FOR(DO_ASSIGN(int i, CS(_u_content_size, 1)), LDE(i, 0), SSI(i))
	DO_ASSIGN(QV(CA(CA(_p_buffer, i), TO_INT(u_len))), QV(CA(_p_buffer, i)));
	DO_ASSIGN(QV(CA(_p_buffer, i)), 0);
	END_FOR
	AA(_u_write_pos, u_len);
	AA(_u_read_pos, u_len);
	AA(_u_mark_pos, u_len);
	AA(_u_content_size, u_len);
}

bool CBuffer::isReadable() const
{
	BEGIN_IF(LE(_u_content_size, 0))
	DO_RETURN_FLASE;
	END_IF
	DO_RETURN_R(LX(_u_read_pos, _u_content_size));
}

bool CBuffer::isReadable(unsigned int u_len) const
{
	BEGIN_IF(LH(LE(_u_content_size, 0), LE(u_len, 0)))
	DO_RETURN_FLASE;
	END_IF
	DO_RETURN_R(LXE(CA(_u_read_pos, u_len), _u_content_size));
}

unsigned int CBuffer::length() const
{
	DO_RETURN_R(getContentSize());
}

unsigned int CBuffer::capacity() const
{
	DO_RETURN_R(getBufferSize());
}

bool CBuffer::empty() const
{
	DO_RETURN_R(LE(length(), 0));
}

char* CBuffer::data() const
{
	DO_RETURN_R(_p_buffer);
}

void CBuffer::clear()
{
	DO_ASSIGN(_u_content_size, 0);
	DO_ASSIGN(_u_write_pos, 0);
	DO_ASSIGN(_u_read_pos, 0);
	DO_ASSIGN(_u_mark_pos, 0);
	memset(_p_buffer, 0, _u_buffer_size);
}

void CBuffer::_reallocBufferSize()
{
	DO_ASSIGN(_u_buffer_size, CM(_u_buffer_size, 2));
	DO_ASSIGN(_p_buffer, (char*) realloc(_p_buffer, _u_buffer_size));
}

void CBuffer::_reallocBufferSizeInChanged(unsigned int u_len)
{
	BEGIN_WHILE_TRUE
	BEGIN_IF( LXE(CA(_u_write_pos, u_len), _u_buffer_size) )
	DO_BREAK;
	BEGIN_ELSE
	_reallocBufferSize();
	END_IF
	END_WHILE
}

void CBuffer::writeData(const char* p_data, unsigned int u_len)
{
	DO_ASSERT(LQ(p_data, LD(u_len,0)), "LQ(p_data, LD(u_len,0))");
	_reallocBufferSizeInChanged(u_len);
	memcpy(CA(_p_buffer, _u_write_pos), p_data, u_len);
	AA(_u_write_pos, u_len);
	MAXA(_u_content_size, _u_write_pos);
}

void CBuffer::writeLengthAndData(const char* p_data, unsigned int u_len)
{
	writeUInt(u_len);
	writeData(p_data, u_len);
}

void CBuffer::writeChar(char data)
{
	_reallocBufferSizeInChanged(sizeof(char));
	DO_ASSIGN(QV(CA(_p_buffer, _u_write_pos)), data);
	AAI(_u_write_pos);
	MAXA(_u_content_size, _u_write_pos);
}

void CBuffer::writeUChar(unsigned char data)
{
	writeChar((char)data);
}

void CBuffer::writeShort(short data)
{
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_data[sizeof(short)], {0});
	memcpy(p_data, (short*)(QZ(data)), sizeof(short));
	std::reverse(QZ(p_data[0]), QZ(p_data[sizeof(short)]));
	writeData(p_data, sizeof(short));
#else
	DO_ASSIGN(char* p_data, (char*)(QZ(data)));
	writeData(p_data, sizeof(short));
#endif
}

void CBuffer::writeUShort(unsigned short data)
{
	writeShort(TO_SHORT(data));
}

void CBuffer::writeInt(int data)
{
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_data[sizeof(int)], {0});
	memcpy(p_data, (char*)(QZ(data)), sizeof(int));
	std::reverse(QZ(p_data[0]), QZ(p_data[sizeof(int)]));
	writeData(p_data, sizeof(int));
#else
	DO_ASSIGN(char* p_data, (char*)(QZ(data)));
	writeData(p_data, sizeof(int));
#endif
}

void CBuffer::writeUInt(unsigned int data)
{
	writeInt(TO_INT(data));
}

void CBuffer::writeLongLong(long long data)
{
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_data[sizeof(long long)], {0});
	memcpy(p_data, (char*)(QZ(data)), sizeof(long long));
	std::reverse(QZ(p_data[0]), QZ(p_data[sizeof(long long)]));
	writeData(p_data, sizeof(long long));
#else
	DO_ASSIGN(char* p_data, (char*)(QZ(data)));
	writeData(p_data, sizeof(long long));
#endif
}

void CBuffer::writeULongLong(unsigned long long data)
{
	writeLongLong((long long)(data));
}

void CBuffer::writeFloat(float data)
{
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_data[sizeof(float)], {0});
	memcpy(p_data, (char*)(QZ(data)), sizeof(float));
	std::reverse(QZ(p_data[0]), QZ(p_data[sizeof(float)]));
	writeData(p_data, sizeof(float));
#else
	DO_ASSIGN(char* p_data, (char*)(QZ(data)));
	writeData(p_data, sizeof(float));
#endif
}

void CBuffer::writeDouble(double data)
{
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_data[sizeof(double)], {0});
	memcpy(p_data, (char*)(QZ(data)), sizeof(double));
	std::reverse(QZ(p_data[0]), QZ(p_data[sizeof(double)]));
	writeData(p_data, sizeof(double));
#else
	DO_ASSIGN(char* p_data, (char*)(QZ(data)));
	writeData(p_data, sizeof(double));
#endif
}

void CBuffer::writeString(const char* p_data)
{
	DO_ASSERT(LQ(p_data, LD(strlen(p_data), 0)), "p_data, LD(strlen(p_data), 0)");
	writeData(p_data, strlen(p_data));
}

void CBuffer::writeLengthAndString(const char* p_data)
{
	DO_ASSERT(LQ(p_data, LD(strlen(p_data), 0)), "p_data, LD(strlen(p_data), 0)");
	writeShort(strlen(p_data));
	writeString(p_data);
}

char* CBuffer::readWholeData()
{
	BEGIN_IF(LNE(_u_content_size, 0))
	DO_ASSIGN(char* p_buffer, new char[_u_content_size]);
	memcpy(p_buffer, _p_buffer, _u_content_size);
	DO_ASSIGN(_u_read_pos, _u_content_size);
	DO_RETURN_R(p_buffer);
	BEGIN_ELSE
	DO_RETURN_NULL;
	END_IF
}

CBuffer* CBuffer::readData(unsigned int u_len)
{
	BEGIN_IF(isReadable(u_len))
	DO_ASSIGN(char* p_data, (char*) malloc(u_len));
	readData(p_data, u_len);
	DO_ASSIGN(CBuffer* p_ret, new CBuffer(p_data, u_len));
	p_ret->autorelease();
	CC_SAFE_FREE(p_data);
	DO_RETURN_R(p_ret);
	BEGIN_ELSE
	DO_RETURN_NULL;
	END_IF
}

void CBuffer::readData(char* p_out_data, unsigned int u_len)
{
	BEGIN_IF(isReadable(u_len))
	memcpy(p_out_data, CA(_p_buffer, _u_read_pos), u_len);
	AA(_u_read_pos, u_len);
	BEGIN_ELSE_IF(LQ(LDE(CS(_u_content_size, _u_read_pos),0), LNE(u_len, 0)))
	DO_ASSIGN(u_len, CS(_u_content_size, _u_read_pos));
	memcpy(p_out_data, CA(_p_buffer, _u_read_pos), u_len);
	AA(_u_read_pos, u_len);
	END_IF
}

char CBuffer::readChar()
{
	BEGIN_IF(isReadable(sizeof(char)))
	DO_ASSIGN(char ret, QV(CA(_p_buffer, _u_read_pos)));
	AA(_u_read_pos, sizeof(char));
	DO_RETURN_R(ret);
	BEGIN_ELSE
	DO_RETURN_Z;
	END_IF
}

unsigned char CBuffer::readUChar()
{
	DO_RETURN_R((unsigned char)readChar());
}

short CBuffer::readShort()
{
	BEGIN_IF(isReadable(sizeof(short)))
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_temp[sizeof(short)], {0});
	memcpy(p_temp, CA(_p_buffer, _u_read_pos), sizeof(short));
	std::reverse(QZ(p_temp[0]), QZ(p_temp[sizeof(short)]));
	DO_ASSIGN(short ret, QV((short*)p_temp));
#else
	DO_ASSIGN(short ret, QV((short*)(CA(_p_buffer, _u_read_pos))));
#endif
	AA(_u_read_pos, sizeof(short));
	DO_RETURN_R(ret);
	BEGIN_ELSE
	DO_RETURN_Z;
	END_IF
}

unsigned short CBuffer::readUShort()
{
	DO_RETURN_R(TO_USHORT(readShort()));
}

int CBuffer::readInt()
{
	BEGIN_IF(isReadable(sizeof(int)))
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_temp[sizeof(int)], {0});
	memcpy(p_temp, CA(_p_buffer, _u_read_pos), sizeof(int));
	std::reverse(QZ(p_temp[0]), QZ(p_temp[sizeof(int)]));
	DO_ASSIGN(int ret, QV((int*)p_temp));
#else
	DO_ASSIGN(int ret, QV((int*)(CA(_p_buffer, _u_read_pos))));
#endif
	AA(_u_read_pos, sizeof(int));
	DO_RETURN_R(ret);
	BEGIN_ELSE
	DO_RETURN_Z;
	END_IF
}

unsigned int CBuffer::readUInt()
{
	DO_RETURN_R(TO_UINT(readInt()));
}

long long CBuffer::readLongLong()
{
	BEGIN_IF(isReadable(sizeof(long long)))
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_temp[sizeof(long long)], {0});
	memcpy(p_temp, CA(_p_buffer, _u_read_pos), sizeof(long long));
	std::reverse(QZ(p_temp[0]), QZ(p_temp[sizeof(long long)]));
	DO_ASSIGN(long long ret, QV((long long*)p_temp));
#else
	DO_ASSIGN(long long ret, QV((long long*)(CA(_p_buffer, _u_read_pos))));
#endif
	AA(_u_read_pos, sizeof(long long));
	DO_RETURN_R(ret);
	BEGIN_ELSE
	DO_RETURN_Z;
	END_IF
}

unsigned long long CBuffer::readULongLong()
{
	DO_RETURN_R((unsigned long long)(readLongLong()));
}

float CBuffer::readFloat()
{
	BEGIN_IF(isReadable(sizeof(float)))
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_temp[sizeof(float)], {0});
	memcpy(p_temp, CA(_p_buffer, _u_read_pos), sizeof(float));
	std::reverse(QZ(p_temp[0]), QZ(p_temp[sizeof(float)]));
	DO_ASSIGN(float ret, QV((float*)p_temp));
#else
	DO_ASSIGN(float ret, QV((float*)(CA(_p_buffer, _u_read_pos))));
#endif
	AA(_u_read_pos, sizeof(float));
	DO_RETURN_R(ret);
	BEGIN_ELSE
	DO_RETURN_Z;
	END_IF
}

double CBuffer::readDouble()
{
	BEGIN_IF(isReadable(sizeof(double)))
#if MEMORYTYPE_REVERSE
	DO_ASSIGN(char p_temp[sizeof(double)], {0});
	memcpy(p_temp, CA(_p_buffer, _u_read_pos), sizeof(double));
	std::reverse(QZ(p_temp[0]), QZ(p_temp[sizeof(double)]));
	DO_ASSIGN(double ret, QV((double*)p_temp));
#else
	DO_ASSIGN(double ret, QV((double*)(CA(_p_buffer, _u_read_pos))));
#endif
	AA(_u_read_pos, sizeof(double));
	DO_RETURN_R(ret);
	BEGIN_ELSE
	DO_RETURN_Z;
	END_IF
}

std::string CBuffer::readString(unsigned int u_len)
{
	DO_ASSERT(LD(u_len, 0), "LD(u_len, 0)");
	std::string str;
	DO_ASSIGN(char* p_data, (char*)malloc(CA(u_len, 1)));
	readData(p_data, u_len);
	DO_ASSIGN(p_data[u_len], 0);
	str.assign(p_data);
	CC_SAFE_FREE(p_data);
	return str;
}

std::string CBuffer::readLengthAndString()
{
	int len = readShort();
	if (len == 0) return "";
	DO_RETURN(readString(len));
} 


NS_CC_END