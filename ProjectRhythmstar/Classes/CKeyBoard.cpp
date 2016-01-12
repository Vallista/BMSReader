#include "stdafx.h"

/**
 @brief : ������
*/
CKeyboard::CKeyboard()
{

}

/**
 @brief : �Ҹ���
*/
CKeyboard::~CKeyboard()
{
	Destroy();
}

void CKeyboard::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}

/**
 @brief : �ʱ�ȭ �Լ�
 @pLayer : ���� ���̾�
*/
void CKeyboard::Init(CCLayer* pLayer)
{
	m_pLayer	= pLayer;
	m_bActive	= true;
	m_fTimer	= 0.0f;

	for(int i = 0 ; i < 7 ; i++)
	{
		//!< ��� Ű
		if(i % 2 == 0)
		{
			m_pKeyboard[i] = CCSprite::create("Images/Game/Keyboard/2.png");
			m_pKeyboard[i]->setPosition(ccp(126 + (i / 2) * 64 , 192));
			m_pKeyboard[i]->setVisible(false);
			m_pKeyboard[i]->setScaleX(1.4f);
			m_pKeyboard[i]->setScaleY(1.35f);
			m_pLayer->addChild(m_pKeyboard[i] , 50);

			m_pLine[i] = CCSprite::create("Images/Game/Keyboard/whiteTouch.png");
			m_pLine[i]->setAnchorPoint(ccp(0.5f , 0.0f));
			m_pLine[i]->setOpacity(255.0f);
			m_pLine[i]->setScaleX(1.1f);
			m_pLine[i]->setPosition(ccp(126 + (i / 2) * 64 , 232.5f));
			m_pLine[i]->setVisible(false);
			m_pLayer->addChild(m_pLine[i] , 20);
		}
		//!< �Ķ��� Ű
		else
		{
			m_pKeyboard[i] = CCSprite::create("Images/Game/Keyboard/1.png");
			m_pKeyboard[i]->setPosition(ccp(158 + ((i / 2)) * 64 , 201));
			m_pKeyboard[i]->setVisible(false);
			m_pKeyboard[i]->setScaleX(1.25f);
			m_pKeyboard[i]->setScaleY(1.35f);
			m_pLayer->addChild(m_pKeyboard[i] , 50);

			m_pLine[i] = CCSprite::create("Images/Game/Keyboard/blueTouch.png");
			m_pLine[i]->setAnchorPoint(ccp(0.5f , 0.0f));
			m_pLine[i]->setOpacity(255.0f);
			m_pLine[i]->setScaleX(1.1f);
			m_pLine[i]->setPosition(ccp(158 + ((i / 2)) * 64 , 232.5f));
			m_pLine[i]->setVisible(false);
			m_pLayer->addChild(m_pLine[i] , 20);
		}

		m_bCheckLineSound[i] = false;
	}
	
	//!< �� ���� ��Ŭ Ű
	m_pLine[7] = CCSprite::create("Images/Game/Keyboard/cdTouch.png");
	m_pLine[7]->setAnchorPoint(ccp(0.5f , 0.0f));
	m_pLine[7]->setScaleX(1.1f);
	m_pLine[7]->setOpacity(255.0f);
	m_pLine[7]->setPosition(ccp(72 , 232.5f));
	m_pLine[7]->setVisible(false);
	m_pLayer->addChild(m_pLine[7] , 20);
	m_bCheckLineSound[7] = false;

	for(int i = 0 ; i < 8 ; i++)
	{
		m_pEffect[i] = new CEffect(m_pLayer);
		m_pEffect[i]->Init("Images/Game/Effect/effect_list" , "Effect_" , ".png" , 55 , 8 , 0.02f , true);
	}
}

