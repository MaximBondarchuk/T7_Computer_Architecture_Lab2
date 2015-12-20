#include <iostream>
#include "Decoder/Decoder.hpp"


using namespace std;
using namespace chrono;

// Last digit should be 0
const int runsNumber = 30;


int main(int argc, char **argv) {
    auto d = Decoder();

    cout << "What do you want program to do? [e/D] ";
    string choice;
    cin >> choice;
    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    auto timeBegin = high_resolution_clock::now();

    if (choice == "E" || choice == "ENCODE") {
        cout << "You selected encode" << endl;
        string lineToEncode = "WORD1 WORD2 WORD3 WORD4 WORD5 WORD6 WORD7 WORD8 WORD9 WORD10";
        cout << endl << lineToEncode << "\" encoded to \"" <<
        d.Encode(lineToEncode) << endl;
    }
    else {
        cout << "You selected decode" << endl;
        cout << "Do you want run optimised case? [y/N] ";
        cin >> choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        auto stringForDecode = "-.---.---...---.---.---...-.---.-...---.-.-...-.---.---.---.---......."
                "-.---.---...---.---.---...-.---.-...---.-.-...-.-.---.---.---......."
                "-.---.---...---.---.---...-.---.-...---.-.-...-.-.-.---.---......."
                "-.---.---...---.---.---...-.---.-...---.-.-...-.-.-.-.---......."
                "-.---.---...---.---.---...-.---.-...---.-.-...-.-.-.-.-......."
                "-.---.---...---.---.---...-.---.-...---.-.-...---.-.-.-.-......."
                "-.---.---...---.---.---...-.---.-...---.-.-...---.---.-.-.-......."
                "-.---.---...---.---.---...-.---.-...---.-.-...---.---.---.-.-......."
                "-.---.---...---.---.---...-.---.-...---.-.-...---.---.---.---.-......."
                "-.---.---...---.---.---...-.---.-...---.-.-...-.---.---.---.---...---.---.---.---.---.......";

        timeBegin = high_resolution_clock::now();
        d.DecodeTest(stringForDecode, (choice == "Y" || choice == "YES"), runsNumber);
    }

    auto time = duration_cast<nanoseconds>(high_resolution_clock::now() - timeBegin).count() / 1000000000.0;
    cout << "Worked for " << time << "s" << endl;
    return 0;
}