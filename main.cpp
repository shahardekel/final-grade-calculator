#include <cstdlib>
#include <iostream>
#include "grade_calculator.h"

int main()
{
    int id(0);
    enum  eGrades{ grHW1 = 0, grHW2, grHW3, grExam } ;
    //reading the id of the first student
    std::cin >> id;
    //while we have students - read the grades and calculate final
    while ( std::cin.good() )
    {
          //array of student's grades
          int studGrades[ iNumGrades ];
          //reading from input to the array   
          std::cin >> studGrades[grHW1] >> studGrades[grHW2] 
                                          >> studGrades[grHW3] >> studGrades[grExam];
          //calculating the final grade
          std::cout << id << " " << calculateFinal( studGrades, grExam ) << std::endl; 
          //reading the id of the next student
          std::cin >> id;           
    }
    
    system( "PAUSE" );
    return EXIT_SUCCESS;
}

