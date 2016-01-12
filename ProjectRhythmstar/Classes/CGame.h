#pragma once

USING_NS_CC;

class CGame : public CCLayer
{
public:
    virtual bool init();  

	//!< �ش� ���� ���� �̱����� ���� �մϴ�.
    static CCScene* scene();

	//!< ���� ������Ʈ ����
	void Update(float dt);

	//!< ��ġ ���� �Լ�
	virtual void registerWithTouchDispatcher(void);
	void ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void ccTouchesCancelled(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    
    CREATE_FUNC(CGame);
};
