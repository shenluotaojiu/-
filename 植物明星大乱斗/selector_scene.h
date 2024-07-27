#pragma once
//ctrl kd 对代码格式化
#include "scene.h"
#include "animation.h"
#include "scene_manager.h"
#include "peashooter_player.h"
#include "sunflower_player.h"
#include "player_id.h"

extern Player* player_1p;
extern Player* player_2p;
extern IMAGE* img_player_1_avatar;
extern IMAGE* img_player_2_avatar;


extern IMAGE img_VS;
extern IMAGE img_1p;
extern IMAGE img_2p;
extern IMAGE img_1p_desc;
extern IMAGE img_2p_desc;
extern IMAGE img_gravestone_left;
extern IMAGE img_gravestone_right;
extern IMAGE img_selector_tip;
extern IMAGE img_selector_background;
extern IMAGE img_1p_selector_btn_idle_left;
extern IMAGE img_1p_selector_btn_idle_right;
extern IMAGE img_1p_selector_btn_down_left;
extern IMAGE img_1p_selector_btn_down_right;
extern IMAGE img_2p_selector_btn_idle_left;
extern IMAGE img_2p_selector_btn_idle_right;
extern IMAGE img_2p_selector_btn_down_left;
extern IMAGE img_2p_selector_btn_down_right;
extern IMAGE img_peashooter_selector_background_left;
extern IMAGE img_peashooter_selector_background_right;
extern IMAGE img_sunflower_selector_background_left;
extern IMAGE img_sunflower_selector_background_right;

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

extern IMAGE img_avatar_peashooter;
extern IMAGE img_avatar_sunflower;


extern SceneManager scene_manager;

