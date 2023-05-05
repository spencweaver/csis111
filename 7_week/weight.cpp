//weight.cpp -- calculate people's weight on different planets
//CSIS 111-D01_202320
//<Sources if necessary>
//Include statements
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
//Global declarations: Constants and type definitions only -- no variables
enum planets {Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto};

//Function prototypes
string GetUserInput();
planets ConvertInputToPlanetType(string planet);
float OutputWeight(planets planet, string weight);


int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 7" << endl << endl;

//Variable declarations
string planet = "";
string weight = "";
bool space_found = false;
string user_input;
planets planet_converted;
double weight_calculated;

// Program logic

// Give instructions to the user
cout << "Hello this program will calculate your weight on one of the following planets" << endl;
cout << "Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune or Pluto" << endl;

// A loop that will repeat until user enters valid info
while (true) {
    // Prompt User for weight and planet
    user_input = GetUserInput();

    // Process the input string by splitting
    // the string into two variables of 'weight'
    // and 'planet' by finding the space
    weight = "";
    planet = "";
    space_found = false;
    for (int i=0; i < user_input.length(); i++) {

        // when the space is found flip the variable
        if (user_input[i] == ' ') {
            space_found = true;
        }

        // check if the space has been found
        else if (space_found == false) {
            weight += user_input[i];
        } else {
            planet += user_input[i];
        }
    }

    // use a try catch block to convert planet string to enum
    // if an error is thrown continue onto the next loop iteration
    try {
        planet_converted = ConvertInputToPlanetType(planet);
    } catch (invalid_argument& e) {
        cout << "ERROR: Please enter a valid planet" << endl;
        continue;
    }

    // use a try catch block to calculate the user's weight
    // if invalid weight was entered throw an error
    // then continue to next loop iteration
    try {
        weight_calculated = OutputWeight(planet_converted, weight);
    } catch(invalid_argument& e) {
        cout << "ERROR: please enter a valid weight" << endl;
        continue;
    }

    // Give the user the output of their computed weight
    cout << "Your weight would be " << weight_calculated << endl;

    // break out of the infinite loop
    break;
}


return 0;
}

//Function definitions
string GetUserInput() {
    // ask user for input
    cout << "Please enter your Weight and Planet: ";

    // create a char array and read the cin into the array then return the input
    char user_input[100];
    cin.getline(user_input, 100);

    return user_input;
}

planets ConvertInputToPlanetType(string planet)  {
    // take the string of the planet and convert to enum variable
    // else throw an error if the planet does not match
    // then return the enum value
    planets planet_enum;
    if (planet=="Mercury") {
        planet_enum = Mercury;
    } else if (planet=="Venus") {
        planet_enum = Venus;
    } else if (planet=="Earth") {
        planet_enum = Earth;
    } else if (planet=="Moon") {
        planet_enum = Moon;
    } else if (planet=="Mars") {
        planet_enum = Mars;
    } else if (planet=="Jupiter") {
        planet_enum = Jupiter;
    } else if (planet=="Saturn") {
        planet_enum = Saturn;
    } else if (planet=="Uranus") {
        planet_enum = Uranus;
    } else if (planet=="Neptune") {
        planet_enum = Neptune;
    } else if (planet=="Pluto") {
        planet_enum = Pluto;
    } else {
        throw invalid_argument("Not a valid planet");
    }
    return planet_enum;
}


float OutputWeight(planets planet_e, string weight) {
    // take the weight string and convert to an int
    // then use a switch to return the calculated weight
    int weight_converted = stoi(weight);
    switch(planet_e) {
        case Mercury:
            return weight_converted * 0.4155;
        case Venus:
            return weight_converted * 0.8975;
        case Earth:
            return weight_converted * 1.0;
        case Moon:
            return weight_converted * 0.166;
        case Mars:
            return weight_converted * 0.3507;
        case Jupiter:
            return weight_converted * 2.5374;
        case Saturn:
            return weight_converted * 1.0677;
        case Uranus:
            return weight_converted * 0.8947;
        case Neptune:
            return weight_converted * 1.1794;
        case Pluto:
            return weight_converted * 0.0899;
    }
}