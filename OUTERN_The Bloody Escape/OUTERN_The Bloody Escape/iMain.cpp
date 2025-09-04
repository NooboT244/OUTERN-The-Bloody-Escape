#include "iGraphics.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
constexpr double Default_window_width = 1520;
constexpr double Default_window_height = 855;


using namespace std;


struct Intro
{
    int blinking_Cursour_Color[3], color_Increment_Decrement,blinking_Cursour_Show;
    int intro_background_texture[3],blackmask_Move_Animation;
    double text_blackmask_X;

    Intro()
    {
        blinking_Cursour_Color[0] = 0;
        blinking_Cursour_Color[1] = 0;
        blinking_Cursour_Color[2] = 0;

        color_Increment_Decrement = 20;
        blinking_Cursour_Show = 0;

        text_blackmask_X = 102;
    }

    //..........functions.........//

    void blinking_Cursour()
    {
        for (int &color : blinking_Cursour_Color)
        {
            color += color_Increment_Decrement;
        }

        if (blinking_Cursour_Color[2] >= 240 || blinking_Cursour_Color[2] <= 0)
        {
            color_Increment_Decrement *= -1;
        }
    }

    void black_Mask_Animation()
    {
        text_blackmask_X += 10;
    }

    void Load_Intro_Textures()
    {
        intro_background_texture[0] = iLoadImage("resources\\game_texture\\intro_text_tex\\TEXT_WHITE.png");
        intro_background_texture[1] = iLoadImage("resources\\game_texture\\intro_text_tex\\TEXT_RED.png");
        intro_background_texture[2] = iLoadImage("resources\\game_texture\\intro_text_tex\\Blood.png");
    }
};

struct Waiting
{
    int Waiting_Page_Textures[4],Tap_To_Continue_Index;
    int Loading_Icon_Textures[25],Loading_icon_index,Loding_Animation;

    Waiting()
    {
        Tap_To_Continue_Index = 2;
        Loading_icon_index = 0;
    }

    //..........functions.........//

    void Load_waiting_page_texture()
    {
        Waiting_Page_Textures[0] = iLoadImage("resources\\game_texture\\waiting_page_tex\\Waiting_Page_bg.png");
        Waiting_Page_Textures[1] = iLoadImage("resources\\game_texture\\waiting_page_tex\\Waiting_Page_Title.png");
        Waiting_Page_Textures[2] = iLoadImage("resources\\game_texture\\waiting_page_tex\\CLICK_TO_CONTINUE_min.png");
        Waiting_Page_Textures[3] = iLoadImage("resources\\game_texture\\waiting_page_tex\\CLICK_TO_CONTINUE_large.png");
    }

};

struct Menu
{
    int Menu_background_texture[64],Menu_background_texture_index,Menu_Button[5],Menu_Button_Dark[5];
    int Menu_Buttons[10];
    int menu_Texture_Load_index;
    int Menu_Textures_Load,Menu_Title;
    int Play_Index,Credits_Index,Help_Index,Sound_Index,Exit_Index;
    int SOUND_ICON_Texture[2],SOUND_ICON_Index;

    Menu()
    {
        Menu_background_texture_index = 0;
        menu_Texture_Load_index = 0;

        Play_Index = 0;
        Credits_Index = 2;
        Help_Index = 4;
        Sound_Index = 6;
        Exit_Index = 8;

        SOUND_ICON_Index = 0;
    }

    //..........functions.........//
    void Load_Menu_Textures()
    {
        if(menu_Texture_Load_index < 64)
        {
            char textures_name[80];
            sprintf_s(textures_name,"resources\\game_texture\\menu_anim_tex\\menu_bg_%d.png",menu_Texture_Load_index + 1);
            Menu_background_texture[menu_Texture_Load_index] = iLoadImage(textures_name);
        }
        menu_Texture_Load_index++;

    }
    void Load_Menu_Buttons()
    {

        for(int i = 1; i < 11; i++)
        {
            char textures_path_name[80];
            sprintf_s(textures_path_name,"resources\\game_texture\\menu_textures\\ui_button\\menu_button_%d.png",i);
            Menu_Buttons[i - 1] = iLoadImage(textures_path_name);
        }

    }

    void Menu_background_texture_Animation()
    {
        if(Menu_background_texture_index < 63)
        {
            Menu_background_texture_index++;
        }
        else
        {
            Menu_background_texture_index = 0;
        }
    }

    void Loading_Sound_Texture()
    {
        SOUND_ICON_Texture[0] = iLoadImage("resources\\game_texture\\SOUND_ICON\\SOUND_ON.png");
        SOUND_ICON_Texture[1] = iLoadImage("resources\\game_texture\\SOUND_ICON\\SOUND_OFF.png");
    }
};

struct Games
{
    int Page,help_page,wave,wave_textures[3],wave_texture_timer_index;
    int Back_Button,wav_3_first_init,wav_1_first_init,wav_2_first_init;
    int game_over_textures[2];
    double Level_Select_X[3],Level_Select_Y[3], Level_Select_Width[3],Level_Select_Height[3];
    int Level_1_Icons[8],Level_1_Icons_index = 0,Level_1_Icons_Animation_ID;
    int Level,key;
    int bg_image_1,exit_text,exit_yes[2],exit_no[2],exit_yes_index = 0,exit_no_index = 0;
    bool  A_D_press,jump_press,exit_press,is_Dodge,is_crouch,is_attack,attack_press,is_game_Over_Call;
    double Back_button_X,Back_button_Y,Back_button_Height,Back_button_Width;

    Games()
    {
        key = 1;
        Page = 0;
        Level = 0;
        wav_3_first_init = 0;
        wav_1_first_init = 0;
        wav_2_first_init = 0;

        A_D_press = false;
        jump_press = false;
        exit_press = false;
        is_Dodge = false;
        is_crouch = false;
        is_attack = false;
        attack_press = false;
        is_game_Over_Call = false;

        Back_button_X = 20;
        Back_button_Y = 785;
        Back_button_Height = 50;
        Back_button_Width = 50;
    }

    //..........functions.........//

    void Level_Icon_Size_Setter()
    {
        Level_Select_X[0] = 155;
        Level_Select_X[1] = 610;
        Level_Select_X[2] = 1065;
        Level_Select_Y[0] = 300;
        Level_Select_Y[1] = 300;
        Level_Select_Y[2] = 300;
        Level_Select_Width[0] = 300;
        Level_Select_Width[1] = 300;
        Level_Select_Width[2] = 300;
        Level_Select_Height[0] = 300;
        Level_Select_Height[1] = 300;
        Level_Select_Height[2] = 300;
    }
    void Load_Wave_Texture()
    {
        wave_textures[0] = iLoadImage("resources\\game_texture\\Wave_Text\\w1.png");
        wave_textures[1] = iLoadImage("resources\\game_texture\\Wave_Text\\w2.png");
        wave_textures[2] = iLoadImage("resources\\game_texture\\Wave_Text\\w3.png");
    }
    void Loading_Level_Icons()
    {
        for (int i = 1; i <= 8; i++)
        {
            char textures_path_name[90];
            sprintf_s(textures_path_name, "resources\\game_texture\\level_selection_tex\\level_icons\\level_1\\Level_1_icon_ %d.png", i);
            Level_1_Icons[i - 1] = iLoadImage(textures_path_name);
        }
    }
    void Level_1_Icons_Animation()
    {
        if (Level_1_Icons_index < 7)
        {
            Level_1_Icons_index++;
        }
        else
        {
            Level_1_Icons_index = 0;
        }
    }

    void Load_game_over_textures()
    {
        game_over_textures[0] = iLoadImage("resources\\game_texture\\Blood dripping\\game_over_tex.png");
        game_over_textures[1] = iLoadImage("resources\\game_texture\\Blood dripping\\b-001.jpg");
    }

};

Games games;
void Level_Icon_Size_Setter()
{
    games.Level_Icon_Size_Setter();
}
void Loading_Level_Icons()
{
    games.Loading_Level_Icons();
}
void Level_1_Icons_Animation()
{
    games.Level_1_Icons_Animation();
}


struct Hero
{
    int hero_standing_left[14],hero_standing_right[14],hero_walking_left[18],hero_walking_right[18],hero_jump_left[17],hero_jump_right[17];
    int hero_Dodge_left[18],hero_Dodge_right[18],hero_jump2_left[30],hero_jump2_right[30];
    int hero_crouch_left[10],hero_crouch_right[10],BulletSpark[2];
    int hero_head,hero_health;
    int hero_attack_1_left[26],hero_attack_1_right[26],hero_attack_2_left[31],hero_attack_2_right[31],hero_attack_3_left[24],hero_attack_3_right[24];                         //hero_textures
    int hero_texture_load_index,hero_standing_index,hero_walking_index,hero_Dodge_index,hero_crouch_index;
    int hero_attack_1_index,hero_attack_2_index,hero_attack_3_index;
    double hero_jump_index,hero_jump2_index;                                                           //hero_index
    int Hero_Animation_Standing;                                                                                //timer_animation
    int Hero_Direction;                                                                                                       //left_right_Direction
    double hero_Position_X,hero_Position_Y,yIncreaseDecrease,yIncreaseDecrease_jump2;                                                      //hero_position

    Hero()
    {
        hero_health = 200;
        hero_attack_3_index = 0;
        hero_attack_2_index = 0;
        hero_attack_1_index = 0;
        hero_crouch_index = 0;
        hero_Dodge_index = 0;
        hero_texture_load_index = 0;
        hero_standing_index = 0;
        hero_walking_index = 0;
        hero_jump_index = 0;
        hero_jump2_index = 0;
        Hero_Direction = 0;
        hero_Position_X = 460;
        hero_Position_Y = 210;
        yIncreaseDecrease = 16.47;
        yIncreaseDecrease_jump2 = 13.33;
    }

    //..........functions.........//

