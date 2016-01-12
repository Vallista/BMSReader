#include "stdafx.h"

/**
@brief : �ʱ�ȭ
@pNote : ��Ʈ ������Ʈ ��
*/
void CState_Touch::Enter(INoteObject* pNote)
{
	m_pNote = pNote;
}

/**
@brief : ���ö�
@pos : ��ġ
*/
void CState_Touch::Execute(CCPoint pos)
{
	m_pNote->setPos(pos);
	m_fMoveTime = 0;
}

/**
@brief : ������Ʈ
@dt : delay time
*/
void CState_Touch::Update(float dt)
{

}

/**
@brief : �����Ӵ� �����̴� �ð�
@dy : ��ġ
*/
void CState_Touch::MoveTime(double dy)
{
	m_fMoveTime = dy;
}