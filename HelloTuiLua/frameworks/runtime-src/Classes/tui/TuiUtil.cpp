#include "TuiUtil.h"

NS_TUI_BEGIN

Animation* TuiUtil::createAnimWithName(const char* name,float delay,unsigned int iLoops){

	SpriteFrameCache *pCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> v;

	SpriteFrame *pFrame = NULL;
	int index = 1;
	char buf[128] = {0};
	do 
	{
		sprintf(buf,"%s%d.png",name,index++);
		pFrame = pCache->getSpriteFrameByName(buf);
		if(pFrame == NULL){
			break;
		}
		v.pushBack(pFrame);
	} while (true);

	Animation *pAnim = Animation::createWithSpriteFrames(v);
	pAnim->setLoops(iLoops);
	pAnim->setRestoreOriginalFrame(true);
	pAnim->setDelayPerUnit(delay);

	return pAnim;
}

Animation* TuiUtil::createAnimWithNameAndNum(const char* name,int iNum, float delay,unsigned int iLoops){

	SpriteFrameCache *pCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> v;

	SpriteFrame *pFrame = NULL;
	int index = 1;
	char buf[128] = {0};
	
	for(int i=1; i<= iNum; i++){
		sprintf(buf,"%s%d.png",name,index++);
		pFrame = pCache->getSpriteFrameByName(buf);
		if(pFrame == NULL){
			break;
		}
		v.pushBack(pFrame);
	}
	
	Animation *pAnim = Animation::createWithSpriteFrames(v);
	pAnim->setRestoreOriginalFrame(true);
	pAnim->setLoops(iLoops);

	return pAnim;
}

string TuiUtil::replace_all_actual(string str, const string& old_value, const string& new_value)
{
	while (true) {
		string::size_type   pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return str;
}

string TuiUtil::replace_all(string str, const string& old_value, const string& new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length())   {
		if ((pos = str.find(old_value, pos)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return str;
}

vector< string > TuiUtil::split(const std::string& s,const std::string& delim)
{
    std::vector< std::string > ret;
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret.push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret.push_back(s.substr(last,index-last));
    }
    return ret;
}

vector< string > TuiUtil::separateUtf8( const std::string & sin )
{
	int l = sin.length();
	vector<string> ret;
	ret.clear();
	for(int p = 0; p < l; ) {
		int size, n = l - p;
		unsigned char c = sin[p], cc = sin[p + 1];
		if(c < 0x80) {
			size = 1;
		} else if(c < 0xc2) {
			return ret;
		} else if(c < 0xe0) {
			if(n < 2) {
				return ret;
			}
			if(!((sin[p + 1] ^ 0x80) < 0x40)) {
				return ret;
			}
			size = 2;
		} else if(c < 0xf0) {
			if(n < 3) {
				return ret;
			}
			if(!((sin[p + 1] ^ 0x80) < 0x40 && 
				(sin[p + 2] ^ 0x80) < 0x40 &&
				(c >= 0xe1 || cc >= 0xa0))) {
					return ret;
			}
			size = 3;
		} else if(c < 0xf8) {
			if(n < 4) {
				return ret;
			}
			if(!((sin[p + 1] ^ 0x80) < 0x40 &&
				(sin[p + 2] ^ 0x80) < 0x40 &&
				(sin[p + 3] ^ 0x80) < 0x40 &&
				(c >= 0xf1 || cc >= 0x90))) {
					return ret;
			}
			size = 4;
		} else if (c < 0xfc) {
			if(n < 5) {
				return ret;
			}
			if(!((sin[p + 1] ^ 0x80) < 0x40 &&
				(sin[p + 2] ^ 0x80) < 0x40 &&
				(sin[p + 3] ^ 0x80) < 0x40 && 
				(sin[p + 4] ^ 0x80) < 0x40 &&
				(c >= 0xfd || cc >= 0x88))) {
					return ret;
			}
			size = 5;
		} else if (c < 0xfe) {
			if(n < 6) {
				return ret;
			}
			if(!((sin[p + 1] ^ 0x80) < 0x40 &&
				(sin[p + 2] ^ 0x80) < 0x40 &&
				(sin[p + 3] ^ 0x80) < 0x40 && 
				(sin[p + 4] ^ 0x80) < 0x40 &&
				(sin[p + 5] ^ 0x80) < 0x40 &&
				(c >= 0xfd || cc >= 0x84))) {
					return ret;
			}
			size = 6;
		} else {
			return ret;
		}
		string temp = "";
		temp = sin.substr(p, size);
		ret.push_back(temp);
		p += size;
	}
	return ret;
}

bool TuiUtil::isChinese(const std::string &inStr)
{
 unsigned char *str = (unsigned char *)inStr.c_str();
 size_t length = inStr.length();
 for (size_t i=0; i< length; ++i)
 {
  if (str[i] > 160)
  {
   return true;
  }
 }
 return false;
}


NS_TUI_END