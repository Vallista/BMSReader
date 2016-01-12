#include "stdafx.h"

#pragma region ������ / �ʱ�ȭ :: ������ �ʱ�ȭ �κ��Դϴ�.
/**
 @brief : ������
*/
CBMSParser::CBMSParser()
{

}

/**
 @brief : �Ҹ���
*/
CBMSParser::~CBMSParser()
{

}
#pragma endregion

#pragma region Init :: �ʱ�ȭ �մϴ�.
/**
 @brief : �ʱ�ȭ
 @pLayer : �ش� ���� ����
*/
void CBMSParser::Init(CCLayer* pLayer)
{
	m_pLayer				= pLayer;

	m_pFileUtill			= CCFileUtils::sharedFileUtils();

	m_nTotalCount			= 0;
	m_nTotalWav				= 0;
	m_nTotalBmp				= 0;
	m_nTotalNote			= 0;
}
#pragma endregion

#pragma region Parsing :: �����͵��� �Ľ��մϴ�.
/**
 @brief : ��ü �ҷ����� ���� �����͸� �Ľ��մϴ�.
 @strFilePath : ��ü ���ڿ�
*/
void CBMSParser::Parse(char* strFilePath)
{	
	m_strFilePath			= strFilePath;
	m_pFileData				= (char*)m_pFileUtill->getFileData(m_strFilePath , "r" , &m_BufferSize); 

	while( m_nTotalCount < m_BufferSize)
	{ 
		LoadLine(m_pFileData);

		m_nTotalCount++;
	}

	D_ASSET_MNG->Setting(m_BmsInfo.cPlayer , m_BmsInfo.cGenre , m_BmsInfo.cTitle , m_BmsInfo.cArtist
		, m_BmsInfo.cBpm , m_BmsInfo.cPlaylevel , m_BmsInfo.cRank , m_BmsInfo.cVolwav , m_BmsInfo.cStagefile
		, m_BmsInfo.cTotal , m_BmsInfo.cMidifile , m_BmsInfo.cVideofile , m_BmsInfo.cSubartist , m_BmsInfo.cBanner , m_BmsInfo.cDifficulty);

	D_ASSET_MNG->setTotalNote(m_nTotalNote);

#pragma region ����׽� �ֿܼ� ���� �� ���� ���� �޼���
#ifdef DEBUG
	CCLog("Player       : %d" , D_ASSET_MNG->getPlayer());
	CCLog("Genre        : %s" , D_ASSET_MNG->getGenre());
	CCLog("Title        : %s" , D_ASSET_MNG->getTitle());
	CCLog("Artist       : %s" , D_ASSET_MNG->getArtist());
	CCLog("BPM          : %f" , D_ASSET_MNG->getBPM());
	CCLog("Playlevel    : %d" , D_ASSET_MNG->getPlayerLevel());
	CCLog("Rank         : %d" , D_ASSET_MNG->getRank());
	CCLog("Volwav       : %d" , D_ASSET_MNG->getVolwav());
	CCLog("StageFile    : %s" , D_ASSET_MNG->getStageFile());
	CCLog("Total        : %d" , D_ASSET_MNG->getTotal());
	CCLog("Midifile     : %s" , D_ASSET_MNG->getMidifile());
	CCLog("VideoFile    : %s" , D_ASSET_MNG->getVideoFile());
	CCLog("SubArtist    : %s" , D_ASSET_MNG->getSubArtist());
	CCLog("Banner       : %s" , D_ASSET_MNG->getBanner());
	CCLog("Total Wave   : %d" , m_nTotalWav);
	CCLog("Total Bmp    : %d" , m_nTotalBmp);
	CCLog("Total Note   : %d" , m_nTotalNote);
#endif
	#pragma endregion
}
#pragma endregion

