#include "MenuLayer.h"
#include "GameScene.h"
#include "GameData.h"
#include "Audio.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)   
#include "platform/android/jni/JniHelper.h"   
#endif 

bool MenuLayer::init(){
	if(!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	/*初始化背景*/
	Sprite* background = Sprite::create("bg_menuscene.jpg");
	background->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(background,-1);
	
	/*初始化菜单*/
	MenuItemImage* startBtn = MenuItemImage::create(
		"menu_start.png","menu_start.png",CC_CALLBACK_0(MenuLayer::startGame,this)
		);
	Menu* menu = Menu::create(startBtn,NULL);
	menu->alignItemsVertically();
	menu->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(menu);

	//按键事件
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listenerkeyPad = EventListenerKeyboard::create(); 
	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(MenuLayer::onKeyReleased, this); 
    dispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this); 

	return true;
}

void MenuLayer::startGame(){
	CCLOG("START!");
	GAMEDATA::getInstance()->init();
	Director::getInstance()->replaceScene(GameScene::create());

}

void MenuLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event)
{
	//返回
	if (keycode == EventKeyboard::KeyCode::KEY_BACK
		|| keycode == EventKeyboard::KeyCode::KEY_BACKSPACE
		|| keycode == EventKeyboard::KeyCode::KEY_ESCAPE) {
		bool has_ads = false;
		//判断当前是否为Android平台   
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)  
			JniMethodInfo minfo;
			bool isHave = JniHelper::getStaticMethodInfo(minfo, "com/mr/star/AppActivity", 
				"getActivity", "()Ljava/lang/Object;");  
			jobject activityObj;  
			if (isHave)  
			{  
				activityObj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);  
			}  
			isHave = JniHelper::getMethodInfo(minfo, "com/mr/star/AppActivity", "dismissads", "()Z");  
			if (isHave)  
			{  
				jboolean has_ad = minfo.env->CallBooleanMethod(activityObj, minfo.methodID);  
				has_ads = has_ad;
			}  
		#endif   
		if (!has_ads)
			Director::getInstance()->end();	
	} else if (keycode == EventKeyboard::KeyCode::KEY_MENU) {
		CCLOG("KEY_MENU onKeyReleased..");
	} 
}
