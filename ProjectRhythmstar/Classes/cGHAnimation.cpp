#include "stdafx.h"

/**
@brief : plist �� �ִ� ��� �ִϸ��̼��� ������ Init �Դϴ�.
@plistPath : plist ��θ� �����ɴϴ�.
@imageGetpath : image ��θ� �����ɴϴ�.
@maxFrame : �ִ� ������ ���� �����ɴϴ�.
*/
void cGHAnimation::Init(string plistPath , string imageGetpath , CCPoint vPosition , string extension , int nLayer , int maxFrame , float aniMaxTime , bool bFrameOnce)
{
	m_bFrameOnce	= bFrameOnce;
	m_fTumTime		= aniMaxTime;
	m_nMaxFrame		= maxFrame;
	m_fMaxTime		= m_fTumTime * (float)m_nMaxFrame;

	//star-ani_default.plist �� �о� ������ �̹�����, ĳ�ÿ� �ִ´�.
	CCString *plistStringName = CCString::createWithFormat("%s.plist" , plistPath.c_str());
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(plistStringName->getCString());

	pAnimFrames = CCArray::createWithCapacity(maxFrame);

	// ĳ�� �س��� �̹����� �ϳ��� �����ͼ� 
	for (int i=1; i<=maxFrame; i++) {
		CCString *stringName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , i , extension.c_str());
		CCSpriteFrame* frame = cache->spriteFrameByName(stringName->getCString());
		// ������� ���ϸ��� �̹����� ĳ�ÿ��� ������ animFrames ���ٰ� �ִ´�.
		pAnimFrames->addObject(frame);
	}

	//���ʷ� ȭ�鿡 ���� ��������Ʈ�� ����� �ش�.
	CCString *stringName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , 1 , extension.c_str());
	pSprite = CCSprite::createWithSpriteFrameName(stringName->getCString());
	pSprite->setPosition(vPosition);
	m_pLayer->addChild(pSprite , nLayer);

	// ���⼭���ʹ� �ִϸ��̼��� ����� ����    
	
	// �ִϸ��̼ǿ� ����� �̹������� �غ�Ǿ���.
	// Animation�̶� Animate �� �̸��� ����ϸ鼭 ������ ��� �� �ִµ�, 
	// Animation�� �����̶�� �����ϰ� �����̵��� �ϴ� �׼��� Animate ��� �����ϸ� �ɰ� ����.
	// �غ�� �̹��� �����ӵ��� 0.1�ʸ��� �ٲ㺸���ֵ��� �����ؼ� animation�� �����.    
	pAnimation = CCAnimation::createWithSpriteFrames(pAnimFrames , m_fTumTime);
	// animation ������ �̿��ؼ� Animate �׼��� �����.
	CCAnimate *animate = CCAnimate::create(pAnimation);

	// ��� ������ �����̵��� RepeatForever �� ����ش�. 
	if(m_bFrameOnce)
	{
		m_pActionStar = CCRepeat::create(animate , 1);
		// ȥ�� ���� ������� �ִ� ��������Ʈ�� ���ϸ��̼� �׼��� �����ϵ��� ��Ų��.
		pSprite->runAction(m_pActionStar);
	}
	else
	{
		m_pActionStar2 = CCRepeatForever::create(animate);
		// ȥ�� ���� ������� �ִ� ��������Ʈ�� ���ϸ��̼� �׼��� �����ϵ��� ��Ų��.
		pSprite->runAction(m_pActionStar2);
	}

}

/**
@brief : plist �� �ִ� ��� �ִϸ��̼��� ������ Init �Դϴ�.
@plistPath : plist ��θ� �����ɴϴ�.
@imageGetpath : image ��θ� �����ɴϴ�.
@maxFrame : �ִ� ������ ���� �����ɴϴ�.
*/
void cGHAnimation::Init_Vector(string plistPath , string imageGetpath , CCPoint vPosition , string extension , int nLayer , int maxFrame , float aniMaxTime , bool bFrameOnce , int nLoopCount)
{
	m_bFrameOnce	= bFrameOnce;
	m_fTumTime		= aniMaxTime;
	m_nMaxFrame		= maxFrame;
	m_fMaxTime		= m_fTumTime * (float)m_nMaxFrame;
	m_nNowFrame		= 0;
	m_fNowTime		= 0.0f;
	m_nLoop			= 1;
	m_nLoopCount	= nLoopCount;


	//star-ani_default.plist �� �о� ������ �̹�����, ĳ�ÿ� �ִ´�.
	CCString *plistStringName = CCString::createWithFormat("%s.plist" , plistPath.c_str());
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(plistStringName->getCString());

	//pAnimFrames = CCArray::createWithCapacity(maxFrame);

	// ĳ�� �س��� �̹����� �ϳ��� �����ͼ� 
	for (int i=1; i<=maxFrame; i++) {
		CCString *stringName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , i , extension.c_str());
		CCSpriteFrame* frame = cache->spriteFrameByName(stringName->getCString());
		
		CCSprite * pTempSprite; 
		pTempSprite = CCSprite::createWithSpriteFrame(frame);
		pTempSprite->setPosition(vPosition);
		pTempSprite->setVisible(false);
		m_pLayer->addChild(pTempSprite , nLayer);	
		m_pVectorTable.push_back(pTempSprite);
	}
}