#pragma region LoadLine :: ������ �о�ɴϴ�.
/**
 @brief : ��� ���ڿ��� �ҷ����� ���� �ش� ���ڿ��� ���پ� �߶��ִ� �Լ� �Դϴ�.
 @data : ��ü ���ڿ� ������
 @info : ���پ� �о���� �޼ҵ�
*/
void CBMSParser::LoadLine(string data)
{
	int nCount = 0;
	char cTemp[D_MAX_ARRAY_SIZE];
	memset(cTemp , NULL , D_MAX_ARRAY_SIZE);

	if(data[m_nTotalCount] == '#')
	{ 
		while( data[m_nTotalCount] != '\\' && data[m_nTotalCount] != '\n')
		{
			cTemp[nCount] = data[m_nTotalCount];

			m_nTotalCount++;
			nCount ++;
		}
		
		m_sLineData = cTemp;

		m_nThisCount = nCount;
		Process(cTemp);
	}
}
#pragma endregion

#pragma region CutString :: ���ڿ��� �ڸ��� ���� �� �Դϴ�.
/**
 @brief : ���ڿ��� �����ͼ� �ڸ��ϴ�
 @data : ���ڿ� ������
 @target : ���ڿ��� �ڸ� ù��° ������
 @subTarget : �ι�° �ڸ� ������
 @string : ��ȯ��, �迭�� �������� �ڸ� �����͸� �����մϴ�.
 @info : �� �Լ��� ���� �ѹ��� �ڸ��� �� �ĺ��ʹ� target �̳� subTarget�� �����ϴ� ���ڿ� ��¥���ϴ�.
  ������ CSurportManager�� SPlit�� ����� ������ ������ ���װ� �־ ���� ��������ϴ�. ��
*/
string* CBMSParser::CutString(string data , char *target)
{
	int nCount = 0;		//!< �ǳ����� �о����� Ȯ���� ����
	bool bChk = false;	//!< �ߺ�üũ
	string * tempData = new string[2];	//!< ���� ������
	
	while (nCount <= data.length())	//!< ���ڿ� ���̸�ŭ
	{
		if(bChk == false && data[nCount] == *target) { nCount ++; bChk = true; } //!< �ߺ��Ǹ� ó��
			
		if(bChk)
			tempData[1] += data[nCount];	//!< �ߺ������� �� ���ĺ��ʹ� ������ 2��°�� �� ��
		else
			tempData[0] += data[nCount];

		nCount ++;
	}

	return tempData;
}

/**
 @brief : ���ڿ��� �����ͼ� �ڸ��ϴ�
 @data : ���ڿ� ������
 @target : ���ڿ��� �ڸ� ù��° ������
 @subTarget : �ι�° �ڸ� ������
 @string : ��ȯ��, �迭�� �������� �ڸ� �����͸� �����մϴ�.
 @info : �� �Լ��� ���� �ѹ��� �ڸ��� �� �ĺ��ʹ� target �̳� subTarget�� �����ϴ� ���ڿ� ��¥���ϴ�.
  ������ CSurportManager�� SPlit�� ����� ������ ������ ���װ� �־ ���� ��������ϴ�. ��
*/
string* CBMSParser::CutString(string data , char *target , char * subTarget)
{
	int nCount = 0;
	bool bChk[2] = {false , false};
	string * tempData = new string[3];
	
	while (nCount <= data.length())
	{
		if(bChk[0] == false && data[nCount] == *target) { nCount ++; bChk[0] = true; }
		if(bChk[0] == true && data[nCount] == *subTarget) { bChk[1] = true; }
			
		if(bChk[0] && !bChk[1])
			tempData[1] += data[nCount];
		else if(!bChk[0] && !bChk[1])
			tempData[0] += data[nCount];
		else if(bChk[0] && bChk[1])
			tempData[2] += data[nCount];

		nCount ++;
	}

	return tempData;
}
#pragma endregion

