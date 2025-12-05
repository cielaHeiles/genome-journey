using namespace std;

#include <string>
#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public: 
        //constructors
        Player();
        Player(string playerName, int experience, int accuracy, int efficiency, int insight, int discoveryPoints);
        //getters
        string getPlayerName();
        int getExperience();
        int getAccuracy();
        int getEfficiency();
        int getInsight();
        int getDiscoveryPoints();

        //setters
        void setPlayerName(string playerName);
        void setExperience(int experience);
        void setAccuracy(int accuracy);
        void setEfficiency(int efficiency);
        void setInsight(int insight);
        void setDiscoveryPoints(int discoveryPoints);

    private:
        string playerName;
        int experience;
        int accuracy;
        int efficiency;
        int insight;
        int discoveryPoints;
};

#endif
