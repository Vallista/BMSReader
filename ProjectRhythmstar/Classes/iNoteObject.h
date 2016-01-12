#pragma once

USING_NS_CC;

class INoteState;

class INoteObject : public iGameObject
{
protected:
	CCLayer*				m_pLayer;

	//!< ���� ���� ����
	INoteState*				m_pState;					//!< ���� Ÿ���� �� ����
	INoteState*				m_pState_Pool[D_MAX_STATE];	//!< ������ ��������Դϴ�.

	//!< Note ���� ���� ����
	bool					m_bActive;					//!< false �� ��ü ������Ʈ false
	bool					m_bSong;					//!< üũ �ߴ���
	bool					m_bMiss;					//!< �̽� üũ
	bool					m_bVisibleNote;				//!< ��Ʈ�� �Ⱥ��̴� ��Ʈ���� üũ

	int						m_nIndex;					//!< ���� ��
	int						m_nKeyboard;				//!< Ű���� ��
	int						m_nPrivateNumber;			//!< ���̵� ��
	int						m_nBarNum;					//!< �� ��
	int						m_nNotePos;					//!< ��Ʈ ��
	int						m_nSoundNum;				//!< �� ���̵� ��

	float					m_fBpm;						//!< ��Ʈ�� BPM ����
	float					m_fCanselTime;				//!< ���� ���� �ð� ����
	float					m_fDestTime;				//!< ������ ���� �������� �ð�

	double					m_dBarperSecond;			//!< BPM �ӵ��� ���� �� ����� �������� �ð�
	double					m_dBarDownTime;				//!< �����Ӵ� ��Ʈ�� �������� �ð�

	CCPoint					m_cPos;						//!< ��ġ
	E_NOTE_COLOR			m_eColor;					//!< ��

	string					m_strTextureName;			//!< �ؽ��� �̸�

public:
	INoteObject();
	virtual ~INoteObject();

public:
	//!< ���� ����
	virtual void ChangeState(E_NOTE_STATE state) = 0;
	virtual void ChangeState(INoteState *) = 0;

	//!< �̺�Ʈ
	virtual void Move(CCPoint pos) = 0;
	virtual void Touch(CCPoint pos) = 0;
	virtual void Die(CCPoint pos) = 0;

	//!< ���� ������Ʈ �� ���
	virtual void Init(CCLayer* pLayer , int nNotePos , double dY , bool bVisible = false) = 0;
	virtual void Create() = 0;
	virtual void Update(float dt) = 0;
	virtual void Destroy() = 0;
	
	virtual void MoveTime(float dt) = 0;

	virtual CCSprite* getAnimation() = 0;

	//!< Set Get �Լ���
	Auto_Set_Get_Make_Virtual(bool , Active , m_bActive);
	Auto_Set_Get_Make_Virtual(int , Index , m_nIndex);
	Auto_Set_Get_Make_Virtual(int , Keyboard , m_nKeyboard);
	Auto_Set_Get_Make_Virtual(int , PrivateNum , m_nPrivateNumber);
	Auto_Set_Get_Make_Virtual(int , BarNum , m_nBarNum);
	Auto_Set_Get_Make_Virtual(int , SoundNum , m_nSoundNum);
	Auto_Set_Get_Make_Virtual(float , Bpm , m_fBpm);
	Auto_Set_Get_Make_Virtual(float , CanselTime , m_fCanselTime);
	Auto_Set_Get_Make_Virtual(CCPoint , Pos , m_cPos);
	Auto_Set_Get_Make_Virtual(E_NOTE_COLOR , Color , m_eColor);
	Auto_Set_Get_Make_Virtual(bool , SongCheck , m_bSong);
	Auto_Set_Get_Make_Virtual(float , DestTime , m_fDestTime);
	Auto_Set_Get_Make_Virtual(bool , MissCheck , m_bMiss);
	Auto_Set_Get_Make_Virtual(bool , VisibleNote , m_bVisibleNote);
	Auto_Set_Get_Make_Virtual(string , TextureName , m_strTextureName);
};