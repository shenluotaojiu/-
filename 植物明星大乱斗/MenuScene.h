#pragma once
#include "scene.h"
#include "scene_manager.h"
#include "atlas.h"
#include "animation.h"

#include "timer.h"


extern Atlas atlas_peashooter_run_right;
extern SceneManager scene_manager;
extern IMAGE img_menu_background;

class MenuScene :
    public Scene
{
public:
    MenuScene() = default;
    ~MenuScene() = default;

	virtual void on_enter()
	{
		mciSendString(_T("play bgm_menu repeat from 0"),NULL,0,NULL);
		
	}
	virtual void on_update(int delta)
	{
		
	}
	virtual void on_draw(const Camera& camera)
	{
		putimage(0, 0, &img_menu_background);
	}
	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYUP)
		{
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	}
	virtual void on_exit()
	{
		
	}
private:
	Animation animation_peashooter_run_right;
	Camera camera;
	Timer timer;
};

