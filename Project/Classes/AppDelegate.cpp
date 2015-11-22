#include "AppDelegate.h"
#include "FieldScene.h"
#include "StaticContentsContainer.h"
#include "DynamicContentsContainer.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		if (!glview) {
			glview = GLViewImpl::createWithRect("My Game", Rect(0, 0, 1280, 720));
			director->setOpenGLView(glview);
		}
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    register_all_packages();

    // create a scene. it's an autorelease object
	
	StaticContentsContainer::readxml();  // 처음 파일을 읽는다. 

	CMap* tempMap = StaticContentsContainer::getMapMap()->find("test")->second;
	DynamicContentsContainer::getInstance()->setMap(tempMap);

	DynamicContentsContainer::getInstance()->getMap()->setStartPoint(Vec2(10, 9));
	DynamicContentsContainer::getInstance()->getCharacter()->setPoint(DynamicContentsContainer::getInstance()->getMap()->getStartPoint()); // 케릭터를 시작 위치로 설정

	auto fieldScene = FieldScene::createScene();  // 테스트를 위한 씬 

	director->runWithScene(fieldScene);      // 처음으로 불러올 씬을 부름 

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
