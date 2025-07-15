
#include "iGraphics.h"
#define Default_window_width 1520
#define Default_window_height 855
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int blinking_Cursour_Color[3] = { 0, 0, 0 }, color_Increment_Decrement = 20,intro_background_texture;
double text_blackmask_X = 165;
void iDraw()
{
	iClear();
	iSetColor(0, 0, 0);
	iShowImage(0, 0, Default_window_width, Default_window_height, intro_background_texture);
	iSetColor(0, 0, 0);
	iFilledRectangle(text_blackmask_X, Default_window_height / 2.25, 1920 - text_blackmask_X, 120);
	iSetColor(blinking_Cursour_Color[0], blinking_Cursour_Color[1], blinking_Cursour_Color[2]);
	iFilledRectangle(text_blackmask_X - 100, Default_window_height / 2.25, 100, 120);
	
	
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

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
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
	text_blackmask_X += 96;
}
int main()
{
	///srand((unsigned)time(NULL));
	
	iInitialize(Default_window_width, Default_window_height, "OUTERN : The Bloody Escape");
	intro_background_texture = iLoadImage("OUTERN1.png");
	iSetTimer(16, blinking_Cursour);
	iSetTimer(300, black_Mask_Animation);

	iStart();
	return 0;
}
