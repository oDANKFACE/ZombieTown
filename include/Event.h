//
// Created by Darien on 9/26/2023.
//

#ifndef ZOMBIETOWN_EVENT_H
#define ZOMBIETOWN_EVENT_H

#include <string>
#include <vector>
#include <map>

// ******************************************************************************|
// CLASS Event
// Represents the in-game encounters.
//      Manages the description of the encounter, the choices the player can make,
//      and the consequences.
// ******************************************************************************|

class Event {
public:
    Event(const int id = -1, const std::string description = "NA");

    // *********************************************|
    // STRUCT Choice
    // Manages the identification, description, and
    // consequences of player decisions.
    struct Choice {
        int id; // A unique (to the event) identifier for the choice
        std::string description; // The text displayed to the player

        // Consequence values of selecting choice
        int timeEffect;
        int hpEffect;
        int energyEffect;

        Choice(int i, std::string desc, int time, int hp, int energy) : id(i), description(desc), timeEffect(time),
                                                                        hpEffect(hp), energyEffect(energy) {}
    };

    void addChoice(Choice choice); // Adds a choice to the event's choices list
    int getId();
    std::string getDescription();
    std::vector<Choice> getChoices();


private:
    int id; // A unique identifier for the event
    std::string eventDescription; // Contains the text that will be displayed by the player
    std::vector<Choice> choices; // Contains the choices the player will choose from in response to event


};


#endif //ZOMBIETOWN_EVENT_H
