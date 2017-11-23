#include "rps_ai.h"

// Difficulty values
const char HARD[] = "hard";
const char HARDER[] = "harder";
const char ADAPTIVEPATTERN[] = "adaptivepattern";
const char ADAPTIVELEARNING[] = "adaptivelearning";

// Throw values
const char VERYLOW[] = "vlow";
const char LOW[] = "low";
const char MEDIUM[] = "medium";
const char HIGH[] = "high";
const char VERYHIGH[] = "vhigh";

// Declare return variable
char rpsThrow[2];

// rps_define local functions
char rpsFirst();

// Returns a pseudo-random number using the system clock as a seed
int randnum(int cap)
{
    srand(clock());
    int num = rand() % cap + 1;
    return num;
}

// Returns throw based upon difficulty and player input
// resultHistory is the history of the game from the player's perspective

GMEXPORT char *rpsReturn(const char *difficulty, char *playerInput, char *cpuHistory, char *resultHistory)
{
    rpsThrow[1] = '\0';

    if(strlen(playerInput) == 1)
    {
        rpsThrow[0] = rpsFirst();
        return rpsThrow;
    }

    char cpuLast = cpuHistory[0];
    char lastResult = resultHistory[0];

    if(!(strcmp(HARD, difficulty)))
    {
        //setResult(resultHistory);
        //rpsThrow[0] = rpsHard(cpuLast);
    }
    else if(!(strcmp(HARDER, difficulty)))
    {
        //setResult(resultHistory);
        //rpsThrow[0] = rpsHarder(cpuLast);
    }
    else if(!(strcmp(ADAPTIVEPATTERN, difficulty)))
    {
        rpsThrow[0] = rpsAdaptivePattern(playerInput, cpuLast, lastResult);
    }
    else if(!(strcmp(ADAPTIVELEARNING, difficulty)))
    {
        rpsThrow[0] = rpsAdaptiveLearning(playerInput, cpuHistory, resultHistory);
    }
    else
    {
        rpsThrow[0] = rpsNormal(cpuLast, lastResult);
    }

    return rpsThrow;
}

//------------------------------------------------------ Statistics-based AI ---------------------------------------------------------------//

// Returns a throw based upon the average statistics of a first throw

char rpsFirst()
{
    double firstThrow = randnum(101);

    if(firstThrow <= 37)
    {
        return ROCK;
    }
    else if(firstThrow <= 71)
    {
        return PAPER;
    }
    else
    {
        return SCISSORS;
    }
}

// Calculates approximate value of throw

const char * throwValue(int toWin, int localWin, int localLoss, int localTie)
{
    int localTotal = localWin + localLoss + localTie;
    int playerToWin = toWin - localWin;
    int compToWin = toWin - localLoss;
    int losingLocal = playerToWin < compToWin;
    int winningLocal = playerToWin > compToWin;
    int manyThrows = localTotal >= toWin;
    double localPlayerWinRatio = playerToWin / toWin;
    double localCompWinRatio = compToWin / toWin;
    double localTieRatio = localTie / localTotal;
    double playerWinningRatio = localWin / localTotal;
    double compWinningRatio = localLoss / localTotal;

    if((manyThrows && losingLocal) || (manyThrows && winningLocal) || (localCompWinRatio > 0.5) || (localPlayerWinRatio > 0.5) || (manyThrows && (localTieRatio > (1/3))) || (losingLocal && (compWinningRatio > 0.25)) || (winningLocal && (playerWinningRatio > 0.25)))
    {
       if(1)
       {
           if(1)
           {
               if (1)
               {
                   return VERYHIGH;
               }
               return HIGH;
           }
           return MEDIUM;
       }
       return LOW;
    }
    else
    {
        return VERYLOW;
    }

}

// A throw response that moves clockwise on the rock-paper-scissors triangle. This means that the person moves from their last throw to the throw that beat it
char clockwiseThrow(char lastThrow)
{
    switch(lastThrow)
    {
        case ROCK:
            return SCISSORS;
        case PAPER:
            return ROCK;
        case SCISSORS:
            return PAPER;
    }

    return lastThrow;
}

// A throw response that moves counterclockwise on the rock-paper-scissors triangle. This means that the person moves from their last throw to the throw that it would beat
char counterclockwiseThrow(char lastThrow)
{
    switch(lastThrow)
    {
        case ROCK:
            return PAPER;
        case PAPER:
            return SCISSORS;
        case SCISSORS:
            return ROCK;
    }

    return lastThrow;
}

// An algorithm that randomly chooses what kind of throw to use(clockwise, stay, counterclockwise) based upon input statistics
char chanceThrow(char lastThrow, int clockwise, int counterclockwise)
{
    int stay = 1000 - (clockwise + counterclockwise);
    int newThrow = randnum(1000);

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
