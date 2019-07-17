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
void initial_condition();

int ball_x, ball_y,rec_x,h,h1,h2,rec_2_x,rec_3_x;
int dx, dy;
int playopt=0,yesno=11,play=-1,menu=1,click=0,about=0;
int score=0,fall=0,pause=0;
int birdwide=32,birdheight=32;
int gap=100;

char score_text[10]={'0','0'};

/* 
	function iDraw() is called again and again by the system.
*/
void initial_condition()
{
				fall=0;
				play=0;
				yesno=11;
				score_text[0]='0';
				score_text[1]='0';

				score=0;
				ball_x=300;
				ball_y=300;
				h=300;
				h1=250;
				h2=200;
				rec_x=600;
				rec_2_x=820;
				rec_3_x=1020;
				
				playopt=0;
}
void iDraw()
{
	//place your drawing codes here	
    iClear();
	if(menu==1)
	{
		iShowBMP(0,0,"menu1.BMP");
		iText(250,250,"NEW GAME",GLUT_BITMAP_HELVETICA_18);
		iText(247,210,"LOAD GAME",GLUT_BITMAP_HELVETICA_18);
		iText(265,170,"ABOUT",GLUT_BITMAP_HELVETICA_18);
		iText(270,130,"EXIT",GLUT_BITMAP_HELVETICA_18);

	}
	if(about==1)
	{
		iShowBMP(0,0,"about.BMP");
	}



	
	if(play==0)// "click to start the game" eta dekhabe
	{
		
		
		
		
			iSetColor(49, 118, 234);
      	iFilledRectangle(0,0,600,600);
		
		if(pause==0)
		{
			click=1;

			iShowBMP(30,400,"play1.BMP");
		}
		
		iShowBMP(ball_x,ball_y,"flappybird0.BMP");
	
	}

	if(play==1) //when game is on
	{
		iSetColor(49, 118, 234);
      	iFilledRectangle(0,0,600,600);
		
		iShowBMP(ball_x,ball_y,"flappybird0.BMP");
		RecDraw();
		iSetColor(0,0,0);
		iText(18,560,"POINT",GLUT_BITMAP_HELVETICA_18);

		iText(100,560,score_text,GLUT_BITMAP_HELVETICA_18); //score dekhabe
	}
	
	
	


		if(pause==1)

		{
			
			
			RecDraw();
			iSetColor(0,0,0);
			iText(50,50,"....PAUSED",GLUT_BITMAP_HELVETICA_18);
			iText(250,250,"RESUME",GLUT_BITMAP_HELVETICA_18);
			iText(247,210,"NEW GAME",GLUT_BITMAP_HELVETICA_18);
			iText(250,170,"SAVE & EXIT to MAIN MENU",GLUT_BITMAP_HELVETICA_18);

			
			
		}


	RandomRec();
	playagain();
	


	

}
void playagain()
{
		if (playopt==1)
		{
			fall=1; 
			
			
			iShowBMP(50,50,"playagain.BMP");
		//	iText(250,60,"Press y",GLUT_BITMAP_HELVETICA_18);

			iText(260,350,"YOUR SCORE :",GLUT_BITMAP_HELVETICA_18);
			iText(400,350,score_text,GLUT_BITMAP_TIMES_ROMAN_24);
			if(yesno==10)
			{
				initial_condition();
				
				iResumeTimer(0);
				
			}



			
		
		}

}

