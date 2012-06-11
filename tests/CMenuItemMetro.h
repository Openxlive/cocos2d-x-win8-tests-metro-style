/*
The code is written by nowpaper, without any profit purposes. 
Developer: nowpaper 
*/
#ifndef __CCMENUITEMMETRO_H__
#define __CCMENUITEMMETRO_H__
#include "ccmenuitem.h"
namespace cocos2d
{

class CC_DLL CCMenuItemMetro :
	public CCMenuItemLabel
{
public:
	CCMenuItemMetro():m_pLayer(NULL){};
	~CCMenuItemMetro();
	static CCMenuItemMetro* itemWithMetro(CCNode *label);
	static CCMenuItemMetro * itemWithMetro(CCNode*label, SelectorProtocol* target, SEL_MenuHandler selector);
	bool initWithMetro(CCNode* label, SelectorProtocol* target, SEL_MenuHandler selector);
	void setMetroSlyte(ccColor4B color,CCfloat width,CCfloat height);
	void setMetroSlyte(ccColor4B color);
	// super methods
	virtual void activate();
	virtual void selected();
	virtual void unselected();
private:
	CC_PROPERTY(CCNode*, m_pLayer, PPLayer);
	
};

}
#endif //__CCMENUITEMMETRO_H__