class SelectScene
	: public Scene
{
public:
	SelectScene() = default;
	~SelectScene() = default;

	virtual void on_enter()
	{
		animation_peashooter.set_atlas(&atlas_peashooter_idle_right);
		animation_sunflower.set_atlas(&atlas_sunflower_idle_right);
		animation_peashooter.set_interval(100);
		animation_sunflower.set_interval(100);

		static const int OFFSET_X = 50;

		pos_img_VS.x = (getwidth() - img_VS.getwidth()) / 2;
		pos_img_VS.y = (getheight() - img_VS.getheight()) / 2;
		pos_img_tip.x = (getwidth() - img_selector_tip.getwidth()) / 2;
		pos_img_tip.y = getheight() - 125;
		pos_img_1p.x = (getwidth() / 2 - img_1p.getwidth()) / 2 - OFFSET_X;
		pos_img_1p.y = 35;
		pos_img_2p.x = getwidth() / 2 + (getwidth() / 2 - img_2p.getwidth()) / 2 + OFFSET_X;
		pos_img_2p.y = pos_img_1p.y;
		pos_img_1p_desc.x = (getwidth() / 2 - img_1p_desc.getwidth()) / 2 - OFFSET_X;
		pos_img_1p_desc.y = getheight() - 150;
		pos_img_2p_desc.x = getwidth() / 2 +(getwidth() / 2 - img_2p_desc.getwidth()) / 2 + OFFSET_X;
		pos_img_2p_desc.y = pos_img_1p_desc.y;
		pos_img_1p_gravestone.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
		pos_img_1p_gravestone.y = pos_img_1p.y + img_1p.getheight() + 35;
		pos_img_2p_gravestone.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth() ) / 2 + OFFSET_X;
		pos_img_2p_gravestone.y = pos_img_1p_gravestone.y;
		pos_animation_1p.x = (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 - OFFSET_X;
		pos_animation_1p.y = pos_img_1p_gravestone.y + 80;
		pos_animation_2p.x = getwidth() / 2 + (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 + OFFSET_X;
		pos_animation_2p.y = pos_animation_1p.y;
		pos_img_1p_name.y = pos_animation_1p.y + 155;
		pos_img_2p_name.y = pos_img_1p_name.y;
		pos_1p_selector_btn_left.x = pos_img_1p_gravestone.x - img_1p_selector_btn_idle_left.getwidth();
		pos_1p_selector_btn_left.y = pos_img_1p_gravestone.y + (img_gravestone_right.getheight() - img_1p_selector_btn_down_left.getheight()) / 2;
		pos_1p_selector_btn_right.x = pos_img_1p_gravestone.x + img_gravestone_right.getwidth();
		pos_1p_selector_btn_right.y = pos_1p_selector_btn_left.y;
		pos_2p_selector_btn_left.x = pos_img_2p_gravestone.x - img_2p_selector_btn_idle_left.getwidth();
		pos_2p_selector_btn_left.y = pos_1p_selector_btn_left.y;
		pos_2p_selector_btn_right.x = pos_img_2p_gravestone.x + img_gravestone_left.getwidth();
		pos_2p_selector_btn_right.y = pos_1p_selector_btn_left.y;



	}

	virtual void on_update(int delta)
	{
		animation_peashooter.on_update(delta);
		animation_sunflower.on_update(delta);

		selector_background_scorll_offset_x += 5;
		if (selector_background_scorll_offset_x >= img_peashooter_selector_background_left.getwidth())
			selector_background_scorll_offset_x = 0;
	}
	
	virtual void on_draw(const Camera& camera)
	{	
		IMAGE* img_p1_selector_background = nullptr;
		IMAGE* img_p2_selector_background = nullptr;

		switch (player_type_2p)
		{
		case PlayerType::Peashooter:
			img_p1_selector_background = &img_peashooter_selector_background_right;
			break;
		case PlayerType::Sunflower:
			img_p1_selector_background = &img_sunflower_selector_background_right;
			break;
		default:
			img_p1_selector_background = &img_peashooter_selector_background_right;
			break;
		}

		switch (player_type_1p)
		{
		case PlayerType::Peashooter:
			img_p2_selector_background = &img_peashooter_selector_background_left;
			break;
		case PlayerType::Sunflower:
			img_p2_selector_background = &img_sunflower_selector_background_left;
			break;
		default:
			img_p2_selector_background = &img_peashooter_selector_background_left;
			break;
		}


		putimage(0, 0, &img_selector_background);

		putimage_alpha(selector_background_scorll_offset_x - img_p1_selector_background->getwidth(), 0, img_p1_selector_background);
		putimage_alpha(selector_background_scorll_offset_x, 0,
			img_p1_selector_background->getwidth() - selector_background_scorll_offset_x, 0, img_p1_selector_background, 0, 0);
		putimage_alpha(getwidth() - img_p2_selector_background->getwidth(), 0, img_p2_selector_background->getwidth() -
			selector_background_scorll_offset_x, 0, img_p2_selector_background, selector_background_scorll_offset_x, 0);
		putimage_alpha(getwidth() - selector_background_scorll_offset_x, 0, img_p2_selector_background);

		putimage_alpha(pos_img_VS.x, pos_img_VS.y, &img_VS);
		putimage_alpha(pos_img_1p.x, pos_img_1p.y, &img_1p);
		putimage_alpha(pos_img_2p.x, pos_img_2p.y, &img_2p);
		putimage_alpha(pos_img_1p_gravestone.x, pos_img_1p_gravestone.y, &img_gravestone_right);
		putimage_alpha(pos_img_2p_gravestone.x, pos_img_2p_gravestone.y, &img_gravestone_left);

		switch (player_type_1p)
		{
		case PlayerType::Peashooter:
			animation_peashooter.on_draw(camera, pos_animation_1p.x, pos_animation_1p.y);
			pos_img_1p_name.x = pos_img_1p_gravestone.x + (img_gravestone_right.getwidth() - textwidth(str_peashooter_name)) / 2;
			outtextxy_shaded(pos_img_1p_name.x, pos_img_1p_name.y, str_peashooter_name);
			break;
		case PlayerType::Sunflower:
			animation_sunflower.on_draw(camera, pos_animation_1p.x, pos_animation_1p.y);
			pos_img_1p_name.x = pos_img_1p_gravestone.x + (img_gravestone_right.getwidth() - textwidth(str_sunflower_name)) / 2;
			outtextxy_shaded(pos_img_1p_name.x, pos_img_1p_name.y, str_sunflower_name);
			break;
		}

		switch (player_type_2p)
		{
		case PlayerType::Peashooter:
			animation_peashooter.on_draw(camera, pos_animation_2p.x, pos_animation_2p.y);
			pos_img_2p_name.x = pos_img_2p_gravestone.x + (img_gravestone_left.getwidth() - textwidth(str_peashooter_name)) / 2;
			outtextxy_shaded(pos_img_2p_name.x, pos_img_2p_name.y, str_peashooter_name);
			break;
		case PlayerType::Sunflower:
			animation_sunflower.on_draw(camera, pos_animation_2p.x, pos_animation_2p.y);
			pos_img_2p_name.x = pos_img_2p_gravestone.x + (img_gravestone_left.getwidth() - textwidth(str_sunflower_name)) / 2;
			outtextxy_shaded(pos_img_2p_name.x, pos_img_2p_name.y, str_sunflower_name);
			break;
		}

		putimage_alpha(pos_1p_selector_btn_left.x, pos_1p_selector_btn_left.y,
			is_btn_1p_left_down ? &img_1p_selector_btn_down_left : &img_1p_selector_btn_idle_left);
		putimage_alpha(pos_1p_selector_btn_right.x, pos_1p_selector_btn_right.y,
			is_btn_1p_right_down ? &img_1p_selector_btn_down_right : &img_1p_selector_btn_idle_right);
		putimage_alpha(pos_2p_selector_btn_left.x, pos_2p_selector_btn_left.y,
			is_btn_2p_left_down ? &img_1p_selector_btn_down_left : &img_2p_selector_btn_idle_left);
		putimage_alpha(pos_2p_selector_btn_right.x, pos_2p_selector_btn_right.y,
			is_btn_2p_right_down ? &img_2p_selector_btn_down_right : &img_2p_selector_btn_idle_right);

		putimage_alpha(pos_img_1p_desc.x, pos_img_1p_desc.y, &img_1p_desc);
		putimage_alpha(pos_img_2p_desc.x, pos_img_2p_desc.y, &img_2p_desc);

		putimage_alpha(pos_img_tip.x, pos_img_tip.y, &img_selector_tip);


	}

	virtual void on_input(const ExMessage& msg) 
	{
		switch (msg.message)
		{
		case WM_KEYDOWN:
			switch (msg.vkcode)
			{
			case 0x41:
				is_btn_1p_left_down = true;
				break;
			case 0x44:
				is_btn_1p_right_down = true;
				break;
			case VK_LEFT:
				is_btn_2p_left_down = true;
				break;
			case VK_RIGHT:
				is_btn_2p_right_down = true;
				break;
			default:
				break;
			}
			break;

		case WM_KEYUP:
			switch (msg.vkcode)
			{
			case 0x41:
				is_btn_1p_left_down = false;
				player_type_1p = (PlayerType)(((int)PlayerType::Invalid + (int)player_type_1p - 1) % (int)PlayerType::Invalid);
				mciSendString(_T("play ui_switch from 0"), NULL, 0, NULL);
				break;
			case 0x44:
				is_btn_1p_right_down = false;
				player_type_1p = (PlayerType)(((int)player_type_1p + 1) % (int)PlayerType::Invalid);
				mciSendString(_T("play ui_switch from 0"), NULL, 0, NULL);
				break;
			case VK_LEFT:
				is_btn_2p_left_down = false;
				player_type_2p = (PlayerType)(((int)PlayerType::Invalid + (int)player_type_2p - 1) % (int)PlayerType::Invalid);
				mciSendString(_T("play ui_switch from 0"), NULL, 0, NULL);
				break;
			case VK_RIGHT:
				is_btn_2p_right_down = false;
				player_type_2p = (PlayerType)(((int)player_type_2p +1) % (int)PlayerType::Invalid);
				mciSendString(_T("play ui_switch from 0"), NULL, 0, NULL);
				break;
			case VK_RETURN:
				scene_manager.switch_to(SceneManager::SceneType::Game);
				mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	}

	virtual void on_exit()
	{
		switch (player_type_1p)
		{
		case SelectScene::PlayerType::Peashooter:
			player_1p = new Peashooter_player();
			img_player_1_avatar = &img_avatar_peashooter;
			break;
		case SelectScene::PlayerType::Sunflower:
			player_1p = new SunflowerPlayer();
			img_player_1_avatar = &img_avatar_sunflower;
			break;
		default:
			break;
		}
		player_1p->setId(PlayerId::P1);

		switch (player_type_2p)
		{
		case SelectScene::PlayerType::Peashooter:
			player_2p = new Peashooter_player(false);
			img_player_2_avatar = &img_avatar_peashooter;
			break;
		case SelectScene::PlayerType::Sunflower:
			player_2p = new SunflowerPlayer(false);
			img_player_2_avatar = &img_avatar_sunflower;
			break;
		default:
			break;
		}
		player_2p->setId(PlayerId::P2);

		mciSendString(_T("stop bgm_menu"), NULL, 0, NULL);
	}

private:
	enum class PlayerType
	{
		Peashooter = 0,
		Sunflower,
		Invalid
	};

	void outtextxy_shaded(int x, int y, LPCTSTR str)
	{
		settextcolor(RGB(45, 45, 45));
		outtextxy(x + 3, y + 3, str);
		settextcolor(RGB(255, 255, 255));
		outtextxy(x, y, str);
	}


private:
	POINT pos_img_VS = { 0 };
	POINT pos_img_tip = { 0 };
	POINT pos_img_1p = { 0 };
	POINT pos_img_2p = { 0 };
	POINT pos_img_1p_desc = { 0 };
	POINT pos_img_2p_desc = { 0 };
	POINT pos_img_1p_name = { 0 };
	POINT pos_img_2p_name = { 0 };
	POINT pos_animation_1p = { 0 };
	POINT pos_animation_2p = { 0 };
	POINT pos_img_1p_gravestone = { 0 };
	POINT pos_img_2p_gravestone = { 0 };
	POINT pos_1p_selector_btn_left = { 0 };
	POINT pos_1p_selector_btn_right = { 0 };
	POINT pos_2p_selector_btn_left = { 0 };
	POINT pos_2p_selector_btn_right = { 0 };

	Animation animation_peashooter;
	Animation animation_sunflower;

	LPCTSTR str_peashooter_name = _T("万多射手");
	LPCTSTR str_sunflower_name = _T("想日葵");

	PlayerType player_type_1p = PlayerType::Peashooter;
	PlayerType player_type_2p = PlayerType::Sunflower;
	
	int selector_background_scorll_offset_x = 0; // 背景板滚动距离

	bool is_btn_1p_left_down = false;
	bool is_btn_2p_left_down = false;
	bool is_btn_1p_right_down = false;
	bool is_btn_2p_right_down = false;
};