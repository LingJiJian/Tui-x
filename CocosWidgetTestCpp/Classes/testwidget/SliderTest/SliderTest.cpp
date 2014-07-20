#include "SliderTest.h"

void CSliderTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCSliderTestScene();
}

void CSliderTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCSliderTestScene();
}

void CSliderTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCSliderTestScene();
}

//////////////////////////////////////////////////////

bool CSliderBasicTest::init()
{
	CSliderTestSceneBase::init();
	setTitle("CSliderBasicTest");
	setDescription("Slider From ProgressBar in vertical direction");

	m_pSlider = CSlider::create("slider.png", "progress_v.png");
	m_pSlider->setBackgroundImage("progress_v_bg.png");
	m_pSlider->setPosition(Vec2(130, 320));
	m_pSlider->setMaxValue(100);
	m_pSlider->setMinValue(0);
	m_pSlider->setDirection(eProgressBarDirectionBottomToTop);
	m_pSlider->setOnValueChangedListener(this,
		ccw_valuechanged_selector(CSliderBasicTest::onValueChanged));
	m_pWindow->addChild(m_pSlider);


	m_pText = CLabel::create();
	m_pText->setAnchorPoint(Vec2(0, 0.5));
	m_pText->setPosition(Vec2(380, 400));
	//m_pText->setFontSize(35.0f);
	m_pText->setString("none");
	m_pWindow->addChild(m_pText);

	return true;
}

void CSliderBasicTest::onValueChanged(Ref* pSender, int nValue)
{
	char buff[82] = {0};
	sprintf(buff, "value %d, percentage %f", m_pSlider->getValue(), m_pSlider->getPercentage());
	m_pText->setString(buff);
}

//////////////////////////////////////////////////////

bool CSliderWithScrollTest::init()
{
	CSliderTestSceneBase::init();
	setTitle("CSliderWithScrollTest");
	setDescription("Slider With ScrollView");

	m_pScrollView = CScrollView::create(Size(480, 320));
	//m_pScrollView->setBackgroundImage("background.png");
	m_pScrollView->setContainerSize(Size(3100, 320));
	m_pScrollView->setDirection(eScrollViewDirectionHorizontal);
	m_pScrollView->setPosition(Vec2(480, 350));
	m_pScrollView->setDragable(false);
	m_pWindow->addChild(m_pScrollView);

	float x = 100.0f;
	for( int i = 0; i < 30; i++ )
	{
		CButton* pIcon = CButton::createWith9Sprite(Size(60, 60), "sprite9_btn1.png", "sprite9_btn2.png");

		char buf[32] = {0};
		sprintf(buf, "%d", i + 1);
		pIcon->initText(buf, "", 25);
		pIcon->setPosition(Vec2( x , 160 ));
		m_pScrollView->getContainer()->addChild(pIcon);
		x += 100.0f;
	}

	m_pSlider = CSlider::create();
	m_pSlider->setSliderImage("slider.png");
	m_pSlider->setProgressImage("progress.png");
	m_pSlider->setBackgroundImage("progress_bg.png");

	m_pSlider->setPosition(Vec2(480, 140));
	m_pSlider->setMaxValue( (int)(m_pScrollView->getContainer()->getContentSize().width - m_pScrollView->getContentSize().width) );
	m_pSlider->setMinValue(0);
	m_pSlider->setValue(0);
	m_pSlider->setOnValueChangedListener(this, ccw_valuechanged_selector(CSliderWithScrollTest::onValueChanged));
	m_pWindow->addChild(m_pSlider);

	return true;
}

void CSliderWithScrollTest::onValueChanged(Ref* pSender, int nValue)
{
	m_pScrollView->setContentOffset(Vec2((float)(-nValue), 0));
}