    void Load_Hero_Textures()                                                                                                     //Loading_textures
    {
        char path[120];
        if(hero_texture_load_index < 1)
        {
            hero_head = iLoadImage("resources\\game_texture\\hero\\hero er Khoma.png");
            BulletSpark[0] = iLoadImage("resources\\game_texture\\hero\\Bullet_Spark\\left.png");
            BulletSpark[1] = iLoadImage("resources\\game_texture\\hero\\Bullet_Spark\\right.png");
        }
        if(hero_texture_load_index < 10)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Crouch\\Left\\left (%d).png",hero_texture_load_index + 1);
            hero_crouch_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Crouch\\Right\\right (%d).png", hero_texture_load_index + 1);
            hero_crouch_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 14)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Standing\\Left\\left (%d).png",hero_texture_load_index + 1);
            hero_standing_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Standing\\Right\\right (%d).png", hero_texture_load_index + 1);
            hero_standing_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 15)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Walking\\Left\\left (%d).png",hero_texture_load_index + 1);
            hero_walking_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Walking\\Right\\right (%d).png",hero_texture_load_index + 1);
            hero_walking_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 17)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Vertical jump\\left\\left (%d).png",hero_texture_load_index + 1);
            hero_jump_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Vertical jump\\right\\right (%d).png",hero_texture_load_index + 1);
            hero_jump_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 18)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Dodge\\left\\left (%d).png",hero_texture_load_index + 1);
            hero_Dodge_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Dodge\\right\\right (%d).png",hero_texture_load_index + 1);
            hero_Dodge_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 24)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Pistol\\left\\left (%d).png",hero_texture_load_index + 1);
            hero_attack_3_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Pistol\\right\\right (%d).png",hero_texture_load_index + 1);
            hero_attack_3_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 26)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Knife\\Left\\left (%d).png",hero_texture_load_index + 1);
            hero_attack_1_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Knife\\Right\\right (%d).png",hero_texture_load_index + 1);
            hero_attack_1_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 30)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Jump\\Left\\left (%d).png",hero_texture_load_index + 1);
            hero_jump2_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Jump\\Right\\right (%d).png",hero_texture_load_index + 1);
            hero_jump2_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 31)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Chain Saw\\left\\left (%d).png",hero_texture_load_index + 1);
            hero_attack_2_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Chain Saw\\right\\right (%d).png",hero_texture_load_index + 1);
            hero_attack_2_right[hero_texture_load_index] = iLoadImage(path);
        }
        hero_texture_load_index++;
    }

    void Hero_Standing_Animation()                                                                                              //Standing_timer_animation
    {
        if(hero_standing_index < 13)
        {
            hero_standing_index++;
        }
        else
        {
            hero_standing_index = 0;
        }
    }



    void Hero_Moves()
    {
        if(games.is_crouch)
        {
            games.A_D_press = false;
            hero_walking_index = 0;

            if(hero_crouch_index < 4)
            {
                hero_crouch_index++;
                if(hero_crouch_index == 4)
                {
                    games.is_crouch = false;
                }
            }
            else
            {
                if(hero_crouch_index < 9)
                {
                    hero_crouch_index++;
                }
                else
                {
                    hero_crouch_index = 0;
                    games.is_crouch = false;
                }
            }
        }

        if(games.is_Dodge)
        {
            hero_crouch_index = 0;
            games.is_crouch = false;
            hero_jump2_index = 0;
            hero_jump_index = 0;

            if(hero_Dodge_index < 17)
            {
                hero_Dodge_index++;
            }
            else
            {
                hero_Dodge_index = 0;
                games.is_Dodge = false;
            }
        }

        if(games.jump_press && !games.A_D_press)
        {
            hero_crouch_index = 0;
            games.is_crouch = false;
            hero_jump2_index = 0;


            hero_Position_Y += yIncreaseDecrease;


            if(hero_Position_Y >= 410)
            {
                yIncreaseDecrease = -abs(yIncreaseDecrease);
            }


            if(hero_Position_Y <= 210)
            {
                hero_Position_Y = 210;
                games.jump_press = false;
                yIncreaseDecrease = abs(yIncreaseDecrease);
            }


            if(hero_jump_index < 16)
            {
                hero_jump_index += 0.5;
            }
            else
            {
                hero_jump_index = 0;
            }
        }


        if(games.jump_press && games.A_D_press)
        {
            hero_crouch_index = 0;
            games.is_crouch = false;
            hero_jump_index = 0;

            hero_Position_Y += yIncreaseDecrease_jump2;

            if(hero_Position_Y >= 410)
            {
                yIncreaseDecrease_jump2 = -abs(yIncreaseDecrease_jump2);
            }

            if(hero_Position_Y <= 210)
            {
                hero_Position_Y = 210;
                games.jump_press = false;
                yIncreaseDecrease_jump2 = abs(yIncreaseDecrease_jump2);
            }

            if(hero_jump2_index < 29)
            {
                hero_jump2_index += 1;
            }
            else
            {
                hero_jump2_index = 0;
            }
        }


        if(games.A_D_press)
        {
            hero_crouch_index = 0;

            if(hero_Position_X <= 1320 && !Hero_Direction)
            {
                hero_Position_X += 20;
            }

            if(hero_Position_X >= 0 && Hero_Direction)
            {
                hero_Position_X -= 20;
            }

            if(hero_walking_index < 14)
            {
                hero_walking_index++;
            }
            else
            {
                hero_walking_index = 0;
            }
        }

        if(!Hero_Direction)
        {
            if(games.is_attack)
            {
                switch(games.key)
                {
                case 2:
                    iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/7,Default_window_height/2.8, hero_attack_2_right[hero_attack_2_index]);
                    if(hero_Position_X <= 1320)
                    {
                        hero_Position_X += 3;
                    }
                    break;
                case 3:
                    iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/7,Default_window_height/2.8, hero_attack_3_right[hero_attack_3_index]);
                    if(hero_attack_3_index == 11 || hero_attack_3_index == 12)
                    {
                        iShowImage(hero_Position_X + 300,395,260,80,BulletSpark[0]);
                    }

                    break;
                default:
                    iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/7,Default_window_height/2.8, hero_attack_1_right[hero_attack_1_index]);
                    if(hero_Position_X <= 1320)
                    {
                        hero_Position_X += 3;
                    }
                }
            }
            else if(games.is_Dodge)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/14,Default_window_height/4, hero_Dodge_right[hero_Dodge_index]);
                if(hero_Position_X <= 1320)
                {
                    hero_Position_X += 15;
                }
            }
            else if(games.jump_press && games.A_D_press)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/11,Default_window_height/4, hero_jump2_right[(int)hero_jump2_index]);
            }
            else if(games.jump_press )
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/11,Default_window_height/4, hero_jump_right[(int)hero_jump_index]);
            }
            else if(games.is_crouch || hero_crouch_index == 4)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/8.5,Default_window_height/4, hero_crouch_right[hero_crouch_index]);
            }
            else if(games.A_D_press)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/8.5,Default_window_height/3.5, hero_walking_right[hero_walking_index]);
            }
            else
            {
                iShowImage(hero_Position_X,hero_Position_Y,160,Default_window_height/3.5, hero_standing_right[hero_standing_index]);
            }
        }
        else
        {
            if(games.is_attack)
            {
                switch(games.key)
                {
                case 2:
                    iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/7,Default_window_height/2.8, hero_attack_2_left[hero_attack_2_index]);
                    if(hero_Position_X >= 0)
                    {
                        hero_Position_X -= 3;
                    }
                    break;
                case 3:
                    iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/7,Default_window_height/2.8,hero_attack_3_left[hero_attack_3_index]);
                    if(hero_attack_3_index == 11 || hero_attack_3_index == 12)
                    {
                        iShowImage(hero_Position_X - 300,395,260,80,BulletSpark[1]);
                    }
                    break;
                default:
                    iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/7,Default_window_height/2.8, hero_attack_1_left[hero_attack_1_index]);
                    if(hero_Position_X >= 0)
                    {
                        hero_Position_X -= 3;
                    }
                }
            }
            else if(games.is_Dodge)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/14,Default_window_height/4, hero_Dodge_left[hero_Dodge_index]);
                if(hero_Position_X >= 0)
                {
                    hero_Position_X -= 15;
                }
            }
            else if(games.jump_press && games.A_D_press)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/11,Default_window_height/4, hero_jump2_left[(int)hero_jump2_index]);
            }
            else if(games.jump_press )
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/11,Default_window_height/4, hero_jump_left[(int)hero_jump_index]);
            }
            else if(games.is_crouch || hero_crouch_index == 4)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/8.5,Default_window_height/4, hero_crouch_left[hero_crouch_index]);
            }
            else if(games.A_D_press)
            {
                iShowImage(hero_Position_X,hero_Position_Y,Default_window_width/8.5,Default_window_height/3.5, hero_walking_left[hero_walking_index]);
            }
            else
            {
                iShowImage(hero_Position_X,hero_Position_Y,160,Default_window_height/3.5, hero_standing_left[hero_standing_index]);
            }
        }
    }

    void Hero_Attack()
    {
        if (!games.is_attack)
        {
            hero_attack_1_index = 0;
            hero_attack_2_index = 0;
            hero_attack_3_index = 0;
            return;
        }

        games.is_crouch = false;
        hero_crouch_index = 0;
        hero_Dodge_index = 0;
        games.is_Dodge = false;

        switch (games.key)
        {

        case 2:
            if(!hero_attack_2_index)
            {
                mciSendString("play Chainsaw_Sound from 2", NULL, 0, NULL);
            }

            if (hero_attack_2_index < 25)
            {
                hero_attack_2_index++;
                if (hero_attack_2_index >= 15 && !games.attack_press)
                    hero_attack_2_index = 26;
            }
            else if (hero_attack_2_index >= 26 && hero_attack_2_index < 30)
            {
                hero_attack_2_index++;
                if (hero_attack_2_index >= 30)
                {
                    hero_attack_2_index = 0;
                    games.is_attack = false;
                }
            }
            else
            {
                hero_attack_2_index = 2;
                mciSendString("play Chainsaw_Sound from 2", NULL, 0, NULL);
            }


            if (hero_attack_2_index == 2)
            {
                hero_attack_1_index = 0;
                hero_attack_3_index = 0;
            }

            break;
        case 3:
            games.A_D_press = false;
            if (hero_attack_3_index < 23)
            {
                hero_attack_3_index++;
                if (hero_attack_3_index >= 23 && !games.attack_press)
                {
                    hero_attack_3_index = 0;
                    games.is_attack = false;
                }
                if(hero_attack_3_index == 9)
                {

                }
            }
            else
            {
                hero_attack_3_index = 7;
            }

            if (hero_attack_3_index == 7)
            {
                hero_attack_1_index = 0;
                hero_attack_2_index = 0;
            }

            break;
        default:
            if (hero_attack_1_index < 25)
            {
                hero_attack_1_index++;
                if (hero_attack_1_index >= 5 && !games.attack_press)
                {
                    hero_attack_1_index = 0;
                    games.is_attack = false;
                }
            }
            else
            {
                hero_attack_1_index = 0;
            }

            if (hero_attack_1_index == 0)
            {
                hero_attack_2_index = 0;
                hero_attack_3_index = 0;
            }
            break;
        }
    }
};

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
Intro intro;
void blinking_Cursour()
{
    intro.blinking_Cursour();
}
void black_Mask_Animation()
{
    intro.black_Mask_Animation();
}
void Load_Intro_Textures()
{
    intro.Load_Intro_Textures();
}

Waiting waiting;
void Load_waiting_page_texture()
{
    waiting.Load_waiting_page_texture();
}

Menu menu;
void Load_Menu_Textures()
{
    menu.Load_Menu_Textures();
}
void Load_Menu_Buttons()
{
    menu.Load_Menu_Buttons();
}

