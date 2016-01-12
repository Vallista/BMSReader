#include "stdafx.h"

/**
 @brief : ������
*/
CInput::CInput()
{
	memset(m_eKeyState , DEFAULT , sizeof(m_eKeyState));
}

/**
 @brief : �Ҹ���
*/
CInput::~CInput()
{

}

/**
 @brief : inline �Լ� Ű ������
 @vk : Ű
*/
bool CInput::KeyDown(int vk)
{
	return ((GetAsyncKeyState(vk) & 0x8000) ? true : false);
}

/**
 @brief : inline �Լ� Ű ����
 @vk : Ű
*/
bool CInput::KeyUp(int vk)
{
	return ((GetAsyncKeyState(vk) & 0x8000) ? false : true);
}

/**
 @brief : Ű ���� �������°� ������
 @vk : Ű
*/
bool CInput::GetKeyDown(int vk)
{
	if(m_eKeyState[vk] == DOWN)
		return true;

	return false;
}

/**
 @brief : Ű ���� �������°� ����
 @vk : Ű
*/
bool CInput::GetKeyUp(int vk)
{
	if(m_eKeyState[vk] == UP)
		return true;

	return false;
}

/**
 @brief : ������Ʈ �Լ�
*/
void CInput::Update()
{
	for(int i = 0 ; i < 256 ; i++)
	{
		if(m_eKeyState[i] == DOWN && KeyUp(i))
			m_eKeyState[i] = UP;
		else if(KeyDown(i))
			m_eKeyState[i] = DOWN;
		else
			m_eKeyState[i] = DEFAULT;
	}
}