#include "stdafx.h"

//!< using namespace cocos2d �� �����Դϴ�.
//!< �ش� ���� Ÿ�� ���� Define (��ó����) �� �Ǿ� �ֽ��ϴ�.
USING_NS_CC;

//!< AppDelegate �� ������ �Դϴ�
//!< ���⿡ simpleaudiosound �� ���� �ʱ�ȭ �� NULL ���� ���ִ� ������ �־� �־�� �մϴ�.
AppDelegate::AppDelegate() {
	//h ���Ͽ� ������ ���ݴϴ�.
	// CocosDenshion::SimpleAudioEngine * mSound;
	// mSound = CocosDenshion::SimpleAudioEngine::sharedEngine(); ���Կ����ڷ� �ʱ�ȭ ���ݴϴ�.
	// mSound->preloadBackgroundMusic("BGMName.mp3"); ��׶��� ���� ���ſ� �͵��� ���� ó���� �����ν� �Ų����� ����� �ǵ��� �մϴ�.
}

//!< AppDelegate �� �Ҹ��� �Դϴ�.
//!< ���⿡ simpleaudiosound �� �ʱ�ȭ �ϰ� �������ִ� ������ �־� �־�� �մϴ�.
AppDelegate::~AppDelegate() {
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("SoundName.mp3"); !< �ش� �������� ����Ʈ ���忡 �Ҵ��� �޸𸮸� �����մϴ�.
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusci(true); !< �ش� �������� ��׶��� ���忡 �Ҵ��� �޸𸮸� �����մϴ�.
}

