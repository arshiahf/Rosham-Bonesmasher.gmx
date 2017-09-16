#include "rpslib.h"

char rpsThrow[1];

char * testReturn = "f";

// Default low level rock-paper-scissors gameplay based upon average players with low risk
GMEXPORT char * rpsNormal(char lastThrow, double winLast, double tieLast)
{
    // Near-random starting throw
    if(strcmp(&FIRSTTHROW, &lastThrow) && !(winLast) && !(tieLast))
    {
        double firstThrow = randnum(101);

        if(firstThrow <= 37)
        {
            rpsThrow[0] = ROCK;
        }
        else if(37 < firstThrow && firstThrow <= 71)
        {
            rpsThrow[0] = PAPER;
        }
        else if(firstThrow > 71)
        {
            rpsThrow[0] = SCISSORS;
        }
    }
    else if(tieLast && !(winLast))
    {
        // Clockwise = 142, Stay = 600, Counterclockwise = 252
        rpsThrow[0] = chanceThrow(lastThrow, 142, 600, 252);
    }
    else if(!(tieLast) && winLast)
    {
        // Clockwise = 248, Stay = 567, Counterclockwise = 180
        rpsThrow[0] = chanceThrow(lastThrow, 248, 567, 180);
    }
    else if(!(tieLast) && !(winLast))
    {
        // Clockwise = 323, Stay = 309, Counterclockwise = 362
        rpsThrow[0] = chanceThrow(lastThrow, 323, 309, 362);
    }

    return testReturn;
}

GMEXPORT double testRun()
{
    return 10;
}
