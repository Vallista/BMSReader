#pragma once

#include "cocos2d.h"
/*
	cocos2d-x �� ������ �÷��� ���� �������� �԰��� �����մϴ�.
	������ Ÿ�Ժ��� ���߾ ���ָ� �������� ���� �÷��� ������ ������ ���ϴ�.

CC_PLATFORM_UNKNOWN            0				//!< �ƹ����µ� �ƴմϴ� ^^
CC_PLATFORM_IOS                1				//!< IOS ������ �� �Դϴ�
CC_PLATFORM_ANDROID            2				//!< �ȵ���̵� ������ �� �Դϴ�.
CC_PLATFORM_WIN32              3				//!< ������ �϶� �Դϴ�.
CC_PLATFORM_MARMALADE          4				//!< �������̵� �϶� �Դϴ�
CC_PLATFORM_LINUX              5				//!< ������ �϶� �Դϴ�~
CC_PLATFORM_BADA               6				//!< �ٴ� �϶� �Դϴ�.
CC_PLATFORM_BLACKBERRY         7				//!< ������ �϶� �Դϴ�.
CC_PLATFORM_MAC                8				//!< ���϶� �Դϴ�
CC_PLATFORM_NACL               9				//!< NACL �϶� �Դϴ�
CC_PLATFORM_EMSCRIPTEN        10				//!< EMSCRIPTEN �϶� �Դϴ�
CC_PLATFORM_TIZEN             11				//!< Ÿ���� �϶� �Դϴ�.
CC_PLATFORM_WINRT             12				//!< ������ 8 �� ���� ���� (7) �϶� �Դϴ�.
CC_PLATFORM_WP8               13				//!< ������ 8 �� �϶� �Դϴ�
*/

//!< #if �� �ڿ� �÷��� ���� �ٿ��ְ� �ȿ� ���뿡�� �ҽ��ڵ带 ���ԵǸ� �÷��� ���� ����ó���� �����ϰ� �˴ϴ�.

#pragma region View :: �ػ� ���� ������ �޼��� �Դϴ�.
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) 

#define DESIGN_RESOLUTION_480X320    0
#define DESIGN_RESOLUTION_1024X768   1
#define DESIGN_RESOLUTION_2048X1536  2

/* If you want to switch design resolution, change next line */
#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_480X320

typedef struct tagResource
{
    cocos2d::CCSize size;
    char directory[100];
}Resource;

static Resource smallResource  =  { cocos2d::CCSizeMake(480, 320),   "iphone" };
static Resource mediumResource =  { cocos2d::CCSizeMake(1024, 768),  "ipad"   };
static Resource largeResource  =  { cocos2d::CCSizeMake(2048, 1536), "ipadhd" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_480X320)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480, 320);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1024X768)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1024, 768);
#elif (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_2048X1536)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(2048, 1536);
#else
#error unknown target design resolution!
#endif

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#define D_DESIGN_WIDTH 800
#define D_DESIGN_HEIGHT 480

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 

#define D_DESIGN_WIDTH 1280
#define D_DESIGN_HEIGHT 720

#endif
#pragma endregion

#pragma region Defined :: ���� ������ ���̴� �����ε� �Դϴ�.

#define D_PROJECT_NAME	"RhythmStar"

#define D_MAX_STATE		E_STATE_MAX
#define D_GAME_MNG		CGameManager::ins()
#define D_UI_MNG		CUIManager::ins()
#define D_ASSET_MNG		CAssetManager::ins()
#define D_SURPORT_MNG	CSurportManager::ins()
#define D_INPUT			CInput::ins()

#define D_MAX_ARRAY_SIZE 256								//!< �ִ� �迭 ����

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#define D_START_POS 30										//!< ��Ʈ �ѷ��ִ� ���� ���� ��ġ �Դϴ�. X ��ǥ
#define D_MAX_NOTEFIELD_HEIGHT 240							//!< ���� ����
#define D_JUDGE_POSITIONY 80								//!< ���� ó�� ��ġ

#define D_KEYBOARD_NUM 1
#define D_BPMBLOCK_NUM 13
#define D_BITMAPBLOCK_NUM 14
#define D_WAVEBLOCK_NUM 15
#define D_CANSELBLOCK_NUM 16

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 

#define D_START_POS 40										//!< ��Ʈ �ѷ��ִ� ���� ���� ��ġ �Դϴ�. X ��ǥ
#define D_MAX_NOTEFIELD_HEIGHT 150							//!< ���� ����
#define D_JUDGE_POSITIONY 233								//!< ���� ó�� ��ġ

#define D_KEYBOARD_NUM 1
#define D_BPMBLOCK_NUM 22
#define D_BITMAPBLOCK_NUM 23
#define D_WAVEBLOCK_NUM 24
#define D_CANSELBLOCK_NUM 25
#define D_STOPBLOCK_NUM 25

