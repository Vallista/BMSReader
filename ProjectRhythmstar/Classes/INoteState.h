#pragma once

/**
@brief :: ��Ʈ ���� �ֻ��� �Լ�
��Ʈ�� ���� �ֻ����� ��Ÿ���� �Լ��Դϴ�.
���¿� ���� Ŭ������ �������ִ� �Լ��Դϴ�.
*/

class INoteObject;

class INoteState
{
private:
	const E_NOTE_STATE m_eState;

public:
	INoteState(E_NOTE_STATE state) : m_eState( state )
	{}

	E_NOTE_STATE GetState()
	{
		return m_eState;
	}

public:
	virtual void Enter(INoteObject* pNote) = 0;
	virtual void Update(float dt) = 0;
	virtual void Execute(CCPoint pos) = 0;
	virtual void MoveTime(double dy) = 0;
};
