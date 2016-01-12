#pragma once

class INoteState;

class CShortNote : public INoteObject
{
private:
	CCSprite*			m_pSpNote[3];

public:
	CShortNote();
	virtual ~CShortNote();

public:
	// ���� ����
	void ChangeState(E_NOTE_STATE state);
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

	void MoveTime(float dt);

	CCSprite* getAnimation();
};