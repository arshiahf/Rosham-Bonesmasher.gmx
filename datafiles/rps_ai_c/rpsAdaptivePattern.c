#include "rps_ai.h"

char rpsAdaptivePattern(const char * playerHistory)
{
    if(strlen(playerHistory) > 4)
    {
        char playerPatternMatch;
        int patternSize;

        if(strlen(playerHistory) > 8)
        {
            patternSize = 6;
        }
        else
        {
            patternSize = strlen(playerHistory) - 1;
        }

        while(patternSize > 2)
        {
            int p = 0;
            char playerPattern[patternSize + 1];
            int tempSize = patternSize + 1;
            while(tempSize > 0)
            {
                playerPattern[tempSize] = '\0';
                tempSize--;
            }
            while(p < patternSize && !(playerPatternMatch))
            {
                playerPattern[p] = playerHistory[p + 1];
                p++;
            }

            if(!(playerPatternMatch))
            {
                int j = patternSize + 1;
                while(j < strlen(playerHistory))
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
            return rpsNormal(cpuLast);
        }
    }
    else
    {
        return rpsNormal(cpuLast);
    }
}
