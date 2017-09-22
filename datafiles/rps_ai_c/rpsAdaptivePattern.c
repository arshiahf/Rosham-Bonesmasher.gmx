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

        while(patternSize > 2)
        {
            char playerPattern[patternSize + 1];
            int p = 0;
            while(p < patternSize && !(playerPatternMatch))
            {
                playerPattern[p] = playerHistory[p + 1];
                p++;
            }

            if(!(playerPatternMatch))
            {
                int j = patternSize + 2;
                while(j < strlen(playerHistory) - 1)
                {
                    if(!(playerPatternMatch))
                    {
                        int k = 0;
                        while(k <= patternSize)
                        {
                            if(playerPattern[patternSize - k - 1] != playerHistory[j - k])
                            {
                                break;
                            }
                            else if(k == patternSize - 1)
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
            return ' ';//rpsNormal(cpuLast);
        }
    }
    else
    {
        return ' ';//rpsNormal(cpuLast);
    }
}