void Score()
{
	if( rec_x==225||rec_2_x==225||rec_3_x==225)   
	{
		score++;
		itoa(score,score_text,10);

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
		if(rec_3_x==-75)
	{
		rec_3_x=600;
		h2=rand()%370+30;
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

	iFilledRectangle(rec_3_x,0,75,h2);

	iFilledRectangle(rec_3_x,h2+gap,75,600-(h2+gap));
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

		//main menu click option
		if(menu==1&&(mx>250&&my>250&&mx<350&&my<268))// ei click korle "new game" select hobe
		{
			menu=0;
			play=0;
		}
		//if(menu==1&&(mx>247&&my>210&&mx<354&&my<226))***********HIMEL****** ei khane clcik korle loadgame start hobe
	//	{

	//	}
		if(menu==1&&(mx>265&&my>170&&mx<329&&my<185))// 1i clcik korle about dekhabe
		{
			menu=0;
			about=1;
		}
		if(about==1&&(mx>469&&my>165&&mx<519&&my<188))// about theke back korbe main menu te
		{
			about=0;
			menu=1;
		}
		if(menu==1&&(mx>270&&my>130&&mx<312&&my<145))// 1i clcik korle about dekhabe
			exit(0);

		

		//pausemenu click option
		if(pause==1&&(mx>250&&my>250&&mx<325&&my<265))// ei click korle pause menu te "resume" select hobe 
		{
			click=1;
		}
		if(pause==1&&(mx>247&&my>210&&mx<348&&my<224))// ei clcik korle khela newgame shuru hobe.....
		{
			pause=0;
			initial_condition();

		}
		if(pause==1&&(mx>250&&my>170&&mx<496&&my<185))// ei clcik korle game save hobe and main menu te jabe....
		{
			//*********HIMEL******* eikahne game save er code ta likhbi....
			pause=0;
			menu=1;
			click=0;
			
			initial_condition();
			play=-1;
				
			iResumeTimer(0);
		}




		
			
	
		if(click==1)// jei click korle sudhu bird fly korbe... 
		{

				play=1;
				pause=0;
				iResumeTimer(0);
				if (fall==0)
				{

		
					ball_y+=45;
					dy=1;
			
				}
			
		}
		
		if(playopt=1&&(mx>160&&my>205&&mx<205&&my<270))// pakhi mara khaoar por "yes" select korbe... jate playagain hoi...
		{
			
			yesno=10;
		     fall=0;
		}
		else if(mx>377&&my>190&&mx<458&&my<265)// pakhi mara khaoar por "No" select korbe. jate Main menu te jay...
		{
			menu=1;
			click=0;
			
			initial_condition();
			play=-1;
				
			iResumeTimer(0);
			
		}
		


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
		pause=0;
		iResumeTimer(0);

		if (fall==0)
		{
		
			ball_y+=45;
			dy=1;
		}
	}
	if(key == 'y')
	{
		yesno=10;
		fall=0;
	}

	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	
		play=0;
		pause=1;
		click=0;
		
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
		playopt=1;
	}
	

	

	
}

void RecChange(){
	Score();
	if(play==1)
	{
	
		rec_x -= 1;
		rec_2_x-=1;
		rec_3_x-=1;
	}
	if(rec_x<=(300+birdwide) && rec_x>=(300-75))
	{


		if(ball_y<h|| ball_y>h+70)
		{
			iPauseTimer(0);
			playopt=1;
	
		}

	}
	else if (rec_2_x<=(300+birdwide) && rec_2_x>=(300-75))
	{

		if(ball_y<h1|| ball_y>h1+70)
		{	
			iPauseTimer(0);
			playopt=1;
			
		}

	}
	else if (rec_3_x<=(300+birdwide) && rec_3_x>=(300-75))
	{

		if(ball_y<h2|| ball_y>h2+70)
		{	
			iPauseTimer(0);
			playopt=1;
	
		}

	}
	
	
}



int main()
{
	//place your own initialization codes here. 
	
	iSetTimer(2, RecChange);
	iSetTimer(50, BallChange);
	
	ball_x=300;
	ball_y=300;
	//h=300;
	h=rand()%370+30;
//	h1=250;
	h1=rand()%370+30;
//	h2=275;
	h2=rand()%370+30;
	rec_x=600;
	rec_2_x=820;

	rec_3_x=1020;
	//rec_4_x=400;

	
	

	dx = 1;
	dy = 1;
	iInitialize(600, 600, "Ball Demo");
	return 0;
}