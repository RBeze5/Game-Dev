#include <iostream>
#include <string>
#include <vector>
#include <map>
//high-level overview of code structure
using namespace std;
/*Provides a basic framework for a text-based RPG.
Can be expanded upon by adding more NPCs, quests, and branching dialogue options.
The main game loop allows players to interact with NPCs and check their available quests.
Continue to build upon this foundation to create a more immersive experience.*/

// Define a class for representing NPCs
class NPC {
public:
    string name;
    string description;

    // Constructor
    NPC(string _name, string _description) : name(_name), description(_description) {}

    // Define interactions with NPCs
    void talk() {
        cout << name << ": Hello, adventurer!" << endl;
        // You can add dialogue options here.
    }
};

// Define a class for representing quests
class Quest {
public:
    string title;
    string description;
    bool completed;

    // Constructor
    Quest(string _title, string _description) : title(_title), description(_description), completed(false) {}

    // Method to complete a quest
    void complete() {
        completed = true;
        cout << "Quest completed: " << title << endl;
    }
};

int main() {
    // Create the player character
    string playerName = "YourName";
    cout << "Welcome, " << playerName << "!" << endl;

    // Create NPCs
    NPC npc1("NPC 1", "A friendly villager.");
    NPC npc2("NPC 2", "A mysterious stranger.");

    // Create quests
    Quest quest1("Find the Lost Sword", "Help me find my lost sword in the forest.");
    Quest quest2("Defeat the Goblin King", "Slay the Goblin King in his lair.");

    // Create a map to store available quests
    map<string, Quest> availableQuests;
    availableQuests["quest1"] = quest1;
    availableQuests["quest2"] = quest2;

    // Game loop
    while (true) {
        // Display options
        cout << "Options:" << endl;
        cout << "1. Talk to NPCs" << endl;
        cout << "2. Check quests" << endl;
        cout << "3. Quit" << endl;

        // Get player's choice
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                // Interact with NPCs
                npc1.talk();
                npc2.talk();
                break;
            case 2:
                // Check quests
                cout << "Available Quests:" << endl;
                for (const auto& entry : availableQuests) {
                    cout << entry.first << ": " << entry.second.title << " - " << entry.second.description;
                    if (entry.second.completed) {
                        cout << " (Completed)";
                    }
                    cout << endl;
                }
                break;
            case 3:
                // Quit the game
                cout << "Goodbye, " << playerName << "!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select again." << endl;
        }
    }

    return 0;
}
