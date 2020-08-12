#include "grade_calculator.h"
#include <cmath>

int calculateFinal( int studentGrades[iNumGrades] ,int iExamIndex )
{
    //The following array will store the grades calculated by all policies
    double arrGrades[ NUM_OF_POLICIES ];
    initArray( arrGrades, NUM_OF_POLICIES, 0 );
    //The following array will store the weights of the grades calculated by each policy
    double arrWeights[ iNumGrades ];
    initArray( arrWeights, iNumGrades, 0);

    //Equal policy
    gradingPolicyEqual( arrWeights );
    arrGrades[ pEQUAL ] = calcWeightedAverage( studentGrades, arrWeights );

    //Multiply
    gradingPolicyMutiply( arrWeights );
    arrGrades[ pMULT ] = calcWeightedAverage( studentGrades, arrWeights );

    //Ignore
    gradingPolicyIgnoreLowest( studentGrades, arrWeights );
    arrGrades[ pIGNORE ] = calcWeightedAverage( studentGrades, arrWeights );

    //Exam only
    gradingPolicyExamOnly( arrWeights, iExamIndex );
    arrGrades[ pEXAM ] = calcWeightedAverage( studentGrades, arrWeights);

    //ceil function rounds a number up
    //(int)  - we are casting a double number to be int
    return (int)ceil( getMax( arrGrades, NUM_OF_POLICIES ) ) ;

}


double calcWeightedAverage( int arrNumbers[iNumGrades], double arrWeights[ iNumGrades ] )
{
   double dAvg(0);
   double dSum(0);


   for ( int i=0; i< iNumGrades; ++i )
   {
       dAvg += ( arrNumbers[ i ] * arrWeights[ i ] );
       dSum +=  arrWeights[ i ];
   }
   return dAvg/dSum;
}

void gradingPolicyEqual( double arrWeights[ iNumGrades ])//avg for 4 grades
{
   for ( int i = 0; i < iNumGrades; ++i )
   {
       arrWeights[i] = 1;
   }
}

void gradingPolicyMutiply( double arrWeights[ iNumGrades ] )
{
   for ( int i = 0; i < iNumGrades; ++i )
   {
       arrWeights[i] = ( i + 1 );
   }
}

void gradingPolicyIgnoreLowest( int arrGrades[ iNumGrades ], double arrWeights[ iNumGrades ])//erase the lowest grade
{
    int iLowest = getMin( arrGrades, iNumGrades );
    int saver(0);
    for ( int i = 0; i < iNumGrades; ++i )
    {
    	if(arrGrades[i] == iLowest && saver != iLowest)
    	{
    		arrWeights[i] = 0;
    		saver = arrGrades[i];
    	}
    	else
    	{
    		arrWeights[i] = 1;
    	}
    }
}

void gradingPolicyExamOnly( double arrWeights[ iNumGrades ],
                               int iExamIndex )
{
    for ( int i = 0; i < iNumGrades; ++i )
    {
       arrWeights[i] = 0;
    }
    arrWeights[ iExamIndex ] = 1;
}


double getMax( double* arr, int isize )
{
    if ( (!isize ) || (!arr )) return -1;
    double dMax( arr[0] );
    for ( int i = 1; i < isize; ++i )
    {
        dMax = ( arr[i] > dMax ) ? arr[i] : dMax;
    }

    return dMax;
}

int   getMin( int* arr, int isize )
{
    if ( (!isize ) || (!arr )) return -1;
    int dMin( arr[0] );
    for ( int i = 1; i < isize; ++i )
    {
        dMin = ( arr[i] < dMin ) ? arr[i] : dMin;
    }

    return dMin;
}

void  initArray( double* arr, int isize, double dValue )
{

	for ( int i = 0; i < isize; ++i )
    {
        arr[ i ] = dValue;
    }


}
