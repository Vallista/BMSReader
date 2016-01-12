#pragma once

#include "cocos2d.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
USING_NS_CC;

////////////////////////////////////////////////////
//!< Cocos2d-x ���̺귯��
//#include "SimpleAudioEngine.h"		//!< ���� �߰� ��Ű�� ���

////////////////////////////////////////////////////
//!< �ܺ� ���̺귯��
#include "../fmod/inc/fmod.hpp"			//!< fmod ���� ���
#include "../fmod/inc/fmod_errors.h"
#pragma comment (lib, "../fmod/fmodex_vc.lib")		//!< fmod ���� ���̺귯�� �߰�
#pragma comment (lib, "../fmod/fmodex64_vc.lib")	//!< fmod ���� ���̺귯�� �߰�

using namespace FMOD;

////////////////////////////////////////////////////
//!< ������ ��� ���̺귯�� FFMPEG
// 
//#define inline __inline  
//
////#ifdef __cplusplus
//extern "C" {
////#endif
//
//#include <libavcodec/avcodec.h>
//#include <libavfilter/avfilter.h>
//#include <libavformat/avformat.h>
//#include <libavdevice/avdevice.h>
//#include <libavutil/avutil.h>
//#include <libswresample/swresample.h>
//#include <libswscale/swscale.h>
//
////#ifdef __cplusplus
//};
////#endif 
//
//#pragma comment(lib, "avcodec.lib")
//#pragma comment(lib, "avdevice.lib")
//#pragma comment(lib, "avfilter.lib")
//#pragma comment(lib, "avformat.lib")
//#pragma comment(lib, "avutil.lib")
//#pragma comment(lib, "swresample.lib")
//#pragma comment(lib, "swscale.lib")
////////////////////////////////////////////////////
//!< ����� ���� ���̺귯��
#include "cGHAnimation.h"
#include "CNumber.h"
#include "CInput.h"

////////////////////////////////////////////////////
//!< ���� �ֻ��� ��Ʈ
#include "iGameObject.h"

//!< ����� ���� ������Ʈ
#include "CBMSParser.h"			//!< BMS ���� ������ ����Ʈ Ŭ����
#include "IFormatList.h"		//!< ���� ����Ʈ
#include "CBmpDataList.h"		//!< �̹��� ������ ����Ʈ Ŭ����
#include "CWaveDataList.h"		//!< ���̺� ������ ����Ʈ Ŭ����
#include "CNoteDataList.h"		//!< ��Ʈ ������ ����Ʈ Ŭ����
#include "CKey.h"				//!< Ű ���� �޼���
#include "CBar.h"				//!< ��Ʈ ������ ���� ��
#include "CEffect.h"			//!< ����Ʈ

//!< UI
#include "iUI.h"				//!< UI interface
#include "iPopup.h"				//!< �˾� �ΰ͵�
#include "iNoPopup.h"			//!< �˾� �ƴѰ͵�

////////////////////////////////////////////////////
//!< ��Ʈ ����

#include "INoteState.h"			//!< ��Ʈ ���� �ֻ��� Ŭ����
#include "CState_Move.h"		//!< ��Ʈ�� ������ �� ����Ǵ� Ŭ����
#include "CState_Touch.h"		//!< ��Ʈ�� Touch �����϶� ����Ǵ� Ŭ����
#include "CState_Die.h"			//!< ��Ʈ�� ���� �� ����Ǵ� Ŭ����

#include "INoteObject.h"

#include "CShortNote.h"			//!< CNoteObject ���
#include "CLongNote.h"			//!< CNoteObject ���

////////////////////////////////////////////////////
//!< UI ����
#include "CVideo.h"				//!< ���� ���
#include "CJudge.h"				//!< ������
#include "CBarLine.h"			//!< ���� ���μ�
#include "CMenuItem.h"			//!< ��ü���� �޴�
#include "CKeyboard.h"			//!< Ű����
#include "CShowJudge.h"			//!< ���� �����ִ� Ŭ����
#include "CGameOver.h"			//!< ���� ����
#include "CFont.h"				//!< ��Ʈ
#include "CBackGround.h"		//!< �޹��

////////////////////////////////////////////////////
//!< ����� ���� �Ŵ���
#include "CNoteManager.h"		//!< ��Ʈ ���� �޼ҵ� ����
#include "CBarManager.h"		//!< ��Ʈ ������ �ʿ��� Bar ���� �޼ҵ� ����
#include "CAssetManager.h"		//!< �ڿ� ����
#include "CSurportManager.h"	//!< ����Ʈ ���� ���� (�� ��ȯ�̶����)
#include "CSongManager.h"		//!< ���� ����
#include "CUIManager.h"			//!< UI ����
#include "CGameManager.h"		//!< ���� ��ü ����

////////////////////////////////////////////////////
//!< ����
#include "AppDelegate.h"

////////////////////////////////////////////////////
//!< �� ���
#include "CMenu.h"
#include "CGame.h"
