#include "AnimationUtil.h"

NS_TUI_BEGIN

Animation* AnimationUtil::createAnimWithName(const char* name,float delay,unsigned int iLoops){

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

Animation* AnimationUtil::createAnimWithNameAndNum(const char* name,int iNum, float delay,unsigned int iLoops){

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


NS_TUI_END