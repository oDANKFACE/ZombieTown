//
// Created by Darien on 9/21/2023.
//

#ifndef ZOMBIETOWN_GAME_H
#define ZOMBIETOWN_GAME_H

class Game {
public:
    void run();

    int getTime() const;
    void setTime(int addedTime);
    void generateDisplay(int hp, int energy) const; // Update the display: new HP, Energy, time of day, etc.
    int getPlayerChoice();
private:
    int currentTime;
    int addedTime;
    int choice;
};

#endif //ZOMBIETOWN_GAME_H
