#include "stdafx.h"

USING_NS_CC;

CCScene* CGame::scene()
{
    //!< ���� �����մϴ� ^^
    CCScene *scene = CCScene::create();
    
    //!< HelloWorld ���� ����ϴ� ^^
    CGame *layer = CGame::create();

    //!< Scene �̱��濡 �߰������ݴϴ� ^^
    scene->addChild(layer);

    //!< scene �� return �մϴ�.
    return scene;
}

//!<  �ʱ�ȭ ���ִ� �� �Դϴ�.
bool CGame::init()
{
	//!< ���� �θ��� Init�� ����� Ȱ��ȭ �ȵ��ִٸ� return false �� �����ϴ�.
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	this->setTouchEnabled(true);

	D_GAME_MNG->Init(this);

	//!< ������ ���
	schedule(schedule_selector(CGame::Update), 0.0f);

    return true;
} 

void CGame::Update(float dt)
{
	D_GAME_MNG->Update(dt);
}

void CGame::registerWithTouchDispatcher(void)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addStandardDelegate(this, 0);
}

void CGame::ccTouchesBegan(CCSet* pTouches, CCEvent* event)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
	D_GAME_MNG->TouchDown(touchPoint);
}

void CGame::ccTouchesMoved(CCSet* pTouches, CCEvent* event)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
	D_GAME_MNG->TouchMove(touchPoint);
}
void CGame::ccTouchesEnded(CCSet* pTouches, CCEvent* event)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
	D_GAME_MNG->TouchUp(touchPoint);
}
void CGame::ccTouchesCancelled(CCSet* pTouches, CCEvent* event)
{
    CCLog("Touch cancelled");
}