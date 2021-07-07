#include "Print.h"

int color(int R, int G, int B) {
	return ((R << 8) + G << 8) + B;
}

void rect(int x, int y, int w, int h, uint32_t color)
{
	for (int j = y; j < y + h; j++)
		for (int i = x; i < x + w; i++)
			if (i < SCREEN_WIDTH && j < SCREEN_HEIGHT && j >= 0 && i >= 0)
				buffer[j][i] = color;
}

void printDigit(int n, int x, int y)
{
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 4; i++)
		{
			uint32_t clr = nums[n][j][i] ? color(255, 255, 255) : color(0, 0, 0);
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					buffer[j * 2 + y + k][i * 2 + x + l] = clr;
		}
}

void printPressR(int n, int x, int y)
{
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 5; i++)
		{
			uint32_t clr = pressR[n][j][i] ? color(255, 255, 255) : color(0, 0, 0);
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					buffer[j * 2 + y + k][i * 2 + x + l] = clr;
		}
}

void printLetter(int n, int x, int y)
{
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 5; i++)
		{
			uint32_t clr = letters[n][j][i] ? color(255, 30, 30) : color(0, 0, 0);
			for (int k = 0; k < 8; k++)
				for (int l = 0; l < 8; l++)
					buffer[j * 8 + y + k][i * 8 + x + l] = clr;
		}
}