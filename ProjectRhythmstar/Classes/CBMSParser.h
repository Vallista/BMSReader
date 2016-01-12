#pragma once


class CBMSParser
{
private:
	CCLayer*		m_pLayer;

	// ���� ��ƿ ����
	CCFileUtils*	m_pFileUtill;			//!< cocos2dx ���� �����
	unsigned long	m_BufferSize;			//!< ���� ������
	string			m_pFileData;			//!< ���� Data
	char*			m_strFilePath;			//!< ���� ���

	//!< ���� ������
	string			m_sLineData;			//!< ���� ������ ���� ����

	int				m_nTotalCount;			//!< ���� ����� ���� ����

	__ST_BMSSong_Info		m_BmsInfo;		//!< ����� ���� 

	//!< �� ����
	int				m_nTotalWav;			//!< ���̺� ���� ����
	int				m_nTotalBmp;			//!< BMP ���� ����
	int				m_nTotalNote;			//!< �� ��Ʈ ����

	int				m_nThisCount;			//!< ���� ����

public:
	CBMSParser();
	~CBMSParser();

public:
	//!< �⺻���� ��Ʈ
	//!< Init �ʱ�ȭ -> Parse ��� -> Process ����
	void Init(CCLayer* pLayer);
	void Parse(char* strFilePath);					//!< ���Ͼ� ��ü �ؽ�Ʈ �ε� �� ��ü���� ������ ����

	void LoadLine(string data);								//!< ���� ������ ����

	void Process(string name);						//!< ���� ������ ��

	//!< ���ڿ� split
	string* CutString(string data , char * target);
	string* CutString(string data , char * target , char * subTarget);

private:
	int GetBarNum(string data);
	int GetChannelFirst(string data);
	int GetChannelSecond(string data);
};