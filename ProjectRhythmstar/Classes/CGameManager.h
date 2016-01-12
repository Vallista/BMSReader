#pragma once

class CGameManager
{
private:
	//!< ���ӸŴ����� Ȱ��ȭ ��ų���� �Ƚ�ų������ ���� ����
	bool					m_pActive;

	//!< ���� ���� �ð�
	float					m_fGameTime;	
	float					m_fStopTime;

	//!< ����� Ŭ����
	CCLayer*				m_pLayer;
	CBMSParser*				m_pLoadBmsData;

	CNoteManager*			m_pNoteManager;
	CBarManager*			m_pBarManager;
	CSongManager*			m_pSongManager;

	
public:
	CGameManager();			
	~CGameManager();

public:
	//!< �̱���
	static CGameManager *ins()
	{
		static CGameManager ins;
		return &ins;
	};

public:
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

	void TouchDown(CCPoint pos);
	void TouchMove(CCPoint pos);
	void TouchUp(CCPoint pos);
	
	//!< Add �޼ҵ��
	void AddCancelBlock(float fCanselTime , int nBarNum , double y);
	void AddBpmBlock(string sBpm , int nBarNum , double y);
	void AddBitmapBlock(string sBitmapnum , int nBarNum , double y);
	void AddWaveBlock(string sWavenum , int nBarNum , double y);
	void AddStopBlock(string sWavenum , int nBarNum , double y);
	void AddKeyboardBlock(int nKeyboard , int nBarNum , string sWavNum , double y , bool bVisible = false);

	//!< ���� ��ü ����
	void Miss();
	void Bad();
	void Good();
	void Great();
	void Perfect();

	//!< �Ŵ��� get
	CNoteManager* getNoteManager();
	CBarManager* getBarManager();
	CSongManager* getSongManager();
	
private:
	//!< ���� ����
	void UpdateStopNode(float dt);
	//!< init�� ��������� ���� ����
	void VectorUnlock();
	//!< String ������ ����
	string CreateFullPathData(string sName);

public:
	//!< get set
	Auto_Set_Get_Make(float , GameTime , m_fGameTime);
};
