#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
const char FIRSTTHROW = 'f';

#ifndef __RPSLIB_H__
#define __RPSLIB_H__


#ifdef BUILD_DLL
    #define GMEXPORT extern __declspec(dllexport)
#else
    #define GMEXPORT extern __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

GMEXPORT char * rpsNormal(char lastThrow, double winLast, double tieLast);
GMEXPORT double testRun();
//GMEXPORT void SomeFunction(const LPCSTR sometext);
double randnum(int cap);
char clockwiseThrow(char lastThrow);
char counterclockwiseThrow(char lastThrow);
char chanceThrow(char lastThrow, double clockwise, double stay, double counterclockwise);

#ifdef __cplusplus
}
#endif

double randnum(int cap)
{
    srand(time(NULL));
    double num = rand() % cap + 1;
    return num;
}

char clockwiseThrow(char lastThrow)
{
    char newThrow;
    switch(lastThrow)
    {
        case 'r':
            newThrow = SCISSORS;
            break;
        case 'p':
            newThrow = ROCK;
            break;
        case 's':
            newThrow = PAPER;
            break;
    }
    return newThrow;
}

char counterclockwiseThrow(char lastThrow)
{
    char newThrow;
    switch(lastThrow)
    {
        case 'r':
            newThrow = PAPER;
            break;
        case 'p':
            newThrow = SCISSORS;
            break;
        case 's':
            newThrow = ROCK;
            break;
    }
    return newThrow;
}

char chanceThrow(char lastThrow, double clockwise, double stay, double counterclockwise)
{
    double total = clockwise + stay + counterclockwise;
    double newThrow = randnum(total);

    if(newThrow <= clockwise) // Throws clockwise
    {
        return clockwiseThrow(lastThrow);
    }
    else if(clockwise < newThrow && newThrow <= (clockwise + stay)) // Throws same
    {
        return lastThrow;
    }
    else if((clockwise + stay) < newThrow) // Throws counterclockwise
    {
        return counterclockwiseThrow(lastThrow);
    }

    return lastThrow;
}

#endif // __RPSLIB_H__
