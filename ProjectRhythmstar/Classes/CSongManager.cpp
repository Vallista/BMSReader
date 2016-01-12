#include "stdafx.h"

/**
 @brief : ������
*/
CSongManager::CSongManager()
{

}

/**
 @brief : �Ҹ���
*/
CSongManager::~CSongManager()
{
	Destroy();
}

/**
 @brief : ���� üũ
 @result : ����� ����
*/
void CSongManager::ErrorChk(FMOD_RESULT result)
{
	if(result != FMOD_OK) { CCLog("FMOD ERROR! %s" , FMOD_ErrorString(result)); }
}

/**
 @brief : �ʱ�ȭ
*/
void CSongManager::Init()
{
	m_nResult = FMOD_System_Create(&m_pSystem); // System_Create(&m_pSystem);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif
	m_nResult = FMOD_System_SetHardwareChannels(m_pSystem , 3000); // m_pSystem->setHardwareChannels(3000);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif
	m_nResult = FMOD_System_SetSoftwareChannels(m_pSystem , 3000); // m_pSystem->setSoftwareChannels(3000);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif
	m_nResult = FMOD_System_Init(m_pSystem , 320 , FMOD_INIT_NORMAL , NULL); // m_pSystem->init(320, FMOD_INIT_NORMAL, 0);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif

	m_nCount = 0;
}

/**
 @breif : ������Ʈ
 @dt : delay time
*/
void CSongManager::Update(float dt)
{
	FMOD_System_Update(m_pSystem);
}

/**
 @brief : ����
*/
void CSongManager::Destroy()
{
	FMOD_System_Close(m_pSystem);
	FMOD_System_Release(m_pSystem);
}

/**
 @brief : ���� ����
 @sData : ���
 @return : m_nCount - 1
*/
int CSongManager::CreateSound(string sData)
{
	//CCLog("%s" , sData.c_str());

	m_nResult = FMOD_System_CreateSound(m_pSystem , sData.c_str() , FMOD_DEFAULT , false , &m_pVecSound[m_nCount]);

#ifdef DEBUG
	ErrorChk(m_nResult);
#endif
	m_nResult = FMOD_Sound_SetMode(m_pVecSound[m_nCount] , FMOD_DEFAULT); // m_pVecSound[m_nCount]->setMode(FMOD_DEFAULT);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif
	m_nResult = FMOD_Channel_SetVolume(m_pVecChannel[m_nCount] , 1.0f); // m_pVecChannel[m_nCount]->setVolume(1.0f);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif

	m_nCount++;

	return m_nCount - 1;
}

/**
 @brief : ���� ���
 @value : ���� id ��
*/
void CSongManager::Play(int value)
{
	m_nResult = FMOD_System_PlaySound(m_pSystem , FMOD_CHANNEL_FREE , m_pVecSound[value] , false , &m_pVecChannel[value]);  // m_pSystem->playSound(FMOD_CHANNEL_FREE , m_pVecSound[value] , 0 , &m_pVecChannel[value]);
#ifdef DEBUG
	ErrorChk(m_nResult);
#endif
}

/**
 @brief : ���� ��� ����
*/
void CSongManager::AllStop()
{
	for(int i = 0 ; i < m_pVecChannel.size() ; i++)
	{
		if(i != D_ASSET_MNG->getEffectNum(E_EFFECT_FAIL)
			&& i != D_ASSET_MNG->getEffectNum(E_EFFECT_CLEAR))
			FMOD_Channel_Stop(m_pVecChannel[i]);
	}
}