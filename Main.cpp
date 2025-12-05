using namespace std;

#include <iostream>
#include "tile.cpp"
#include "player.cpp"
int main(){
    vector<Character> selectedCharacters = readCharacterFile();
    for(int i = 0; i<2; i++){
        cout<<selectedCharacters[i].name;
        cout<<selectedCharacters[i].experience;
        cout<<selectedCharacters[i].accuracy;
        cout<<selectedCharacters[i].efficiency;
        cout<<selectedCharacters[i].insight;
        cout<<selectedCharacters[i].discoveryPoints;
    }
    return 0;
}