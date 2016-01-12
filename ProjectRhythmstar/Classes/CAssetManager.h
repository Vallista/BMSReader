#pragma once

class CAssetManager
{
private:
	//!< ���� BMS �÷��� ���� ���µ� 
	//!< Song Info
	int			m_nPlayer;				//!< �ش� BMS ������ �÷��� ����� �ǹ��Ѵ�. 
										//!< 1. Player 1 ä�� ��� (1�� �÷���)
										//!< 2. Player 1�� 2 ä�� ��� ��� (2�� �÷���)
										//!< 3. Player 1�� 2 ä�� �����Ͽ� ��� (1�� ���� �÷���)
										//!< 4. Player 1 ä�θ��� ���, Player 2ä�ο��� Player 1ä�ΰ� ���� �����Ͱ� ����ִ� ������ ���� (2�� �÷���)

	int			m_nPlayerLevel;			//!< ���̵�
	int			m_nRank;				//!< �÷��̾��� �Է��� �󸶳� ������ ������ ������ (�⺻�� 2)
										//!< 0: ���־���� 1: ����� 2: ���� 3: ����

	int			m_nTotal;				//!< ��ü ������Ʈ ���� �������� ���� ���� ���̵��� �����ϴµ� ���
	int			m_nVolWav;				//!< ���� ������ �Ҹ� ũ�⸦ �����Ѵ�. �⺻���� 100
	int			m_nDifficulty;			//!< ���̵�
	int			m_nJointValue;			//!< ���� ���� ��
	int			m_nTotalNote;			//!< ��Ż ��Ʈ ��
	int			m_nNowNote;				//!< ���� ��� ��Ʈ ��
	int			m_nHP;					//!< ü��
	int			m_nScore;				//!< ����
	int			m_nCombo;				//!< ���� �޺�
	int			m_nMaxCombo;			//!< �ִ� ���� �޺�
	int			m_nNowNode;				//!< ���� ���

	int			m_nEffect[E_EFFECT_MAX]; //!< ����Ʈ ��ȣ

	char		m_sGenre[256];			//!< �帣
	char		m_sTitle[256];			//!< �뷡 �̸�
	char		m_sArtist[256];			//!< �۰
	char		m_sMidifile[256];		//!< ��������� ����� �̵� ���� ����
	char		m_sStageFile[256];		//!< ���� �����͸� �о���� �� ������ �̹��� ����
	char		m_sVideoFile[256];		//!< BGA��ſ� ����� ������ ���� ���� , �� ����� �����Ǹ� �ٸ� BGA ���� ��� ����
	char		m_sSubArtist[256];		//!< ���� �۰
	char		m_sBanner[256];			//!< ��� ����

	float		m_fAttachment;			//!< ���
	float		m_fDistance;			//!< Bar���� ������ ��
	float		m_fDelayTime;			//!< dt ��
	float		m_fFPS;					//!< FPS ��
	float		m_fStopTime;			//!< ���� �ð�

	__ST_JUDGEMENT_TYPE	m_stJudgement;	//!< �������

	double		m_dJointMul;			//!< ���� ��
	double		m_dBpm;					//!< BPM�Ǽ� �⺻�� 130 , �߰��� BPM �� �ٲ�� ó������ BPM���� �ٲ�� �������� �����

	bool		m_bCDRotate;			//!< CD���ư��°� üũ
	bool		m_bGameOver;			//!< ���� ����
	bool		m_bDieActive;			//!< ���� ������ Ȱ��ȭ �Ұ���
	bool		m_bGameClear;			//!< ���� Ŭ����

	string		m_strPath;				//!< ���

	//!< Wav File Info
	CWaveDataList*	m_pWaveDataList;	//!< Wave ���� ������ ����Ʈ
	CNoteDataList*	m_pNoteDataList;	//!< ��Ʈ ��ũ ������ ����Ʈ
	CBmpDataList*	m_pBmpDataList;		//!< BMP ������ ����Ʈ

	int			m_nJudgementValue[E_JUDGEMENT_TYPE_MAX];

	

public:
	CAssetManager()
	{
		
	}

	~CAssetManager()
	{
		Destroy();
	} 

public:
	static CAssetManager *ins()
	{
		static CAssetManager ins;
		return &ins;
	};

	void Init();
	void Destroy();

	void Setting(char * player , char * genre , char * title , char * artist , char * bpm
		, char * playLevel , char * rank , char * volwav , char * stagefile , char * total
		, char * midifile , char * vidiofile , char * subartist , char * banner , char * difficulty);

	Auto_Set_Get_Make(string , Path , m_strPath);
	Auto_Set_Get_Make(double , JointMul , m_dJointMul);
	Auto_Set_Get_Make(int , JointValue , m_nJointValue);
	Auto_Set_Get_Make(float , Attachment , m_fAttachment);
	Auto_Set_Get_Make(int , TotalNote , m_nTotalNote);
	Auto_Set_Get_Make(double , FBPM , m_dBpm);
	Auto_Set_Get_Make(bool , CDRotate , m_bCDRotate);
	Auto_Set_Get_Make(int , HP , m_nHP);
	Auto_Set_Get_Make(int , Score , m_nScore);
	Auto_Set_Get_Make(int , MaxCombo , m_nMaxCombo);
	Auto_Set_Get_Make(int , Combo , m_nCombo);
	Auto_Set_Get_Make(int , NowNote , m_nNowNote);
	Auto_Set_Get_Make(int , NowNode , m_nNowNode);
	Auto_Set_Get_Make(float , Distance , m_fDistance);
	Auto_Set_Get_Make(__ST_JUDGEMENT_TYPE , Judge , m_stJudgement);
	Auto_Set_Get_Make(bool , Gameclear , m_bGameClear);
	Auto_Set_Get_Make(bool , Gameover , m_bGameOver);
	Auto_Set_Get_Make(bool , DieActive , m_bDieActive);
	Auto_Set_Get_Make(float , FPS , m_fFPS);
	Auto_Set_Get_Make(float , DelayTime , m_fDelayTime);
	Auto_Set_Get_Make(float , StopTime , m_fStopTime);


	//!< set
	void setJudgementValue(int i , E_JUDGEMENT_TYPE eType);
	void setEffectNum(int i , int value);
	void setPlayer(char* temp);
	void setPlayerLevel(char* temp);
	void setRank(char* temp);
	void setTotal(char* temp);
	void setVolwav(char* temp);
	void setBPM(char* temp);
	void setGenre(char* data);
	void setTitle(char* data);
	void setArtist(char* data);
	void setMidifile(char* data);
	void setStageFile(char* data);
	void setVideoFile(char* data);
	void setSubArtist(char* data);
	void setBanner(char* data);
	void setDifficulty(char* data);

	//!< get
	int getEffectNum(int i);
	int getJudgementValue(int i);
	int getPlayer();
	int getPlayerLevel();
	int getRank();
	int getVolwav();
	int getTotal();
	int getDifficulty();
	double getBPM();
	char* getGenre();
	char* getTitle();
	char* getArtist();
	char* getMidifile();
	char* getStageFile();
	char* getVideoFile();
	char* getSubArtist();
	char* getBanner();
	CWaveDataList* getWaveDataList();
	CNoteDataList* getNoteDataList();
	CBmpDataList* getBmpDataList();
};