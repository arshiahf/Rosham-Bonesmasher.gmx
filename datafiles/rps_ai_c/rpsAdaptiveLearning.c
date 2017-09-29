#include "rps_ai.h"

const char CLOCKWISE[] = "clockwise";
const char COUNTERCLOCKWISE[] = "counterclockwise";

double rockClockwiseWin;
double rockCounterClockwiseWin;
double rockClockwiseLose;
double rockCounterClockwiseLose;
double paperClockwiseWin;
double paperCounterClockwiseWin;
double paperClockwiseLose;
double paperCounterClockwiseLose;
double scissorsClockwiseWin;
double scissorsCounterClockwiseWin;
double scissorsClockwiseLose;
double scissorsCounterClockwiseLose;

void calculateHabitShiftThrowType(const char * playerHistory, const char * resultHistory);
const char * determineDirection(char init, char second);

char rpsAdaptiveLearning(const char * playerHistory, const char * cpuHistory, const char * resultHistory)
{
    if(0)
    {

    }
    else
    {
        return rpsNormal(cpuLast);
    }
}

void calculateHabitShiftThrowType(const char * playerHistory, const char * resultHistory)
{
    int totalRock;
    int totalPaper;
    int totalScissors;

    int i = 0;
    while(i < totalThrows)
    {
        int historyRock = playerHistory[i - 1] == ROCK;
        int historyPaper = playerHistory[i - 1] == PAPER;
        int historyScissors = playerHistory[i - 1] == SCISSORS;
        int historyNextRock = playerHistory[i] == ROCK;
        int historyNextPaper = playerHistory[i] == PAPER;
        int historyNextScissors = playerHistory[i] == SCISSORS;
        int historyWin = resultHistory[i] == WIN;
        int historyLose = resultHistory[i] == LOSE;
        int historyTie = resultHistory[i] == TIE;
        if(historyRock)
        {
            if(historyWin && historyNextRock)
            {

            }
        }
        else if(historyPaper)
        {

        }
        else if(historyScissors)
        {

        }
        i++;
    }
}

const char * determineDirection(char init, char second)
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
        return "";
    }
}