#pragma region Process :: �ٽ����� ���μ��� �κ� �Դϴ�.
/**
 @brief : �ٸ��� �����͸� �о�鿩 �� Ÿ�Կ� �´� ������ �����մϴ�.
 @name : ���� ���ڿ��� �����ɴϴ�.
 @info : �ٽ� ���μ��� �Դϴ�.
*/
void CBMSParser::Process(string name)
{
	//!< �ش��ٿ� ������ #���� Ȯ�� 
	//!< ������ # �ƴϸ� �����ٷ�
	if(name[0] != '#') return;

	//!< ���ڿ� �ڸ��ϴ�.
	string * sTempData = CutString(name , " ");

	/////////////////////////////////////////////////////////////////
	//!< �ش� �����͵� �������� �κ� �ٽ�
	if(sTempData[0] == "#PLAYER")
		sprintf(m_BmsInfo.cPlayer , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#GENRE")
		sprintf(m_BmsInfo.cGenre , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#TITLE")
		sprintf(m_BmsInfo.cTitle , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#ARTIST")
		sprintf(m_BmsInfo.cArtist , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#BPM")
		sprintf(m_BmsInfo.cBpm , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#PLAYLEVEL")
		sprintf(m_BmsInfo.cPlaylevel , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#RANK")
		sprintf(m_BmsInfo.cRank , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#VOLWAV")
		sprintf(m_BmsInfo.cVolwav , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#STAGEFILE")
		sprintf(m_BmsInfo.cStagefile , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#TOTAL")
		sprintf(m_BmsInfo.cTotal , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#MIDIFILE")
		sprintf(m_BmsInfo.cMidifile , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#VIDEOFILE")
		sprintf(m_BmsInfo.cVideofile , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#SUBARTIST")
		sprintf(m_BmsInfo.cSubartist , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#BANNER")
		sprintf(m_BmsInfo.cBanner , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#DIFFICULTY")
		sprintf(m_BmsInfo.cDifficulty , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#BACKBMP")
		sprintf(m_BmsInfo.cBackBmp , "%s" , sTempData[1].c_str());

	else //!< �̿� �������� ���� �� �߰��� ���־���Ұ� �ִ� �͵�
	{
		
#pragma region WAVFILE :: ���̺� ���� �д� ���� �Դϴ�.
		//!< ���̺� ���� ������ �н��ϴ�.
		if(sTempData[0].substr(0,4) == "#WAV")
		{
			__ST_BMSINFO_RETUNE info;

			//!< ���� �ΰ��� �ڸ��ϴ�.
			//!< ������ #WAV0U uptec - Marker #59.wav �̷��� �������� �Ǿ��ֱ� ������ 
			//!< #WAVOU // uptec - Marker #59 //.wav �̷��� �߶�����ϴ�.
			//!< �׸��� �� substr�� ���ڿ��� �߶�����ϴ�.
			//!< #WAVOU ���� OU�� �ش� wav�� ��ȣ�̱� �����Դϴ�. 

			string * sTempData = CutString(name , " " , ".");

			//!< ���̺� ���� ��ȣ
			info.nNameTarget = (int)strtol(sTempData[0].substr(4,2).c_str() , NULL , 36);
			//!< �����̸�
			sprintf(info.sDataTarget , "%s" , sTempData[1].c_str());
			//!< Ȯ����
			sprintf(info.sExtensionTarget , "%s" , sTempData[2].c_str());

			D_ASSET_MNG->getWaveDataList()->addData(info);

			m_nTotalWav++;
		}
#pragma endregion
#pragma region BMPFILE :: BMP ���� �д� ���� �Դϴ�.
		//!< �޹�濡�� ������ ������ �Դϴ�.
		else if(sTempData[0].substr(0,4) == "#BMP")
		{
			//!< ���� �ΰ��� �ڸ��ϴ�.
			//!< ������ #WAV0U uptec - Marker #59.wav �̷��� �������� �Ǿ��ֱ� ������ 
			//!< #WAVOU // uptec - Marker #59 //.wav �̷��� �߶�����ϴ�.
			//!< �׸��� �� substr�� ���ڿ��� �߶�����ϴ�.
			//!< #WAVOU ���� OU�� �ش� wav�� ��ȣ�̱� �����Դϴ�. 

			__ST_BMSINFO_RETUNE info;

			string * sTempData = CutString(name , " " , ".");

			//!< BMP ���� ��ȣ
			info.nNameTarget = (int)strtol(sTempData[0].substr(4,2).c_str() , NULL , 36);
			//!< �����̸�
			sprintf(info.sDataTarget , "%s" , sTempData[1].c_str());
			//!< Ȯ����
			sprintf(info.sExtensionTarget , "%s" , sTempData[2].c_str()); 

			D_ASSET_MNG->getBmpDataList()->m_pTable.insert(map<int , __ST_BMSINFO_RETUNE>::value_type(info.nNameTarget , info));

			//D_ASSET_MNG->getBmpDataList()->getTable()[info.nNameTarget].nNameTarget = info.nNameTarget;//->addData(info);
			//sprintf(D_ASSET_MNG->getBmpDataList()->getTable()[info.nNameTarget].sDataTarget , "%s" , info.sDataTarget);
			//sprintf(D_ASSET_MNG->getBmpDataList()->getTable()[info.nNameTarget].sExtensionTarget , "%s" , info.sExtensionTarget);

			m_nTotalBmp++;
		}
#pragma endregion
#pragma region NOTEFILE :: ��Ʈ������ �д� ���� �Դϴ�.
		//!< �׿��� �����͸� ��Ʈ ������ �Դϴ�.
		else
		{
			//!< ��Ʈ�����ʹ� #06718:0000CT0000CW008N000000000000008O �̷��� �������� �Ǿ��ֽ��ϴ�.
			//!< �ش� �������� ������ # ���ķ� �̷�� ���� # ���� 3�� , �� ���� 1���� �Ǿ��ְ�
			//!< ���� Bar ��ȣ , ä�ι�ȣ �� ���������� ä�ι�ȣ���� ù��° ���ڰ� 1�̸� �ǹ�ä��,
			//!< 0�̸� ä�� �����Դϴ�.
			__ST_BMSDATA_RETURN data;

			string * sTempData = CutString(name , ":");

			//!< ���� ��Ʈ������ �ѹ� �ɷ��־�� �մϴ�.
			//!< Bar�� ��ȣ ������
			data.nNodeNumber = GetBarNum(sTempData[0]);
			//!< ä�� �չ�ȣ �����ɴϴ�.
			data.nChannelFirstValue = GetChannelFirst(sTempData[0]);
			//!< ä�� �޹�ȣ �����ɴϴ�.
			data.nChannelSecondValue = GetChannelSecond(sTempData[0]);

			//!< ������ �����ɴϴ�.
			//!< #03101:2947294712471247 �����ϸ�
			//!< Bar ��ȣ�� 31���̰� ä�� �չ�ȣ�� 0�� , �޹�ȣ�� 1���̹Ƿ� ������� ���ϴ� ����Դϴ�.
			//!< : (�ݷ�) ������ data ���� ��� ��µǴ����� �����մϴ�.

			//!< �ش� �����͸� �ֽٰܳ��ϴ�.
			sprintf(data.sData , "%s" , sTempData[1].c_str());
			
			D_GAME_MNG->getBarManager()->AddBar(data.nNodeNumber , data.nChannelFirstValue , data.nChannelSecondValue , data.sData);

			if(data.nChannelFirstValue == 1)
				m_nTotalNote++;
		}
#pragma endregion
	}
}

#pragma endregion

#pragma region PrivateFunc :: ���� �Լ�
int CBMSParser::GetBarNum(string data)
{
	return atoi(data.substr(1,3).c_str());
}

int CBMSParser::GetChannelFirst(string data)
{
	return atoi(data.substr(4,1).c_str());
}

int CBMSParser::GetChannelSecond(string data)
{
	return atoi(data.substr(5,1).c_str());
}
#pragma endregion