//permutations.cpp -- calculate permutations from two variables read in from a file
//CSIS 111-D01_202320
//<Sources if necessary>
//Include statements
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes for people and team size
const int PEOPLE = 18;
const int TEAM_SIZE = 3;
const float PI = 3.14159;

//Function definitions
double find_factorial(int n) {

    //Multiply the numbers to calculate the factorial
    //Then return the result
    double factorial = 1/exp(n) * pow(n, n) * sqrt(2 * PI * n);
    return factorial;
}


int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 2" << endl << endl;

//Program logic
//Display the people and team_size
cout << "The number of people is " << PEOPLE
        << " and the size of the teams is " << TEAM_SIZE << endl;

//Variable declarations
// calculate the permutation
double result =  find_factorial(PEOPLE)/
            (find_factorial(TEAM_SIZE) * find_factorial(PEOPLE - TEAM_SIZE));


//Print the result to the screen
cout << "The number of teams is " << ceil(result) << endl;

//Closing program statements
// system("pause"); //command not needed for mac
return 0;
}
