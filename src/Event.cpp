//
// Created by Darien on 9/26/2023.
//

#include "../include/Event.h"

Event::Event(const int id, const std::string description) : id(id), eventDescription(description) {}

void Event::addChoice(Event::Choice choice) { choices.push_back(choice); }

int Event::getId() { return id; }

std::string Event::getDescription() { return eventDescription; }

std::vector<Event::Choice> Event::getChoices() {
    return choices;
}
