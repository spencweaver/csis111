//songs.cpp -- Calculate remaining space on cd from list of songs
//CSIS 111-D01_202320

//Include statements
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//Global declarations: Constants and type definitions only -- no variables
//Function prototypes
int main()
{
//In cout statement below SUBSTITUTE your name and lab number
cout << "Spencer Weaver -- Lab 6" << endl << endl;
//Variable declarations
string lumber_type;
int number_of_boards;
int length;
int height;
int width;

enum lumber {Pine, Fir, Cedar, Maple, Oak} lum;

lum = Cedar;
// v = Fir;
// l = Maple;
// cout << l << "lumber" << endl;
// cout << v << "lumber" << endl;
cout << lum << " <> lumber" << endl;

cout << "Please the type of wood you would like" << endl
        << "Enter P for Pine, F for Fir, C for Cedar, M for Maple, " << endl
        << "O for Oak, or T for your Total." << endl
        << "followed by the number of boards you would like" << endl
        << "Then enter 3 numbers for the dimension of your wood." << endl;

do {
    cout << "Enter Item: ";
    cin >> lumber_type >> number_of_boards >> length >> height >> width;
    cout << lumber_type << endl;

    // switch (lumber_type) {
    //     case "P":
    //         cout << "P";

    // }
}
while( lumber_type != "T" );
//Program logic
// // read in the file
// ifstream inData;
// inData.open("songs.txt", ios::in);

// // Check to make sure the file loaded
// if (inData.is_open()) {

//     // print out the first header line
//     cout << setw(0) << "Song" <<
//         setw(20) << "Song Time" <<
//         setw(20) << "Total Time" << '\n'; //setw(10) << "test" <<

//     // print out the second header line
//     cout << setw(0) << "Number" <<
//         setw(12) << "Minutes" <<
//         setw(10) << "Seconds" <<
//         setw(10) << "Minutes" <<
//         setw(10) << "Seconds" << '\n';

//     // print out the lines of the header
//     cout << setw(0) << "------" <<
//         setw(12) << "-------" <<
//         setw(10) << "-------" <<
//         setw(10) << "-------" <<
//         setw(10) << "-------" << '\n';

//     // loop through the file until the end
//     while (!inData.eof()) {

//         // Read in the seconds for the song
//         inData >> current_song_total_seconds;

//         // load the variables need to print out the next line
//         current_song_minutes = current_song_total_seconds/60;
//         current_song_seconds = current_song_total_seconds%60;
//         total_minutes += current_song_minutes;
//         total_seconds += current_song_seconds;

//         // if more than a minute in seconds
//         // add the seconds onto minutes
//         if (total_seconds >= 60) {
//             total_minutes += total_seconds/60;
//             total_seconds = total_seconds%60;
//         }

//         // Check if counter is one or two digits
//         // to make sure the alignment is correct
//         if (counter < 10) {
//             cout << setw(2) << counter <<
//             setw(15) << current_song_minutes <<
//             setw(10) << current_song_seconds <<
//             setw(10) << total_minutes <<
//             setw(10) << total_seconds << '\n';
//         } else {
//             cout << setw(0) << counter <<
//             setw(15) << current_song_minutes <<
//             setw(10) << current_song_seconds <<
//             setw(10) << total_minutes <<
//             setw(10) << total_seconds << '\n';
//         }

//         // Iterate at the end of while loop
//         counter++;
//     }

//     // Calculate remaining space on CD
//     if (total_seconds > 0) {
//         remaining_minutes = 80 - total_minutes - 1;
//         remaining_seconds = 60 - total_seconds;
//     } else {
//         remaining_minutes = 80 - total_minutes;
//     }

//     cout << "There are " << remaining_minutes << " minutes and " <<
//         remaining_seconds << " seconds of space left on the 80-minute CD." <<
//         endl;

// }

return 0;
}
//Function definitions
