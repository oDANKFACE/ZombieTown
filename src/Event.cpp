//
// Created by Darien on 9/26/2023.
//

#include "../include/Event.h"

void Event::generateEvent(const std::string &description, const std::vector<Choice> &choicesList) {
    eventDescription = description;
    choices = choicesList;
}