#include "stdafx.h"

/**
 @brief : ������
*/
CBarManager::CBarManager()
{
	m_nBarCursor = 0;
}

/**
 @brief : �Ҹ���
*/
CBarManager::~CBarManager()
{

}

/**
 @brief : �ʱ�ȭ
*/
void CBarManager::Init()
{
}

/**
 @brief : �� �߰�
*/
void CBarManager::AddBar(int nBarNum , int nChannelFirst , int nChannelSecond , string data)
{
	//!< ���� �ٹ�ȣ�� �����Ѱ� �ִٸ� �����Ѱ� �� �ϳ��� �߰�
	for(int i = 0 ; i < m_pBarTable.size() ; i++)
	{
		if(m_pBarTable[i]->getBarnum() == nBarNum)
		{
			m_pBarTable[i]->AddKey(nChannelFirst , nChannelSecond , data);
			return;
		}
	}

	if(m_nBarCursor != nBarNum)
	{
		for(int i = 0 ; i < m_pBarTable[m_nBarCursor]->m_pVecKey.size(); i++)
		{
			m_pBarTable[m_nBarCursor]->CreateNote(m_pBarTable[m_nBarCursor]->m_pVecKey[i]->getChannelfirst(),
				m_pBarTable[m_nBarCursor]->m_pVecKey[i]->getChannelsecond(),
				m_pBarTable[m_nBarCursor]->m_pVecKey[i]->getData());
		}
	}
	
	//!< ���� �� ��ȣ �߰��߰� ��ȣ�� ������ �� ��ȣ �Ųٴ� �۾�
	if(m_pBarTable.size())
	{
		int nTemp = (nBarNum - m_pBarTable[m_pBarTable.size() - 1]->getBarnum()) - 1;

		for(int i = 0 ; i < nTemp ; i++)
		{
			CBar * bar = new CBar();
			bar->setBarnum((nBarNum - nTemp) + i);
			bar->setBarheight(D_MAX_NOTEFIELD_HEIGHT);
			m_pBarTable.push_back(bar);
		}
	}

	CBar * bar = new CBar();
	bar->setBarnum(nBarNum);
	bar->setBarheight(D_MAX_NOTEFIELD_HEIGHT);
	bar->AddKey(nChannelFirst , nChannelSecond , data);
	m_pBarTable.push_back(bar);
	m_nBarCursor = nBarNum;
}

void CBarManager::Destroy()
{
	for(int i=0;i<m_pBarTable.size();i++)
	{
		CBar* temp = m_pBarTable[i];

		delete m_pBarTable[i];
	}
}