#endif

#define D_BACKGROUNDBAR_SHOW	1							//!< 1 = ���� , !1 = �Ⱥ���


/**
 @brief : Get Set �ڵ����� ������ִ� �Լ� (�����Լ�) 
 @ret : ������
 @fname : �̸�
 @var : set���� �������� �̸�
*/
#define Auto_Set_Get_Make_Virtual(ret, fname, var) \
	virtual ret get##fname() \
	{ \
		return var; \
	} \
	virtual void set##fname(ret tmp) \
	{ \
		var = tmp; \
	}

/**
 @brief : Get Set �ڵ����� ������ִ� �Լ� 
 @ret : ������
 @fname : �̸�
 @var : set���� �������� �̸�
*/
#define Auto_Set_Get_Make(ret, fname, var) \
	ret get##fname() \
	{ \
		return var; \
	} \
	void set##fname(ret tmp) \
	{ \
		var = tmp; \
	}

#pragma endregion


#pragma region Enum :: ������ �����Դϴ�.

/**
 @brief : ��Ʈ ��
*/
enum E_NOTE_COLOR
{
	E_NOTE_WHITE = 0,
	E_NOTE_BLUE,
	E_NOTE_RED,
	E_NOTE_COLOR_MAX,
};

/**
 @brief : ��Ʈ ���� Ÿ��
*/
enum E_NOTE_STATE
{
	E_STATE_MOVE = 0,
	E_STATE_TOUCH,
	E_STATE_DIE,
	E_STATE_MAX,

};

/**
 @brief : ä�� Ÿ��
*/
enum E_NOTE_CHANNEL
{
	E_CHANNEL_BGM = 1,		//!< ����� ä��
	E_CHANNEL_CANSEL ,		//!< ���� ���� ä��
	E_CHANNEL_BPM ,			//!< BPM ä��
	E_CHANNEL_BGA ,			//!< BGA ä��
	E_CHANNEL_BM98EX,		//!< BM 98 Ȯ�� ä��
	E_CHANNEL_POORBGA,		//!< poor BGA ä��
	E_CHANNEL_KEY,			//!< �ǹ� ä��
	E_CHANNEL_EXTENSION_BPM = 8,	//!< Ȯ�� BPM ä��
	E_CHANNEL_STOP,			//!< ������ ���� ä��
	E_CHANNEL_MAX,
};

/**
 @brief : ��Ʈ Ÿ��
*/
enum E_NOTE_TYPE
{
	E_NOTE_TYPE_BPM = 0,
	E_NOTE_TYPE_BITMAP ,
	E_NOTE_TYPE_CANCEL ,
	E_NOTE_TYPE_WAV ,
	E_NOTE_TYPE_KEY ,
	E_NOTE_TYPE_STOP ,
	E_NOTE_TYPE_MAX,
};


/**
 @brief : Ű���� Ÿ��
*/
enum E_KEYBOARD_TYPE
{
	E_KEYBOARD_ONE = 1,
	E_KEYBOARD_TWO ,
	E_KEYBOARD_THREE ,
	E_KEYBOARD_FOUR ,
	E_KEYBOARD_FIVE ,
	E_KEYBOARD_SIX ,
	E_KEYBOARD_TEMP ,
	E_KEYBOARD_EIGHT ,
	E_KEYBOARD_NINE ,
	E_KEYBOARD_MAX,

};

/**
 @brief : ���� ����
*/
enum E_JUDGELINE_COLOR
{
	E_JUDGELINE_BLUE = 0,
	E_JUDGELINE_GREEN ,
	E_JUDGELINE_RED ,
	E_JUDGELINE_YELLOW ,
	E_JUDGELINE_MAX ,
};

/**
 @brief : Ű���� �ִϸ��̼� Ÿ��
*/
enum E_KEYBOARD_ANITYPE
{
	E_KEYBOARDANI_OPACITY = 0,
	E_KEYBOARDANI_SIZE,
	E_KEYBOARDANI_MAX,
};


enum E_UI
{
	E_UI_MENUITEM = 0,
	E_UI_JUDGE,
	E_UI_VIDEO,
	E_UI_KEYBOARD,
	E_UI_SHOW,
	E_UI_GAMEOVER,
	E_UI_FONT,
	E_UI_BACKGROUND,
	E_UI_MAX,
};

enum E_JUDGEMENT_COUNT
{
	E_JUDGEMENT_MIN = 0,
	E_JUDGEMENT_MAX,
	E_JUDGEMENT_VALUE_MAX ,
};

enum E_JUDGEMENT_TYPE
{
	E_JUDGEMENT_PERFECT = 0,
	E_JUDGEMENT_GREAT ,
	E_JUDGEMENT_GOOD ,
	E_JUDGEMENT_BAD ,
	E_JUDGEMENT_MISS,
	E_JUDGEMENT_TYPE_MAX,
};



