#pragma once

class INoteState;

class CLongNote : public INoteObject
{

public:
	CLongNote();
	virtual ~CLongNote();

public:
	void ChangeState(E_NOTE_STATE state);
	// ���� ����
	void ChangeState(INoteState *);
	
	// �̺�Ʈ
	void Move(CCPoint pos);
	void Touch(CCPoint pos);
	void Die(CCPoint pos);

	// ���� ������Ʈ
	void Init(CCLayer* pLayer , int nNotePos , double dY , bool bVisible = false);
	void Create();
	void Update(float dt);
	void Destroy();
	
};