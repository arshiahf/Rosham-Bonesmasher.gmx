#include "rps_ai.h"

// Basic throw concepts
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

// Difficulty values
const char HARD[] = "hard";
const char HARDER[] = "harder";
const char ADAPTIVEPATTERN[] = "adaptivepattern";
const char ADAPTIVELEARNING[] = "adaptivelearning";

// Possible results
const char TIE = 't';
const char WIN = 'w';
const char LOSE = 'l';
const char ROUNDWIN = 'W';
const char ROUNDLOSE = 'L';

// Throw values
const char VERYLOW[] = "vlow";
const char LOW[] = "low";
const char MEDIUM[] = "medium";
const char HIGH[] = "high";
const char VERYHIGH[] = "vhigh";

// Returns a pseudo-random number using the system clock as a seed
double randnum(int cap)
{
    srand(clock());
    double num = rand() % cap + 1;
    return num;
}

// Returns throw based upon difficulty and player input
// resultHistory is the history of the game from the player's perspective

GMEXPORT char * rpsReturn(const char * difficulty, char * playerInput, char * cpuHistory, char * resultHistory)
{
    if(strlen(playerInput) == 1)
    {
        rpsThrow[0] = rpsFirst();
        return rpsThrow;
    }

    cpuLast = cpuHistory[0];
    lastResult = resultHistory[0];
    setResult(resultHistory);

    if(!(strcmp(HARD, difficulty)))
    {
        //rpsThrow[0] = rpsHard(cpuLast);
    }
    else if(!(strcmp(HARDER, difficulty)))
    {
        //rpsThrow[0] = rpsHarder(cpuLast);
    }
    else if(!(strcmp(ADAPTIVEPATTERN, difficulty)))
    {
        rpsThrow[0] = rpsAdaptivePattern(playerInput);
    }
    else if(!(strcmp(ADAPTIVELEARNING, difficulty)))
    {
        //rpsThrow[0] = rpsAdaptiveLearning(playerInput, cpuHistory, resultHistory);
    }
    else
    {
        rpsThrow[0] = rpsNormal(cpuLast);
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
    else if(37 < firstThrow && firstThrow <= 71)
    {
        return PAPER;
    }
    else
    {
        return SCISSORS;
    }
}

// Calculates the number of wins, losses, tie, and total throws
void setResult(char * lastResultInput)
{
    int i = 0;
    while(i < strlen(lastResultInput))
    {
        char tempRes = lastResultInput[i];
        if(TIE == tempRes)
        {
            numTie++;
        }
        else if(WIN == tempRes || ROUNDWIN == tempRes)
        {
            numWin++;
        }
        else
        {
            numLoss++;
        }
        totalThrows++;
        i++;
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
        case 'r':
            return SCISSORS;
        case 'p':
            return ROCK;
        case 's':
            return PAPER;
    }

    return lastThrow;
}

// A throw response that moves counterclockwise on the rock-paper-scissors triangle. This means that the person moves from their last throw to the throw that it would beat
char counterclockwiseThrow(char lastThrow)
{
    switch(lastThrow)
    {
        case 'r':
            return PAPER;
        case 'p':
            return SCISSORS;
        case 's':
            return ROCK;
    }

    return lastThrow;
}

// Decides if computer changes throw based upon input percentages
char oddsShift(char lastThrow, double clockwiseChance, double counterClockwiseChance)
{
    int shiftYN = randnum(1000);

    int clockwiseLimit = clockwiseChance * 1000;
    int counterClockwiseLimit = counterClockwiseChance * 1000;

    if(shiftYN <= clockwiseLimit)
    {
        return clockwiseThrow(lastThrow);
    }
    else if((clockwiseLimit < shiftYN) && (shiftYN <= (clockwiseLimit + counterClockwiseLimit)))
    {
        return counterclockwiseThrow(lastThrow);
    }
    else
    {
        return lastThrow;
    }
}

// An algorithm that randomly chooses what kind of throw to use(clockwise, stay, counterclockwise) based upon input statistics
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

//------------------------------------------------------ Adaptive AI -----------------------------------------------------------------------//

//
