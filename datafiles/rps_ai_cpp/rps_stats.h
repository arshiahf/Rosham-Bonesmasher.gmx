#include "rps_ai.h"

#ifndef __RPS_STATS_H__
#define __RPS_STATS_H__

double randnum(int cap)
{
    srand(clock());
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

#endif // __RPS_STATS_H__
