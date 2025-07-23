#include "iGraphics.h"
#include <iostream>
#include <ctime>
#include <thread>
#define Default_window_width 1520
#define Default_window_height 855


using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int blinking_Cursour_Color[3] = { 0, 0, 0 }, color_Increment_Decrement = 20,intro_background_texture[3],blackmask_Move_Animation;
int blinking_Cursour_Show = 0,Page = 0;
int Menu_background_texture[22],Menu_background_texture_index = 0,Menu_Button[5],Menu_Button_Dark[5];
int Menu_Buttons[10];
int Waiting_Page_Textures[4],Tap_To_Continue_Index = 2;
int Play_Index = 0,Credits_Index = 2,Help_Index = 4,Sound_Index = 6,Exit_Index = 8;
int menu_Texture_Load_index = 0;
int Menu_Textures_Load;
double text_blackmask_X = 102;
int Loading_Icon_Textures[25],Loading_icon_index = 0,Loding_Animation;


void Load_Texture_Animation();
void Load_Menu_Textures();

void iDraw()
{
    iClear();
    //iDelayMS(16.67);
    //Intro_Start
    if(!Page)
    {
        iSetColor(0, 0, 0);
        /*if(text_blackmask_X >= 1420)
        {
            //iShowImage(20, Default_window_height/2,200, 200, intro_background_texture[2]);
            iShowImage(1320, 200,200, 200, intro_background_texture[2]);
            //iShowImage(Default_window_width/2 - 50, Default_window_height/2 - 100,200 , 200, intro_background_texture[2]);
        }*/
        iShowImage(0, 0, Default_window_width, Default_window_height, intro_background_texture[0]);

        if(!blinking_Cursour_Show)
        {
            //BLACK_MASK
            iSetColor(0, 0, 0);
            iFilledRectangle(text_blackmask_X, Default_window_height / 2.3, 1920 - text_blackmask_X, 105);
            //BLINKING_CURSOUR

            iSetColor(blinking_Cursour_Color[0], blinking_Cursour_Color[1], blinking_Cursour_Color[2]);
            iFilledRectangle(text_blackmask_X,Default_window_height / 2.3, 20, 105);
        }

        if(text_blackmask_X >= 1420 && !blinking_Cursour_Show)
        {
            blinking_Cursour_Show = 1;
        }

        if(text_blackmask_X >= 1420)
        {
            iShowImage(0, 0, Default_window_width, Default_window_height, intro_background_texture[1]);
        }

        if(text_blackmask_X >= 1700)
        {
            iPauseTimer(blackmask_Move_Animation);
            Page = 1;
			Menu_Textures_Load = iSetTimer(700, Load_Menu_Textures);
			iResumeTimer(Loding_Animation);
			
        }
    }
    else if(Page == 1)
    {
        iShowImage(0, 0, Default_window_width, Default_window_height, Waiting_Page_Textures[0]);
        iShowImage(0, 0, Default_window_width, Default_window_height, Waiting_Page_Textures[1]);
        if(menu_Texture_Load_index <= 24)
        {
			
            iSetColor(255,255,255);
            iRectangle(200,100,1120,30);
            iFilledRectangle(205,105,(((menu_Texture_Load_index < 22)? menu_Texture_Load_index:21)*1110)/21,20);
			iShowImage((Default_window_width / 2) - 190, 150, Default_window_width / 4, Default_window_height / 4, Loading_Icon_Textures[Loading_icon_index]);
			
        }
        else
        {
			
            iPauseTimer(Menu_Textures_Load);
			iPauseTimer(Loding_Animation);
            iShowImage((Default_window_width/2) - 150,300,300,101, Waiting_Page_Textures[Tap_To_Continue_Index]);
        }

    }
    else if(Page == 2)
    {
        iShowImage(0, 0, Default_window_width, Default_window_height, Menu_background_texture[Menu_background_texture_index]);
        iShowImage(1100, 400, 200,67,Menu_Buttons[Play_Index]);
        iShowImage(1100, 320, 200,67,Menu_Buttons[Credits_Index]);
        iShowImage(1100, 240, 200,67,Menu_Buttons[Help_Index]);
        iShowImage(1100, 160, 200,67,Menu_Buttons[Sound_Index]);
        iShowImage(1100, 80, 200,67,Menu_Buttons[Exit_Index]);


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
    if(Page == 1 && mx >= (Default_window_width/2) - 150 && mx <= (Default_window_width/2) + 150 && my >= 300 && my <= 300+101 && menu_Texture_Load_index > 24)
    {
        Tap_To_Continue_Index = 3;
    }
    else
    {
        Tap_To_Continue_Index = 2;
    }


    if(mx >= 1100 && mx <= 1300 && Page == 2)
    {
        if(my <= 467 && my >= 400)
        {
            Play_Index = 1;
            Credits_Index = 2;
            Help_Index = 4;
            Sound_Index = 6;
            Exit_Index = 8;
        }
        else if(my <= 387 && my >= 320)
        {
            Play_Index = 0;
            Credits_Index = 3;
            Help_Index = 4;
            Sound_Index = 6;
            Exit_Index = 8;
        }
        else if(my <= 307 && my >= 240)
        {
            Play_Index = 0;
            Credits_Index = 2;
            Help_Index = 5;
            Sound_Index = 6;
            Exit_Index = 8;
        }
        else if(my <= 227 && my >= 160)
        {
            Play_Index = 0;
            Credits_Index = 2;
            Help_Index = 4;
            Sound_Index = 7;
            Exit_Index = 8;
        }
        else if(my <= 147 && my >= 80)
        {
            Play_Index = 0;
            Credits_Index = 2;
            Help_Index = 4;
            Sound_Index = 6;
            Exit_Index = 9;
        }
        else
        {
            Play_Index = 0;
            Credits_Index = 2;
            Help_Index = 4;
            Sound_Index = 6;
            Exit_Index = 8;
        }
    }
    else
    {

        Play_Index = 0;
        Credits_Index = 2;
        Help_Index = 4;
        Sound_Index = 6;
        Exit_Index = 8;
    }
}

void iMouse(int button, int state, int mx, int my)
{

    if(Page == 1 && mx >= (Default_window_width/2) - 150 && mx <= (Default_window_width/2) + 150 && my >= 300 && my <= 300+101 && menu_Texture_Load_index > 24)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            Page = 2;
            Tap_To_Continue_Index = 2;
        }
    }


    if(mx >= 1100 && mx <= 1300 && Page == 2)
    {
        if(my <= 467 && my >= 400 && button == GLUT_LEFT_BUTTON)
        {
            Page = 3;
        }
        else if(my <= 387 && my >= 320 && button == GLUT_LEFT_BUTTON)
        {

        }
        else if(my <= 307 && my >= 240 && button == GLUT_LEFT_BUTTON)
        {

        }
        else if(my <= 227 && my >= 160 && button == GLUT_LEFT_BUTTON)
        {

        }
        else if(my <= 147 && my >= 80 && button == GLUT_LEFT_BUTTON)
        {
            exit(0);
        }

    }
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
    if (key == ' ')
    {
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
    intro_background_texture[0] = iLoadImage("game_texture\\intro_text_tex\\TEXT_WHITE.png");
    intro_background_texture[1] = iLoadImage("game_texture\\intro_text_tex\\TEXT_RED.png");
    intro_background_texture[2] = iLoadImage("game_texture\\intro_text_tex\\Blood.png");
}


