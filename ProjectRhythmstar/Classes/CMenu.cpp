#include "stdafx.h"

USING_NS_CC;

CCScene* CMenu::scene()
{
    //!< ���� �����մϴ� ^^
    CCScene *scene = CCScene::create();
    
    //!< HelloWorld ���� ����ϴ� ^^
    CMenu *layer = CMenu::create();

    //!< Scene �̱��濡 �߰������ݴϴ� ^^
    scene->addChild(layer);

    //!< scene �� return �մϴ�.
    return scene;
}

//!<  �ʱ�ȭ ���ִ� �� �Դϴ�.
bool CMenu::init()
{
	//!< ���� �θ��� Init�� ����� Ȱ��ȭ �ȵ��ִٸ� return false �� �����ϴ�.
    if ( !CCLayer::init() )
    {
        return false;
    }
    

	//!< ������ ���
	schedule(schedule_selector(CMenu::Update) , 0.0);

    return true;
} 

void CMenu::Update(float dt)
{
	
}