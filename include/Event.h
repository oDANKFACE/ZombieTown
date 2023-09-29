//
// Created by Darien on 9/26/2023.
//

#ifndef ZOMBIETOWN_EVENT_H
#define ZOMBIETOWN_EVENT_H

#include <string>
#include <vector>
#include <map>



class Event {
public:


private:
    int id;
    std::string eventDescription;


    struct Choice {
        int id;
        std::string description;
    };

    std::vector<Choice> choices;

    void generateEvent(const std::string &description, const std::vector<Choice> &choicesList);
};


#endif //ZOMBIETOWN_EVENT_H
