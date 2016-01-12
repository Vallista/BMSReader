#include "stdafx.h"

/**
 @brief : ������
*/
CBar::CBar()
{
	
}

/**
 @brief : �Ҹ���
*/
CBar::~CBar()
{

}

/**
 @brief : Ű �߰�
 @nChannelFirst : ä�� ù����
 @nChannelSecond : ä�� ������
 @data : �޵�����
*/
void CBar::AddKey(int nChannelFirst , int nChannelSecond , string data)
{
	CKey * ckey = new CKey(nChannelFirst , nChannelSecond , data);
	if(nChannelFirst == 0 && nChannelSecond == 2)
		m_pVecKey.insert(m_pVecKey.begin() , ckey);
	else
		m_pVecKey.push_back(ckey);
}

void CBar::CreateNote(int nChannelFirst , int nChannelSecond , string data)
{
	//!< Barnum�� �̿��Ͽ� y ���� ��ġ ����
	//!< ������ �м�
	switch(nChannelFirst)
	{
	case 0:		//!< �ǹ��� �ȳ����� ä��
		DefaultChannel(nChannelSecond , data);
		break;
	case 1:		//!< �ǹ� ä��
		KeyboardChannel(nChannelSecond , data);
		break;
	case 3:		//!< �ǹ� ä��
		//KeyboardChannel(nChannelSecond , data , true);//DefaultChannel(nChannelSecond , data);
		break;
	}
}

/**
 @brief : ����Ʈ ä�ΰ�
 @nChannelNum : ä�ΰ�
 @data : �� ������ ��
*/
void CBar::DefaultChannel(int nChannelNum , string data)
{
	switch(nChannelNum)
	{
	case E_CHANNEL_BGM:
		ChannelWave(0 , data);
		break;
	case E_CHANNEL_CANSEL:
		ChannelCancel(0 , data);
		break;
	case E_CHANNEL_BPM:
		ChannelBpm(0 , data);
		break;
	case E_CHANNEL_BGA:
		ChannelBitmap(0 , data);
		break;
	case E_CHANNEL_BM98EX:
		break;
	case E_CHANNEL_POORBGA:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		ChannelStop(0 , data);
		break;
	default:
		break;
	}
}

/**
 @brief : ���� �ܼ� ä��
 @nType : Ÿ�� ��
 @data : ������ ��
*/
void CBar::ChannelCancel(int nType , string data)
{
	BlockProcess( nType , data , E_NOTE_TYPE_CANCEL);
}

/**
 @brief : Ű���� ä��
 @nChannelNum : ù ä�� ���� ��
 @data : ������ ��
*/
void CBar::KeyboardChannel(int nChannelNum , string data , bool bVisible)
{
	BlockProcess(nChannelNum , data , E_NOTE_TYPE_KEY , bVisible);
}

/**
 @brief : ���̺� ä��
 @nType : Ÿ�� ��
 @data : ������ ��
*/
void CBar::ChannelWave(int nType , string data)
{
	BlockProcess( nType , data , E_NOTE_TYPE_WAV);
}

/**
 @brief : BPM ä��
 @nType : Ÿ�� ��
 @data : ������ ��
*/
void CBar::ChannelBpm(int nType , string data)
{
	BlockProcess( nType , data , E_NOTE_TYPE_BPM);
}

/**
 @brief : ��Ʈ�� ä��
 @nType : Ÿ�� ��
 @data : ������ ��
*/
void CBar::ChannelBitmap(int nType , string data)
{
	BlockProcess( nType , data , E_NOTE_TYPE_BITMAP);
}

/**
 @brief : ��Ʈ�� ä��
 @nType : Ÿ�� ��
 @data : ������ ��
*/
void CBar::ChannelStop(int nType , string data)
{
	BlockProcess( nType , data , E_NOTE_TYPE_STOP);
}


/**
 @brief : ��� ���μ���
 @nKeynum : Ű��
 @data : ������ ��
 @eType : Ÿ�� ��
*/
void CBar::BlockProcess(int nKeynum , string data , E_NOTE_TYPE eType , bool bVisible)
{
	int nLength = data.length();
	if(nLength % 2 != 0) nLength -= 1;

	nLength /= 2;

	if(eType == E_NOTE_TYPE_CANCEL) 
	{
		//D_GAME_MNG->AddCancelBlock(atof(data.c_str())  , m_nBarNum , (m_nBarNum * D_MAX_NOTEFIELD_HEIGHT) + 400 + D_JUDGE_POSITIONY);
		m_fBarHeight = D_MAX_NOTEFIELD_HEIGHT * atof(data.c_str());

		return;
	}
	
	for(int i = 0 ; i < nLength ; i++)
	{
		int nTemp = (int)strtol(data.substr(i * 2 , 2).c_str() , NULL , 36);
		int nHeightTotal = 0;

		if(nTemp == 0) continue;

		if(D_GAME_MNG->getBarManager()->m_pBarTable.size())
		{
			for(int j = 0 ; j < D_GAME_MNG->getBarManager()->m_pBarTable.size() - 1 ; j++)
			{
				//printf("%d\n" , (D_GAME_MNG->getBarManager()->m_pBarTable[j]->getBarheight()));
				nHeightTotal += (D_GAME_MNG->getBarManager()->m_pBarTable[j]->getBarheight());
			}
		}
		
		double y = ((i / (double)nLength)) + nHeightTotal + 400 + D_JUDGE_POSITIONY;

		if(m_fBarHeight > 0.0f)
			y = ((i / (double)nLength) * m_fBarHeight) + nHeightTotal + 400 + D_JUDGE_POSITIONY;	
			
		switch(eType)
		{
		case E_NOTE_TYPE_BPM:
			D_GAME_MNG->AddBpmBlock(data.substr(i * 2 , 2) , m_nBarNum , y);
			break;
		case E_NOTE_TYPE_BITMAP:
			D_GAME_MNG->AddBitmapBlock(data.substr(i * 2 , 2) , m_nBarNum , y);
			break;
		case E_NOTE_TYPE_WAV:
			D_GAME_MNG->AddWaveBlock(data.substr(i * 2 , 2) , m_nBarNum , y);
			break;
		case E_NOTE_TYPE_KEY:
			D_GAME_MNG->AddKeyboardBlock( nKeynum , m_nBarNum , data.substr(i * 2 , 2) , y, bVisible);
			break;
		case E_NOTE_TYPE_STOP:
			D_GAME_MNG->AddStopBlock( data.substr(i * 2 , 2) , m_nBarNum , y);
			break;
		}
	}
}                                                                                                                                                                                                                                                                                         