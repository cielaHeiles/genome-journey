using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


#include "Player.h"
//constructors
Player :: Player(){
    playerName = "playerName";
    experience = -1;
    accuracy = -1;
    efficiency = -1;
    insight = -1;
    discoveryPoints = -1;
}

Player :: Player(string name, int exp, int acc, int eff, int ins, int disP){
    playerName = name;
    experience = exp;
    accuracy = acc;
    efficiency = eff;
    insight = ins;
    discoveryPoints = disP;
}

//getters
string Player :: getPlayerName(){
    return playerName;
}

int Player :: getExperience(){
    return experience;
}

int Player :: getAccuracy(){
    return accuracy;
}

int Player :: getEfficiency(){
    return efficiency;
}

int Player :: getInsight(){
    return insight;
}

int Player :: getDiscoveryPoints(){
    return discoveryPoints;
}


//setters
void Player :: setPlayerName(string name){
    playerName = name;
}

void Player :: setExperience(int exp){
    experience = exp;
}

void Player :: setAccuracy(int acc){
    accuracy = acc;
}

void Player :: setInsight(int ins){
    insight = ins;
}

void Player :: setDiscoveryPoints(int disP){
    discoveryPoints = disP;
}



struct Character{
    string name;
    int experience;
    int accuracy;
    int efficiency;
    int insight;
    int discoveryPoints;
    int path;
    int advisor=0;
};
vector<Character> readCharacterFile(){
    
    //Read individual lines from characters.txt into characters vector
    //Read vector into 2D array
    //Read 2D array into player structs
    
    //open file
    fstream inFile("characters.txt");
    string line;
    vector<string> characters(0);
    if(inFile.fail()){
        cout<<"Failed to open file characters.txt";
    }
    //Read individual lines into characters vector
    while(getline(inFile, line)){
        characters.push_back(line);
    }
    //Read vector into 2D array
    string allCharactersArray[5][6];
    for(int i = 0; i<5; i++){
        stringstream ss(characters[i]);
        string item;
        int j = 0;
        while(getline(ss, item, '|')){
            allCharactersArray[i][j] = item;
            j++;
        }
        j=0;
    }
    //Read 2D array to character structs
    Character Leo  = {allCharactersArray[0][0], stoi(allCharactersArray[0][1]), stoi(allCharactersArray[0][2]), stoi(allCharactersArray[0][3]), stoi(allCharactersArray[0][4]), stoi(allCharactersArray[0][5])};
    Character Helix  = {allCharactersArray[1][0], stoi(allCharactersArray[1][1]), stoi(allCharactersArray[1][2]), stoi(allCharactersArray[1][3]), stoi(allCharactersArray[1][4]), stoi(allCharactersArray[1][5])};
    Character Panthera  = {allCharactersArray[2][0], stoi(allCharactersArray[2][1]), stoi(allCharactersArray[2][2]), stoi(allCharactersArray[2][3]), stoi(allCharactersArray[2][4]), stoi(allCharactersArray[2][5])};
    Character Adenine  = {allCharactersArray[3][0], stoi(allCharactersArray[3][1]), stoi(allCharactersArray[3][2]), stoi(allCharactersArray[3][3]), stoi(allCharactersArray[3][4]), stoi(allCharactersArray[3][5])};
    Character KMer  = {allCharactersArray[4][0], stoi(allCharactersArray[4][1]), stoi(allCharactersArray[4][2]), stoi(allCharactersArray[4][3]), stoi(allCharactersArray[4][4]), stoi(allCharactersArray[4][5])};
    vector<Character> charactersVector = {Leo, Helix, Panthera, Adenine, KMer};
    //Display character menu
    int player1CharacterNum;
    int player2CharacterNum;
    cout<<"Character selection: "<<endl;
    cout<<"Available characters and stats: "<<endl;
    cout<<"Name - Experience - Accuracy - Efficiency - Insight - Discovery Points"<<endl<<endl;
    for(int i = 0; i<5; i++){
        cout<<"("<<i+1<<")"<<charactersVector[i].name <<" - "<<charactersVector[i].experience<<" - "<<charactersVector[i].accuracy<<" - "<<charactersVector[i].efficiency<<" - "<<charactersVector[i].insight<<" - "<<charactersVector[i].discoveryPoints<<endl;
    }
    cout<<endl;
    //Player 1 chooses character
    cout<<"Player 1 choose character: ";
    cin>>player1CharacterNum;
    cout<<endl;
    //Remove selected character
    charactersVector.erase(charactersVector.begin() + player1CharacterNum-1);
    cout<<"Available characters and stats:"<<endl;
    cout<<"Name - Experience - Accuracy - Efficiency - Insight - Discovery Points"<<endl<<endl;
    for(size_t i = 0; i<charactersVector.size(); i++){
        cout<<"("<<i+1<<")"<<charactersVector[i].name <<" - "<<charactersVector[i].experience<<" - "<<charactersVector[i].accuracy<<" - "<<charactersVector[i].efficiency<<" - "<<charactersVector[i].insight<<" - "<<charactersVector[i].discoveryPoints<<endl;
    }
    cout<<endl;
    //Player 2 chooses character
    cout<<"Player 2 choose character: ";
    cin>>player2CharacterNum;
    cout<<endl;
    cout<<"All characters selected!"<<endl<<endl;
    //Return a vector with the two selected characters
    vector<Character> selectedCharacters = {charactersVector[player1CharacterNum-1], charactersVector[player2CharacterNum-1]};
    return selectedCharacters;
}

