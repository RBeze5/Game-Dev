/*Title: 16-48-49-Cpp_Mad_Libs_Game.md (Markdown Source File)
Creating a Mad Libs game in C++ can be a fun project! Mad Libs is a word game where players fill in the blanks of a story with different types 
of words (nouns, verbs, adjectives, etc.) without knowing the context of the story. Here's a simple example of how you can implement a Mad Libs 
game in C++:
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string noun, verb, adjective;

    cout << "Welcome to Mad Libs Game!\n";
    
    // Input phase
    cout << "Enter a noun: ";
    getline(cin, noun);

    cout << "Enter a verb: ";
    getline(cin, verb);

    cout << "Enter an adjective: ";
    getline(cin, adjective);

    // Story phase
    cout << "\nHere's your Mad Libs story:\n";
    cout << "Once upon a time, there was a " << adjective << " " << noun << ".\n";
    cout << "This " << noun << " loved to " << verb << " all day long.\n";
    cout << "Everyone in the town admired the " << adjective << " " << noun << "'s energy.\n";
    cout << "But one day, the " << adjective << " " << noun << " decided to take a break from " << verb << ".\n";
    cout << "Without the " << adjective << " " << noun << "'s " << verb << "ing, the town felt gloomy.\n";
    cout << "So, the " << adjective << " " << noun << " resumed " << verb << "ing, and everyone lived happily ever after!\n";

    return 0;
}

/*
The code above will prompt the user to enter a noun, a verb, and an adjective. Then, it will use these inputs to construct a short Mad Libs 
story and print it out to the console.

Compile and run the C++ code to play the game! You can, of course, expand this program by adding more blanks in the story or creating a larger
 collection of stories with a more elaborate structure. Have fun experimenting and making your Mad Libs game more entertaining!
*/