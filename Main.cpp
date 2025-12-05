using namespace std;

#include <iostream>
#include "tile.cpp"
#include "player.cpp"
#include "mainMenu.cpp"
int main(){
    vector<Character> selectedCharacters = readCharacterFile();
    selectPathType();
}