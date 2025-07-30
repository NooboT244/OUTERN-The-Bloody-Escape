#include "iGraphics.h"
#include <iostream>
#include <ctime>
#include <thread>
#define Default_window_width 1520
#define Default_window_height 855


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
        text_blackmask_X += 4;
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
    void Load_Menu_Sounds()
    {
        mciSendString("open \"resources\\sounds\\hover_effect.mp3\" alias Hover_Sound", NULL, 0, NULL);
        mciSendString("open \"resources\\sounds\\select_effect.mp3\" alias Select_Sound", NULL, 0, NULL);
    }
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

struct Hero
{
    int hero_standing_left[6],hero_standing_right[6],hero_walking_left[18],hero_walking_right[18];                                //hero_textures
    int hero_texture_load_index,hero_standing_index,hero_walking_index;                                                           //hero_index
    int hero_texture_load,Hero_Animation_Standing;                                                                                //timer_animation
    int Hero_Direction;                                                                                                       //left_right_Direction
    double hero_Position_X,hero_Position_Y,yIncreaseDecrease;                                                      //hero_position

    Hero()
    {
        hero_texture_load_index = 0;
        hero_standing_index = 0;
        hero_walking_index = 0;
        Hero_Direction = 0;
        hero_Position_X = 20;
        hero_Position_Y = 210;
        yIncreaseDecrease = 16;
    }

    //..........functions.........//

    void Load_Hero_Textures()                                                                                                     //Loading_textures
    {
        char path[120];
        if(hero_texture_load_index < 6)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Standing\\Left\\hero_standing_left(%d).png",hero_texture_load_index + 1);
            hero_standing_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Standing\\Right\\hero_standing_right(%d).png", hero_texture_load_index + 1);
            hero_standing_right[hero_texture_load_index] = iLoadImage(path);
        }
        if(hero_texture_load_index < 18)
        {
            sprintf_s(path, "resources\\game_texture\\hero\\Walking\\Left\\left (%d).png",hero_texture_load_index + 1);
            hero_walking_left[hero_texture_load_index] = iLoadImage(path);
            sprintf_s(path, "resources\\game_texture\\hero\\Walking\\Right\\right (%d).png",hero_texture_load_index + 1);
            hero_walking_right[hero_texture_load_index] = iLoadImage(path);
        }
        hero_texture_load_index++;
    }

    void Hero_Standing_Animation()                                                                                              //Standing_timer_animation
    {
        if(hero_standing_index < 5)
        {
            hero_standing_index++;
        }
        else
        {
            hero_standing_index = 0;
        }
    }
};

struct Games
{
    int Page;
    int Back_Button;
    double Level_Select_X[3],Level_Select_Y[3], Level_Select_Width[3],Level_Select_Height[3];
    int Level_1_Icons[8],Level_1_Icons_index = 0,Level_1_Icons_Animation_ID;
    int Level;
    int bg_image_1;
    bool  A_D_press,jump_press;
    double Back_button_X,Back_button_Y,Back_button_Height,Back_button_Width;