void Menu_background_texture_Animation()
{
    menu.Menu_background_texture_Animation();
}
void Loading_Sound_Texture()
{
    menu.Loading_Sound_Texture();
}

Hero hero;
void Hero_Standing_Animation()                                                                                              //Staning_timer_animation
{
    hero.Hero_Standing_Animation();
}

struct Enemy
{
    int enemy_texture_load_index,boss_Icons[3];
    int enemy_baseball_approach_left[8],enemy_baseball_approach_right[8],enemy_baseball_attack_left[18],enemy_baseball_attack_right[18];
    int enemy_awk_approach_left[12],enemy_awk_approach_right[12],enemy_awk_attack_left[8],enemy_awk_attack_right[8];
    int boss_razor_approach_left[38],boss_razor_approach_right[38],boss_razor_attack_left[49],boss_razor_attack_right[49];
    int enemy_aws_approach_left[16],enemy_aws_approach_right[16],enemy_aws_attack_left[14],enemy_aws_attack_right[14];
    int enemy_fatRunner_red_left[15],enemy_fatRunner_red_right[15],enemy_fatRunner_pink_left[15],enemy_fatRunner_pink_right[15];
    int boss_dr_approach_left[25],boss_dr_approach_right[25],boss_dr_attack_left[49],boss_dr_attack_right[49];
    int boss_dr_attack_Loop_left[9],boss_dr_attack_Loop_right[9];
    Enemy()
    {
        enemy_texture_load_index = 0;
    }

    void Load_Enemy_Textures()                                                                                                     //Loading_textures
    {
        char path[170];
        if(!enemy_texture_load_index)
        {
            boss_Icons[0] = iLoadImage("resources\\game_texture\\enemy\\Boss_Razor\\razor_er_khoma.png");
            boss_Icons[1] = iLoadImage("resources\\game_texture\\enemy\\DR\\Dr_er_khoma.png");
        }

        if(enemy_texture_load_index < 8)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Baseball bat\\Approaching\\Left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_baseball_approach_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Baseball bat\\Approaching\\Right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_baseball_approach_right[enemy_texture_load_index] = iLoadImage(path);

            sprintf_s(path, "resources\\game_texture\\enemy\\Army with knife\\Attacking\\left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_awk_attack_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with knife\\Attacking\\right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_awk_attack_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 9)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\DR\\Loop attack\\left\\left (%d).png",enemy_texture_load_index + 1);
            boss_dr_attack_Loop_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\DR\\Loop attack\\right\\right (%d).png",enemy_texture_load_index + 1);
            boss_dr_attack_Loop_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 12)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with knife\\Approaching\\left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_awk_approach_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with knife\\Approaching\\right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_awk_approach_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 14)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with sword\\Attacking\\Left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_aws_attack_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with sword\\Attacking\\Right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_aws_attack_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 15)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Fat Runner\\Type-1\\left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_fatRunner_red_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Fat Runner\\Type-1\\right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_fatRunner_red_right[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Fat Runner\\Type-2\\left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_fatRunner_pink_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Fat Runner\\Type-2\\right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_fatRunner_pink_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 16)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with sword\\Approaching\\Left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_aws_approach_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Army with sword\\Approaching\\Right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_aws_approach_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 18)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Baseball bat\\Attacking\\Left\\left (%d).png",enemy_texture_load_index + 1);
            enemy_baseball_attack_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Baseball bat\\Attacking\\Right\\right (%d).png",enemy_texture_load_index + 1);
            enemy_baseball_attack_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 25)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\DR\\Approaching\\left\\left (%d).png",enemy_texture_load_index + 1);
            boss_dr_approach_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\DR\\Approaching\\right\\right (%d).png",enemy_texture_load_index + 1);
            boss_dr_approach_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 38)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Boss_Razor\\Approaching\\Left\\left (%d).png",enemy_texture_load_index + 1);
            boss_razor_approach_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Boss_Razor\\Approaching\\Right\\right (%d).png",enemy_texture_load_index + 1);
            boss_razor_approach_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 49)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\Boss_Razor\\First attack\\Left\\left (%d).png",enemy_texture_load_index + 1);
            boss_razor_attack_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\Boss_Razor\\First attack\\Right\\right (%d).png",enemy_texture_load_index + 1);
            boss_razor_attack_right[enemy_texture_load_index] = iLoadImage(path);
        }
        if(enemy_texture_load_index < 66)
        {
            sprintf_s(path, "resources\\game_texture\\enemy\\DR\\Attack\\left\\left (%d).png",enemy_texture_load_index + 1);
            boss_dr_attack_left[enemy_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\enemy\\DR\\Attack\\right\\right (%d).png",enemy_texture_load_index + 1);
            boss_dr_attack_right[enemy_texture_load_index] = iLoadImage(path);
        }
        enemy_texture_load_index++;
    }

};
Enemy enemy;

struct Enemy_Baseball
{
    int enemy_approach_index,enemy_attack_index;
    double enemy_Position_X;
    static int index;
    int enemy_health;
    Enemy_Baseball()
    {
        /*enemy_health = 30;
        enemy_attack_index = 0;
        enemy_approach_index = 0;
        enemy_Position_X = 1600;*/
    }
    void Enemy_Life_Bar()
    {
        if(enemy_health > 0)
        {
            glLineWidth(1);
            iSetColor(255,255,255);
            iRectangle(enemy_Position_X + 65,460,32,12);
            iSetColor(164,198,57);
            iFilledRectangle(enemy_Position_X + 66,461,enemy_health,10);
        }

    }

    void Enemy_Attacked_By_Hero(bool isHeroNear)
    {
        if(games.is_attack && isHeroNear)
        {
            switch(games.key)
            {
            case 2:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X += 150;
                        enemy_health -= 15;

                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 160 && hero.hero_Position_X - 5 <= enemy_Position_X + 160 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X -= 150;
                        enemy_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 160 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        if(hero.Hero_Direction == 1)
                        {
                            enemy_Position_X -= 150;
                        }
                        else
                        {
                            enemy_Position_X += 150;
                        }
                        enemy_health -= 15;

                    }
                }
                break;
            case 3:
                if(enemy_Position_X >= 0 && enemy_Position_X <= 1520 && hero.hero_attack_3_index == 7)
                {
                    if(hero.hero_Position_X <= enemy_Position_X  && hero.Hero_Direction == 0)
                    {
                        enemy_health -= 10;
                        enemy_Position_X += 150;
                    }

                    if(hero.hero_Position_X > enemy_Position_X  && hero.Hero_Direction == 1)
                    {
                        enemy_health -= 10;
                        enemy_Position_X -= 150;
                    }
                }
                break;

            default:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 160 && hero.hero_Position_X - 5 <= enemy_Position_X + 160 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 160 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
            }
        }
    }

    void Enemy_Attack()
    {
        if(enemy_health > 0)
        {
            if(hero.hero_Position_X + 140 < enemy_Position_X)
            {
                iShowImage(enemy_Position_X,210,Default_window_width/9.5,Default_window_height/3.5, enemy.enemy_baseball_approach_left[enemy_approach_index]);
                if(enemy_approach_index < 7)
                {
                    enemy_approach_index++;
                }
                else
                {
                    enemy_approach_index = 0;
                }

                enemy_Position_X -= 10;
            }
            else if(hero.hero_Position_X - 170 > enemy_Position_X)
            {
                iShowImage(enemy_Position_X,210,Default_window_width/9.5,Default_window_height/3.5, enemy.enemy_baseball_approach_right[enemy_approach_index]);
                if(enemy_approach_index < 7)
                {
                    enemy_approach_index++;
                }
                else
                {
                    enemy_approach_index = 0;
                }

                enemy_Position_X += 10;
            }
            else
            {
                enemy_approach_index = 0;
                if(hero.hero_Position_X  < enemy_Position_X + 80)
                {
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_baseball_attack_left[enemy_attack_index++]);

                }
                else
                {
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_baseball_attack_right[enemy_attack_index++]);

                }
                if(enemy_attack_index == 18)
                {
                    enemy_attack_index = 0;
                    if(hero.hero_Position_Y <= 270 && !games.is_Dodge)
                    {
                        if(hero.hero_health > 0)
                        {
                            hero.hero_health -= 5;
                        }
                        if(hero.hero_Position_X <= 1320 && hero.hero_Position_X >= 0)
                        {
                            if(hero.hero_Position_X + 80 < enemy_Position_X + 80)
                            {
                                hero.hero_Position_X -= 70;
                            }
                            else
                            {
                                hero.hero_Position_X += 70;
                            }
                        }
                    }
                }
            }
        }
    }
};
int Enemy_Baseball::index = 0;
Enemy_Baseball enemy_baseball[8];