/**
 @brief : ������Ʈ �Լ�
*/
void CKeyboard::Update(float dt)
{
	if(!m_bActive) return;
	m_fTimer += dt;

	for(int i = 0 ; i < 8 ; i++) m_pEffect[i]->Update(dt);
	//!< Ű ������Ʈ ����
	for(int i = 0 ; i < 8; i++) { if(!m_pLine[i]->isVisible()) continue; if(m_fLineSizeX[i] > 0.0f) { m_fLineSizeX[i] -= (10 * dt); m_pLine[i]->setScaleX(m_fLineSizeX[i]); } else m_pLine[i]->setVisible(false); }	//!< ���� ����Ʈ ������Ʈ ����
	//if(CCDirector::sharedDirector()->keyA[0])			setKey(E_KEYBOARD_SIX		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_SIX);		//!< ���� A
	//if(CCDirector::sharedDirector()->keyS[0])			setKey(E_KEYBOARD_ONE		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_ONE);		//!< S Ű
	//if(CCDirector::sharedDirector()->keyD[0])			setKey(E_KEYBOARD_TWO		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_TWO);		//!< D Ű
	//if(CCDirector::sharedDirector()->keyF[0])			setKey(E_KEYBOARD_THREE		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_THREE);		//!< F Ű
	//
	//if(CCDirector::sharedDirector()->keyJ[0])		setKey(E_KEYBOARD_FOUR		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_FOUR);			//!< J Ű
	//if(CCDirector::sharedDirector()->keyK[0])			setKey(E_KEYBOARD_FIVE		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_FIVE);		//!< K Ű
	//if(CCDirector::sharedDirector()->keyL[0])			setKey(E_KEYBOARD_EIGHT		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_EIGHT);		//!< L Ű
	//if(CCDirector::sharedDirector()->keySemicolon[0])			setKey(E_KEYBOARD_NINE		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_NINE);		//!< ; Ű

	if (GetKeyState(VK_LSHIFT) & 0x8000/*CCDirector::sharedDirector()->keyLshift[0]*/)		setKey(E_KEYBOARD_SIX, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_SIX);		//!< ���� ����Ʈ Ű
	if (GetKeyState('S') & 0x8000/*CCDirector::sharedDirector()->keyS[0]*/)			setKey(E_KEYBOARD_ONE		, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_ONE);		//!< S Ű
	if (GetKeyState('D') & 0x8000/*CCDirector::sharedDirector()->keyD[0]*/)			setKey(E_KEYBOARD_TWO, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_TWO);		//!< D Ű
	if (GetKeyState('F') & 0x8000/*CCDirector::sharedDirector()->keyF[0]*/)			setKey(E_KEYBOARD_THREE, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_THREE);		//!< F Ű
	if (GetKeyState(VK_SPACE) & 0x8000/*CCDirector::sharedDirector()->keySpace[0]*/)		setKey(E_KEYBOARD_FOUR, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_FOUR);		//!< �����̽� �� Ű
	if (GetKeyState('J') & 0x8000/*CCDirector::sharedDirector()->keyJ[0]*/)			setKey(E_KEYBOARD_FIVE, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_FIVE);		//!< J Ű
	if (GetKeyState('K') & 0x8000/*CCDirector::sharedDirector()->keyK[0]*/)			setKey(E_KEYBOARD_EIGHT, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_EIGHT);		//!< K Ű
	if (GetKeyState('L') & 0x8000/*CCDirector::sharedDirector()->keyL[0]*/)			setKey(E_KEYBOARD_NINE, E_KEYBOARDANI_SIZE);		else setChk(E_KEYBOARD_NINE);		//!< L Ű
	if (GetKeyState('P') & 0x8000/*CCDirector::sharedDirector()->keyP[0]*/) { if (m_fTimer >= 0.15f) { if (D_ASSET_MNG->getAttachment() < 10.0f) { D_GAME_MNG->getSongManager()->Play(D_ASSET_MNG->getEffectNum(E_EFFECT_SPEED)); D_ASSET_MNG->setAttachment(D_ASSET_MNG->getAttachment() + 1.0f); m_fTimer = 0.0f; } } }	//!< ���� - ���� Ű
	if (GetKeyState('O') & 0x8000/*CCDirector::sharedDirector()->keyO[0]*/) { if (m_fTimer >= 0.15f) { if (D_ASSET_MNG->getAttachment() > 1.0f) { D_GAME_MNG->getSongManager()->Play(D_ASSET_MNG->getEffectNum(E_EFFECT_SPEED)); D_ASSET_MNG->setAttachment(D_ASSET_MNG->getAttachment() - 1.0f); m_fTimer = 0.0f; } } }	//!< ���� - ���� Ű
}

/**
 @brief : Keyboard Ŭ������ ���� �Լ�
*/
void CKeyboard::Destroy()
{
	for(int i = 0 ; i < 7 ; i++)
		CC_SAFE_DELETE(m_pKeyboard[i]);
	for(int i = 0 ; i < 8 ; i++)
		CC_SAFE_DELETE(m_pLine[i]);
	for(int i = 0 ; i < 8 ; i++)
	{
		m_pEffect[i]->Destroy();
		CC_SAFE_DELETE(m_pEffect[i]);
	}
}

