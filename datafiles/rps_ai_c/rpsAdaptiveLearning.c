#include "rps_ai.h"

const char CLOCKWISE = 'c';
const char COUNTERCLOCKWISE = 'C';



int* calculateHabitShift(const char *playerHistory, const char *resultHistory, int totalThrows, int *absoluteThrows);
const char determineDirection(char init, char second);
char decideThrow(int clockwiseChance);
const char learningThrow(char lastThrow, int clockwise, int counterClockwise);

char rpsAdaptiveLearning(const char * playerHistory, const char * cpuHistory, const char * resultHistory)
{
    int totalThrows = 0;
    char returnthrow;
    char playerLast = playerHistory[1];

    // Win Cw, Win CCw, Lose Cw, Lose CCw, Tie Cw, Tie CCw
    int *absoluteThrows = (int*)malloc(6 * sizeof(int));
    absoluteThrows = calculateHabitShift(playerHistory, resultHistory, totalThrows, absoluteThrows);

    if(resultHistory[0])
    {
        switch(resultHistory[0])
        {
            case 'w':
            case 'W':
                returnthrow = learningThrow(playerLast, absoluteThrows[0], absoluteThrows[1]);
                break;
            case 'l':
            case 'L':
                returnthrow = learningThrow(playerLast, absoluteThrows[2], absoluteThrows[3]);
                break;
            case 't':
                returnthrow = learningThrow(playerLast, absoluteThrows[4], absoluteThrows[5]);
                break;
            default:
                free(absoluteThrows);
                return rpsNormal(cpuHistory[0]);
        }
        free(absoluteThrows);
        return counterclockwiseThrow(returnthrow);

    }
    else
    {
        free(absoluteThrows);
        return rpsNormal(cpuHistory[0]);
    }
}

int* calculateHabitShift(const char *playerHistory, const char *resultHistory, int totalThrows, int *absoluteThrows)
{
    int *absThrows = (int*)malloc(6 * sizeof(int));

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
        int historyWin = resultHistory[i] == WIN || resultHistory[i] == ROUNDWIN;
        int historyLose = resultHistory[i] == LOSE || resultHistory[i] == ROUNDLOSE;
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

        totalThrows++;
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

    // Calculate absolute shift chance

    if(clockwiseWin && throwClockwiseWin)
    {
        absThrows[0] = (int) 1000 * (clockwiseWin + throwClockwiseWin) / 2;
    }

    if(counterClockwiseWin && throwCounterClockwiseWin)
    {
        absThrows[1] = (int) 1000 * (counterClockwiseWin + throwCounterClockwiseWin) / 2;
    }

    if(clockwiseLose && throwClockwiseLose)
    {
        absThrows[2] = (int) 1000 * (clockwiseLose + throwClockwiseLose) / 2;
    }

    if(counterClockwiseLose && throwCounterClockwiseLose)
    {
        absThrows[3] = (int) 1000 * (counterClockwiseLose + throwCounterClockwiseLose) / 2;
    }

    if(clockwiseTie && throwClockwiseTie)
    {
        absThrows[4] = (int) 1000 * (clockwiseTie + throwClockwiseTie) / 2;
    }

    if(counterClockwiseTie && throwCounterClockwiseTie)
    {
        absThrows[5] = (int) 1000 * (counterClockwiseTie + throwCounterClockwiseTie) / 2;
    }

    return absThrows;
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

const char learningThrow(char lastThrow, int clockwise, int counterClockwise)
{
    int stay = 1000 - (clockwise + counterClockwise);
    return counterclockwiseThrow(lastThrow);
}

