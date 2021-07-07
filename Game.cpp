#include "Engine.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <vector>
#include "Bird.h"
#include "Tube.h"
#include "Structs.h"
#include "Apples.h"
#include "Print.h"
#include "GameManager.h"

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()


//score 
const int scoreX = 100;
const int scoreY = 10;
//tube
//


//int nums[40][8];

Bird bird(startPosX, startPosY, birdSpeedX, birdSpeedY);
std::vector<Tube> tubes;
std::vector<Apple> apples;
GameManager gm(&tubes, &apples);


void resetTubes()
{
	bird.reset();
	tubes.clear();
	apples.clear();

}

// initialize game data in this function
void initialize()
{
	srand(time(0));

	resetTubes();

	FILE* f;
	if (fopen_s(&f, "HiScore.txt", "r") == 0)
	{
		int n;
		fscanf_s(f, "%d", &n);
		gm.setHiScore(n);
		fclose(f);
	}
}


// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
	if (is_key_pressed(VK_ESCAPE))
		schedule_quit_game();
	if (is_key_pressed(VK_SPACE))
	{
		bird.wing();
	}
	

	bird.move(dt);
	gm.passTime(dt);

	if (bird.isAlive())
	{
		for (auto it = tubes.begin(); it != tubes.end(); it++)
		{
			it->move(dt);
			gm.addScore(it->checkCollision(bird));
			if (it->isOut())
				it = tubes.erase(it);
		}

		for (auto it = apples.begin(); it != apples.end(); it++)
		{
			it->move(dt);
			gm.addScore(it->checkCollision(bird));
			if (it->isOut())
			{
				it = apples.erase(it);
				if (it == apples.end())
					break;
			}
		}
	}
	else
	{
		gm.dead();
		for (auto& tube : tubes)
		{
			tube.move(0);
		}
		if (is_key_pressed('R'))
		{
			resetTubes();
			gm.Init();
		}
	}
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)




void draw()
{
	// clear backbuffer
	memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
	//bird body
	rect(bird.getX(), bird.getY(), birdSizeX, birdSizeY, color(50, 255, 199));
	rect(bird.getX() + birdSizeX, bird.getY() + 7, birdHeadSizeX, birdHeadSizeY, color(255, 30, 30));
	//bird fly
	if (int(bird.getV()) > 0)
		rect(bird.getX() + 5, bird.getY() - 10, birdWingSizeX, birdWingSizeY, color(50, 255, 199));
	else
		rect(bird.getX() + 2, bird.getY() + 15, birdWingSizeX, birdWingSizeY, color(200, 200, 250));
	//tubes
	for (auto& tube : tubes)
	{
		rect(tube.getX(), 0, tube.getW(), tube.getY(), color(30, 255, 30));
		rect(tube.getX(), tube.getY() + tube.getH(), tube.getW(), SCREEN_HEIGHT - (tube.getY() + tube.getH()), color(30, 255, 30));
	}
	//apples
	for (auto& apple : apples)
	{
		rect(apple.getX(), apple.getY(), apple.getW(), apple.getH(), color(255, 30, 30));
	}
	//check stop game
	if (bird.isAlive())
	{
		int n = gm.getScore();
		for (int i = 10; i >= 0; i--)
		{
			printDigit(n % 10, scoreX + i * 10, scoreY);
			n /= 10;
		}
	}
	else
	{
		//black back
		rect(startPosX - 150, startPosY - 160, 390, 80, color(0, 0, 0));
		rect(startPosX - 48, startPosY + 50, 130, 120 , color(0, 0, 0));
		
		int n = gm.getScore();
		for (int i = 10; i >= 0; i--)
		{
			printDigit(n % 10, startPosX + (i - 4) * 12, startPosY + 50);
			n /= 10;
		}
		n = gm.getTopScore();
		for (int i = 10; i >= 0; i--)
		{
			printDigit(n % 10, startPosX + (i - 4) * 12, startPosY + 130);
			n /= 10;
		}
		for (int i = 0; i < 8; i++)
		{

			printLetter(i, startPosX + (i - 3) * 48, startPosY - 150);
		}
		for (int i = 0; i < 7; i++)
		{

			printPressR(i, startPosX + (i - 2) * 12, startPosY + 100);
		}
	}
}

// free game data in this function
void finalize()
{
	FILE* f;
	if (fopen_s(&f, "HiScore.txt", "w") == 0)
	{
		fprintf(f, "%d", gm.getTopScore());
		fclose(f);
	}
}