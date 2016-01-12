#include "stdafx.h"

/**
 @brief : ������
*/
CNumber::CNumber()
{

}

/**
 @brief : �Ҹ���
*/
CNumber::~CNumber()
{
	Destroy();
}

/**
 @brief : �ʱ�ȭ
 @pLayer : ���� ����
*/
void CNumber::Init(CCLayer* pLayer)
{
	m_pLayer		= pLayer;

	m_bVisible		= true;
	m_nScore		= 0;
	m_nLayer		= 0;

	m_cPos			= ccp(0,0);
	m_cSize			= ccp(1,1);
}

/**
 @brief : ���� �Լ�
*/
void CNumber::Destroy()
{
	vector<CCSprite*>::iterator itr;
	if(m_pVectable.size())
	{
		for(itr = m_pVectable.begin(); itr != m_pVectable.end() ;)
		{
			m_pLayer->removeChild((*itr) , true);
			itr = m_pVectable.erase(itr);
		}
	}

	m_pVectable.clear();
}

/**
 @brief : ������Ʈ �Լ�
 @strPath : ���
 @strExtension : Ȯ����
 @nScore : ����
 @nLayer : z ���̾� ��
 @fBetweenX : x ���� ��
 @cPos : ��ġ
 @dt : delay time
 @type : default = 0  (0�̸� �߾� ���� , 1�̸� ������ ���� , 2�� ���� ����)
*/
void CNumber::UpdateNumber(string strPath , string strExtension , int nScore , int nLayer , float fBetweenX , CCPoint cPos , float dt , int type)
{
	string strTemp;
	string strNameTemp;
	int nCount = 0;
	int nCountNumber = 0;

	m_nScore = nScore;
	nCountNumber = m_nScore;
	m_cPos = cPos;
	m_nLayer = nLayer;

	vector<CCSprite*>::iterator itr;
	if(m_pVectable.size())
	{
		for(itr = m_pVectable.begin(); itr != m_pVectable.end() ;)
		{
			m_pLayer->removeChild((*itr) , true);
			itr = m_pVectable.erase(itr);
		}
	}

	m_pVectable.clear();

	do
	{
		strTemp = strPath;
		int nTemp = (int)nCountNumber%10;
		if(nTemp < 0) nTemp = 0;
		strTemp += itoa( nTemp , (char*)strNameTemp.c_str() , 10);
		strTemp += ".";
		strTemp += strExtension;

		CCSprite * pTempSprite = CCSprite::create(strTemp.c_str());
		if(type == 0)
			pTempSprite->setPosition( ccp( (m_cPos.x - (fBetweenX * m_cSize.width) * nCount) , m_cPos.y ) );
		else if(type == 1)
			pTempSprite->setPosition( ccp( (m_cPos.x + (fBetweenX * m_cSize.width) * nCount) , m_cPos.y ) );
		else if(type == 2)
			pTempSprite->setPosition( ccp( (m_cPos.x - (fBetweenX * m_cSize.width) * nCount) , m_cPos.y ) );
		pTempSprite->setScaleX(m_cSize.width);
		pTempSprite->setScaleY(m_cSize.height);
		pTempSprite->setVisible(m_bVisible);
		m_pLayer->addChild(pTempSprite , m_nLayer);
		m_pVectable.push_back(pTempSprite);
		nCount++;

	}while((nCountNumber /= 10) > 0);

	nCount-=1;

	if(nCount >= 1)
	{
		for(itr = m_pVectable.begin(); itr != m_pVectable.end(); itr++)
		{ if(type == 0) (*itr)->setPositionX( (*itr)->getPositionX() + (((30*m_cSize.width) * (nCount))/2)); }
	}
}

/**
 @brief : ��ǥ ����
 @pos = ��ġ
*/
void CNumber::setPos(CCPoint pos)
{
	m_cPos = pos;
}

/**
 @brief : ũ�� ����
 @pos = ũ��
*/
void CNumber::setSize(CCSize pos)
{
	m_cSize = pos;
}

/**
 @brief : �����ִ��� üũ
 @bChk : ����
*/
void CNumber::setVisible(bool bChk)
{
	m_bVisible = bChk;
}

/**
 @brief : ��ǥ ������
*/
CCPoint CNumber::getPos()
{
	return m_cPos;
}

/**
 @brief : ������ ������
*/
CCSize CNumber::getSize()
{
	return m_cSize;
}

/**
 @brief : �����ִ��� ������
*/
bool CNumber::getVisible()
{
	return m_bVisible;
}