//
// Created by Darien on 9/21/2023.
//

#include "../include/Game.h"
#include "../include/Character.h"
#include <iostream>



int Game::getTime() const { return currentTime; }
void Game::setTime(int addedTime) { currentTime += addedTime; }





void Game::generateDisplay(int hp, int energy) const {
    std::cout << "HP: " << hp << "          " << "Energy: " << energy;
    std::cout << std::endl;
    std::cout << "Current Time: " << currentTime;
    std::cout << std::endl;
}




int Game::getPlayerChoice() {
    std::cout << "1. Increase HP" << std::endl;
    std::cout << "2. Decrease HP" << std::endl;
    std::cout << "3. Increase Energy" << std::endl;
    std::cout << "4. Decrease Energy" << std::endl;
    std::cout << std::endl << "Enter your choice: ";

    std::cin >> choice;

    return choice;
}








void Game::run() {
    bool isRunning = true;
    Character character("Bob", 100, 20);

    currentTime = 0;


    while(isRunning) {

        addedTime = 0;

        // Display updated stats

        generateDisplay(character.getHP(), character.getEnergy());


        // Offer choices to player

        choice = getPlayerChoice();


        // Update stats

        if (addedTime == 0) {
            addedTime = 1;
        }

        setTime(addedTime);



        // Describe resulting status (check for death)



        // Await continue from player



        isRunning = false;
    }
}