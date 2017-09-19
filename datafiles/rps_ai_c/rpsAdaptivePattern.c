#include "rps_ai.h"

char rpsAdaptivePattern(const char * playerHistory)
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
                while(j < strlen(playerHistory) - 1)
                {
                    if(!(playerPatternMatch))
                    {
                        int k = 0;
                        while(k <= patternSize)
                        {
                            if(playerPattern[patternSize - k] != playerHistory[j - k])
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
        if(playerPatternMatch == ROCK || playerPatternMatch == PAPER || playerPatternMatch == SCISSORS)
        {
            return counterclockwiseThrow(playerPatternMatch);
        }
        else
        {
            return rpsNormal(cpuLast);
        }
    }
    else
    {
        return rpsNormal(cpuLast);
    }
}