    Games()
    {
        Page = 0;
        Level = 0;

        A_D_press = false;
        jump_press = false;

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
void Load_Hero_Textures()                                                                                                     //Loading_textures
{
    hero.Load_Hero_Textures();
}
void Hero_Standing_Animation()                                                                                              //Staning_timer_animation
{
    hero.Hero_Standing_Animation();
}

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
            games.Page = 1;
            Loading_Sound_Texture();
            menu.Load_Menu_Sounds();
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
    }
    else if(games.Page == 3)
    {
        if(games.Level == 0)
        {
            iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
            iShowImage(games.Back_button_X,games.Back_button_Y,games.Back_button_Width,games.Back_button_Height, games.Back_Button);
            glLineWidth(5);
            iSetColor(255, 255, 255);
            iShowImage(games.Level_Select_X[0],games.Level_Select_Y[0], games.Level_Select_Width[0],games.Level_Select_Height[0],games.Level_1_Icons[games.Level_1_Icons_index]);
            iRectangle(games.Level_Select_X[0],games.Level_Select_Y[0], games.Level_Select_Width[0],games.Level_Select_Height[0]);
            iText(260,250,"Level 1",GLUT_BITMAP_TIMES_ROMAN_24);
            /*iRectangle(Level_Select_X[1],Level_Select_Y[1], Level_Select_Width[1],Level_Select_Height[1]);
            iRectangle(Level_Select_X[2],Level_Select_Y[2], Level_Select_Width[2],Level_Select_Height[2]);*/
        }
        else if(games.Level == 1)
        {
            if(hero.hero_texture_load_index < 20)
            {
                glLineWidth(1);
                iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[0]);
                iShowImage(0, 0, Default_window_width, Default_window_height, waiting.Waiting_Page_Textures[1]);
                iSetColor(255,255,255);
                iRectangle(200,100,1120,30);
                iFilledRectangle(205,105,(((hero.hero_texture_load_index < 18)? hero.hero_texture_load_index:17)*1110)/17,20);
                if(hero.hero_texture_load_index == 7)
                {
                    iResumeTimer(hero.Hero_Animation_Standing);
                }
            }
            else
            {
                iPauseTimer(hero.hero_texture_load);
                iShowImage(0,0,760,855,games.bg_image_1);
                iShowImage(760,0,760,855,games.bg_image_1);
                iDelayMS(55);
                if(!hero.Hero_Direction)
                {
                    if(games.jump_press)
                    {
                        hero.hero_Position_Y += hero.yIncreaseDecrease;
                        if(hero.hero_Position_Y >= 350)
                        {
                            hero.yIncreaseDecrease *= -1;
                        }
                        if(hero.hero_Position_Y <= 210)
                        {
                            hero.yIncreaseDecrease *= -1;
                            games.jump_press = false;
                        }
                    }

                    if(games.A_D_press)
                    {
                        if(hero.hero_Position_X <= 1320)
                        {
                            hero.hero_Position_X += 20;
                        }

                        if(hero.hero_walking_index < 17)
                        {
                            hero.hero_walking_index++;
                        }
                        else
                        {
                            hero.hero_walking_index = 0;
                        }
                    }

                    if((games.jump_press && games.A_D_press) || games.jump_press )
                    {
                        iShowImage(hero.hero_Position_X,hero.hero_Position_Y,Default_window_width/8,Default_window_height/2, hero.hero_standing_right[hero.hero_standing_index]);
                    }
                    else if(games.A_D_press)
                    {
                        iShowImage(hero.hero_Position_X,hero.hero_Position_Y,Default_window_width/7,Default_window_height/2, hero.hero_walking_right[hero.hero_walking_index]);
                    }
                    else
                    {
                        iShowImage(hero.hero_Position_X,hero.hero_Position_Y,Default_window_width/8,Default_window_height/2, hero.hero_standing_right[hero.hero_standing_index]);
                    }
                }
                else
                {
                    if(games.jump_press)
                    {
                        hero.hero_Position_Y += hero.yIncreaseDecrease;
                        if(hero.hero_Position_Y >= 350)
                        {
                            hero.yIncreaseDecrease *= -1;
                        }
                        if(hero.hero_Position_Y <= 210)
                        {
                            hero.yIncreaseDecrease *= -1;
                            games.jump_press = false;
                        }
                    }

                    if(games.A_D_press)
                    {
                        if(hero.hero_Position_X >= 0)
                        {
                            hero.hero_Position_X -= 20;
                        }

                        if(hero.hero_walking_index < 17)
                        {
                            hero.hero_walking_index++;
                        }
                        else
                        {
                            hero.hero_walking_index = 0;
                        }
                    }


                    if((games.jump_press && games.A_D_press) || games.jump_press )
                    {
                        iShowImage(hero.hero_Position_X,hero.hero_Position_Y,Default_window_width/8,Default_window_height/2, hero.hero_standing_left[hero.hero_standing_index]);
                    }
                    else if(games.A_D_press)
                    {
                        iShowImage(hero.hero_Position_X,hero.hero_Position_Y,Default_window_width/7,Default_window_height/2, hero.hero_walking_left[hero.hero_walking_index]);
                    }
                    else
                    {
                        iShowImage(hero.hero_Position_X,hero.hero_Position_Y,Default_window_width/8,Default_window_height/2, hero.hero_standing_left[hero.hero_standing_index]);
                    }
                }
            }
        }
        else if(games.Level == 2)
        {

        }
        else if(games.Level == 3)
        {

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
        mciSendString("play Hover_Sound", NULL, 0, NULL);
        waiting.Tap_To_Continue_Index = 3;
    }
    else
    {
        waiting.Tap_To_Continue_Index = 2;
    }

