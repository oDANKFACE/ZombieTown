//
// Created by Darien on 9/21/2023.
//

#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include "../include/Game.h"


Game::Game() : playerCharacter("ErrNameXxX", 0, 0) {

}

int Game::getTime() const { return currentTime; }

void Game::setTime(int addedTime) { currentTime += addedTime; }

void Game::createCharacter() {
    // Give player base HP and Energy
    playerCharacter.setHP(100);
    playerCharacter.setEnergy(20);
    std::string newName;
    int perkChoice;

    // Begin creation
    std::cout << "CREATE A NEW CHARACTER" << std::endl << std::endl;
    std::cout << "First you must choose a name: ";
    std::cin >> newName;
    playerCharacter.setName(newName);
    std::cout << std::endl << "Hello " << newName << "!" << std::endl << std::endl;

    // Write perk prompt and options
//    prompt = "Now you must choose a starting perk:";
//    choices = {
//            "Wired (+5 Max Energy)",
//            "Swoll (+20 Max HP)"
//    };
//    perkChoice = getPlayerDecision(prompt, choices);
//
//    if (perkChoice == 1) {
//        std::cout << "You have chosen to be wired. You feel more energized." << std::endl;
//        playerCharacter.changeEnergy(5);
//    } else if (perkChoice == 2) {
//        std::cout << "You have chosen to be swoll. You feel stronger." << std::endl;
//        playerCharacter.changeHP(20);
//    }
}

bool Game::inputValidator(int numChoices, int input) {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    if (input <= numChoices && input > 0) {
        return true;
    } else {
        return false;
    }
}

void Game::generateStatsDisplay(int hp, int energy) const {
    std::string bars = "--------------------------------------------------------------------------------------\n";
    std::cout << "\n\n";
    std::cout << bars;
    std::cout << playerCharacter.getName() << "'s Current Status:" << std::endl;
    std::cout << "HP: " << hp << "          " << "Energy: " << energy << std::endl;
    std::cout << bars;
    std::cout << "                                          Current Time: " << currentTime << std::endl;
}

int Game::getPlayerDecision(const std::string prompt, std::vector<Event::Choice> &choices) {
    bool validInput;
    int decision;

    // Display prompt and decisions
    std::cout << prompt << std::endl;
    for (int i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i].description << std::endl;
    }
    std::cout << std::endl;
    // Ask for decision and validate
    do {
        std::cout << "What is your decision?  ";
        std::cin >> decision;
        validInput = inputValidator(choices.size(), decision);

        if (!validInput) {
            std::cout << "Please enter a valid input." << std::endl;
        }

    } while (!validInput);

    return decision - 1;
}

void Game::run() {
    bool isRunning = true;
    eventManager.initializeEvents();
    createCharacter();


    currentTime = 0;


    while (isRunning) {


        addedTime = 0;

        // Display updated stats
        generateStatsDisplay(playerCharacter.getHP(), playerCharacter.getEnergy());

        currentEvent = eventManager.selectNextEvent(currentEventId);
        currentEventId = currentEvent.getId();
        prompt = currentEvent.getDescription();
        choices = currentEvent.getChoices();

        choiceMaster = getPlayerDecision(prompt, choices);

        playerCharacter.changeHP(choices[choiceMaster].hpEffect);
        playerCharacter.changeEnergy(choices[choiceMaster].energyEffect);
        setTime(choices[choiceMaster].timeEffect);

        std::cout << std::endl << std::endl << std::endl;


        // Describe resulting status (check for death)

        if (playerCharacter.getHP() <= 0 || playerCharacter.getEnergy() <= 0) {
            std::cout << "YOU HAVE DIED... or ran out of energy I guess" << std::endl;
            isRunning = false;
//            std::cout << std::endl;
//            prompt = "Try again?";
//            choices = {
//                    "Yes",
//                    "No"
//            };
//
//            choiceMaster = getPlayerDecision(prompt, choices);
//            if (choiceMaster == 1) {
//                std::cout << "Here we go again!" << std::endl;
//                createCharacter();
//                currentTime = 0;
//            } else if (choiceMaster == 2) {
//                std::cout << "Until next time!" << std::endl;
//                isRunning = false;
//            }

        }

        // Await continue from player



    }
}


