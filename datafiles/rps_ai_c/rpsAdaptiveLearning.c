#include "rps_ai.h"

const char CLOCKWISE = 'c';
const char COUNTERCLOCKWISE = 'C';



void calculateHabitShift(const char * playerHistory, const char * resultHistory, int *totalThrows);
const char determineDirection(char init, char second);

char rpsAdaptiveLearning(const char * playerHistory, const char * cpuHistory, const char * resultHistory)
{
    int *totalThrows = 0;
    calculateHabitShift(playerHistory, resultHistory, totalThrows);

    if(0)
    {

    }
    else
    {
        return rpsNormal(cpuLast);
    }
}

void calculateHabitShift(const char * playerHistory, const char * resultHistory, int *totalThrows)
{
    int totalThrowWin;
    int totalThrowLose;
    int totalThrowTie;

    int totalClockwiseWin;
    int totalCounterClockwiseWin;
    int totalClockwiseLose;
    int totalCounterClockwiseLose;
    int totalClockwiseTie;
    int totalCounterClockwiseTie;

    int throwClockwiseWinCount;
    int throwCounterClockwiseWinCount;
    int throwClockwiseLoseCount;
    int throwCounterClockwiseLoseCount;
    int throwClockwiseTieCount;
    int throwCounterClockwiseTieCount;

    double clockwiseWin;
    double counterClockwiseWin;
    double clockwiseLose;
    double counterClockwiseLose;
    double clockwiseTie;
    double counterClockwiseTie;

    double throwClockwiseWin;
    double throwCounterClockwiseWin;
    double throwClockwiseLose;
    double throwCounterClockwiseLose;
    double throwClockwiseTie;
    double throwCounterClockwiseTie;

    int i = 0;
    while(i < strlen(resultHistory))
    {
        int historySame = playerHistory[i + 1] == playerHistory[1];
        int historyWin = resultHistory[i] == WIN;
        int historyLose = resultHistory[i] == LOSE;
        int historyTie = resultHistory[i] == TIE;
        if(historyWin)
        {
            switch (determineDirection(playerHistory[i + 1], playerHistory[i]))
            {
                case 'c':
                    if(historySame)throwClockwiseWinCount++;
                    totalClockwiseWin++;
                    break;
                case 'C':
                    if(historySame)throwCounterClockwiseWinCount++;
                    totalCounterClockwiseWin++;
                    break;
                default:
                    break;
            }
            if(historySame)totalThrowWin++;
            numWin++;
        }
        else if(historyLose)
        {
            switch (determineDirection(playerHistory[i + 1], playerHistory[i]))
            {
                case 'c':
                    if(historySame)throwClockwiseLoseCount++;
                    totalClockwiseLose++;
                    break;
                case 'C':
                    if(historySame)throwCounterClockwiseLoseCount++;
                    totalCounterClockwiseLose++;
                    break;
                default:
                    break;
            }
            if(historySame)totalThrowLose++;
            numLoss++;
        }
        else if(historyTie)
        {
            switch (determineDirection(playerHistory[i + 1], playerHistory[i]))
            {
                case 'c':
                    if(historySame)throwClockwiseTieCount++;
                    totalClockwiseTie++;
                    break;
                case 'C':
                    if(historySame)throwCounterClockwiseTieCount++;
                    totalCounterClockwiseTie++;
                    break;
                default:
                    break;
            }
            if(historySame)totalThrowTie++;
            numTie++;
        }

        *totalThrows++;
        i++;
    }

    //Calculate chances you shift from throw
    if(totalThrowWin)
    {
        throwClockwiseWin = throwClockwiseWinCount / totalThrowWin;
        throwCounterClockwiseWin = throwCounterClockwiseWinCount / totalThrowWin;
    }

    if(totalThrowLose)
    {
        throwClockwiseLose = throwClockwiseLoseCount / totalThrowLose;
        throwCounterClockwiseLose = throwCounterClockwiseLoseCount / totalThrowLose;
    }

    if(totalThrowTie)
    {
        throwClockwiseTie = throwClockwiseTieCount / totalThrowTie;
        throwCounterClockwiseTie = throwCounterClockwiseTieCount / totalThrowTie;
    }

    //Calculate overall shift chances
    if(numWin)
    {
        clockwiseWin = totalClockwiseWin / numWin;
        counterClockwiseWin = totalCounterClockwiseWin / numWin;
    }

    if(numLoss)
    {
        clockwiseLose = totalCounterClockwiseLose / numLoss;
        counterClockwiseLose = totalCounterClockwiseLose / numLoss;
    }

    if(numTie)
    {
        clockwiseTie = totalClockwiseTie / numTie;
        counterClockwiseTie = totalCounterClockwiseTie / numTie;
    }
}

const char determineDirection(char init, char second)
{
    int rockInit = (init == ROCK);
    int paperInit = (init == PAPER);
    int scissorsInit = (init == SCISSORS);
    int rockSecond = (second == ROCK);
    int paperSecond = (second == PAPER);
    int scissorsSecond = (second == SCISSORS);
    if((rockInit && scissorsSecond) || (paperInit && rockSecond) || (scissorsInit && paperSecond))
    {
        return CLOCKWISE;
    }
    else if((rockInit && paperSecond) || (paperInit && scissorsSecond) || (scissorsInit && rockSecond))
    {
        return COUNTERCLOCKWISE;
    }
    else
    {
        return 0;
    }
}
