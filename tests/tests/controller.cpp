/*
The appropriate modification, in order to more in line with the metro style.
Modifier : Nowpaper
2012 6 10
*/
#include "controller.h"
#include "testResource.h"
#include "tests.h"
#include "CCMetroTpyes.h"

#define LINE_SPACE          120

static CCPoint s_tCurPos = CCPointZero;

static TestScene* CreateTestScene(int nIdx)
{
    CCDirector::sharedDirector()->purgeCachedData();

    TestScene* pScene = NULL;

    switch (nIdx)
    {
    case TEST_ACTIONS:
        pScene = new ActionsTestScene(); break;
    case TEST_TRANSITIONS:
        pScene = new TransitionsTestScene(); break;
    case TEST_PROGRESS_ACTIONS:
        pScene = new ProgressActionsTestScene(); break;
    case TEST_EFFECTS:
        pScene = new EffectTestScene(); break;
    case TEST_CLICK_AND_MOVE:
        pScene = new ClickAndMoveTestScene(); break;
    case TEST_ROTATE_WORLD:
        pScene = new RotateWorldTestScene(); break;
    case TEST_PARTICLE:
        pScene = new ParticleTestScene(); break;
    case TEST_EASE_ACTIONS:
        pScene = new EaseActionsTestScene(); break;
    case TEST_MOTION_STREAK:
        pScene = new MotionStreakTestScene(); break;
    case TEST_DRAW_PRIMITIVES:
        pScene = new DrawPrimitivesTestScene(); break;
    case TEST_COCOSNODE:
        pScene = new CocosNodeTestScene(); break;
    case TEST_TOUCHES:
        pScene = new PongScene(); break;
    case TEST_MENU:
        pScene = new MenuTestScene(); break;
    case TEST_ACTION_MANAGER:
        pScene = new ActionManagerTestScene(); break;
    case TEST_LAYER:
        pScene = new LayerTestScene(); break;
    case TEST_SCENE:
        pScene = new SceneTestScene(); break;
    case TEST_PARALLAX:
        pScene = new ParallaxTestScene(); break;
    case TEST_TILE_MAP:
        pScene = new TileMapTestScene(); break;
    case TEST_INTERVAL:
        pScene = new IntervalTestScene(); break;
//    case TEST_CHIPMUNK:
//#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
//        pScene = new ChipmunkTestScene(); break;
//#else
//#ifdef MARMALADEUSECHIPMUNK
//#if	(MARMALADEUSECHIPMUNK == 1)
//        pScene = new ChipmunkTestScene(); 
//#endif
//		break;
//#endif
//#endif
    case TEST_LABEL:
        pScene = new AtlasTestScene(); break;
//#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
//    case TEST_TEXT_INPUT:
//        pScene = new TextInputTestScene(); break;
//#endif
    case TEST_SPRITE:
        pScene = new SpriteTestScene(); break;
    case TEST_SCHEDULER:
        pScene = new SchedulerTestScene(); break;
    case TEST_RENDERTEXTURE:
        pScene = new RenderTextureScene(); break;
    case TEST_TEXTURE2D:
        pScene = new TextureTestScene(); break;
    case TEST_BOX2D:
        pScene = new Box2DTestScene(); break;
    //case TEST_BOX2DBED:
    //    pScene = new Box2dTestBedScene(); break;
    case TEST_EFFECT_ADVANCE:
        pScene = new EffectAdvanceScene(); break;
    case TEST_HIRES:
        pScene = new HiResTestScene(); break;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	case TEST_ACCELEROMRTER:
        pScene = new AccelerometerTestScene(); break;
#endif
#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA)
    case TEST_KEYPAD:
        pScene = new KeypadTestScene(); break;
#endif
	case TEST_COCOSDENSHION:
		pScene = new CocosDenshionTestScene(); break;
    case TEST_PERFORMANCE:
        pScene = new PerformanceTestScene(); break;
    case TEST_ZWOPTEX:
        pScene = new ZwoptexTestScene(); break;
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
// bada don't support libcurl
//#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA)
//	case TEST_CURL:
//		pScene = new CurlTestScene(); break;
//#endif
#endif
	case TEST_USERDEFAULT:
		pScene = new UserDefaultTestScene(); break;
    case TEST_DIRECTOR:
        pScene = new DirectorTestScene(); break;
    case TEST_BUGS:
        pScene = new BugsTestScene(); break;
	case TEST_FONTS:
		pScene = new FontTestScene(); break;
	case TEST_CURRENT_LANGUAGE:
		pScene = new CurrentLanguageTestScene(); break;
//#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
//	case TEST_TEXTURECACHE: pScene = new TextureCacheTestScene(); break;
//#endif
	
    default:
        break;
    }

    return pScene;
}

