#include "stdafx.h"

/**
@brief : ������
*/
CNoteManager::CNoteManager()
{

}

/**
@brief : �Ҹ���
*/
CNoteManager::~CNoteManager()
{
	//Destroy();
}

/**
@brief : �ʱ�ȭ
@pLayer : ���� ����
*/
void CNoteManager::Init(CCLayer* pLayer)
{
	m_bActive = true;
	m_nCreateCount = 0;
}

/**
@brief : ������Ʈ
@dt : delay time
*/
void CNoteManager::Update(float dt)
{
	if(!m_bActive) return;

	//LoadNextNoteDatas(D_GAME_MNG->getNextNode());

	for(int i = 0 ; i < m_pNoteTable.size() ; i++)
	{
		if(!m_pNoteTable[i]->getActive()) return;
		m_pNoteTable[i]->Update(dt);
		m_pNoteTable[i]->MoveTime(dt);
	}
}

/**
@brief : ���� �Լ�
*/
void CNoteManager::Destroy()
{
	for(int i=0;i<m_pNoteTable.size();i++)
	{
		delete m_pNoteTable[i];
	}
}