/**
 @brief : Key Down �� ���� �ϴ� �Լ�
 @eType : Ű���� ��ȣ
 @eAniType : �ִϸ��̼� Ÿ��
*/
void CKeyboard::setKey(E_KEYBOARD_TYPE eType , E_KEYBOARD_ANITYPE eAniType )
{
	int nTempValue = 0;

	//!< Ű���� ���� üũ
	switch(eType) { 
	case E_KEYBOARD_ONE:	nTempValue = 0;	break; 
	case E_KEYBOARD_TWO:	nTempValue = 1; break; 
	case E_KEYBOARD_THREE:	nTempValue = 2; break; 
	case E_KEYBOARD_FOUR:	nTempValue = 3; break; 
	case E_KEYBOARD_FIVE:	nTempValue = 4; break; 
	case E_KEYBOARD_SIX:	nTempValue = 7; break; 
	case E_KEYBOARD_EIGHT:	nTempValue = 5; break; 
	case E_KEYBOARD_NINE:	nTempValue = 6; break; }

	//!< ���� üũ ����
	if(!m_bCheckLineSound[nTempValue]) 
	{ 
		if(D_ASSET_MNG->getNowNote() < D_ASSET_MNG->getTotalNote())
		{
			for(int i = 0 ; i < D_GAME_MNG->getNoteManager()->m_pNoteTable.size() ; i++) 
			{ 
				if(D_GAME_MNG->getNoteManager()->m_pNoteTable[i]->getKeyboard() != eType) continue; 
				if(!D_GAME_MNG->getNoteManager()->m_pNoteTable[i]->getAnimation()->isVisible()) continue;
				D_GAME_MNG->getSongManager()->Play(D_GAME_MNG->getNoteManager()->m_pNoteTable[i]->getSoundNum());
				if(D_GAME_MNG->getNoteManager()->m_pNoteTable[i]->getDestTime() < 0.4f){ D_GAME_MNG->getNoteManager()->m_pNoteTable[i]->Die(ccp(0,0)); 
				if(nTempValue == 7) m_pEffect[nTempValue]->Create(ccp(72 , 232.5f)); 
				else if(nTempValue % 2 == 0) m_pEffect[nTempValue]->Create(ccp(126 + (nTempValue / 2) * 64 , 232.5f)); 
				else m_pEffect[nTempValue]->Create(ccp(158 + ((nTempValue / 2)) * 64 , 232.5f)); }
				else D_GAME_MNG->Miss();
				break; 
			}
		}
		m_bCheckLineSound[nTempValue] = true; 	
	}
	//!< �ִϸ��̼� , Ű���� üũ

	m_pLine[nTempValue]->setVisible(true); if(nTempValue != 7) m_pKeyboard[nTempValue]->setVisible(true);

	//!< �ִϸ��̼� ����
	switch(eAniType) { 
	case E_KEYBOARDANI_OPACITY: m_fLineOpacity[nTempValue] = 255.0f; m_pLine[nTempValue]->setOpacity(m_fLineOpacity[nTempValue]); break; 
	case E_KEYBOARDANI_SIZE: m_fLineSizeX[nTempValue] = 1.1f; m_pLine[nTempValue]->setScaleX(m_fLineSizeX[nTempValue]); break; }
}

/**
 @brief : Key Up �� ���� �ϴ� �Լ�
 @eType : Ű���� ��ȣ
*/
void CKeyboard::setChk(E_KEYBOARD_TYPE eType)
{
	int nTempValue = 0;

	//!< Ű���� Ÿ��
	switch(eType) {
	case E_KEYBOARD_ONE:	nTempValue = 0; break;
	case E_KEYBOARD_TWO:	nTempValue = 1; break;
	case E_KEYBOARD_THREE:	nTempValue = 2; break;
	case E_KEYBOARD_FOUR:	nTempValue = 3; break;
	case E_KEYBOARD_FIVE:	nTempValue = 4; break;
	case E_KEYBOARD_SIX:	nTempValue = 7; break; 
	case E_KEYBOARD_EIGHT:	nTempValue = 5; break; 
	case E_KEYBOARD_NINE:	nTempValue = 6; break; }

	//!< üũ ����
	m_bCheckLineSound[nTempValue] = false; if(nTempValue != 7) m_pKeyboard[nTempValue]->setVisible(false);
}