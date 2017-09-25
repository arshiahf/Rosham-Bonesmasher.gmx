#include "rps_ai.h"

// Default low level rock-paper-scissors gameplay based upon average players with low risk
char rpsNormal(char lastThrow)
{
    // Near-random starting throw
    if(strcmp(TIE, lastResult))
    {
        // Clockwise = 142, Stay = 600, Counterclockwise = 252
        return chanceThrow(lastThrow, 142, 600, 252);
    }
    else if(strcmp(WIN, lastResult))
    {
        // Clockwise = 248, Stay = 567, Counterclockwise = 180
        return chanceThrow(lastThrow, 248, 567, 180);
    }
    else if(strcmp(LOSE, lastResult))
    {
        // Clockwise = 323, Stay = 309, Counterclockwise = 362
        return chanceThrow(lastThrow, 323, 309, 362);
    }

    return lastThrow;
}