    //For_Page 2
    if(mx >= 1100 && mx <= 1300 && games.Page == 2)
    {
        if(my <= 467 && my >= 400)
        {
            mciSendString("play Hover_Sound", NULL, 0, NULL);
            menu.Play_Index = 1;
            menu.Credits_Index = 2;
            menu.Help_Index = 4;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
        else if(my <= 387 && my >= 320)
        {
            mciSendString("play Hover_Sound", NULL, 0, NULL);
            menu.Play_Index = 0;
            menu.Credits_Index = 3;
            menu.Help_Index = 4;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
        else if(my <= 307 && my >= 240)
        {
            mciSendString("play Hover_Sound", NULL, 0, NULL);
            menu.Play_Index = 0;
            menu.Credits_Index = 2;
            menu.Help_Index = 5;
            menu.Sound_Index = 6;
            menu.Exit_Index = 8;
        }
        else if(my <= 227 && my >= 160)
        {
            mciSendString("play Hover_Sound", NULL, 0, NULL);
            menu.Play_Index = 0;
            menu.Credits_Index = 2;
            menu.Help_Index = 4;
            menu.Sound_Index = 7;
            menu.Exit_Index = 8;
        }
        else if(my <= 147 && my >= 80)
        {
            mciSendString("play Hover_Sound", NULL, 0, NULL);
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
    //For_Page 1
    if(games.Page == 1 && mx >= (Default_window_width/2) - 150 && mx <= (Default_window_width/2) + 150 && my >= 300 && my <= 300+101 && menu.menu_Texture_Load_index > 24)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Page = 2;
            waiting.Tap_To_Continue_Index = 2;
        }
    }

    //For_Page 2
    if(mx >= 1100 && mx <= 1300 && games.Page == 2)
    {
        if(my <= 467 && my >= 400 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mciSendString("play Select_Sound", NULL, 0, NULL);
            games.Page = 3;
            iResumeTimer(games.Level_1_Icons_Animation_ID);
            Level_Icon_Size_Setter();
            Loading_Level_Icons();
        }
        else if(my <= 387 && my >= 320 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mciSendString("play Select_Sound", NULL, 0, NULL);
            games.Page = 4;
        }
        else if(my <= 307 && my >= 240 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mciSendString("play Select_Sound", NULL, 0, NULL);
            games.Page = 5;
        }
        else if(my <= 227 && my >= 160 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mciSendString("play Select_Sound", NULL, 0, NULL);
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
            mciSendString("play Select_Sound", NULL, 0, NULL);
            exit(0);
        }

    }

    //For_Page 3 to 5 Back Button
    if(mx >= games.Back_button_X && mx <= games.Back_button_X + 50 && games.Page > 2 && games.Page < 6 && my <= games.Back_button_Y + 50 && my >= games.Back_button_Y)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Page = 2;
        }
    }

    //For_Page 3
    if(my <= 600 && my >= 300 && games.Page == 3 && !games.Level)
    {
        if(mx >= 155 && mx <= 455 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            games.Level = 1;
            games.bg_image_1 = iLoadImage("resources\\game_texture\\game_bg\\bg_1.png");
            hero.hero_texture_load = iSetTimer(300,Load_Hero_Textures);
        }
        /*else if(mx >= 610 && mx <= 910 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            Level = 2;
        }
        else if(mx >= 1065 && mx <= 1365 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            Level = 3;
        }*/
    }

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
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
    if(key == ' ')
    {
        games.jump_press = true;
    }

    if(key == 27 && games.Page == 3 && games.Level > 0)
    {
        games.Level = 0;
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
    iInitialize(Default_window_width, Default_window_height, "OUTERN : The Bloody Escape");
    glutKeyboardUpFunc(iKeyboardUp);
    Load_Intro_Textures();
    Load_waiting_page_texture();

    Load_Menu_Buttons();
    mciSendString("open \"resources\\musics\\Main_bg_sound.mp3\" alias bgsong", NULL, 0, NULL);
    mciSendString("open \"resources\\sounds\\Intro.mp3\" alias Intro_Sound", NULL, 0, NULL);
    games.Back_Button = iLoadImage("resources\\game_texture\\ui_buttons\\Back.png");
    menu.Menu_Title = iLoadImage("resources\\game_texture\\menu_textures\\title.png");
    iSetTimer(16, blinking_Cursour);
    hero.Hero_Animation_Standing = iSetTimer(300, Hero_Standing_Animation);
    iPauseTimer(hero.Hero_Animation_Standing);
    //Loding_Animation = iSetTimer(30, Load_Texture_Animation);
    //iPauseTimer(Loding_Animation);
    games.Level_1_Icons_Animation_ID = iSetTimer(150,Level_1_Icons_Animation);
    iPauseTimer(games.Level_1_Icons_Animation_ID);

    intro.blackmask_Move_Animation = iSetTimer(16, black_Mask_Animation);
    iSetTimer(80, Menu_background_texture_Animation);
    iStart();
    return 0;
}
