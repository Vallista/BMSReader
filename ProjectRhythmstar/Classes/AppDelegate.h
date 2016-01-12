#pragma once

#include "stdafx.h"

/**
@brief    AppDelegate�� Header �κ� �Դϴ�.

���⼭ CCDirector�� �ҷ��ɴϴ�.
*/
class  AppDelegate : private cocos2d::CCApplication
{
public:
	//!< ������
    AppDelegate();
	//!< �Ҹ���
    virtual ~AppDelegate();

    /**
    @brief    CCDirector �� CCScene�� �ҽ��� �� �ȿ� �ֽ��ϴ�.
    @return true    true�� ��ȯ�Ǹ� ���������� Initialize�� �� �� �Դϴ�.
    @return false   false�� ��ȯ�Ǹ� ���������� ���ϰ� Initialize�� �Ѱ� �Դϴ�.
    */
    virtual bool applicationDidFinishLaunching();

    /**
	������ cpp�� �ֽ��ϴ�.
    */
    virtual void applicationDidEnterBackground();

    /**
	������ cpp�� �ֽ��ϴ�.
    */
    virtual void applicationWillEnterForeground();
};
