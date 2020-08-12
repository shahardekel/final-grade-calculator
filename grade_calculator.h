#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H


const int iNumGrades = 4;
typedef enum  { pEQUAL = 0, pMULT, pIGNORE, pEXAM, NUM_OF_POLICIES } ePolicies;

int calculateFinal( int arrGrades[iNumGrades], int iExamIndex );

double calcWeightedAverage( int arrNumbers[ iNumGrades ], double arrWeights[ iNumGrades ] );

void gradingPolicyEqual( double arrWeights[ iNumGrades ]);
void gradingPolicyMutiply( double arrWeights[ iNumGrades ]);
void gradingPolicyIgnoreLowest( int arrGrades[ iNumGrades ], double arrWeights[ iNumGrades ]);
void gradingPolicyExamOnly( double arrWeights[ iNumGrades ], int iExamIndex );

///Help functions
double getMax( double* arr, int isize );
int    getMin( int* arr, int isize );
void   initArray(  double* arr, int isize, double dValue );


#endif
