#pragma once

USING_NS_CC;

class CMenu : public CCLayer
{
public:
    virtual bool init();  

	//!< �ش� ���� ���� �̱����� ���� �մϴ�.
    static CCScene* scene();

	void Update(float dt);
    
    CREATE_FUNC(CMenu);
};
