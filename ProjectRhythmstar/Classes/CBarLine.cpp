#include "stdafx.h"

/**
 @brief : ������
*/
CBarLine::CBarLine()
{

}

/**
 @brief : �Ҹ���
*/
CBarLine::~CBarLine()
{
	Destroy();
}

/**
 @brief : ���� �Լ�
 @fY : Y��ǥ ��ġ
*/
void CBarLine::Create(float fY)
{
	m_bActive		= true;
	m_cPos			= ccp(D_START_POS , fY);
	m_pSprite->setPosition(ccp(m_cPos.x , m_cPos.y * D_ASSET_MNG->getAttachment()));
}


void CBarLine::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}
 
/**
 @brief : �ʱ�ȭ �Լ�
 @pLayer : ���� ���̾�
*/
void CBarLine::Init(CCLayer * pLayer)
{
	m_bActive		= false;
	m_pLayer		= pLayer;

	m_pSprite = CCSprite::create("Images/Game/Line/white.png");
	m_pSprite->setAnchorPoint(ccp(0.0f , 0.5f));
	m_pSprite->setVisible(false);
	m_pSprite->setScaleX(298.0f);
	m_pSprite->setOpacity(129);
	m_pLayer->addChild(m_pSprite , 10);
}

/**
 @brief : ������Ʈ �Լ�
*/
void CBarLine::Update(float dt)
{
	//!< ���� On �ȵ������� return
	if(!m_bActive) return;
	if(D_ASSET_MNG->getGameover()) return;

	//!< �浹ó�� ���α��� ���� ����������
	if(m_pSprite->getPositionY() < D_JUDGE_POSITIONY) { D_ASSET_MNG->setNowNode(D_ASSET_MNG->getNowNode()+1); m_bActive = false; m_pSprite->setVisible(false); return; }

	//!< ���� , �ʴ� ���� , BPM �����ؼ� �̵��ӵ� ����
	double dBarperSecond = ((4 * 60) / D_ASSET_MNG->getBPM());
	double dBarDownTime = D_MAX_NOTEFIELD_HEIGHT * (dt / dBarperSecond);

	//!< ���� ��ǥ �ӽ� �����
	float fTemp = m_cPos.y;

	//!< �̵�
	fTemp -= dBarDownTime;
	
	//!< ��ǥ ����
	m_cPos.y = fTemp;

	//!< ��ǥ ����
	m_pSprite->setPositionY((m_cPos.y - D_JUDGE_POSITIONY) * D_ASSET_MNG->getAttachment() + D_JUDGE_POSITIONY);

	//!< �̹��� ��ġ�� ȭ�� ���̸�
	if(m_pSprite->isVisible() || m_pSprite->getPosition().y > D_DESIGN_HEIGHT) return;
	
	//!< fade ó��
	m_pSprite->setVisible(true);
}

void CBarLine::Destroy()
{
	CC_SAFE_DELETE(m_pSprite);
}