/**
@brief : plist ���� �ִϸ��̼��� ������ Init �Դϴ�.
@filePath : ��� �ҷ��ɴϴ�.
@frameMax : �ִ� ������ �Դϴ�.
@aniMaxTime : �ִ� ��� �ð��Դϴ�.
*/
void cGHAnimation::Init(string filePath , CCPoint vPos , string extension  , int nLayer , int frameMax , float aniMaxTime , bool bFrameOnce)
{
	m_bFrameOnce	= bFrameOnce;
	m_fTumTime		= aniMaxTime;
	m_nMaxFrame		= frameMax;
	m_fMaxTime		= m_fTumTime * (float)m_nMaxFrame;

	pAnimation = CCAnimation::create();
	CCString *fileName;

	for(int i = 1 ; i <= m_nMaxFrame ; i++)
	{
		fileName = CCString::createWithFormat("%s%d%s" , filePath.c_str() , i , extension.c_str());
		pAnimation->addSpriteFrameWithFileName(fileName->getCString());
	}

	pAnimation->setDelayPerUnit(m_fTumTime);
	pAnimation->setRestoreOriginalFrame(!m_bFrameOnce);

	fileName = CCString::createWithFormat("%s%d%s" , filePath.c_str() , 1 , extension.c_str());
	pSprite = CCSprite::create(fileName->getCString());
	pSprite->setPosition(vPos);

	CCAnimate *animate = CCAnimate::create(pAnimation);

	if(m_bFrameOnce)
	{
		m_pActionStar = CCRepeat::create(animate , 1);
		m_pLayer->addChild(pSprite , nLayer);
		pSprite->runAction(m_pActionStar);
	}
	else
	{
		m_pActionStar2 = CCRepeatForever::create(animate);
		m_pLayer->addChild(pSprite , nLayer);
		pSprite->runAction(m_pActionStar2);
	}

}

/**
 @brief : �ִϸ��̼� ������Ʈ Ŭ����
 @param : delay time
*/
void cGHAnimation::AnimationUpdate(float dt)
{
	if(m_pVectorTable.size())
	{
		switch(m_bFrameOnce)
		{
		case 0:
			m_fNowTime += dt;

			if(m_fNowTime >= m_fTumTime)
			{
				m_pVectorTable[m_nNowFrame]->setVisible(false);
				m_nNowFrame ++;
				if(m_nNowFrame >= m_nMaxFrame)
					m_nNowFrame = 0;
				m_pVectorTable[m_nNowFrame]->setVisible(true);
				m_fNowTime = 0.0f;
			}

			break;
		case 1:
			m_fNowTime += dt;
			
			if(m_fNowTime >= m_fTumTime)
			{
				m_pVectorTable[m_nNowFrame]->setVisible(false);
				m_nNowFrame ++;

				if(m_nNowFrame >= m_nMaxFrame)
				{
					if(m_nLoop >= m_nLoopCount)
						m_nNowFrame = m_nMaxFrame - 1;
					else
					{
						m_nLoop++;
						m_nNowFrame = 0;
					}
				}
				else
					m_pVectorTable[m_nNowFrame]->setVisible(true);

				m_fNowTime = 0.0f;
			}
			break;
		}
	}
}

void cGHAnimation::setPosition(CCPoint pos)
{
	for(int i = 0 ; i < m_nMaxFrame ; i++)
		m_pVectorTable[i]->setPosition(pos);
}

CCPoint cGHAnimation::getPosition()
{
	return pSprite->getPosition();
}

void cGHAnimation::setAnchorPositon(CCPoint pos)
{
	pSprite->setAnchorPoint(pos);
}

CCPoint cGHAnimation::getAnchorPosition()
{
	return pSprite->getAnchorPoint();
}

void cGHAnimation::setRect(CCRect pos)
{
	pSprite->setTextureRect(pos);
}

CCRect cGHAnimation::getRect()
{
	return pSprite->getTextureRect();
}

void cGHAnimation::setVisible(bool bChk)
{
	pSprite->setVisible(bChk);
}

void cGHAnimation::setVisible2(bool bChk)
{
	for(int i = 0 ; i < m_nMaxFrame ; i++)
		m_pVectorTable[i]->setVisible(bChk);
}

bool cGHAnimation::getVisible()
{
	return pSprite->isVisible();
}

void cGHAnimation::setScale(CCPoint pos)
{
	pSprite->setScaleX(pos.x);
	pSprite->setScaleY(pos.y);
}

void cGHAnimation::setScale2(CCPoint pos)
{
	for(int i = 0 ; i < m_nMaxFrame ; i++)
	{
		m_pVectorTable[i]->setScaleX(pos.x);
		m_pVectorTable[i]->setScaleY(pos.y);
	}
}

CCPoint cGHAnimation::getScale()
{
	CCPoint tempSize;
	tempSize.x = pSprite->getScaleX();
	tempSize.y = pSprite->getScaleY();

	return tempSize;
}

void cGHAnimation::Destroy()
{
	CC_SAFE_DELETE(pSprite);
	CC_SAFE_DELETE(pAnimFrames);
	CC_SAFE_DELETE(pAnimation);
}

void cGHAnimation::setFrame(int nFrame)
{
	m_nNowFrame = nFrame;
	//pAnimation->setFrames(&pAnimFrames[nFrame]);
}

void cGHAnimation::setLoop(int nLoop)
{
	m_nLoop = nLoop;
}