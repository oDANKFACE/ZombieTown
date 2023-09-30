//
// Created by Darien on 9/21/2023.
//

#ifndef ZOMBIETOWN_GAME_H
#define ZOMBIETOWN_GAME_H

#include <vector>
#include "Character.h"
#include "EventManager.h"
#include "Event.h"

// ******************************************************************************|
// CLASS Game
// Used to run the game.
//      Manages game state, gameplay loop, and player input.
// ******************************************************************************|

class Game {
public:
    Game();
    void run();

    // Deal with the in-game clock
    int getTime() const;
    void setTime(int addedTime);

    // Starts Character Creation segment
    void createCharacter();

    // Update the display with new HP, Energy, time of day, etc.
    void generateStatsDisplay(int hp, int energy) const;

    // Returns the decision (int) the player makes from the list of choices.
    // Uses inputValidator.
    int getPlayerDecision(const std::string prompt, std::vector<Event::Choice>& choices);

    // Validates the input from the player.
    // Used in getPlayerDecision.
    bool inputValidator(int numChoices, int input);
private:
    int currentTime;
    int addedTime;
    int choiceMaster;
    int currentEventId = -1;
    Character playerCharacter;
    std::string prompt;
    std::vector<Event::Choice> choices;
    EventManager eventManager;
    Event currentEvent;
};

#endif //ZOMBIETOWN_GAME_H
