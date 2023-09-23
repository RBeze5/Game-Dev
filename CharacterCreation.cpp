#include <iostream>
#include <string>
/*Implements a Character class with attributes such as name, appearance, backstory, strength, agility, and intelligence.
It allows the player to customize their character and allocate attribute points during creation.
Finally, it displays the created character's information.
Expand upon this foundation to add more features and complexity to the text-based RPG character creation system.*/

// Define the Character class with attributes
class Character {
public:
    std::string name;
    std::string appearance;
    std::string backstory;
    int strength;
    int agility;
    int intelligence;

    // Constructor to initialize attributes
    Character(std::string n, std::string app, std::string bg)
        : name(n), appearance(app), backstory(bg), strength(0), agility(0), intelligence(0) {}

    // Method to allocate attribute points
    void allocateStats(int str, int agi, int intel) {
        strength += str;
        agility += agi;
        intelligence += intel;
    }

    // Display character information
    void displayCharacter() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Appearance: " << appearance << std::endl;
        std::cout << "Backstory: " << backstory << std::endl;
        std::cout << "Strength: " << strength << std::endl;
        std::cout << "Agility: " << agility << std::endl;
        std::cout << "Intelligence: " << intelligence << std::endl;
    }
};

int main() {
    std::string playerName, playerAppearance, playerBackstory;
    int strPoints, agiPoints, intelPoints;

    // Get player customization inputs
    std::cout << "Welcome to the character creation system!" << std::endl;
    std::cout << "Enter your character's name: ";
    std::cin >> playerName;
    std::cin.ignore(); // Clear the newline character

    std::cout << "Enter your character's appearance: ";
    std::getline(std::cin, playerAppearance);

    std::cout << "Enter your character's backstory: ";
    std::getline(std::cin, playerBackstory);

    // Create the character
    Character playerCharacter(playerName, playerAppearance, playerBackstory);

    // Allocate attribute points
    std::cout << "Allocate attribute points (strength agility intelligence): ";
    std::cin >> strPoints >> agiPoints >> intelPoints;

    playerCharacter.allocateStats(strPoints, agiPoints, intelPoints);

    // Display the created character
    std::cout << "\nCharacter Created!" << std::endl;
    playerCharacter.displayCharacter();

    return 0;
}
