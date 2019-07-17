/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
void RecDraw();
void RandomRec();
void Score();
void playagain();

int ball_x, ball_y,rec_x,h,h1,rec_2_x;
int dx, dy;
int playopt=1,yesno=11,play=0;
int score=0;
int birdwide=32,birdheight=32;
int gap=100;

char score_text[10];

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
    iClear();

	iSetColor(49, 118, 234);
	iFilledRectangle(0,0,600,600);

	if(play==1)
	{
		
		RecDraw();
	}
	
	
	
	
	if(play==0)
		iShowBMP(30,300,"play.BMP");
		

	
	iShowBMP(ball_x,ball_y,"flappybird0.BMP");

	//Score();
	//iSetColor(255, 100, 10);
	//iFilledCircle(ball_x,ball_y,birdwide);
	RandomRec();
	playagain();
	 

	

	
	

	

}
void playagain()
{
		if (playopt==0)
		{
			
			
			iShowBMP(50,50,"playagain.BMP");
			if(yesno==10)
			{
				play=0;
				yesno=11;
				ball_x=300;
				ball_y=300;
				h=300;
				h1=250;
				rec_x=600;
				rec_2_x=900;
				
				playopt=1;
				
				iResumeTimer(0);
				
			}



			
		
		}

}

void Score()
{
	if( rec_x==220||rec_2_x==220)   
	{
		score+=1;
		sprintf(score_text, "%d", score);
		puts(score_text);

	}
}


		
void RandomRec()
{
	if(rec_x==-75)
	{

		rec_x=600;
		h=rand()%370+30;
	}
		if(rec_2_x==-75)
	{
		rec_2_x=600;
		h1=rand()%370+30;
	}
}


void RecDraw()
{
	iSetColor(45, 207, 27);

    iFilledRectangle(rec_x,0,75,h);
	iFilledRectangle(rec_x,h+gap,75,600-(h+gap));

	
	
	//iShowBMP(ball_x,ball_y,"flappybird1.BMP");
	

    iFilledRectangle(rec_2_x,0,75,h1);
	iFilledRectangle(rec_2_x,h1+gap,75,600-(h1+gap));
}


/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	printf(" %d %d ",mx,my);
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		play=1;
		ball_y+=40;
		dy=1;

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{


	if(key == ' ')
	{
		play=1;
		
		ball_y+=40;
		dy=1;
	}
	if(key == 'y')
	{
		yesno=10;
	}

	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
		
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}

void BallChange()
{
	if(play==1)
	{
		dy++;
		ball_y -= dy;
	}



	if(ball_y<0)
	{
		iPauseTimer(0);
		playopt=0;
	}
	

	

	
}

void RecChange(){
	if(play==1)
	{
	
		rec_x -= 1;
		rec_2_x-=1;
	}
	if(rec_x<=(300+birdwide) && rec_x>=(300-75))
	{


		if(ball_y<h|| ball_y>h+70)
		{
			iPauseTimer(0);
			playopt=0;
		}

	}
	else if (rec_2_x<=(300+birdwide) && rec_2_x>=(300-75))
	{

		if(ball_y<h1|| ball_y>h1+70)
		{	
			iPauseTimer(0);
			playopt=0;
		}

	}
	
	
}



int main()
{
	//place your own initialization codes here. 
	
	iSetTimer(5, RecChange);
	iSetTimer(50, BallChange);
	ball_x=300;
	ball_y=300;
	h=300;
	h1=250;
	rec_x=600;
	rec_2_x=900;
	//rec_3_x=400;
	//rec_4_x=400;

	
	

	dx = 1;
	dy = 1;
	iInitialize(600, 600, "Ball Demo");
	return 0;
}