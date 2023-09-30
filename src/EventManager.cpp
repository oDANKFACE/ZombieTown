//
// Created by Darien on 9/28/2023.
//

#include "../include/EventManager.h"


EventManager::EventManager() : rng(std::random_device()()) {
    initializeEvents();
}

void EventManager::loadEvents() {
    // Placeholder, as mentioned in EventManager.h
}

void EventManager::initializeEvents() {

    Event event1(1, "You find an abandoned car");
    event1.addChoice(Event::Choice(0, "Sleep in the car", 4, 0, 5));
    event1.addChoice(Event::Choice(1, "Scavenge for resources", 1, 10, -1));
    event1.addChoice(Event::Choice(2, "Kick the car", 1, -10, -1));
    events.push_back(event1);

    Event event2(2, "You run into a mutant");
    event2.addChoice(Event::Choice(0, "Attack", 1, -10, -5));
    event2.addChoice(Event::Choice(1, "Run", 1, 0, -5));
    event2.addChoice(Event::Choice(2, "Strike up a conversation", 2, 0, -1));
    events.push_back(event2);

    Event event3(3, "You find a lake");
    event3.addChoice(Event::Choice(0, "Take some time for yourself", 2, 0, 5));
    event3.addChoice(Event::Choice(1, "Take a swim", 1, 0, -1));
    event3.addChoice(Event::Choice(2, "Eat a fish", 1, 10, -2));
    events.push_back(event3);
}

Event EventManager::selectNextEvent(int endingEventId) {
    int eventIndex;
    std::uniform_int_distribution<> randRange(0, events.size() - 1);
    do {
        eventIndex = randRange(rng);
    } while (events[eventIndex].getId() == endingEventId);
    return events[eventIndex];
}

Event EventManager::getCurrentEvent() { return currentEvent; }