//!< ���ø����̼��� ��ó�� ������Ű�� Init �̶� ���ø� �˴ϴ� ^^
bool AppDelegate::applicationDidFinishLaunching() {
    
#pragma region �ػ� ���� �ҽ�
	//!< CCDirector �� �Ѱ��ϴ� ���� �Դϴ�.
	//!< ������ �̱������� ¥�� ������, �� ��ü�� ���̽��� ����մϴ�.
	//!< ��Ȳ�� ���� CCDirector �� ���� Scene�� ������ ���� �� �� �ֽ��ϴ�.
    CCDirector* pDirector = CCDirector::sharedDirector();

	//!< CCEGView �� �����츦 �׷��ִ� ������ �մϴ�.
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	
/*
	sharedOpenGLView�� ����Ҷ� �� ������ ���ڷ� ���� �͵� �Դϴ� ^^

	//!< ���� ���� ������ �������� �ʰ� ���� �������� ǥ�õ˴ϴ� ^^
    kResolutionExactFit,
	
    //!< ���� ���� ������ �����ϰ� �������̳� ���ʿ� ����� ���� ������ �ִ� ������� �ϰ� 
	//!< �� ������ ���������� ����ϴ�.
    kResolutionNoBorder,
    
	//!< ���� ���� ���� �����ϰ� ȭ�� ���� ǥ�õ˴ϴ� ^^
	kResolutionShowAll,
    
	//!< ���� �������� ǳ���ϰ� ����ϴ�.
    kResolutionFixedHeight,
    
	//!< ���� �������� ǳ���ϰ� ����ϴ�.
    kResolutionFixedWidth,

	//!< �ƹ� ����� ���� �ƴ� ��� ���ɴϴ� ^^
    kResolutionUnKnown,
*/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //!< Android ���� �϶� �Դϴ�.
	//!< ========================================================================
	//!< ���� �ػ� ���� �κ� ����

	//!< CCDirector �� ��ũ���� �ѷ��ݴϴ�.
    pDirector->setOpenGLView(pEGLView);
	
	//!< ��ũ���� �ѷ��� �͵��� ���� ���� �ػ� ������ �Ͽ� �ڵ��� �������� ���� �����ִ� ������ �մϴ�. 
	//!< ù��° ���� : width (����) // �ι�° ���� : height (����)
	//!< ����° ���� Resolution Policy
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(D_DESIGN_WIDTH, D_DESIGN_HEIGHT, kResolutionShowAll);
	
	//!< ���� �ػ� ���� �κ� ��
	//!< ========================================================================>

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //!< IOS ���� �϶� �Դϴ�.

	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
	
	//!< ���� �ڽ��� �ڵ����� ����� �����ɴϴ� ^^
	CCSize frameSize = pEGLView->getFrameSize();

	//!< �̹������� �������ֱ� ���� ����
	vector<string> searchPath;

    //!< �� �κ��� ������ ������ �ȼ����� ������ �ִ� �κ��Դϴ� ^^
	//!< ������ �÷��� ���� ������ ������ Resources ���Ͽ� �����̴ϴ� ^^ �ű�ȿ� �ش� �̹��� �ȼ���ŭ ó���ϸ� �˴ϴ� ^^
	//!< �������� �� �÷����� � �����Ƿ� �������� ���������ϴ� ^^

	//!< ����� medium ���� Ŭ�� �̹Ƿ� �� large �Դϴ� ^^
	if (frameSize.height > mediumResource.size.height)
	{
        searchPath.push_back(largeResource.directory);

        pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
    
	//!< ����� small ���� ũ�� large ���� ������ �� medium �϶� �Դϴ� ^^
    else if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
        
        pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
   
	//!< �� ���ص� �ƽð���?
	else
    {
        searchPath.push_back(smallResource.directory);

        pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }

    // ���� �����͸��� ã���ϴ� ^^
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) //!< ������ ���� �϶� �Դϴ�.

	//!< CCDirector �� ��ũ���� �ѷ��ݴϴ�.
    pDirector->setOpenGLView(pEGLView);
	
	//!< ��ũ���� �ѷ��� �͵��� ���� ���� �ػ� ������ �Ͽ� �ڵ��� �������� ���� �����ִ� ������ �մϴ�. 
	//!< ù��° ���� : width (����) // �ι�° ���� : height (����)
	//!< ����° ���� Resolution Policy
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(D_DESIGN_WIDTH, D_DESIGN_HEIGHT, kResolutionShowAll);
#endif
#pragma endregion

	//!< DEBUG �Ͻÿ��� Display Stats (������) �����ݴϴ�.
#ifdef DEBUG
    pDirector->setDisplayStats(true);
#else
	//!< DEBUG�� �ƴ� ��쿡�� �Ⱥ����ݴϴ�. ex) Release
	pDirector->setDisplayStats(false);
#endif

    //!< FPS �� �����մϴ�. ����� 1�ʿ� 60�� �������� ���� �˴ϴ�.
    pDirector->setAnimationInterval(1.0 / 60);
	
	D_ASSET_MNG->setFPS(pDirector->getSecondsPerFrame());
    //!< Scene�� �����մϴ�. 
	//!< Start Scene�� HelloWorld ��� Scene���� ���� �Ͽ����ϴ�.
	CCScene *pScene = CGame::scene();

    //!< ���� �����ݴϴ�.
	//!< ���⼭ ������ ���̽��� ���ư��� ���ÿ� ���� ���� ���ư��� ģ������ ���̶� ���ø� �˴ϴ�.
    pDirector->runWithScene(pScene);

	//!< �ѹ��� ���ư����� �����մϴ� ^^
    return true;
}

//!< �� ���� ���ø����̼��� Ȩ��ư�� �����ٰų� Ȧ�� ��ư�� ���� ������ �Ǿ��� �� ������ �κ� �Դϴ�.
//!< �� ������ ���� ������ �Ͻ������� �ǵ��� �ϸ� ������ ��ġ���ϰ� �����ų� ������ ��
//!< ������ �� �� �Դϴ�.
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    //!< ���� ���� ���� ���߸� �����ϴ�.
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

//!< �̰��� �ݴ�� �������� �ƴ� �ٽ� ���ö� ������ �κ� �Դϴ�.
//!< �ٽ� ����� ���� �ֽø� �˴ϴ�.
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    //!< ���⼭ ���� ���� ���� ������ϸ� �����ϴ�.
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}


