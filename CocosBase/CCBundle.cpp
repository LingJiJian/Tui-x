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
#include "CCBundle.h"
using namespace std;

#define CCBUNDLE_SHORT 1
#define CCBUNDLE_UNSIGNEDSHORT 2
#define CCBUNDLE_INT 3
#define CCBUNDLE_UNSIGNEDINT 4
#define CCBUNDLE_FLOAT 5
#define CCBUNDLE_DOUBLE 6
#define CCBUNDLE_STRING 7
#define CCBUNDLE_BUNDLE 8
#define CCBUNDLE_OBJECT 9
#define CCBUNDLE_PARAM 10
#define MAP_DATAS std::map<std::string, _ccBUNDLEVALUE>

NS_CC_BEGIN

CCBundle::CCBundle()
{

}

CCBundle::~CCBundle()
{
	MAP_DATAS::iterator iter = m_mDatas.begin();
	for(; iter != m_mDatas.end(); ++iter)
	{
		removeValue(iter->second);
	}
	m_mDatas.clear();
}

CCBundle* CCBundle::create()
{
	CCBundle* pRet = new CCBundle();
	if( pRet )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

Ref* CCBundle::copyWithZone(void* pZone)
{
	void *pNewZone = NULL;
	CCBundle *pRet = NULL;
	if( pZone )
	{
		pRet = (CCBundle*)pZone;
	}
	else
	{
		pRet = new CCBundle();
		pNewZone = pRet;
	}

	MAP_DATAS::iterator iter = m_mDatas.begin();
	for(; iter != m_mDatas.end(); ++iter)
	{
		switch(iter->second.nType)
		{
		case CCBUNDLE_SHORT:
			pRet->putShort(iter->first.c_str(), *((short*)(iter->second.pValue)));
			break;
		case CCBUNDLE_UNSIGNEDSHORT:
			pRet->putUShort(iter->first.c_str(), *((unsigned short*)(iter->second.pValue)));
			break;
		case CCBUNDLE_INT:
			pRet->putInt(iter->first.c_str(), *((int*)(iter->second.pValue)));
			break;
		case CCBUNDLE_UNSIGNEDINT:
			pRet->putUInt(iter->first.c_str(), *((unsigned int*)(iter->second.pValue)));
			break;
		case CCBUNDLE_FLOAT:
			pRet->putFloat(iter->first.c_str(), *((float*)(iter->second.pValue)));
			break;
		case CCBUNDLE_DOUBLE:
			pRet->putDouble(iter->first.c_str(), *((double*)(iter->second.pValue)));
			break;
		case CCBUNDLE_STRING:
			pRet->putString(iter->first.c_str(), (char*)(iter->second.pValue));
			break;
		case CCBUNDLE_BUNDLE:
			pRet->putBundle(iter->first.c_str(), (CCBundle*)((CCBundle*)(iter->second.pValue))->copyWithZone(0));
			break;
		case CCBUNDLE_OBJECT:
			pRet->putObject(iter->first.c_str(), ((Ref*)(iter->second.pValue)));
			break;
		case CCBUNDLE_PARAM:
			pRet->putParam(iter->first.c_str(), iter->second.pValue);
			break;
		default:
			break;
		}
	}

	CC_SAFE_DELETE(pNewZone);
	return pRet;
}

void CCBundle::removeValue(const _ccBUNDLEVALUE& tValue)
{
	switch(tValue.nType)
	{
	case CCBUNDLE_SHORT:
		delete (short*)(tValue.pValue);
		break;
	case CCBUNDLE_UNSIGNEDSHORT:
		delete (unsigned short*)(tValue.pValue);
		break;
	case CCBUNDLE_INT:
		delete (int*)(tValue.pValue);
		break;
	case CCBUNDLE_UNSIGNEDINT:
		delete (unsigned int*)(tValue.pValue);
		break;
	case CCBUNDLE_FLOAT:
		delete (float*)(tValue.pValue);
		break;
	case CCBUNDLE_DOUBLE:
		delete (double*)(tValue.pValue);
		break;
	case CCBUNDLE_STRING:
		delete[] (char*)(tValue.pValue);
		break;
	case CCBUNDLE_BUNDLE:
		((CCBundle*)(tValue.pValue))->release();
		break;
	case CCBUNDLE_OBJECT:
		((Ref*)(tValue.pValue))->release();
		break;
	case CCBUNDLE_PARAM:
		break;
	default:
		break;
	}
}

void CCBundle::removeValueByKey(const char* key)
{
	MAP_DATAS::iterator itr = m_mDatas.find(key);
	if( itr != m_mDatas.end() )
	{
		removeValue(itr->second);
		m_mDatas.erase(itr->first);
	}
}

void CCBundle::putShort(const char* key, short value)
{
	removeValueByKey(key);
	short* ret = new short(value);
	_ccBUNDLEVALUE tag = { CCBUNDLE_SHORT, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putUShort(const char* key, unsigned short value)
{
	removeValueByKey(key);
	unsigned short* ret = new unsigned short(value);
	_ccBUNDLEVALUE tag = { CCBUNDLE_UNSIGNEDSHORT, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putInt(const char* key, int value)
{
	removeValueByKey(key);
	int* ret = new int(value);
	_ccBUNDLEVALUE tag = { CCBUNDLE_INT, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putUInt(const char* key, unsigned int value)
{
	removeValueByKey(key);
	unsigned int* ret = new unsigned int(value);
	_ccBUNDLEVALUE tag = { CCBUNDLE_UNSIGNEDINT, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putFloat(const char* key, float value)
{
	removeValueByKey(key);
	float* ret = new float(value);
	_ccBUNDLEVALUE tag = { CCBUNDLE_FLOAT, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putDouble(const char* key, double value)
{
	removeValueByKey(key);
	double* ret = new double(value);
	_ccBUNDLEVALUE tag = { CCBUNDLE_DOUBLE, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putString(const char* key, const char* value)
{
	removeValueByKey(key);
	size_t ulen = strlen(value);
	char* ret = new char[ulen + 1];
	memcpy(ret, value, ulen);
	ret[ulen] = '\0';

	_ccBUNDLEVALUE tag = { CCBUNDLE_STRING, ret };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putBundle(const char* key, CCBundle* value)
{
	removeValueByKey(key);
	value->retain();
	_ccBUNDLEVALUE tag = { CCBUNDLE_BUNDLE, value };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putObject(const char* key, Ref* value)
{
	removeValueByKey(key);
	value->retain();
	_ccBUNDLEVALUE tag = { CCBUNDLE_OBJECT, value };
	m_mDatas.insert(make_pair(key, tag));
}

void CCBundle::putParam(const char* key, void* value)
{
	removeValueByKey(key);
	_ccBUNDLEVALUE tag = { CCBUNDLE_PARAM, value };
	m_mDatas.insert(make_pair(key, tag));
}

short CCBundle::getShort(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_SHORT )
		{
			return *((short*)(iter->second.pValue));
		}
	}
	return 0;
}

unsigned short CCBundle::getUShort(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_UNSIGNEDSHORT )
		{
			return *((unsigned short*)(iter->second.pValue));
		}
	}
	return 0;
}

int CCBundle::getInt(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_INT )
		{
			return *((int*)(iter->second.pValue));
		}
	}
	return 0;
}

unsigned int CCBundle::getUInt(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_UNSIGNEDINT )
		{
			return *((unsigned int*)(iter->second.pValue));
		}
	}
	return 0;
}

float CCBundle::getFloat(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_FLOAT )
		{
			return *((float*)(iter->second.pValue));
		}
	}
	return 0;
}

double CCBundle::getDouble(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_DOUBLE )
		{
			return *((double*)(iter->second.pValue));
		}
	}
	return 0;
}

const char* CCBundle::getString(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_STRING )
		{
			return (char*)(iter->second.pValue);
		}
	}
	return NULL;
}

CCBundle* CCBundle::getBundle(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_BUNDLE )
		{
			return (CCBundle*)(iter->second.pValue);
		}
	}
	return NULL;
}

Ref* CCBundle::getObject(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_OBJECT )
		{
			return (Ref*)(iter->second.pValue);
		}
	}
	return NULL;
}

void* CCBundle::getParam(const char* key)
{
	MAP_DATAS::iterator iter = m_mDatas.find(key);
	if( iter != m_mDatas.end() )
	{
		if( iter->second.nType == CCBUNDLE_PARAM )
		{
			return iter->second.pValue;
		}
	}
	return NULL;
}

NS_CC_END
