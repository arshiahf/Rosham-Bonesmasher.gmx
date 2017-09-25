#include "rps_ai.h"

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
const char FIRSTTHROW = 'f';

const char HARD[] = "hard";
const char HARDER[] = "harder";
const char ADAPTIVEPATTERN[] = "adaptivepattern";
const char ADAPTIVELEARNING[] = "adaptivelearning";

const char TIE[] = "tie";
const char WIN[] = "win";
const char LOSE[] = "lose";

// Returns a pseudo-random number using the system clock as a seed
double randnum(int cap)
{
    srand(clock());
    double num = rand() % cap + 1;
    return num;
}

// Returns throw based upon difficulty and player input

GMEXPORT char * rpsReturn(const char * difficulty, char * playerInput, char * cpuHistory, char * lastResultInput)
{
    if(strlen(playerInput) == 1)
    {
        rpsThrow[0] = rpsFirst();
        return rpsThrow;
    }

    cpuLast = cpuHistory[0];
    setResult(lastResultInput);

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
        //rpsThrow[0] = rpsAdaptiveLearning(playerInput, cpuHistory);
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

// Sets global last response variable
void setResult(char * lastResultInput)
{
    if(strcmp(TIE, lastResultInput))
    {
        lastResult = "tie";
    }
    else if(strcmp(WIN, lastResultInput))
    {
        lastResult = "win";
    }
    else
    {
        lastResult = "lose";
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