struct Enemy_AWK
{
    int enemy_approach_index,enemy_attack_index;
    double enemy_Position_X;
    static int index;
    int enemy_health;
    Enemy_AWK()
    {
        /*enemy_health = 40;
        enemy_attack_index = 0;
        enemy_approach_index = 0;
        enemy_Position_X = 1600;*/
    }
    void Enemy_Life_Bar()
    {
        if(enemy_health > 0)
        {
            glLineWidth(1);
            iSetColor(255,255,255);
            iRectangle(enemy_Position_X + 60,460,42,12);
            iSetColor(164,198,57);
            iFilledRectangle(enemy_Position_X + 61,461,enemy_health,10);
        }
    }
    void Enemy_Attacked_By_Hero()
    {
        if(games.is_attack)
        {
            switch(games.key)
            {
            case 2:
                if(hero.hero_Position_X + 80 <= enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X += 150;
                        enemy_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 >= enemy_Position_X + 160 && hero.hero_Position_X - 5 <= enemy_Position_X + 160 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X -= 150;
                        enemy_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 160 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        if(hero.Hero_Direction == 1)
                        {
                            enemy_Position_X -= 150;
                        }
                        else
                        {
                            enemy_Position_X += 150;
                        }
                        enemy_health -= 15;
                    }
                }
                /*else if(enemy_Position_X <= hero.hero_Position_X + 80 && enemy_Position_X >= hero.hero_Position_X - 5)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        if(hero.Hero_Direction == 1)
                        {
                            enemy_Position_X -= 150;
                        }
                        else
                        {
                            enemy_Position_X += 150;
                        }
                        enemy_health -= 15;
                    }
                }
                else if(enemy_Position_X + 160 >= hero.hero_Position_X + 80 && enemy_Position_X + 160 <= hero.hero_Position_X + 165)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        if(hero.Hero_Direction == 1)
                        {
                            enemy_Position_X -= 150;
                        }
                        else
                        {
                            enemy_Position_X += 150;
                        }
                        enemy_health -= 15;
                    }
                }*/
                break;
            case 3:
                if(enemy_Position_X >= 0 && enemy_Position_X <= 1520 && hero.hero_attack_3_index == 7)
                {
                    if(hero.hero_Position_X <= enemy_Position_X  && hero.Hero_Direction == 0)
                    {
                        enemy_health -= 10;
                        enemy_Position_X += 150;
                    }

                    if(hero.hero_Position_X > enemy_Position_X  && hero.Hero_Direction == 1)
                    {
                        enemy_health -= 10;
                        enemy_Position_X -= 150;
                    }
                }
                break;

            default:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 160 && hero.hero_Position_X - 5 <= enemy_Position_X + 160 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(enemy_Position_X <= hero.hero_Position_X + 80 && enemy_Position_X >= hero.hero_Position_X - 5)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 160 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
            }
        }
    }

    void Enemy_Attack()
    {
        if(enemy_health > 0)
        {
            if(hero.hero_Position_X + 140 < enemy_Position_X)
            {
                iShowImage(enemy_Position_X,210,Default_window_width/9.5,Default_window_height/3.5, enemy.enemy_awk_approach_left[enemy_approach_index]);
                if(enemy_approach_index < 11)
                {
                    enemy_approach_index++;
                }
                else
                {
                    enemy_approach_index = 0;
                }

                enemy_Position_X -= 10;
            }
            else if(hero.hero_Position_X - 170 > enemy_Position_X)
            {
                iShowImage(enemy_Position_X,210,Default_window_width/9.5,Default_window_height/3.5, enemy.enemy_awk_approach_right[enemy_approach_index]);
                if(enemy_approach_index < 11)
                {
                    enemy_approach_index++;
                }
                else
                {
                    enemy_approach_index = 0;
                }

                enemy_Position_X += 10;
            }
            else
            {
                enemy_approach_index = 0;
                if(hero.hero_Position_X  < enemy_Position_X)
                {
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_awk_attack_left[enemy_attack_index++]);
                }
                else
                {
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_awk_attack_right[enemy_attack_index++]);
                }
                if(enemy_attack_index == 8)
                {
                    enemy_attack_index = 0;
                    if(hero.hero_Position_Y <= 270 && !games.is_Dodge)
                    {
                        if(hero.hero_health > 0)
                        {
                            hero.hero_health -= 5;
                        }
                        if(hero.hero_Position_X <= 1320 && hero.hero_Position_X >= 0)
                        {
                            if(hero.hero_Position_X + 80  < enemy_Position_X + 80)
                            {
                                hero.hero_Position_X -= 70;
                            }
                            else
                            {
                                hero.hero_Position_X += 70;
                            }
                        }
                    }
                }
            }
        }
    }
};
int Enemy_AWK::index = 0;
Enemy_AWK enemy_awk[8];

struct Enemy_AWS
{
    int enemy_approach_index,enemy_attack_index;
    double enemy_Position_X;
    static int index;
    int enemy_health;
    Enemy_AWS()
    {
        /*enemy_health = 30;
        enemy_attack_index = 0;
        enemy_approach_index = 0;
        enemy_Position_X = 1600;*/
    }
    void Enemy_Life_Bar()
    {
        if(enemy_health > 0)
        {
            glLineWidth(1);
            iSetColor(255,255,255);
            iRectangle(enemy_Position_X + 55,460,52,12);
            iSetColor(164,198,57);
            iFilledRectangle(enemy_Position_X + 56,461,enemy_health,10);
        }

    }

    void Enemy_Attacked_By_Hero()
    {
        if(games.is_attack)
        {
            switch(games.key)
            {
            case 2:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X += 150;
                        enemy_health -= 15;

                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 217 && hero.hero_Position_X - 5 <= enemy_Position_X + 217 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X -= 150;
                        enemy_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 217 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        if(hero.Hero_Direction == 1)
                        {
                            enemy_Position_X -= 150;
                        }
                        else
                        {
                            enemy_Position_X += 150;
                        }
                        enemy_health -= 15;

                    }
                }
                break;
            case 3:
                if(enemy_Position_X >= 0 && enemy_Position_X <= 1520 && hero.hero_attack_3_index == 7)
                {
                    if(hero.hero_Position_X <= enemy_Position_X  && hero.Hero_Direction == 0)
                    {
                        enemy_health -= 10;
                        enemy_Position_X += 150;
                    }

                    if(hero.hero_Position_X > enemy_Position_X  && hero.Hero_Direction == 1)
                    {
                        enemy_health -= 10;
                        enemy_Position_X -= 150;
                    }
                }
                break;

            default:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 217 && hero.hero_Position_X - 5 <= enemy_Position_X + 217 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 217 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
            }
        }
    }

    void Enemy_Attack()
    {
        if(enemy_health > 0)
        {
            if(hero.hero_Position_X + 140 < enemy_Position_X)
            {
                iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_aws_approach_left[enemy_approach_index++]);
                if(enemy_approach_index == 16)
                {
                    enemy_approach_index = 0;
                }

                enemy_Position_X -= 10;
            }
            else if(hero.hero_Position_X - 170 > enemy_Position_X)
            {
                iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_aws_approach_right[enemy_approach_index++]);
                if(enemy_approach_index == 16)
                {
                    enemy_approach_index = 0;
                }

                enemy_Position_X += 10;
            }
            else
            {
                enemy_approach_index = 0;
                if(hero.hero_Position_X  < enemy_Position_X + 80)
                {
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_aws_attack_left[enemy_attack_index++]);

                }
                else
                {
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_aws_attack_right[enemy_attack_index++]);

                }
                if(enemy_attack_index == 14)
                {
                    enemy_attack_index = 0;
                    if(hero.hero_Position_Y <= 270 && !games.is_Dodge)
                    {
                        if(hero.hero_health > 0)
                        {
                            hero.hero_health -= 7;
                        }
                        if(hero.hero_Position_X <= 1320 && hero.hero_Position_X >= 0)
                        {
                            if(hero.hero_Position_X + 80 < enemy_Position_X + 108.6)
                            {
                                hero.hero_Position_X -= 70;
                            }
                            else
                            {
                                hero.hero_Position_X += 70;
                            }
                        }
                    }
                }
            }
        }
    }
};
int Enemy_AWS::index = 0;
Enemy_AWS enemy_aws[8];

struct Enemy_Fat
{
    int enemy_approach_index,enemy_attack_index;
    double enemy_Position_X,enemy_Position_Direction;
    static int index;
    int enemy_health,enemy_type;
    Enemy_Fat()
    {
        /*enemy_health = 30;
        enemy_attack_index = 0;
        enemy_approach_index = 0;
        enemy_Position_X = 1600;*/
    }
    void Enemy_Life_Bar()
    {
        if(enemy_health > 0)
        {
            glLineWidth(1);
            iSetColor(255,255,255);
            iRectangle(enemy_Position_X + 55,500,52,12);
            iSetColor(164,198,57);
            iFilledRectangle(enemy_Position_X + 56,501,enemy_health,10);
        }

    }

    void Enemy_Attacked_By_Hero()
    {
        if(games.is_attack)
        {
            switch(games.key)
            {
            case 2:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X += 150;
                        enemy_health -= 15;

                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 217 && hero.hero_Position_X - 5 <= enemy_Position_X + 217 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        enemy_Position_X -= 150;
                        enemy_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 217 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        if(hero.Hero_Direction == 1)
                        {
                            enemy_Position_X -= 150;
                        }
                        else
                        {
                            enemy_Position_X += 150;
                        }
                        enemy_health -= 15;

                    }
                }
                break;
            case 3:
                if(enemy_Position_X >= 0 && enemy_Position_X <= 1520 && hero.hero_attack_3_index == 7)
                {
                    if(hero.hero_Position_X <= enemy_Position_X  && hero.Hero_Direction == 0)
                    {
                        enemy_health -= 10;
                        enemy_Position_X += 150;
                    }

                    if(hero.hero_Position_X > enemy_Position_X  && hero.Hero_Direction == 1)
                    {
                        enemy_health -= 10;
                        enemy_Position_X -= 150;
                    }
                }
                break;

            default:
                if(hero.hero_Position_X + 80 < enemy_Position_X && hero.hero_Position_X + 165 >= enemy_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 > enemy_Position_X + 217 && hero.hero_Position_X - 5 <= enemy_Position_X + 217 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 < enemy_Position_X + 217 && hero.hero_Position_X + 80 > enemy_Position_X)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        enemy_health -= 5;
                    }
                }
            }
        }
    }

    void Enemy_Attack()
    {
        if(!enemy_type)
        {
            enemy_type = (rand()%2) + 1;
        }

        if(enemy_health > 0)
        {
            if(enemy_Position_X >= 1302)
            {
                enemy_Position_Direction = -20;
            }

            if(enemy_Position_X <= 0)
            {
                enemy_Position_Direction = 20;
            }

            if( enemy_Position_Direction > 0)
            {
                switch(enemy_type)
                {
                case 1:
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_fatRunner_red_right[enemy_approach_index++]);
                    break;
                default:
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_fatRunner_pink_right[enemy_approach_index++]);
                }
                if(enemy_approach_index == 15)
                {
                    enemy_approach_index = 0;
                }
                enemy_Position_X +=  enemy_Position_Direction;
            }
            else
            {
                switch(enemy_type)
                {
                case 1:
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_fatRunner_red_left[enemy_approach_index++]);
                    break;
                default:
                    iShowImage(enemy_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.enemy_fatRunner_pink_left[enemy_approach_index++]);
                }
                if(enemy_approach_index == 15)
                {
                    enemy_approach_index = 0;
                }
                enemy_Position_X +=  enemy_Position_Direction;
            }

            if(enemy_Position_X >= hero.hero_Position_X && enemy_Position_X <= hero.hero_Position_X + 160 && hero.hero_Position_Y <= 270 && !games.is_Dodge)
            {
                hero.hero_health -= 0.3;
            }
        }
    }
};
int Enemy_Fat::index = 0;
Enemy_Fat enemy_fat[8];

struct Boss_Razor
{
    int boss_approach_index,boss_attack_index;
    double boss_Position_X;
    int boss_health;

    Boss_Razor()
    {
        /*boss_health = 100;
        boss_approach_index = 0;
        boss_attack_index = 0;
        boss_Position_X = 1600;*/
    }

