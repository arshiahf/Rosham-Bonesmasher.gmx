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

// Basic throw concepts
#define ROCK 'r'
#define PAPER 'p'
#define SCISSORS 's'

// Possible results
#define TIE 't'
#define WIN 'w'
#define LOSE 'l'
#define ROUNDWIN 'W'
#define ROUNDLOSE 'L'

// Global constant declaration
extern const char VERYLOW[];
extern const char LOW[];
extern const char MEDIUM[];
extern const char HIGH[];
extern const char VERYHIGH[];

// Implicit function declaration
int randnum(int cap);
const char *throwValue(int toWin, int localWin, int localLoss, int localTie);
char clockwiseThrow(char lastThrow);
char counterclockwiseThrow(char lastThrow);
char chanceThrow(char lastThrow, int clockwise, int counterclockwise);
char rpsNormal(char lastThrow, char lastResult);
char rpsAdaptivePattern(const char *playerHistory, char cpuLast, char lastResult);
char rpsAdaptiveLearning(const char *playerHistory, const char *cpuHistory, const char *resultHistory);
GMEXPORT char *rpsReturn(const char *difficulty, char *playerInput, char *cpuHistory, char *lastResult);

#endif // __RPS_AI_H__
