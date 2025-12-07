using namespace std;

#include <iostream>
#include "tile.cpp"
#include "player.cpp"
#include "board.cpp"
int main(){
    vector<Character> characterVector = selectPathType();
    for(size_t i = 0; i<characterVector.size(); i++){
        cout<<characterVector[i].name;
        cout<<characterVector[i].discoveryPoints;
        cout<<characterVector[i].path;
        cout<<characterVector[i].advisor;
    }
    

}