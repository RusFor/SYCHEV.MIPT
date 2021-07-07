#pragma once

#include <cstdint>
#include "Engine.h"
#include "Structs.h"

int color(int R, int G, int B);

void rect(int x, int y, int w, int h, uint32_t color);

void printDigit(int n, int x, int y);

void printPressR(int n, int x, int y);

void printLetter(int n, int x, int y);