void Load_Menu_Textures()
{
    if(menu_Texture_Load_index < 22)
    {
        char textures_name[45];
        sprintf_s(textures_name,"game_texture\\menu_anim_tex\\menu_bg_%d.png",menu_Texture_Load_index + 1);
        Menu_background_texture[menu_Texture_Load_index] = iLoadImage(textures_name);
    }
    menu_Texture_Load_index++;

}
void Load_Menu_Buttons()
{
    for(int i = 1; i < 11; i++)
    {
        char textures_path_name[50];
        sprintf_s(textures_path_name,"game_texture\\ui_button\\menu_button_%d.png",i);
        Menu_Buttons[i - 1] = iLoadImage(textures_path_name);
    }

}

void Load_waiting_page_texture()
{
    Waiting_Page_Textures[0] = iLoadImage("game_texture\\waiting_page_tex\\Waiting_Page_bg.png");
    Waiting_Page_Textures[1] = iLoadImage("game_texture\\waiting_page_tex\\Waiting_Page_Title.png");
    Waiting_Page_Textures[2] = iLoadImage("game_texture\\waiting_page_tex\\CLICK_TO_CONTINUE_min.png");
    Waiting_Page_Textures[3] = iLoadImage("game_texture\\waiting_page_tex\\CLICK_TO_CONTINUE_large.png");
}
void Load_Loading_Icon_Textures()
{
	for (int i = 1; i <= 25; i++)
	{
		char textures_path_name[70];
		sprintf_s(textures_path_name, "game_texture\\Loading_Icon_Texture\\Loading_Icon%d.png", i);
		Loading_Icon_Textures[i - 1] = iLoadImage(textures_path_name);
	}
}

void Menu_background_texture_Animation()
{
    if(Menu_background_texture_index < 21)
    {
        Menu_background_texture_index++;
    }
    else
    {
        Menu_background_texture_index = 0;
    }
}
void Load_Texture_Animation()
{
	if (Loading_icon_index >= 25)
	{
		Loading_icon_index = 0;
	}else
    {
	    Loading_icon_index++;
    }
}

int main()
{
    ///srand((unsigned)time(NULL));

    iInitialize(Default_window_width, Default_window_height, "OUTERN : The Bloody Escape");
    Load_Intro_Textures();
    Load_waiting_page_texture();
	Load_Loading_Icon_Textures();
    Load_Menu_Buttons();
    iSetTimer(16, blinking_Cursour);
	Loding_Animation = iSetTimer(30, Load_Texture_Animation);
	iPauseTimer(Loding_Animation);
	
    blackmask_Move_Animation = iSetTimer(16, black_Mask_Animation);
    iSetTimer(250, Menu_background_texture_Animation);
    iStart();
    return 0;
}
