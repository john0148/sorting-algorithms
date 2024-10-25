#ifndef _COMMANDPROCESS_H_
#define _COMMANDPROCESS_H_

double timeCounting(int *a, int n, int iAlgo);

long long comparisonCounting(int *a, int n, int iAlgo);

void commandOneAndThree(char* algor, char* givenInput, char* opPara);

void commandTwo(char* algor, char* inputSize, char* ipOrder, char* opPara);

void commandFour(char* givenAlgo1, char* givenAlgo2, char* inputFile);

void commandFive(char* givenAlgo1, char* givenAlgo2, char* inputSize, char* ipOrder);

#endif // _COMMANDPROCESS_H_