/*
The code is written by nowpaper, without any profit purposes. 
Developer: nowpaper 
*/
#include "pch.h"
#include "CMenuItemMetro.h"
#include "CCLayer.h"
#include "CCMetroTpyes.h"
namespace cocos2d
{
	
	CCMenuItemMetro::~CCMenuItemMetro()
	{
	}
	CCMenuItemMetro * CCMenuItemMetro::itemWithMetro(CCNode*label, SelectorProtocol* target, SEL_MenuHandler selector)
	{
		CCMenuItemMetro *pRet = new CCMenuItemMetro();
		pRet->initWithMetro(label, target, selector);
		pRet->autorelease();
		return pRet;
	}
	CCMenuItemMetro* CCMenuItemMetro::itemWithMetro(CCNode *label)
	{
		CCMenuItemMetro *pRet = new CCMenuItemMetro();
		pRet->initWithLabel(label, NULL, NULL);
		pRet->autorelease();
		return pRet;
	}
	void CCMenuItemMetro::activate()
	{
		if(m_bIsEnabled)
		{
			CCMenuItem::activate();
		}
	}
	void CCMenuItemMetro::selected()
	{
		if(m_bIsEnabled)
		{
			CCMenuItem::selected();

		}
	}
	void CCMenuItemMetro::unselected()
	{
		if(m_bIsEnabled)
		{
			CCMenuItem::unselected();
			
		}
	}
	bool CCMenuItemMetro::initWithMetro(CCNode* label, SelectorProtocol* target, SEL_MenuHandler selector)
	{
	    m_pLayer = CCLayerColor::layerWithColorWidthHeight(ccMarine,MetroRectW,MetroRectH);
		addChild(m_pLayer,-10);
		CCMenuItem::initWithTarget(target, selector);
		m_fOriginalScale = 1.0f;
		m_tColorBackup = ccWHITE;
		m_tDisabledColor = ccc3(126,126,126);
		this->setLabel(label);
		m_pLabel->setPosition(CCPointMake(20,10));
		/*setContentSize(pLayer->getContentSize());*/
		return true;
	}
	void CCMenuItemMetro::setMetroSlyte(ccColor4B color,CCfloat width,CCfloat height)
	{
		dynamic_cast<CCLayerColor*>(m_pLayer)->setColor(ccc3(color.r,color.g,color.b));
		dynamic_cast<CCLayerColor*>(m_pLayer)->setOpacity(color.a);
		dynamic_cast<CCLayerColor*>(m_pLayer)->setContentSize(CCSizeMake(width,height));
	}
	void CCMenuItemMetro::setMetroSlyte(ccColor4B color)
	{
		dynamic_cast<CCLayerColor*>(m_pLayer)->setColor(ccc3(color.r,color.g,color.b));
		dynamic_cast<CCLayerColor*>(m_pLayer)->setOpacity(color.a);
	}
	CCNode * CCMenuItemMetro::getPPLayer()
	{
		return m_pLayer;
	}
	void CCMenuItemMetro::setPPLayer(CCNode* var)
	{
        if (var)
        {
            addChild(var, 0);
            var->setIsVisible(true);
        }

        if (m_pLayer)
        {
            removeChild(m_pLayer, true);
        }

        m_pLayer = var;
	}
}