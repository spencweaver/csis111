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
string OutputWeight(planets planet, string weight);


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
string output;

//Program logic

while (true) {
    user_input = GetUserInput();
    cout << user_input.length() << endl;



    for (int i=0; i < user_input.length(); i++) {

        if (user_input[i] == ' ') {
            space_found = true;
        } else if (space_found == false) {
            weight += user_input[i];
        } else {
            planet += user_input[i];
        }
    }

    try {
        planet_converted = ConvertInputToPlanetType(planet);
    } catch (const invalid_argument& e) {
        cout << "ERROR: Please enter your weight followed by valid planet name" << endl;
        continue;
    }

    cout << planet_converted << "  planet_converted" << endl;
    output = OutputWeight(planet_converted, weight);
}


return 0;
}

//Function definitions
string GetUserInput() {
    cout << "Please enter your Weight and Planet: ";
    char user_input[100];
    cin.getline(user_input, 100);
    cout << user_input << endl;
    return user_input;
}

planets ConvertInputToPlanetType(string planet)  {
    planets planet_enum;
    if (planet=="Mercury") {
        planet_enum = Mercury;
    } else if (planet=="Venus") {
        planet_enum = Venus;
    } else if (planet=="Earth") {
        planet_enum = Earth;
    } else if (planet=="Moon") {
        cout << "Moonyyyyy" << endl;
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
        throw invalid_argument("Did not type correct planet name");
    }
    return planet_enum;
}


string OutputWeight(planets planet, string weight) {
    int weight_converted = stoi(weight);
    double conversion = 0;
    switch(planet) {
        case Mercury:
            conversion = 0.4155;
        case Venus:
            conversion = 0.8975;
        case Earth:
            conversion = 1.0;
        case Moon:
            conversion = 0.166;
        case Mars:
            conversion = 0.3507;
        case Jupiter:
            conversion = 2.5374;
        case Saturn:
            conversion = 1.0677;
        case Uranus:
            conversion = 0.8947;
        case Neptune:
            conversion = 1.1794;
        case Pluto:
            conversion = 0.0899;
        default:
            return " ";
    }
}