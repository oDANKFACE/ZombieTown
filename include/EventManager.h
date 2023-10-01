//
// Created by Darien on 9/28/2023.
//

#ifndef ZOMBIETOWN_EVENTMANAGER_H
#define ZOMBIETOWN_EVENTMANAGER_H

#include "Event.h"
#include <random>

// ******************************************************************************|
// CLASS EventManager
// Manages the in-game encounters.
//      Loads events from external file
//      Selects the next event based on previous event details, location,
//      and game state
// ******************************************************************************|

class EventManager {
public:
    // Calls the initializeEvents method. Will call loadEvents instead once fully developed
    EventManager();

    // For loading event data from an external file.
    void initializeEvents();

    // Returns a new event given the previous event's id.
    // previousEventId is -1 if there are no previous events, making this the first event.
    Event selectNextEvent(int endingEventId);
    Event getCurrentEvent();

private:
    std::vector<Event> events; // The list of all game events
    std::mt19937 rng;
    int currentEventId;
    Event currentEvent;


};


#endif //ZOMBIETOWN_EVENTMANAGER_H