TestController::TestController()
: m_tBeginPos(CCPointZero)
{
	
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	
	CCSprite * pbackground = CCSprite::spriteWithFile("metrobackground.png");
	pbackground->setPosition(CCPointMake(s.width/2,s.height/2));
	//addChild(pbackground);
    // add close menu
    CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(s_pPathClose, s_pPathClose, this, menu_selector(TestController::closeCallback) );
    CCMenu* pMenu =CCMenu::menuWithItems(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    pCloseItem->setPosition(CCPointMake( 30, s.height - 50));
	// add title COCOS2S-X
	CCLabelTTF* title = CCLabelTTF::labelWithString("COCOS2D-X-Metro", "Arial", 24);
	title->setAnchorPoint(CCPointMake(0,0.5));
	title->setPosition(CCPointMake(72,s.height - 50));
	addChild(title);
	// Load TestIcons
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("metroIcons.plist", "metroIcons.png");
	char tmp[50];
    // add menu items for tests
    m_pItmeMenu = CCMenu::menuWithItems(NULL);
	int colorscount = sizeof(ccMetroColors) / sizeof(ccColor4B);

	for (int i = 0; i < TESTS_COUNT; ++i)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
		CCLabelBMFont* label = CCLabelBMFont::labelWithString(g_aTestNames[i].c_str(),  "fonts/arial16.fnt");
#else
        CCLabelTTF* label = CCLabelTTF::labelWithString(g_aTestNames[i].c_str(), "Arial", 24);
#endif		
		// Create Metro MenuItem
		CCMenuItemMetro* pMenuItem = CCMenuItemMetro::itemWithMetro(label, this, menu_selector(TestController::menuCallback));
		pMenuItem->setAnchorPoint(CCPointMake(0,0));
		pMenuItem->setMetroSlyte(ccMetroColors[i % colorscount]);
        m_pItmeMenu->addChild(pMenuItem, i + 10000);
		pMenuItem->setPosition(CCPointMake(70 + (i / 3) * (MetroRectW + 10),((MetroRectH + 10)* 3) - (i % 3) * (MetroRectH + 10) - 85));
		//Icons
		sprintf(tmp, "metroicon%d.png", i);
		CCSpriteFrame* frame = cache->spriteFrameByName(tmp);
		CCSprite* pIcon = CCSprite::spriteWithSpriteFrame(frame);
		pMenuItem->addChild(pIcon);
		pIcon->setPosition(CCPointMake(80,60));
    }

	m_pItmeMenu->setContentSize(CCSizeMake((TESTS_COUNT / 3 + 1) * (MetroRectW + 10) - s.width, s.height));
    m_pItmeMenu->setPosition(s_tCurPos);
    addChild(m_pItmeMenu);

    setIsTouchEnabled(true);

    addChild(pMenu, 1);
}

TestController::~TestController()
{
}

void TestController::menuCallback(CCObject * pSender)
{
    // get the userdata, it's the index of the menu item clicked
    CCMenuItem* pMenuItem = (CCMenuItem *)(pSender);
    int nIdx = pMenuItem->getZOrder() - 10000;

    // create the test scene and run it
    TestScene* pScene = CreateTestScene(nIdx);
    if (pScene)
    {
        pScene->runThisTest();
        pScene->release();
    }
}

void TestController::closeCallback(CCObject * pSender)
{
    CCDirector::sharedDirector()->end();
}

void TestController::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	stopAllActions();
	CCDelayTime* delaytime = CCDelayTime::actionWithDuration(0.2);
	delaytime->setTag(99);
	this->runAction(delaytime);
	CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
	m_tBeginPos = touch->locationInView(touch->view());
}

void TestController::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
	CCPoint p1 =	touch->previousLocationInView(touch->view());
	CCPoint p2 =	touch->locationInView(touch->view());
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	float x = m_pItmeMenu->getPosition().x + (p2.x - p1.x) * 2;
	if(x>= 0)
		x = 0;
	else if(x <= -m_pItmeMenu->getContentSize().width)
		x = -m_pItmeMenu->getContentSize().width;
	
	m_pItmeMenu->setPosition(CCPointMake(x,0));
}
void TestController::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCAction* delaytime = CCActionManager::sharedManager()->getActionByTag(99,this);
	if(delaytime != NULL)
		if(delaytime->isDone() == false)
		{
			CCSetIterator it = pTouches->begin();
			CCTouch* touch = (CCTouch*)(*it);
			CCPoint p1 =	m_tBeginPos;
			CCPoint p2 =	touch->locationInView(touch->view());
			float x = m_pItmeMenu->getPosition().x + (p2.x - p1.x) * 5;
			if(x>= 0)
				x = 0;
			else if(x <= -m_pItmeMenu->getContentSize().width)
				x = -m_pItmeMenu->getContentSize().width;
			CCMoveTo* move = CCMoveTo::actionWithDuration(1,CCPointMake(x,0));
			CCActionInterval* ease = CCEaseOut::actionWithAction(move,3.0);
			m_pItmeMenu->runAction(ease);
		}
}


