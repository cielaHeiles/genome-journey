using namespace std;

#include <iostream>
#include "tile.cpp"
#include "player.cpp"
#include "mainMenu.cpp"
int main(){
    vector<Character> selectedCharacters = selectPathType();
    for(size_t i = 0; i<selectedCharacters.size(); i++){
        cout<<selectedCharacters[i].name<<";";
        cout<<selectedCharacters[i].experience<<";";
        cout<<selectedCharacters[i].accuracy<<";";
        cout<<selectedCharacters[i].efficiency<<";";
        cout<<selectedCharacters[i].insight<<";";
        cout<<selectedCharacters[i].discoveryPoints<<";";
        cout<<selectedCharacters[i].path<<";";
        cout<<selectedCharacters[i].advisor<<";";
        cout<<endl;
    }
}