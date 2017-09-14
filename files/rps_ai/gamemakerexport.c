#include "rpslib.h"

// Default low level rock-paper-scissors gameplay based upon average players with low risk
GMEXPORT char rpsNormal(double lastThrow, double winLast, double tieLast)
{
    char rpsThrow;
    return 1;

    // Near-random starting throw
    if(/*strcmp(&lastThrow, &FIRSTTHROW)*/ !(lastThrow) && !(winLast) && !(tieLast))
    {
        double firstThrow = randnum(101);

        if(firstThrow <= 37)
        {
            rpsThrow = ROCK;
        }
        else if(37 < firstThrow && firstThrow <= 71)
        {
            rpsThrow = PAPER;
        }
        else if(firstThrow > 71)
        {
            rpsThrow = SCISSORS;
        }
    }
    else if(tieLast && !(winLast))
    {
        // Clockwise = 142, Stay = 600, Counterclockwise = 252
        rpsThrow = chanceThrow(lastThrow, 142, 600, 252);
    }
    else if(!(tieLast) && winLast)
    {
        // Clockwise = 248, Stay = 567, Counterclockwise = 180
        rpsThrow = chanceThrow(lastThrow, 248, 567, 180);
    }
    else if(!(tieLast) && !(winLast))
    {
        // Clockwise = 323, Stay = 309, Counterclockwise = 362
        rpsThrow = chanceThrow(lastThrow, 323, 309, 362);
    }

    return rpsThrow;
}

GMEXPORT double testRun()
{
    return 10;
}
