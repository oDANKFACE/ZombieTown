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
//      I'm still trying to implement this class and figure out how it works. My
//      current understanding is that it will be used within Game.cpp to load
//      events from an external file, create event objects, and give event info
//      to Game.
// ******************************************************************************|

class EventManager {
public:
    // Calls the initializeEvents method. Will call loadEvents instead once fully developed
    EventManager();

    // Placeholder for loading event data from an external JSON file.
    // Populates events list
    void loadEvents();

    // Temporary event loader, adds 3 hardcoded events to events list
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
