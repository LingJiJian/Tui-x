#include "TuiUtil.h"

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

