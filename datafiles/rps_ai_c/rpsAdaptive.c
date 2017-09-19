#include "rps_ai.h"

char rpsAdaptive()
{
    if(strlen(playerHistory) > 3)
    {
        char playerPatternMatch;
        int patternSize;

        if(strlen(playerHistory) > 7)
        {
            patternSize = 6;
        }
        else
        {
            patternSize = strlen(playerHistory) - 1;
        }

        char playerPattern[patternSize + 1];

        strncpy(playerPattern, playerHistory, patternSize);

        while(patternSize > 2)
        {
            if(!(playerPatternMatch))
            {
                int j = patternSize;
                while(j < strlen(playerHistory))
                {
                    if(!(playerPatternMatch))
                    {
                        int k = 0;
                        while(k < patternSize)
                        {
                            if(playerPattern[patternSize - k - 1] != playerHistory[j - k - 1])
                            {
                                break;
                            }
                            else if(k == patternSize)
                            {
                                playerPatternMatch = playerHistory[j - patternSize];
                                break;
                            }
                            k++;
                        }
                    }
                    else
                    {
                        break;
                    }
                    j++;
                }
            }
            else
            {
                break;
            }
            patternSize--;
        }

        return counterclockwiseThrow(playerPatternMatch);
    }
    else
    {
        return rpsNormal(playerHistory[0]);
    }
}
