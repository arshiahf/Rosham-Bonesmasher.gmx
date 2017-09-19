#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef __RPS_AI_H__
#define __RPS_AI_H__

#ifdef BUILD_DLL
    #define GMEXPORT extern __declspec (dllexport)
#else
    #define GMEXPORT extern __declspec(dllexport)
#endif // BUILD_DLL

#ifdef __cplusplus
    extern "C"
    {
        #endif // __cplusplus


        #ifdef __cplusplus
    }
#endif // __cplusplus

extern const char ROCK;
extern const char PAPER;
extern const char SCISSORS;
extern const char FIRSTTHROW;

extern const char HARD[];
extern const char HARDER[];
extern const char ADAPTIVEPATTERN[];
extern const char ADAPTIVELEARNING[];

char cpuLast;
double winLast;
double tieLast;
char rpsThrow[2];

double randnum(int cap);
char rpsFirst();
char setLast(char playerThrow);
char clockwiseThrow(char lastThrow);
char counterclockwiseThrow(char lastThrow);
char chanceThrow(char lastThrow, double clockwise, double stay, double counterclockwise);
char rpsNormal(char lastThrow);
char rpsAdaptivePattern(const char * playerHistory);
char rpsAdaptiveLearning(const char * playerHistory);
GMEXPORT char * rpsReturn(const char * difficulty, char * playerInput, double winLastIn, double tieLastIn);

#endif // __RPS_AI_H__