    void Boss_Attacked_By_Hero()
    {
        if(games.is_attack)
        {
            switch(games.key)
            {
            case 2:
                if(hero.hero_Position_X + 80 <= boss_Position_X && hero.hero_Position_X + 165 >= boss_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        boss_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 >= boss_Position_X + 325 && hero.hero_Position_X - 5 <= boss_Position_X + 325 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        boss_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 < boss_Position_X + 325 && hero.hero_Position_X + 80 > boss_Position_X)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        boss_health -= 15;
                    }
                }
                break;
            case 3:
                if(boss_Position_X >= 0 && boss_Position_X <= 1520 && hero.hero_attack_3_index == 7)
                {
                    if(hero.hero_Position_X <= boss_Position_X  && hero.Hero_Direction == 0)
                    {
                        boss_health -= 10;
                        boss_Position_X += 70;
                    }

                    if(hero.hero_Position_X > boss_Position_X  && hero.Hero_Direction == 1)
                    {
                        boss_health -= 10;
                        boss_Position_X -= 70;
                    }
                }
                break;

            default:
                if(hero.hero_Position_X + 80 <= boss_Position_X && hero.hero_Position_X + 165 >= boss_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        boss_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 >= boss_Position_X + 160 && hero.hero_Position_X - 5 <= boss_Position_X + 160 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        boss_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 < boss_Position_X + 160 && hero.hero_Position_X + 80 > boss_Position_X)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        boss_health -= 5;
                    }
                }
            }
        }
    }

    void Boss_Attack()
    {
        if(boss_health > 0)
        {
            if(hero.hero_Position_X + 110 < boss_Position_X)
            {
                iShowImage(boss_Position_X,210,640,800, enemy.boss_razor_approach_left[boss_approach_index]);
                if(boss_approach_index < 37)
                {
                    boss_approach_index++;
                }
                else
                {
                    boss_approach_index = 0;
                }

                boss_Position_X -= 15;
            }
            else if(hero.hero_Position_X - 530 > boss_Position_X)
            {
                iShowImage(boss_Position_X,210,640,800, enemy.boss_razor_approach_right[boss_approach_index]);
                if(boss_approach_index < 37)
                {
                    boss_approach_index++;
                }
                else
                {
                    boss_approach_index = 0;
                }

                boss_Position_X += 15;
            }
            else
            {
                boss_approach_index = 0;
                if(hero.hero_Position_X + 80 < boss_Position_X + 320)
                {
                    iShowImage(boss_Position_X,210,720,900, enemy.boss_razor_attack_left[boss_attack_index]);
                }
                else
                {
                    iShowImage(boss_Position_X,210,720,900, enemy.boss_razor_attack_right[boss_attack_index]);
                }
                if(boss_attack_index < 48)
                {
                    boss_attack_index++;
                }
                else
                {
                    boss_attack_index = 0;
                }

                if(boss_attack_index == 20)
                {
                    if(hero.hero_health > 0 && !games.is_Dodge)
                    {
                        hero.hero_health -= 15;
                    }
                }
            }
        }
    }
};
Boss_Razor razor;

struct Boss_DR
{
    int boss_approach_index,boss_attack_index,boss_attack_loop_index;
    double boss_Position_X;
    int boss_health;
    int isLoop,timer;

    Boss_DR()
    {
        /*boss_health = 100;
        boss_approach_index = 0;
        boss_attack_index = 0;
        boss_Position_X = 1600;*/
    }

    void Boss_Attacked_By_Hero()
    {
        if(games.is_attack && boss_health > 0)
        {
            switch(games.key)
            {
            case 2:
                if(hero.hero_Position_X + 80 < boss_Position_X && hero.hero_Position_X + 165 >= boss_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        boss_Position_X += 150;
                        boss_health -= 15;

                    }
                }
                else if(hero.hero_Position_X + 80 > boss_Position_X + 217 && hero.hero_Position_X - 5 <= boss_Position_X + 217 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        boss_Position_X -= 150;
                        boss_health -= 15;
                    }
                }
                else if(hero.hero_Position_X + 80 < boss_Position_X + 217 && hero.hero_Position_X + 80 > boss_Position_X)
                {
                    if(hero.hero_attack_2_index == 11 || hero.hero_attack_2_index == 24)
                    {
                        mciSendString("stop Chainsaw_Sound", NULL, 0, NULL);
                        mciSendString("play Chainsaw_Hit_Sound from 0", NULL, 0, NULL);
                        if(hero.Hero_Direction == 1)
                        {
                            boss_Position_X -= 150;
                        }
                        else
                        {
                            boss_Position_X += 150;
                        }
                        boss_health -= 15;

                    }
                }
                break;
            case 3:
                if(boss_Position_X >= 0 && boss_Position_X <= 1520 && hero.hero_attack_3_index == 7)
                {
                    if(hero.hero_Position_X <= boss_Position_X  && hero.Hero_Direction == 0)
                    {
                        boss_health -= 10;
                        boss_Position_X += 150;
                    }

                    if(hero.hero_Position_X > boss_Position_X  && hero.Hero_Direction == 1)
                    {
                        boss_health -= 10;
                        boss_Position_X -= 150;
                    }
                }
                break;

            default:
                if(hero.hero_Position_X + 80 < boss_Position_X && hero.hero_Position_X + 165 >= boss_Position_X && hero.Hero_Direction == 0)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        boss_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 > boss_Position_X + 217 && hero.hero_Position_X - 5 <= boss_Position_X + 217 && hero.Hero_Direction == 1)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        boss_health -= 5;
                    }
                }
                else if(hero.hero_Position_X + 80 < boss_Position_X + 217 && hero.hero_Position_X + 80 > boss_Position_X)
                {
                    if(hero.hero_attack_1_index == 5 || hero.hero_attack_1_index == 10 || hero.hero_attack_1_index == 17 || hero.hero_attack_1_index == 22)
                    {
                        boss_health -= 5;
                    }
                }
            }
        }
    }

    void Boss_Attack()
    {
        if(boss_health > 0)
        {
            iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_attack_Loop_left[0]);
                    boss_Position_X -= 20;
            /*if(isLoop%2)
            {
                boss_approach_index = 0;
                boss_attack_index = 0;
                if(boss_Position_X > hero.hero_Position_X)
                {
                    iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_attack_Loop_left[boss_attack_loop_index]);
                    boss_Position_X -= 20;
                }
                else
                {
                    iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_attack_Loop_right[boss_attack_loop_index]);
                    boss_Position_X += 20;
                }

                if(boss_Position_X >= hero.hero_Position_X && boss_Position_X <= hero.hero_Position_X + 160 && hero.hero_Position_Y <= 270 && !games.is_Dodge)
                {
                    hero.hero_health -= 1;
                }
                boss_attack_loop_index++;
                if(boss_attack_loop_index == 9)
                {
                    boss_attack_loop_index = 0;
                    timer++;
                }

                if(timer == 5)
                {
                    timer = 0;
                    isLoop++;
                }
            }
            else
            {
                boss_attack_loop_index = 0;
                if(boss_health <= 150 && isLoop == 0)
                {
                    isLoop = 1;
                }
                else if(boss_health <= 100 && isLoop == 2)
                {
                    isLoop = 3;
                }
                else if(boss_health <= 70 && isLoop == 4)
                {
                    isLoop = 5;
                }
                else if(boss_health <= 30 && isLoop == 6)
                {
                    isLoop = 7;
                }

                if(hero.hero_Position_X + 140 < boss_Position_X)
                {
                    iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_approach_left[boss_approach_index]);
                    if(boss_approach_index < 24)
                    {
                        boss_approach_index++;
                    }
                    else
                    {
                        boss_approach_index = 0;
                    }

                    boss_Position_X -= 15;
                }
                else if(hero.hero_Position_X - 170 > boss_Position_X)
                {
                    iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_approach_right[boss_approach_index]);
                    if(boss_approach_index < 24)
                    {
                        boss_approach_index++;
                    }
                    else
                    {
                        boss_approach_index = 0;
                    }

                    boss_Position_X += 15;
                }
                else
                {
                    if(hero.hero_Position_X + 80 < boss_Position_X + 80)
                    {
                        iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_attack_left[boss_attack_index]);
                    }
                    else
                    {
                        iShowImage(boss_Position_X,210,Default_window_width/7,Default_window_height/2.5, enemy.boss_dr_attack_right[boss_attack_index]);
                    }

                    if(boss_attack_index < 65)
                    {
                        boss_attack_index++;
                    }
                    else
                    {
                        boss_attack_index = 0;
                    }

                    if(boss_attack_index == 20)
                    {
                        if(hero.hero_health > 0 && !games.is_Dodge)
                        {
                            hero.hero_health -= 15;
                        }
                    }
                }
            }*/
        }
    }

};
Boss_DR boss_dr;

void game_initialize()
{
    games.wave_texture_timer_index = 0;
    Enemy_Baseball::index = 0;
    Enemy_AWK::index = 0;
    Enemy_AWS::index = 0;
    Enemy_Fat::index = 0;
    games.wav_1_first_init = 0;
    games.wav_2_first_init = 0;
    games.wav_3_first_init = 0;
    hero.hero_health = 200;
    games.wave = 3;

    for(auto &i : enemy_baseball)
    {
        i.enemy_health = 30;
        i.enemy_attack_index = 0;
        i.enemy_approach_index = 0;
        i.enemy_Position_X = 1600;
    }
    for(auto &i : enemy_awk)
    {
        i.enemy_health = 40;
        i.enemy_attack_index = 0;
        i.enemy_approach_index = 0;
        i.enemy_Position_X = 1600;
    }
    for(auto &i : enemy_aws)
    {
        i.enemy_health = 50;
        i.enemy_attack_index = 0;
        i.enemy_approach_index = 0;
        i.enemy_Position_X = 1600;
    }
    for(auto &i : enemy_fat)
    {
        i.enemy_health = 50;
        i.enemy_attack_index = 0;
        i.enemy_approach_index = 0;
        i.enemy_Position_X = 1600;
        i.enemy_type = 0;
        i.enemy_Position_Direction = -30;
    }
}

