#include "iGraphics.h"
#define DWW 1200
#define DWH 800
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int blinking_Cursour_Color[3] = {0,0,0},color_Increment_Decrement = 5;
void iDraw()
{
    iClear();
    iSetColor(blinking_Cursour_Color[0],blinking_Cursour_Color[1],blinking_Cursour_Color[2]);
    iFilledRectangle(600,400,24,45);

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

    for(int &color : blinking_Cursour_Color)
    {
        color += color_Increment_Decrement;
    }

    if(blinking_Cursour_Color[2] >= 240 || blinking_Cursour_Color[2] <= 0)
    {
        color_Increment_Decrement *= -1;
    }
}
int main()
{
    ///srand((unsigned)time(NULL));
    iInitialize(DWW, DWH, "OUTERN : The Bloody Escape");
    iSetTimer(1,blinking_Cursour);
    iStart();
    return 0;
}
