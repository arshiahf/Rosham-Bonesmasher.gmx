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

// Global constant declaration
extern const char ROCK;
extern const char PAPER;
extern const char SCISSORS;

extern const char HARD[];
extern const char HARDER[];
extern const char ADAPTIVEPATTERN[];
extern const char ADAPTIVELEARNING[];

extern const char TIE;
extern const char WIN;
extern const char LOSE;
extern const char ROUNDWIN;
extern const char ROUNDLOSE;

extern const char VERYLOW[];
extern const char LOW[];
extern const char MEDIUM[];
extern const char HIGH[];
extern const char VERYHIGH[];

// Global variable declaration
int numWin;
int numLoss;
int numTie;
int totalThrows;

char lastResult;
char cpuLast;
char rpsThrow[2];

// Implicit function declaration
double randnum(int cap);
char rpsFirst();
void setResult(char * lastResultInput);
const char * throwValue(int toWin, int localWin, int localLoss, int localTie);
char clockwiseThrow(char lastThrow);
char counterclockwiseThrow(char lastThrow);
char chanceThrow(char lastThrow, double clockwise, double counterclockwise);
char rpsNormal(char lastThrow);
char rpsAdaptivePattern(const char * playerHistory);
char rpsAdaptiveLearning(const char * playerHistory, const char * cpuHistory, const char * resultHistory);
GMEXPORT char * rpsReturn(const char * difficulty, char * playerInput, char * cpuHistory, char * lastResult);

#endif // __RPS_AI_H__
