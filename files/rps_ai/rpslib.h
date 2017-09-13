#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

#ifndef __RPSLIB_H__
#define __RPSLIB_H__

#include <windows.h>

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
            newThrow = 's';
            break;
        case 'p':
            newThrow = 'r';
            break;
        case 's':
            newThrow = 'p';
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
            newThrow = 'p';
            break;
        case 'p':
            newThrow = 's';
            break;
        case 's':
            newThrow = 'r';
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
