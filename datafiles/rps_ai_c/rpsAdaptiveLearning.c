#include "rps_ai.h"

// Possible directions
#define CLOCKWISE 'c'
#define COUNTERCLOCKWISE 'C'

int *calculateHabitShift(const char *playerHistory, const char *resultHistory, int totalThrows);
const char determineDirection(char init, char second);
char decideThrow(int clockwiseChance);
const char learningThrow(char lastThrow, int clockwise, int counterClockwise);

char rpsAdaptiveLearning(const char *playerHistory, const char *cpuHistory, const char *resultHistory)
{
    int totalThrows = 0;
    char returnthrow;
    char playerLast = playerHistory[1];
    char lastResult = resultHistory[0];
    char cpuLast = cpuHistory[0];

    // Win Cw, Win CCw, Lose Cw, Lose CCw, Tie Cw, Tie CCw
    int *absoluteThrows = calculateHabitShift(playerHistory, resultHistory, totalThrows);

    if(lastResult)
    {
        switch(lastResult)
        {
            case WIN:
            case ROUNDWIN:
                returnthrow = learningThrow(playerLast, absoluteThrows[0], absoluteThrows[1]);
                break;
            case LOSE:
            case ROUNDLOSE:
                returnthrow = learningThrow(playerLast, absoluteThrows[2], absoluteThrows[3]);
                break;
            case TIE:
                returnthrow = learningThrow(playerLast, absoluteThrows[4], absoluteThrows[5]);
                break;
            default:
                free(absoluteThrows);
                return rpsNormal(cpuLast, lastResult);
        }
        free(absoluteThrows);
        return counterclockwiseThrow(returnthrow);

    }
    else
    {
        free(absoluteThrows);
        return rpsNormal(cpuLast, lastResult);
    }
}

int* calculateHabitShift(const char *playerHistory, const char *resultHistory, int totalThrows)
{
    int *absThrows = (int*)malloc(6 * sizeof(int));

    int numWin=0, numLoss=0, numTie=0;

    int totalThrowWin=0, totalThrowLose=0, totalThrowTie=0;

    int totalClockwiseWin=0, totalCounterClockwiseWin=0;
    int totalClockwiseLose=0, totalCounterClockwiseLose=0;
    int totalClockwiseTie=0, totalCounterClockwiseTie=0;

    int throwClockwiseWinCount=0, throwCounterClockwiseWinCount=0;
    int throwClockwiseLoseCount=0, throwCounterClockwiseLoseCount=0;
    int throwClockwiseTieCount=0, throwCounterClockwiseTieCount=0;

    double clockwiseWin=0, counterClockwiseWin=0;
    double clockwiseLose=0, counterClockwiseLose=0;
    double clockwiseTie=0, counterClockwiseTie=0;

    double throwClockwiseWin=0, throwCounterClockwiseWin=0;
    double throwClockwiseLose=0, throwCounterClockwiseLose=0;
    double throwClockwiseTie=0, throwCounterClockwiseTie=0;

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
                case CLOCKWISE:
                    if(historySame)throwClockwiseWinCount++;
                    totalClockwiseWin++;
                    break;
                case COUNTERCLOCKWISE:
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
                case CLOCKWISE:
                    if(historySame)throwClockwiseLoseCount++;
                    totalClockwiseLose++;
                    break;
                case COUNTERCLOCKWISE:
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
                case CLOCKWISE:
                    if(historySame)throwClockwiseTieCount++;
                    totalClockwiseTie++;
                    break;
                case COUNTERCLOCKWISE:
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
    int highest = stay;
    char bestThrow = lastThrow;
    int stayClockwise = stay >= clockwise - 5 || stay <= clockwise + 5;
    int stayCounter = stay >= counterClockwise - 5 || stay <= counterClockwise + 5;
    int clockwiseCounter = clockwise >= counterClockwise - 5 || clockwise <= counterClockwise + 5;
    int allSame = stayClockwise && stayCounter && clockwiseCounter;

    if(clockwise > highest)
    {
        highest = clockwise;
        bestThrow = clockwiseThrow(lastThrow);
    }
    if(counterClockwise > highest)
    {
        highest = counterClockwise;
        bestThrow = counterclockwiseThrow(lastThrow);
    }
    if(allSame)
    {
        int which = randnum(3);
        if(which == 1)
        {
            //Choose clockwise
            bestThrow = clockwiseThrow(lastThrow);
        }
        else if(which == 2)
        {
            //Choose counterclockwise
            bestThrow = counterclockwiseThrow(lastThrow);
        }
        else
        {
            //Choose stay
            bestThrow = lastThrow;
        }
    }
    else if(stayClockwise)
    {
        int which = randnum(2);
        if(which == 1)
        {
            //Choose clockwise
            bestThrow = clockwiseThrow(lastThrow);
        }
        else
        {
            //Choose stay
            bestThrow = lastThrow;
        }
    }
    else if(stayCounter)
    {
        int which = randnum(2);
        if(which == 1)
        {
            //Choose counterclockwise
            bestThrow = counterclockwiseThrow(lastThrow);
        }
        else
        {
            //Choose stay
            bestThrow = lastThrow;
        }
    }
    else if(clockwiseCounter)
    {
        int which = randnum(2);
        if(which == 1)
        {
            //Choose clockwise
            bestThrow = clockwiseThrow(lastThrow);
        }
        else
        {
            //Choose counterclockwise
            bestThrow = counterclockwiseThrow(lastThrow);
        }
    }
    return counterclockwiseThrow(bestThrow);
}
