//student_scores.cpp -- that calculates student scores from file
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
double calculate_scores(int earned, int possible);
void print_scores(string name, double score);

int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 5" << endl << endl;
//Variable declarations
string student_name;
int score_earned;
int score_possible;
double raw_score;

//Program logic
// Read in the file
ifstream inData;
inData.open("scores.txt", ios::in);

// Check that file is loaded
if (inData.is_open()) {

    // Loop through each line in file
    while (!inData.eof()) {
        inData >> student_name
                >> score_earned
                >> score_possible;

        // Calculate raw score
        raw_score = calculate_scores(score_earned, score_possible);

        // Print out the scores with feedback
        print_scores(student_name, raw_score);
    }
}
return 0;
}
//Function definitions
double calculate_scores(int earned, int possible) {
    // Divide by total score to get raw score
    return (double)earned / possible;
}

void print_scores(string name, double score) {
    int rounded_score = (int)ceil(score*100);
    string score_feedback = "";
    // Give the student feedback
    // show nothing if score is between 50 and 60
    if (rounded_score > 90) {
        score_feedback =  "Excellent";
    } else if (rounded_score > 80) {
        score_feedback =  "Well Done";
    } else if (rounded_score > 70) {
        score_feedback =  "Good";
    } else if (rounded_score >= 60) {
        score_feedback =  "Need Improvement";
    } else if ( rounded_score < 50) {
        score_feedback =  "Fail";
    }

    // print out all the data
    cout << fixed << setprecision(5);
    cout << name << " " << rounded_score
        << "% " << score << " " << score_feedback << endl;
}