vector<Character> getSelectedCharacters(){
    //Runs the readCharacterFile function and returns a vector of the 2 selected characters
    return readCharacterFile();
}

int selectAdvisor(int player){
    //Prompts user to select advisor. Call if user selects path type 0
    int advisor;
    vector<string> advisorList = {"Dr. Aliquot - A master of the \"wet lab\", assisting in avoiding contamination.", "Dr. Assembler - An expert who helps improve efficiency and streamline pipelines", "Dr, Pop-Gen - A genetics specialist with insight for identifying rare genetic variants", "Dr. Bio-Script - The genius behind the data analysis, helps debug code", "Dr. Loci - Your biggest supporter assisting you in learning the equiptment"};
    cout<<"Player "<<player<<" Advisor Selection: "<<endl;
    for(size_t i = 0; i<advisorList.size(); i++){
        cout<<"("<<i+1<<")"<<advisorList[i]<<endl;
    }
    cin>>advisor;
    return advisor-1;
}
void changeStatsBasedOnPathType(int pathType, Character c){
    if(pathType == 0){
        c.discoveryPoints -= 5000;
        c.accuracy += 500;
        c.efficiency +=500;
        c.insight += 1000;
    }if(pathType == 1){
        c.discoveryPoints +=5000;
        c.accuracy += 200;
        c.efficiency += 200;
        c.insight += 200;
    }
}
vector<Character> selectPathType(){
    //Create vector of selected characters
    vector<Character> selectedCharacters = getSelectedCharacters();
    int player1Path;
    int player2Path;
    //Display path options
    cout<<"Path Selection: "<<endl;
    cout<<"(1) Training Fellowship: This path equips your scientist with essential traits(accuracy, efficiency, and insight) needed for future challenges. The training requires an invesgtment of -5,000 Discover Points, symbolizingthe time and resources dedicated to developing these skills. This path also adds 500 Accuracy Points, 500 Efficiency Points, and 1,000 Insight Points to the starting amount of your character's traitsbefore you start the journey. The Training Fellowship path will also allow you to choose an advisor who grants a unique special ability that protects them during random events that have a negative influence on your discover points."<<endl<<endl;
    cout<<"(2) Direct Lab Assignment: This path lets your scientist jump directly into the life of DNA sequencing with an immediate boost of +5,000 Discover Points, allowing early progression and quick success. This path also adds 200 Accuracy Points, 200 Efficiency Points, and 200 Insight Points before you start the journey. Although this path offers a strong head start, it lacks long-term resilience and special abilities that could be gained through mentorship in Training Fellowship, making it a riskier approach to becoming a Lead Genomicist."<<endl<<endl<<endl;
    cout<<"Player 1 select path: ";
    //Player 1 path selection
    cin>>player1Path;
    cout<<endl;
    selectedCharacters[0].path = player1Path-1;
    //advisor selection
    if(player1Path == 1){
        selectedCharacters[0].advisor = selectAdvisor(1);
    }
    //Player 2 path selection
    cout<<"Player 2 select path: ";
    cin>>player2Path;
    cout<<endl;
    selectedCharacters[1].path = player2Path-1;
    //advisor selection
    if(player2Path == 1){
        selectedCharacters[1].advisor = selectAdvisor(2);
    }
    //return characters vector
    return selectedCharacters;
}