enum E_EFFECT_SOUND
{
	E_EFFECT_CLEAR = 0,
	E_EFFECT_FAIL,
	E_EFFECT_SPEED,
	E_EFFECT_MAX,
};

#pragma endregion

#pragma region Struct :: ����ü �����Դϴ�.

struct __POINT
{
	double x;
	double y;
};



/**
 @brief : ����ü �ȿ��� wav �� �������� �������� �̹��� �����̳� �������ϵ��� ���� ������ ������ �ֵ��� �����մϴ�.
*/
struct __ST_BMSINFO_RETUNE
{
	__ST_BMSINFO_RETUNE()
	{
		nNameTarget = 0;
		memset(sDataTarget , NULL , 256);
		memset(sExtensionTarget , NULL , 256);
	}
	
	__ST_BMSINFO_RETUNE(char * name , char * data , char * sExtension) 
	{
		
		memset(sDataTarget , NULL , 256);
		memset(sExtensionTarget , NULL , 256);

		nNameTarget = atoi(name);
		//sprintf(sNameTarget , "%s" , name);
		sprintf(sDataTarget , "%s" , data);
		sprintf(sExtensionTarget , "%s" , sExtension);
	}

	int nNameTarget;
	char sDataTarget[256];
	char sExtensionTarget[256];
};

/**
 @brief : ����ü �ȿ��� ��Ʈ �����͸� ���� �� �ֵ��� �������� ������ �����մϴ�.
*/
struct __ST_BMSDATA_RETURN
{
	__ST_BMSDATA_RETURN()
	{
		nNodeNumber = 0;
		memset(sData , NULL , 256);
	}

	__ST_BMSDATA_RETURN(char * node , char * channelFirstValue , char * channelSecondValue , char * data) 
	{
		nNodeNumber = atoi(node);
		nChannelFirstValue = atoi(channelFirstValue);
		nChannelSecondValue = atoi(channelSecondValue); 
		
		memset(sData , NULL , 256);
		sprintf(sData , "%s" , data);

		nData = strlen(sData) / 2;
	}

	int nNodeNumber;					//!< Bar ��ȣ (int ������ ������ �����)

	int nChannelFirstValue;				//!< ä�� ��ȣ ù��° 0���̸� ä�� �޹�ȣ�� �̿��� �ǹ� ä�η������� ó��
										//!< 1�̸� ä�� �޹�ȣ�� �̿��� �ǹ� ä�� ����

	int nChannelSecondValue;		//!< ä�� ��ȣ �ι�° 
										//!< 1 : ����� (wave ä��) 2 : ���� ���� 3 : BPM ä�� 4 : BGA ä�� 5: BM95 Ȯ�� ä��
										//!< 6 : poor bga ä�� 7 : 8 : 9 : 

	char sData[256];					//!< �� ������
	int	nData;							//!< �� ������ ���� ����
};

/**
 @brief : �뷡�� ������ �� �޽��ϴ�.
*/
struct __ST_BMSSong_Info
{
	__ST_BMSSong_Info()
	{
		memset(cPlayer , NULL , 256);
		memset(cBpm , NULL , 256);
		memset(cPlaylevel , NULL , 256);
		memset(cRank , NULL , 256);
		memset(cGenre , NULL , 256);
		memset(cTitle , NULL , 256);
		memset(cArtist , NULL , 256);
		memset(cVolwav , NULL , 256);
		memset(cStagefile , NULL , 256);
		memset(cTotal , NULL , 256);
		memset(cMidifile , NULL , 256);
		memset(cVideofile , NULL , 256);	
		memset(cSubartist , NULL , 256);
		memset(cBanner , NULL , 256);
		memset(cDifficulty , NULL , 256);
		memset(cBackBmp , NULL , 256);
	}

	char cPlayer[256];
	char cBpm[256];
	char cPlaylevel[256];
	char cRank[256];
	char cGenre[256];
	char cTitle[256];
	char cArtist[256];
	char cVolwav[256];
	char cStagefile[256];
	char cTotal[256];
	char cMidifile[256];
	char cVideofile[256];
	char cSubartist[256];
	char cBanner[256];
	char cDifficulty[256];
	char cBackBmp[256];
};

struct __ST_LINE_DATA
{
	__ST_LINE_DATA()
	{
		nLineData = 0;
	}

	int nLineData;
};

struct __ST_JUDGEMENT_TYPE
{
	float fPerfect[E_JUDGEMENT_VALUE_MAX];
	float fGreat[E_JUDGEMENT_VALUE_MAX];
	float fGood[E_JUDGEMENT_VALUE_MAX];
	float fBad[E_JUDGEMENT_VALUE_MAX];
	float fMiss[E_JUDGEMENT_VALUE_MAX];
};



#pragma endregion
