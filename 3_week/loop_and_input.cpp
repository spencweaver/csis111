//loop_and_input.cpp -- compute a student's grade as a percentage
//CSIS 111-D01-202320
//<Sources if necessary>
//Include statements
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes
int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 3" << endl << endl;

//Variable declarations
float a;
float b;
float score;


//Program logic

//Read grade from file
ifstream inData;
inData.open("input.txt",ios::in);
if (inData.is_open()) {
    // Read in the data and calculate the score
    inData >> a >> b;
    score = a/b * 100;

    // Display the raw score to screen
    cout << fixed << setprecision(5);
    cout << "Your score is " << score << '%' << endl;

    // Round the score to find letter grade
    score = ceil(score);

    // Give the student feedback
    if (score >= 90) {
        cout << "Excellent" << endl;
    } else if (score < 90 && score >= 80) {
        cout << "Well Done" << endl;
    } else if (score < 80 && score >= 70) {
        cout << "Good" << endl;
    } else if (score < 70 && score >= 60) {
        cout << "Need Improvement" << endl;
    } else if ( score < 60) {
        cout << "Fail" << endl;
    }
    // string tmp;
    // // while(getline(inData, tmp)) {
    // //     cout << tmp << endl;
    // // }
    // getline(inData, tmp);
    // cout << tmp << endl;
}
//Closing program statements
return 0;

}
//Function definitions