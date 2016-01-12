#include "stdafx.h"

#pragma region Change Scene :: �� ��ȯ�ϴ� ���� �Դϴ�.
/**
 @brief : �� ��ȯ ����
 @sceneType : �� ��ȯ Ÿ��
 @type : Ÿ��
 @pTargetScene : Ÿ�� ��
 @fChangeTime : ��ȯ �ð�
*/
void CSurportManager::ChangeScene(E_CHANGE_SCENE sceneType , E_SCENE_TYPE type, CCScene* pTargetScene , float fChangeTime)
{
	CCScene* pScene = NULL;

	switch(sceneType)
	{
	case E_CHANGE_CROSSFADE:
		pScene = CCTransitionCrossFade::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADE:
		pScene = CCTransitionFade::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADEBL:
		pScene = CCTransitionFadeBL::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADEDOWN:
		pScene = CCTransitionFadeDown::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADETR:
		pScene = CCTransitionFadeTR::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FLIPANGULAR:
		pScene = CCTransitionFlipAngular::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FLIPX:
		pScene = CCTransitionFlipX::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FLIPY:
		pScene = CCTransitionFlipY::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_JUMPZOOM:
		pScene = CCTransitionJumpZoom::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINB:
		pScene = CCTransitionMoveInB::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINL:
		pScene = CCTransitionMoveInL::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINR:
		pScene = CCTransitionMoveInR::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINT:
		pScene = CCTransitionMoveInT::create(fChangeTime, pTargetScene);
		break;

	case E_CHANGE_PAGETURN:
		pScene = CCTransitionPageTurn::create(fChangeTime, pTargetScene , false);
		break;
	case E_CHANGE_ROTOZOOM:
		pScene = CCTransitionRotoZoom::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_SLIDEINB:
		pScene = CCTransitionSlideInR::create(fChangeTime, pTargetScene);
		break;

	case E_CHANGE_SLIDEINL:
		pScene = CCTransitionSlideInL::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_SLIDEINR:
		pScene = CCTransitionSlideInR::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_SLIDEINT:
		pScene = CCTransitionSlideInT::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_ZOOMFLIPX:
		pScene = CCTransitionZoomFlipX::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_ZOOMFLIPY:
		pScene = CCTransitionZoomFlipY::create(fChangeTime, pTargetScene);
		break;
	}

	if(type == E_REPLACE_SCENE)
		CCDirector::sharedDirector()->replaceScene(pScene);
	else
		CCDirector::sharedDirector()->pushScene(pScene);
}
#pragma endregion

#pragma region Split :: ���ڿ� Split �Դϴ�.
/**
 @brief : ���ڿ��� �߶��ִ� �Լ��Դϴ�. (���� ���� ������� �ʴ°� ����)
 @strOrigin : �ڸ� ������
 @strTok : �б��� ������
 @string : ��ȯ�� , �迭�� ��������
*/
string* CSurportManager::StringSplit(string strOrigin, string strTok)
{
	int     cutAt;                            //�ڸ�����ġ
	int     index     = 0;                    //���ڿ��ε���
	string* strResult = new string[D_MAX_ARRAY_SIZE];  //���return �Һ���

	//strTok��ã���������ݺ�
	while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos)
	{
		if (cutAt > 0)  //�ڸ�����ġ��0����ũ��(������)
		{
			strResult[index++] = strOrigin.substr(0, cutAt);  //����迭���߰�
		}
		strOrigin = strOrigin.substr(cutAt+1);  //�������ڸ��κ������ѳ�����
	}

	if(strOrigin.length() > 0)  //�����̾�����������
	{
		strResult[index++] = strOrigin.substr(0, cutAt);  //������������迭���߰�
	}

	return strResult;  //���return
}
#pragma endregion