void game_initialize_new_start()
{
    games.key = 1;
    hero.hero_Position_X = 460;
    game_initialize();
}
void iDraw()
{
    iClear();

    if(!games.Page)                                                                                                                     //Intro_Page
    {
        iSetColor(0, 0, 0);
        /*if(text_blackmask_X >= 1420)
        {
            //iShowImage(20, Default_window_height/2,200, 200, intro_background_texture[2]);
            iShowImage(1320, 200,200, 200, intro_background_texture[2]);
            //iShowImage(Default_window_width/2 - 50, Default_window_height/2 - 100,200 , 200, intro_background_texture[2]);
        }*/
        iShowImage(0, 0, Default_window_width, Default_window_height, intro.intro_background_texture[0]);

        if(!intro.blinking_Cursour_Show)
        {
            //BLACK_MASK
            iSetColor(0, 0, 0);
            iFilledRectangle(intro.text_blackmask_X, Default_window_height / 2.3, 1920 - intro.text_blackmask_X, 105);
            //BLINKING_CURSOUR

            iSetColor(intro.blinking_Cursour_Color[0], intro.blinking_Cursour_Color[1], intro.blinking_Cursour_Color[2]);
            iFilledRectangle(intro.text_blackmask_X,Default_window_height / 2.3, 20, 105);
        }

        if(intro.text_blackmask_X >= 1420 && !intro.blinking_Cursour_Show)
        {
            intro.blinking_Cursour_Show = 1;
        }

        if(intro.text_blackmask_X >= 1420)
        {

            mciSendString("play Intro_Sound", NULL, 0, NULL);
            iShowImage(0, 0, Default_window_width, Default_window_height, intro.intro_background_texture[1]);
        }

        if(intro.text_blackmask_X >= 1700)
        {
            iPauseTimer(intro.blackmask_Move_Animation);
            games.Page = 3;
            Loading_Sound_Texture();
            menu.Menu_Textures_Load = iSetTimer(300, Load_Menu_Textures);
            mciSendString("play bgsong repeat", NULL, 0, NULL);
        }
    }
    else if(games.Page == 1)                                                                                                 //Waiting_Page
    {
        iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
        iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[1]);
        if(menu.menu_Texture_Load_index <= 66)
        {
            iSetColor(255,255,255);
            iRectangle(200,100,1120,30);
            iFilledRectangle(205,105,(((menu.menu_Texture_Load_index < 64)? menu.menu_Texture_Load_index:63)*1110)/63,20);
        }
        else
        {
            iPauseTimer(menu.Menu_Textures_Load);
            iShowImage((Default_window_width/2) - 150,300,300,101, waiting.Waiting_Page_Textures[waiting.Tap_To_Continue_Index]);
        }

    }
    else if(games.Page == 2)                                                                                                   //Menu_Page
    {
        iShowImage(0, 0, Default_window_width, Default_window_height, menu.Menu_background_texture[menu.Menu_background_texture_index]);
        iShowImage(0, 0, Default_window_width, Default_window_height, menu.Menu_Title);
        iShowImage(1100, 400, 200,67,menu.Menu_Buttons[menu.Play_Index]);
        iShowImage(1100, 320, 200,67,menu.Menu_Buttons[menu.Credits_Index]);
        iShowImage(1100, 240, 200,67,menu.Menu_Buttons[menu.Help_Index]);
        iShowImage(1100, 160, 200,67,menu.Menu_Buttons[menu.Sound_Index]);
        iShowImage(1320, 170, 60,60,menu.SOUND_ICON_Texture[menu.SOUND_ICON_Index]);
        iShowImage(1100, 80, 200,67,menu.Menu_Buttons[menu.Exit_Index]);

        if(games.exit_press)
        {
            iShowImage(360,213.75,800,427.5, waiting.Waiting_Page_Textures[0]);
            iShowImage(360,213.75,800,427.5, games.exit_text);
            iShowImage(410,250,200,67,games.exit_yes[games.exit_yes_index]);
            iShowImage(910,250,200,67,games.exit_no[games.exit_no_index]);
        }
    }
    else if(games.Page == 3)
    {
        iDelayMS(60);
        //Level

        if(games.Level == 0)
        {
            iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
            iShowImage(games.Back_button_X,games.Back_button_Y,games.Back_button_Width,games.Back_button_Height, games.Back_Button);
            glLineWidth(5);
            iSetColor(255, 255, 255);
            //games.wave_texture_timer_index = 0;
            iShowImage(games.Level_Select_X[0],games.Level_Select_Y[0], games.Level_Select_Width[0],games.Level_Select_Height[0],games.Level_1_Icons[games.Level_1_Icons_index]);
            iRectangle(games.Level_Select_X[0],games.Level_Select_Y[0], games.Level_Select_Width[0],games.Level_Select_Height[0]);
            iText(260,250,"Level 1",GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(games.Level_Select_X[1],games.Level_Select_Y[1],games.Level_Select_Width[1],games.Level_Select_Height[1]);
            //iRectangle(Level_Select_X[2],Level_Select_Y[2], Level_Select_Width[2],Level_Select_Height[2]);
        }
        else if(games.Level == 1)
        {
            if(enemy.enemy_texture_load_index < 68)
            {
                glLineWidth(1);
                iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
                iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[1]);
                iSetColor(255,255,255);
                iRectangle(200,100,1120,30);
                hero.Load_Hero_Textures();
                enemy.Load_Enemy_Textures();
                games.Load_game_over_textures();
                iFilledRectangle(205,105,(((enemy.enemy_texture_load_index < 67)? hero.hero_texture_load_index:66)*1110)/66,20);
            }
            else
            {
                if(hero.hero_health <= 0)
                {
                    games.Level = 4;
                }
                iShowImage(0,0,1520,855,games.bg_image_1);
                glLineWidth(1);
                iShowImage(0,705,150,150,hero.hero_head);
                iResumeTimer(hero.Hero_Animation_Standing);
                iSetColor(255,255,255);
                iRectangle(135,765,202,25);
                iSetColor(144,42,18);
                iFilledRectangle(136,766,hero.hero_health,23);
                hero.Hero_Attack();
                hero.Hero_Moves();

                if(games.wave == 1)
                {
                    if(games.wave_texture_timer_index < 20)
                    {
                        iShowImage(0,0,Default_window_width,Default_window_height,games.wave_textures[0]);
                        games.wave_texture_timer_index++;
                    }
                    enemy_baseball[Enemy_Baseball::index].Enemy_Life_Bar();
                    enemy_baseball[Enemy_Baseball::index].Enemy_Attack();
                    enemy_baseball[Enemy_Baseball::index].Enemy_Attacked_By_Hero(true);
                    if(enemy_baseball[Enemy_Baseball::index].enemy_health <= 0)
                    {
                        Enemy_Baseball::index++;
                    }

                    if(Enemy_Baseball::index == 3)
                    {
                        games.wave = 2;
                        games.wave_texture_timer_index = 0;
                    }
                }
                else if(games.wave == 2)
                {
                    if(games.wave_texture_timer_index < 20)
                    {
                        iShowImage(0,0,Default_window_width,Default_window_height,games.wave_textures[1]);
                        games.wave_texture_timer_index++;
                    }
                    if(Enemy_AWK::index%2 == Enemy_Baseball::index%2)
                    {
                        enemy_baseball[Enemy_Baseball::index].Enemy_Life_Bar();
                        enemy_baseball[Enemy_Baseball::index].Enemy_Attack();
                        enemy_baseball[Enemy_Baseball::index].Enemy_Attacked_By_Hero(true);
                        if(enemy_baseball[Enemy_Baseball::index].enemy_health <= 0)
                        {
                            Enemy_Baseball::index++;
                        }
                    }
                    else
                    {
                        enemy_awk[Enemy_AWK::index].Enemy_Life_Bar();
                        enemy_awk[Enemy_AWK::index].Enemy_Attack();
                        enemy_awk[Enemy_AWK::index].Enemy_Attacked_By_Hero();
                        if(enemy_awk[Enemy_AWK::index].enemy_health <= 0)
                        {
                            Enemy_AWK::index++;
                        }
                    }
                    if(Enemy_AWK::index == 3)
                    {
                        games.wave = 3;
                        games.wave_texture_timer_index = 0;
                    }
                }
                else
                {
                    if(games.wave_texture_timer_index < 20)
                    {
                        iShowImage(0,0,Default_window_width,Default_window_height,games.wave_textures[2]);
                        if(!games.wave_texture_timer_index++)
                        {
                            razor.boss_health = 200;
                            razor.boss_approach_index = 0;
                            razor.boss_attack_index = 0;
                            razor.boss_Position_X = 1600;
                            enemy_baseball[6].enemy_Position_X = -80;
                            enemy_awk[3].enemy_Position_X = -80;
                            enemy_awk[5].enemy_Position_X = -80;
                        }
                    }
                    if(Enemy_Baseball::index < 8 || Enemy_AWK::index < 6)
                    {
                        enemy_baseball[Enemy_Baseball::index].Enemy_Life_Bar();
                        enemy_baseball[Enemy_Baseball::index].Enemy_Attack();
                        enemy_baseball[Enemy_Baseball::index].Enemy_Attacked_By_Hero(true);

                        enemy_awk[Enemy_AWK::index].Enemy_Life_Bar();
                        enemy_awk[Enemy_AWK::index].Enemy_Attack();
                        enemy_awk[Enemy_AWK::index].Enemy_Attacked_By_Hero();
                        if (enemy_awk[Enemy_AWK::index].enemy_health <= 0 && enemy_baseball[Enemy_Baseball::index].enemy_health <= 0)
                        {
                            Enemy_AWK::index++;
                            Enemy_Baseball::index++;
                        }
                    }
                    else
                    {
                        iShowImage(1350,705,150,150,enemy.boss_Icons[0]);
                        iSetColor(255,255,255);
                        iRectangle(1150,765,202,25);
                        iSetColor(164,198,57);
                        iFilledRectangle(1151,766,razor.boss_health,23);
                        razor.Boss_Attack();
                        razor.Boss_Attacked_By_Hero();
                        if(razor.boss_health <= 0)
                        {
                            games.Level = 2;
                            games.wave = 3;
                            game_initialize();
                        }
                    }
                }
            }
        }
        else if(games.Level == 2)
        {

            if(enemy.enemy_texture_load_index < 68)
            {
                glLineWidth(1);
                iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
                iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[1]);
                iSetColor(255,255,255);
                iRectangle(200,100,1120,30);
                hero.Load_Hero_Textures();
                enemy.Load_Enemy_Textures();
                games.Load_game_over_textures();
                iFilledRectangle(205,105,(((enemy.enemy_texture_load_index < 67)? hero.hero_texture_load_index:66)*1110)/66,20);

            }
            else
            {
                if(hero.hero_health <= 0)
                {
                    games.Level = 4;
                }
                iShowImage(0,0,1520,855,games.bg_image_1);
                glLineWidth(1);
                iShowImage(0,705,150,150,hero.hero_head);
                iResumeTimer(hero.Hero_Animation_Standing);
                iSetColor(255,255,255);
                iRectangle(135,765,202,25);
                iSetColor(144,42,18);
                iFilledRectangle(136,766,hero.hero_health,23);
                hero.Hero_Attack();
                hero.Hero_Moves();

                if(games.wave == 1)
                {
                    if(games.wave_texture_timer_index < 20)
                    {
                        iShowImage(0,0,Default_window_width,Default_window_height,games.wave_textures[0]);
                        if(!games.wave_texture_timer_index++)
                        {
                            enemy_baseball[0].enemy_Position_X = -80;
                            enemy_awk[1].enemy_Position_X = -80;
                            enemy_aws[1].enemy_Position_X = -80;
                        }
                    }

                    if(Enemy_Baseball::index < 2 || Enemy_AWK::index < 2)
                    {
                        if (enemy_awk[Enemy_AWK::index].enemy_health > 0 && Enemy_AWK::index < 2)
                        {
                            enemy_awk[Enemy_AWK::index].Enemy_Life_Bar();
                            enemy_awk[Enemy_AWK::index].Enemy_Attack();
                            enemy_awk[Enemy_AWK::index].Enemy_Attacked_By_Hero();
                        }

                        if (enemy_awk[Enemy_AWK::index].enemy_health <= 0 && Enemy_AWK::index < 2)
                        {
                            Enemy_AWK::index++;
                        }

                        if(enemy_baseball[Enemy_Baseball::index].enemy_health > 0 && Enemy_Baseball::index < 2)
                        {
                            enemy_baseball[Enemy_Baseball::index].Enemy_Life_Bar();
                            enemy_baseball[Enemy_Baseball::index].Enemy_Attack();
                            enemy_baseball[Enemy_Baseball::index].Enemy_Attacked_By_Hero(true);
                        }

                        if(enemy_baseball[Enemy_Baseball::index].enemy_health <= 0 && Enemy_Baseball::index < 2)
                        {
                            Enemy_Baseball::index++;
                        }

                    }
                    else
                    {
                        enemy_aws[Enemy_AWS::index].Enemy_Life_Bar();
                        enemy_aws[Enemy_AWS::index].Enemy_Attack();
                        enemy_aws[Enemy_AWS::index].Enemy_Attacked_By_Hero();
                        if(enemy_aws[Enemy_AWS::index].enemy_health <= 0)
                        {
                            Enemy_AWS::index++;
                        }

                        if(Enemy_AWS::index == 3)
                        {
                            games.wave = 2;
                            games.wave_texture_timer_index = 0;
                        }
                    }
                }
                else if(games.wave == 2)
                {
                    if(games.wave_texture_timer_index < 20)
                    {
                        iShowImage(0,0,Default_window_width,Default_window_height,games.wave_textures[1]);
                        if(!games.wave_texture_timer_index++)
                        {
                            enemy_fat[0].enemy_Position_X = -80;
                            enemy_fat[0].enemy_Position_Direction = 30;
                            enemy_fat[2].enemy_Position_X = -80;
                            enemy_fat[2].enemy_Position_Direction = 30;
                            enemy_awk[3].enemy_Position_X = -80;
                            enemy_aws[3].enemy_Position_X = -80;
                        }
                    }

                    if(Enemy_Fat::index < 2)
                    {
                        enemy_fat[Enemy_Fat::index].Enemy_Life_Bar();
                        enemy_fat[Enemy_Fat::index].Enemy_Attack();
                        enemy_fat[Enemy_Fat::index].Enemy_Attacked_By_Hero();

                        if(enemy_fat[Enemy_Fat::index].enemy_health <= 0)
                        {
                            Enemy_Fat::index++;
                        }
                    }
                    else if(Enemy_AWS::index == 5)
                    {
                        if(enemy_fat[2].enemy_health > 0)
                        {
                            enemy_fat[2].Enemy_Life_Bar();
                            enemy_fat[2].Enemy_Attack();
                            enemy_fat[2].Enemy_Attacked_By_Hero();
                        }

                        if(enemy_fat[3].enemy_health > 0)
                        {
                            enemy_fat[3].Enemy_Life_Bar();
                            enemy_fat[3].Enemy_Attack();
                            enemy_fat[3].Enemy_Attacked_By_Hero();
                        }

                        if(enemy_fat[2].enemy_health <= 0 && enemy_fat[3].enemy_health <= 0)
                        {
                            Enemy_Fat::index += 2;
                        }
                    }
                    else
                    {
                        enemy_aws[Enemy_AWS::index].Enemy_Life_Bar();
                        enemy_aws[Enemy_AWS::index].Enemy_Attack();
                        enemy_aws[Enemy_AWS::index].Enemy_Attacked_By_Hero();

                        enemy_awk[Enemy_AWK::index].Enemy_Life_Bar();
                        enemy_awk[Enemy_AWK::index].Enemy_Attack();
                        enemy_awk[Enemy_AWK::index].Enemy_Attacked_By_Hero();
                        if (enemy_awk[Enemy_AWK::index].enemy_health <= 0 && enemy_aws[Enemy_AWS::index].enemy_health <= 0)
                        {
                            Enemy_AWK::index++;
                            Enemy_AWS::index++;
                        }
                    }


                    if(Enemy_Fat::index == 4)
                    {
                        games.wave = 3;
                        games.wav_3_first_init = 0;
                        games.wave_texture_timer_index = 0;
                        hero.hero_health = 200;
                    }

                }
                else
                {

                    if(games.wave_texture_timer_index < 20)
                    {
                        iShowImage(0,0,Default_window_width,Default_window_height,games.wave_textures[2]);

                        if(!games.wave_texture_timer_index++)
                        {
                            boss_dr.boss_health = 200;
                            boss_dr.boss_approach_index = 0;
                            boss_dr.boss_attack_index = 0;
                            boss_dr.boss_attack_loop_index = 0;
                            boss_dr.boss_Position_X = 1600;
                            boss_dr.isLoop = 0;
                            boss_dr.timer = 0;
                            enemy_baseball[3].enemy_Position_X = -80;
                            enemy_baseball[5].enemy_Position_X = -80;
                            enemy_baseball[7].enemy_Position_X = -80;
                            enemy_awk[5].enemy_Position_X = -80;
                            enemy_awk[7].enemy_Position_X = -80;
                            enemy_aws[6].enemy_Position_X = -80;
                        }
                    }



                    if(Enemy_Baseball::index < 8)
                    {
                        enemy_baseball[Enemy_Baseball::index].Enemy_Life_Bar();
                        enemy_baseball[Enemy_Baseball::index].Enemy_Attack();
                        enemy_baseball[Enemy_Baseball::index].Enemy_Attacked_By_Hero(true);
                    }

                    if(Enemy_AWK::index < 8)
                    {
                        enemy_awk[Enemy_AWK::index].Enemy_Life_Bar();
                        enemy_awk[Enemy_AWK::index].Enemy_Attack();
                        enemy_awk[Enemy_AWK::index].Enemy_Attacked_By_Hero();
                    }

                    if(Enemy_AWS::index < 8)
                    {
                        enemy_aws[Enemy_AWS::index].Enemy_Life_Bar();
                        enemy_aws[Enemy_AWS::index].Enemy_Attack();
                        enemy_aws[Enemy_AWS::index].Enemy_Attacked_By_Hero();
                    }


                    if(enemy_baseball[Enemy_Baseball::index].enemy_health <= 0 && Enemy_Baseball::index < 8)
                    {
                        Enemy_Baseball::index++;
                    }

                    if(enemy_awk[Enemy_AWK::index].enemy_health <= 0 && Enemy_AWK::index < 8)
                    {
                        Enemy_AWK::index++;
                    }

                    if(enemy_aws[Enemy_AWS::index].enemy_health <= 0 && Enemy_AWS::index < 8)
                    {
                        Enemy_AWS::index++;
                    }

                    if(boss_dr.boss_health > 0)
                    {
                        iShowImage(1350,705,150,150,enemy.boss_Icons[1]);
                        iSetColor(255,255,255);
                        iRectangle(1150,765,202,25);
                        iSetColor(164,198,57);
                        iFilledRectangle(1151,766,boss_dr.boss_health,23);
                        boss_dr.Boss_Attack();
                        boss_dr.Boss_Attacked_By_Hero();
                    }

                    if(Enemy_Baseball::index == 8 && Enemy_AWK::index == 8 && Enemy_AWS::index == 8 && boss_dr.boss_health <= 0)
                    {
                        games.Level = 3;
                        games.wave = 1;
                        game_initialize();
                    }
                }
            }
        }
        else if(games.Level == 3)
        {

        }
        else
        {
            iShowImage(0,0,Default_window_width,Default_window_height,games.game_over_textures[1]);
            iShowImage(0,0,Default_window_width,Default_window_height,games.game_over_textures[0]);
        }
    }
    else if(games.Page == 4)
    {
        iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
        iShowImage(games.Back_button_X,games.Back_button_Y,games.Back_button_Width,games.Back_button_Height, games.Back_Button);
    }
    else if(games.Page == 5)
    {
        iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
        iShowImage(0, 0, Default_window_width, Default_window_height, games.help_page);
        iShowImage(games.Back_button_X,games.Back_button_Y,games.Back_button_Width,games.Back_button_Height, games.Back_Button);
    }
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
    //press = 0;
    //For_Page 1
    if(games.Page == 1 && mx >= (Default_window_width/2) - 150 && mx <= (Default_window_width/2) + 150 && my >= 300 && my <= 300+101 && menu.menu_Texture_Load_index > 24)
    {
        waiting.Tap_To_Continue_Index = 3;
    }
    else
    {
        waiting.Tap_To_Continue_Index = 2;
    }

    //For_Page 2
    if(mx >= 1100 && mx <= 1300 && games.Page == 2 && !games.exit_press)
    {
        if(my <= 467 && my >= 400)
        {
            menu.Play_Index = 1;
            menu.Credits_Index = 2;
            menu.Help_Index = 4;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
        else if(my <= 387 && my >= 320)
        {
            menu.Play_Index = 0;
            menu.Credits_Index = 3;
            menu.Help_Index = 4;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
        else if(my <= 307 && my >= 240)
        {
            menu.Play_Index = 0;
            menu.Credits_Index = 2;
            menu.Help_Index = 5;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
        else if(my <= 227 && my >= 160)
        {
            menu.Play_Index = 0;
            menu.Credits_Index = 2;
            menu.Help_Index = 4;
            menu.Sound_Index = 7;
            menu.Exit_Index = 8;
        }
        else if(my <= 147 && my >= 80)
        {
            menu.Play_Index = 0;
            menu.Credits_Index = 2;
            menu.Help_Index = 4;
            menu.Sound_Index = 6;
            menu.Exit_Index = 9;
        }
        else
        {
            menu.Play_Index = 0;
            menu.Credits_Index = 2;
            menu.Help_Index = 4;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
    }
    else
    {
        menu.Play_Index = 0;
        menu.Credits_Index = 2;
        menu.Help_Index = 4;
        menu.Sound_Index = 6;
        menu.Exit_Index = 8;
    }

    if(my >= 250 && my <= 317 && games.exit_press)
    {
        if(mx >= 410 && mx <= 610)
        {
            games.exit_yes_index = 1;
            games.exit_no_index = 0;
        }
        else if(mx >= 910 && mx <= 1110)
        {
            games.exit_yes_index = 0;
            games.exit_no_index = 1;
        }
        else
        {
            games.exit_yes_index = 0;
            games.exit_no_index = 0;
        }
    }
    else
    {
        games.exit_yes_index = 0;
        games.exit_no_index = 0;
    }

    //For_Page 3 to 5 Back Button
    if(mx >= games.Back_button_X && mx <= games.Back_button_X + 50 && games.Page > 2 && games.Page < 6 && my <= games.Back_button_Y + 50 && my >= games.Back_button_Y)
    {
        games.Back_button_X = 17.5;
        games.Back_button_Y = 782.5;
        games.Back_button_Width = 55;
        games.Back_button_Height = 55;
    }
    else
    {
        games.Back_button_X = 20;
        games.Back_button_Y = 785;
        games.Back_button_Height = 50;
        games.Back_button_Width = 50;
    }

    //For_page 3
    if(my <= 600 && my >= 300 && games.Page == 3 && !games.Level)
    {
        if(mx >= 155 && mx <= 455)
        {
            games.Level_Select_X[0] = 145;
            games.Level_Select_X[1] = 610;
            games.Level_Select_X[2] = 1065;
            games.Level_Select_Y[0] = 290;
            games.Level_Select_Y[1] = 300;
            games.Level_Select_Y[2] = 300;
            games.Level_Select_Width[0] = 320;
            games.Level_Select_Width[1] = 300;
            games.Level_Select_Width[2] = 300;
            games.Level_Select_Height[0] = 320;
            games.Level_Select_Height[1] = 300;
            games.Level_Select_Height[2] = 300;
        }
        else if(mx >= 610 && mx <= 910)
        {
            games.Level_Select_X[0] = 155;
            games.Level_Select_X[1] = 600;
            games.Level_Select_X[2] = 1065;
            games.Level_Select_Y[0] = 300;
            games.Level_Select_Y[1] = 290;
            games.Level_Select_Y[2] = 300;
            games.Level_Select_Width[0] = 300;
            games.Level_Select_Width[1] = 320;
            games.Level_Select_Width[2] = 300;
            games.Level_Select_Height[0] = 300;
            games.Level_Select_Height[1] = 320;
            games.Level_Select_Height[2] = 300;
        }
        else if(mx >= 1065 && mx <= 1365)
        {
            games.Level_Select_X[0] = 155;
            games.Level_Select_X[1] = 610;
            games.Level_Select_X[2] = 1055;
            games.Level_Select_Y[0] = 300;
            games.Level_Select_Y[1] = 300;
            games.Level_Select_Y[2] = 290;
            games.Level_Select_Width[0] = 300;
            games.Level_Select_Width[1] = 300;
            games.Level_Select_Width[2] = 320;
            games.Level_Select_Height[0] = 300;
            games.Level_Select_Height[1] = 300;
            games.Level_Select_Height[2] = 320;
        }
        else
        {
            games.Level_Select_X[0] = 155;
            games.Level_Select_X[1] = 610;
            games.Level_Select_X[2] = 1065;
            games.Level_Select_Y[0] = 300;
            games.Level_Select_Y[1] = 300;
            games.Level_Select_Y[2] = 300;
            games.Level_Select_Width[0] = 300;
            games.Level_Select_Width[1] = 300;
            games.Level_Select_Width[2] = 300;
            games.Level_Select_Height[0] = 300;
            games.Level_Select_Height[1] = 300;
            games.Level_Select_Height[2] = 300;
        }
    }
    else
    {
        games.Level_Select_X[0] = 155;
        games.Level_Select_X[1] = 610;
        games.Level_Select_X[2] = 1065;
        games.Level_Select_Y[0] = 300;
        games.Level_Select_Y[1] = 300;
        games.Level_Select_Y[2] = 300;
        games.Level_Select_Width[0] = 300;
        games.Level_Select_Width[1] = 300;
        games.Level_Select_Width[2] = 300;
        games.Level_Select_Height[0] = 300;
        games.Level_Select_Height[1] = 300;
        games.Level_Select_Height[2] = 300;
    }
}

void iMouse(int button, int state, int mx, int my)
{
    //For_Page 3
    if(games.Page == 3 && games.Level && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        games.is_attack = true;
        games.attack_press = true;
    }
    else
    {
        games.attack_press = false;
    }

    if(my <= 600 && my >= 300 && games.Page == 3 && !games.Level)
    {
        if(mx >= 155 && mx <= 455 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Level = 1;
            games.bg_image_1 = iLoadImage("resources\\game_texture\\game_bg\\bg_1.png");
            game_initialize_new_start();

        }
        else if(mx >= 610 && mx <= 910 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Level = 2;
            games.bg_image_1 = iLoadImage("resources\\game_texture\\game_bg\\bg_1.png");
            game_initialize_new_start();

        }
        /*else if(mx >= 1065 && mx <= 1365 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Level = 3;
        }
        else
        {
        }*/
    }

    //For_Page 3 to 5 Back Button
    if(mx >= games.Back_button_X && mx <= games.Back_button_X + 50 && games.Page > 2 && games.Page < 6 && my <= games.Back_button_Y + 50 && my >= games.Back_button_Y)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Page = 2;
        }
    }

    //For_Page 2
    if(my >= 250 && my <= 317 && games.exit_press)
    {
        if(mx >= 410 && mx <= 610 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            exit(0);
        }
        else if(mx >= 910 && mx <= 1110 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.exit_press = false;
        }

    }

    if(mx >= 1100 && mx <= 1300 && games.Page == 2 && !games.exit_press)
    {
        if(my <= 467 && my >= 400 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {

            mciSendString("play Select_Sound from 0", NULL, 0, NULL);
            games.Page = 3;
            iResumeTimer(games.Level_1_Icons_Animation_ID);
            Level_Icon_Size_Setter();
            Loading_Level_Icons();
        }
        else if(my <= 387 && my >= 320 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {

            mciSendString("play Select_Sound from 0", NULL, 0, NULL);
            games.Page = 4;
        }
        else if(my <= 307 && my >= 240 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {

            mciSendString("play Select_Sound from 0", NULL, 0, NULL);
            games.Page = 5;
        }
        else if(my <= 227 && my >= 160 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {

            mciSendString("play Select_Sound from 0", NULL, 0, NULL);
            if(menu.SOUND_ICON_Index == 0)
            {
                menu.SOUND_ICON_Index = 1;
                mciSendString("stop bgsong", NULL, 0, NULL);
            }
            else
            {
                menu.SOUND_ICON_Index = 0;
                mciSendString("play bgsong repeat", NULL, 0, NULL);
            }
        }
        else if(my <= 147 && my >= 80 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mciSendString("play Select_Sound from 0", NULL, 0, NULL);
            games.exit_press = true;
        }

    }

    //For_Page 1
    if(games.Page == 1 && mx >= (Default_window_width/2) - 150 && mx <= (Default_window_width/2) + 150 && my >= 300 && my <= 300+101 && menu.menu_Texture_Load_index > 24)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Page = 2;
            waiting.Tap_To_Continue_Index = 2;
        }
    }

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{

    if(games.Page == 3 && games.Level > 0 && games.Level < 4 && enemy.enemy_texture_load_index >= 55)
    {
        if (key == 'D' || key == 'd')
        {
            hero.Hero_Direction = 0;
            games.A_D_press = true;
        }
        if (key == 'A' || key == 'a')
        {
            hero.Hero_Direction = 1;
            games.A_D_press = true;
        }
        if (key == 'E' || key == 'e')
        {
            games.is_Dodge = true;
        }
        if (key == 'C' || key == 'c')
        {
            games.is_crouch = true;
        }

        if (key == '1')
        {
            games.key = 1;
        }
        if (key == '2')
        {
            games.key = 2;
        }
        if (key == '3')
        {
            games.key = 3;
        }

        if(key == ' ')
        {
            games.jump_press = true;
        }
    }

    if(key == '\r' &&  games.Level == 4)
    {
        games.Level = 0;
        game_initialize_new_start();
    }

    if(key == 27 && games.Level > 0 && enemy.enemy_texture_load_index >= 55)
    {
        games.Level = 0;
        games.is_game_Over_Call = false;
    }


}
void iKeyboardUp(unsigned char key,int x,int y)
{
    //games.jump_press = false;
    if (key == 'D' || key == 'd'||key == 'A' || key == 'a')
    {
        games.A_D_press = false;
        hero.hero_walking_index = 0;
    }
    /* if (key == 'C' || key == 'c')
     {
         games.is_crouch = false;
     }*/
}
/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


    if (key == GLUT_KEY_RIGHT)
    {

    }
    if (key == GLUT_KEY_LEFT)
    {

    }

    if (key == GLUT_KEY_HOME)
    {

    }

}




int main()
{
    srand(time(0));
    iInitialize(Default_window_width, Default_window_height, "OUTERN : The Bloody Escape");
    //ShowCursor(FALSE);
    glutKeyboardUpFunc(iKeyboardUp);
    Load_Intro_Textures();
    Load_waiting_page_texture();

    Load_Menu_Buttons();
    mciSendString("open \"resources\\musics\\Main_bg_sound.mp3\" alias bgsong", NULL, 0, NULL);
    mciSendString("open \"resources\\sounds\\Intro.mp3\" alias Intro_Sound", NULL, 0, NULL);
    mciSendString("open \"resources\\sounds\\select_effect.mp3\" alias Select_Sound", NULL, 0, NULL);
    mciSendString("open \"resources\\sounds\\Effect\\Chain saw\\ATK_ChainsawSwipe1.mp3\" alias Chainsaw_Sound", NULL, 0, NULL);
    mciSendString("open \"resources\\sounds\\Effect\\Chain_saw hit\\sawHit1.mp3\" alias Chainsaw_Hit_Sound", NULL, 0, NULL);
    games.exit_text = iLoadImage("resources\\game_texture\\exit\\exit_text.png");
    games.Back_Button = iLoadImage("resources\\game_texture\\ui_buttons\\Back.png");
    menu.Menu_Title = iLoadImage("resources\\game_texture\\menu_textures\\title.png");
    games.help_page = iLoadImage("resources\\game_texture\\help.png");
    //
    games.exit_yes[0] = iLoadImage("resources\\game_texture\\ui_buttons\\YES.png");
    games.exit_yes[1] = iLoadImage("resources\\game_texture\\ui_buttons\\YES_Black.png");
    games.exit_no[0] = iLoadImage("resources\\game_texture\\ui_buttons\\NO.png");
    games.exit_no[1] = iLoadImage("resources\\game_texture\\ui_buttons\\NO_Black.png");
    //
    iSetTimer(16, blinking_Cursour);
    hero.Hero_Animation_Standing = iSetTimer(150, Hero_Standing_Animation);
    iPauseTimer(hero.Hero_Animation_Standing);
    //Loding_Animation = iSetTimer(30, Load_Texture_Animation);
    //iPauseTimer(Loding_Animation);
    games.Level_1_Icons_Animation_ID = iSetTimer(150,Level_1_Icons_Animation);
    iPauseTimer(games.Level_1_Icons_Animation_ID);

    intro.blackmask_Move_Animation = iSetTimer(16, black_Mask_Animation);
    iSetTimer(80, Menu_background_texture_Animation);
    games.Load_Wave_Texture();
    iStart();
    return 0;
}
