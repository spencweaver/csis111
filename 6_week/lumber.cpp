//lumber.cpp -- Calculate the cost of lumber for customers
//CSIS 111-D01_202320

//Include statements
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
enum lumber {Pine, Fir, Cedar, Maple, Oak} lum;

//Function prototypes
lumber load_lumber_enum(string lumber_input);
float find_lumber_price(lumber lum_input);
float calculate_lumber_cost(float price, int num, int len, int hei, int wid);
string create_feedback(int b_num, string lumber, int len, int hei, int wid, float total);
string final_feedback(string feedback, float total);



int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 6" << endl << endl;
//Variable declarations
string lumber_input;
int number_of_boards;
int length;
int height;
int width;
float total_cost = 0;
string user_feedback;


// Give the user instructions to use the app
cout << "Please the type of wood you would like" << endl
        << "Enter Pine, Fir, Cedar, or Maple, " << endl
        << "O for Oak, or T for your Total." << endl
        << "followed by the number of boards you would like" << endl
        << "Then enter 3 numbers for the dimension of your wood." << endl;

do {
    // Ask user for lumber type
    // And read into a variable
    cout << "Enter Lumber type (Or press T for total): ";
    cin >> lumber_input;

    // check to see if user entered "T"
    if (lumber_input == "T") {
        // Calculate the final feedback
        cout << final_feedback(user_feedback, total_cost);
        break;
    }

    // Ask user for number of boards
    cout << "Enter number of boards: ";
    cin >> number_of_boards;

    // As user for the
    cout << "Enter width, height, and, length: ";
    cin >> width >> height >> length;

    // load the lumber enum and store in variable
    lumber lum_loaded = load_lumber_enum(lumber_input);

    // Find the price of the lumber
    float lumber_price = find_lumber_price(lum_loaded);

    // Calculate the cost of the lumber based on number of pieces and size
    float lumber_cost = calculate_lumber_cost(lumber_price, number_of_boards, length, height, width);

    // Keep tract of the total cost for final line
    total_cost += lumber_cost;

    // Create string feedback to print out to the user
    string feedback = create_feedback(number_of_boards, lumber_input, length, height, width, lumber_cost);

    // Concatenate the feedback for the final piece of feedback
    user_feedback += feedback;

    // Print feed back out to user
    cout << feedback;

}
while(true);

return 0;
}

//Function definitions

// Function to round the total cost to 2 decimal places
string float_to_string(float num) {
    // Find the whole number part
    int int_part = int(num);

    // Find the float part by multiplying by 100 and
    // adding 0.5 to round correctly
    // finally the modulo opperator gives the last two decimal places
    int dec_part = (int)(num * 100 + 0.5) % 100;

    // return the formatted string to user
    return to_string(int_part) + "." + to_string(dec_part);
}

// function to load the enum variable
lumber load_lumber_enum(string lumber_input) {
    // using if else blocks find the correct value
    if (lumber_input == "Pine") {
        lum = Pine;
    } else if (lumber_input == "Fir") {
        lum = Fir;
    } else if (lumber_input == "Cedar") {
        lum = Cedar;
    } else if (lumber_input == "Maple") {
        lum = Maple;
    } else if (lumber_input == "Oak") {
        lum = Oak;
    }

    // return value to user
    return lum;
}

// function to find the price of the board foot
float find_lumber_price(lumber lum_input) {

    // using a switch find the price of the wood
    float board_price;
    switch(lum_input)
    {
        case Pine:
            board_price = 0.89;
            cout << "Pine"; break;

        case Oak:
            board_price = 1.09;
            cout << "Oak"; break;

        case Fir:
            board_price = 2.26;
            cout << "Fir"; break;

        case Cedar:
            board_price = 4.50;
            cout << "Cedar"; break;

        case Maple:
            board_price = 3.10;
            cout << "Maple"; break;

        default:
            cout << "error"; break;
    }

    // return board price
    return board_price;
}

// Taking the dimensions of the wood and number of pieces
// calculate the total cost
float calculate_lumber_cost(float price, int num, int len, int hei, int wid) {
    // multiply the dimensions and divide by 12
    float board_feet = (float)len * hei * wid / 12;

    // multiply by price and num of pieces
    float cost = board_feet * price * num;

    // return cost
    return cost;
}

// generate the string feedback to user
// use special function to convert floats to
// string with 2 decimal places
string create_feedback(int b_num, string lumber, int len, int hei, int wid, float total) {
    string feedback = to_string(b_num) + " " + to_string(wid) + "x" + to_string(hei) +
                        "x" + to_string(len) + " " + lumber + " at a cost of " +
                        float_to_string(total) + "\n";

    return feedback;
}

// This function takes the concatenated string of feedback
// and adds on the extra feedback for the final line
string final_feedback(string feedback, float total) {

    // Add extra text to front and back of the feedback string
    string final_feedback = "The total for\n" + feedback +
                                "is " + float_to_string(total);
    // return to print to user
    return final_feedback;
}

