#include "stdafx.h"

/**
@brief : �ʱ�ȭ
@pNote : ��Ʈ ������Ʈ
*/
void CState_Move::Enter(INoteObject* pNote)
{
	m_pNote = pNote;
}

/**
@brief : ���ö�
@pos : ��ġ��
*/
void CState_Move::Execute(CCPoint pos)
{
	m_pNote->setPos(pos);
	m_dMoveTime = 0.0;
}

/**
@brief : ������Ʈ
@dt : delay time
*/
void CState_Move::Update(float dt)
{
	//!< �浹��ġ - 10���� ���̰� ó��
	if(m_pNote->getPos().y > D_JUDGE_POSITIONY - 10 && m_pNote->getPos().y < D_DESIGN_HEIGHT) {
	//!< ��׶��� ���� ��Ʈ�� �����ٰ��� ������ Define���� ó��
#if (D_BACKGROUNDBAR_SHOW == FALSE) 
		if(m_pNote->getPrivateNum() == D_KEYBOARD_NUM) m_pNote->getAnimation()->setVisible(true);
#else 
		m_pNote->getAnimation()->setVisible(true);  
#endif 
	}
	else{
		m_pNote->getAnimation()->setVisible(false); 
	}

	//!< ��Ʈ Ÿ���� 10���� ������ (9���� Ű���� ��Ʈ ��)
	if(m_pNote->getPrivateNum() < 10) 
	{ 
		if(m_pNote->getPos().y  > D_JUDGE_POSITIONY - 40) 
		{ 
			double dTemp = m_pNote->getPos().y; 
			dTemp -= m_dMoveTime; 
			m_pNote->setPos(ccp(m_pNote->getPos().x , dTemp)); 
			m_pNote->getAnimation()->setPosition(ccp(m_pNote->getPos().x, (dTemp - D_JUDGE_POSITIONY) * D_ASSET_MNG->getAttachment() + D_JUDGE_POSITIONY )); 
		} 
		else 
		{
			m_pNote->setMissCheck(true);
			D_ASSET_MNG->setCombo(0);
			m_pNote->Die(m_pNote->getPos()); 
		}
	}
	else 
	{ 
		if(m_pNote->getPos().y  > D_JUDGE_POSITIONY) 
		{ 
			double dTemp = m_pNote->getPos().y; 
			dTemp -= m_dMoveTime; 
			m_pNote->setPos(ccp(m_pNote->getPos().x , dTemp)); 
			m_pNote->getAnimation()->setPosition(ccp(m_pNote->getPos().x , dTemp)); 
		} 
		else 
		{
			m_pNote->setDestTime(2.0f);
			m_pNote->Die(m_pNote->getPos()); 
		}
	}
}

/**
@brief : �����Ӵ� �����̴� ��ġ
@dy : �����̴� ��ġ
*/
void CState_Move::MoveTime(double dy)
{
	m_dMoveTime = dy;
}
