//
// Created by Darien on 9/21/2023.
//

#ifndef ZOMBIETOWN_GAME_H
#define ZOMBIETOWN_GAME_H

#include <vector>
#include "Character.h"

class Game {
public:
    Game();
    void run();

    int getTime() const;
    void setTime(int addedTime);
    void createCharacter();

    void generateStatsDisplay(int hp, int energy) const; // Update the display: new HP, Energy, time of day, etc.
    int getPlayerChoiceOld();


    int getPlayerDecision(const std::string prompt, std::vector<std::string>& choices);

    bool inputValidator(int numChoices, int input);
private:
    int currentTime;
    int addedTime;
    int choiceMaster;
    Character playerCharacter;
    std::string prompt;
    std::vector<std::string> choices;
};

#endif //ZOMBIETOWN_GAME_H
