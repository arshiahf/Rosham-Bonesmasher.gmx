#include "rps_ai.h"

const char CLOCKWISE = 'c';
const char COUNTERCLOCKWISE = 'C';



void calculateHabitShift(const char * playerHistory, const char * resultHistory);
const char determineDirection(char init, char second);

char rpsAdaptiveLearning(const char * playerHistory, const char * cpuHistory, const char * resultHistory)
{
    calculateHabitShift(playerHistory, resultHistory);

    if(0)
    {

    }
    else
    {
        return rpsNormal(cpuLast);
    }
}

void calculateHabitShift(const char * playerHistory, const char * resultHistory)
{
    int totalRock;
    int totalPaper;
    int totalScissors;

    int totalRockWin;
    int totalRockLose;
    int totalRockTie;

    int totalPaperWin;
    int totalPaperLose;
    int totalPaperTie;

    int totalScissorsWin;
    int totalScissorsLose;
    int totalScissorsTie;

    int totalClockwiseWin;
    int totalCounterClockwiseWin;
    int totalClockwiseLose;
    int totalCounterClockwiseLose;
    int totalClockwiseTie;
    int totalCounterClockwiseTie;

    int rockClockwiseWinCount;
    int rockCounterClockwiseWinCount;
    int rockClockwiseLoseCount;
    int rockCounterClockwiseLoseCount;
    int rockClockwiseTieCount;
    int rockCounterClockwiseTieCount;

    int paperClockwiseWinCount;
    int paperCounterClockwiseWinCount;
    int paperClockwiseLoseCount;
    int paperCounterClockwiseLoseCount;
    int paperClockwiseTieCount;
    int paperCounterClockwiseTieCount;

    int scissorsClockwiseWinCount;
    int scissorsCounterClockwiseWinCount;
    int scissorsClockwiseLoseCount;
    int scissorsCounterClockwiseLoseCount;
    int scissorsClockwiseTieCount;
    int scissorsCounterClockwiseTieCount;

    double clockwiseWin;
    double counterClockwiseWin;
    double clockwiseLose;
    double counterClockwiseLose;
    double clockwiseTie;
    double counterClockwiseTie;

    double rockClockwiseWin;
    double rockCounterClockwiseWin;
    double rockClockwiseLose;
    double rockCounterClockwiseLose;
    double rockClockwiseTie;
    double rockCounterClockwiseTie;

    double paperClockwiseWin;
    double paperCounterClockwiseWin;
    double paperClockwiseLose;
    double paperCounterClockwiseLose;
    double paperClockwiseTie;
    double paperCounterClockwiseTie;

    double scissorsClockwiseWin;
    double scissorsCounterClockwiseWin;
    double scissorsClockwiseLose;
    double scissorsCounterClockwiseLose;
    double scissorsClockwiseTie;
    double scissorsCounterClockwiseTie;

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
            if(historyWin)
            {
                if(historyNextPaper)
                {
                    rockCounterClockwiseWinCount++;
                    totalCounterClockwiseWin++;
                }
                else if(historyNextScissors)
                {
                    rockClockwiseWinCount++;
                    totalClockwiseWin++;
                }
                totalRockWin++;
                numWin++;
            }
            else if(historyLose)
            {
                if(historyNextPaper)
                {
                    rockCounterClockwiseLoseCount++;
                    totalCounterClockwiseLose++;
                }
                else if(historyNextScissors)
                {
                    rockClockwiseLoseCount++;
                    totalClockwiseLose++;
                }
                totalRockLose++;
                numLoss++;
            }
            else if(historyTie)
            {
                if(historyNextPaper)
                {
                    rockCounterClockwiseTieCount++;
                    totalCounterClockwiseTie++;
                }
                else if(historyNextScissors)
                {
                    rockClockwiseTieCount++;
                    totalClockwiseTie++;
                }
                totalRockTie++;
                numTie++;
            }

            totalRock++;
        }
        else if(historyPaper)
        {
            if(historyWin)
            {
                if(historyNextRock)
                {
                    paperClockwiseWinCount++;
                    totalClockwiseWin++;
                }
                else if(historyNextScissors)
                {
                    paperCounterClockwiseWinCount++;
                    totalCounterClockwiseWin++;
                }
                totalPaperWin++;
                numWin++;
            }
            else if(historyLose)
            {
                if(historyNextRock)
                {
                    paperClockwiseLoseCount++;
                    totalClockwiseLose++;
                }
                else if(historyNextScissors)
                {
                    paperCounterClockwiseLoseCount++;
                    totalCounterClockwiseLose++;
                }
                totalPaperLose++;
                numLoss++;
            }
            else if(historyTie)
            {
                if(historyNextRock)
                {
                    paperClockwiseTieCount++;
                    totalClockwiseTie++;
                }
                else if(historyNextScissors)
                {
                    paperCounterClockwiseTieCount++;
                    totalCounterClockwiseTie++;
                }
                totalPaperTie++;
                numTie++;
            }

            totalPaper++;
        }
        else if(historyScissors)
        {
            if(historyWin)
            {
                if(historyNextRock)
                {
                    scissorsCounterClockwiseWinCount++;
                    totalCounterClockwiseWin++;
                }
                else if(historyNextPaper)
                {
                    scissorsClockwiseWinCount++;
                    totalClockwiseWin++;
                }
                totalScissorsWin++;
                numWin++;
            }
            else if(historyLose)
            {
                if(historyNextRock)
                {
                    scissorsCounterClockwiseLoseCount++;
                    totalCounterClockwiseLose++;
                }
                else if(historyNextPaper)
                {
                    scissorsClockwiseLoseCount++;
                    totalClockwiseLose++;
                }
                totalScissorsLose++;
                numLoss++;
            }
            else if(historyTie)
            {
                if(historyNextRock)
                {
                    scissorsCounterClockwiseTieCount++;
                    totalCounterClockwiseTie++;
                }
                else if(historyNextPaper)
                {
                    scissorsClockwiseTieCount++;
                    totalClockwiseTie++;
                }
                totalScissorsTie++;
                numTie++;
            }

            totalScissors++;
        }
        totalThrows++;
        i++;
    }

    //Calculate chances you shift from rock
    if(totalRockWin)
    {
        rockClockwiseWin = rockClockwiseWinCount / totalRockWin;
        rockCounterClockwiseWin = rockCounterClockwiseWinCount / totalRockWin;
    }

    if(totalRockLose)
    {
        rockClockwiseLose = rockClockwiseLoseCount / totalRockLose;
        rockCounterClockwiseLose = rockCounterClockwiseLoseCount / totalRockLose;
    }

    if(totalRockTie)
    {
        rockClockwiseTie = rockClockwiseTieCount / totalRockTie;
        rockCounterClockwiseTie = rockCounterClockwiseTieCount / totalRockTie;
    }

    //Calculates chances you shift from paper
    if(totalPaperWin)
    {
        paperClockwiseWin = paperClockwiseWinCount / totalPaperWin;
        paperCounterClockwiseWin = paperCounterClockwiseWinCount / totalPaperWin;
    }

    if(totalPaperLose)
    {
        paperClockwiseLose = paperClockwiseLoseCount / totalPaperLose;
        paperCounterClockwiseLose = paperCounterClockwiseLoseCount / totalPaperLose;
    }

    if(totalPaperTie)
    {
        paperClockwiseTie = paperClockwiseTieCount / totalPaperTie;
        paperCounterClockwiseTie = paperCounterClockwiseTieCount / totalPaperTie;
    }

    //Calculates chances you shift from scissors
    if(totalScissorsWin)
    {
        scissorsClockwiseWin = scissorsClockwiseWinCount / totalScissorsWin;
        scissorsCounterClockwiseWin = scissorsCounterClockwiseWinCount / totalScissorsWin;
    }

    if(totalScissorsLose)
    {
        scissorsClockwiseLose = scissorsClockwiseLoseCount / totalScissorsLose;
        scissorsCounterClockwiseLose = scissorsCounterClockwiseLoseCount / totalScissorsLose;
    }

    if(totalScissorsTie)
    {
        scissorsClockwiseTie = scissorsClockwiseTieCount / totalScissorsTie;
        scissorsCounterClockwiseTie = scissorsCounterClockwiseTieCount / totalScissorsTie;
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
