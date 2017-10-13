#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
const char FIRSTTHROW = 'f';

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

        //void GMEXPORT SomeFunction(const LPCSTR sometext);
        double randnum(int cap);
        char clockwiseThrow(char lastThrow);
        char counterclockwiseThrow(char lastThrow);
        char chanceThrow(char lastThrow, double clockwise, double stay, double counterclockwise);
        GMEXPORT char * rpsNormal(char lastThrow, double winLast, double tieLast);
        GMEXPORT double testRun();

        #ifdef __cplusplus
    }
#endif // __cplusplus

#endif // __RPS_AI_H__

