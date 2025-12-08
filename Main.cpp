using namespace std;

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "tile.cpp"
#include "player.cpp"
#include "board.cpp"
#include "menu.cpp"


void taskBasedOnColor(Board myBoard, int player_index, Character c){
//select task based on tile color
    int position = myBoard.getPlayerPosition(player_index);
    char color = myBoard.getTileColor(player_index, position);
    if(color == 'B'){
        c.accuracy += executeDNATask1();
    }else if(color == 'P'){
        c.accuracy += executeDNATask2();
    }else if(color == 'R'){
        DNATask3("AAAABBBBAAAA", "BCBB");
    }else if(color == 'B'){
        c.accuracy+= executeDNATask4();
    }else if(color == 'P'){
        bool answer = randomRiddle();
        if(answer == true){
            c.insight += 500;
        }
    }else if(color == 'G'){
        srand(time(0));
        int randomNumber = rand()%2 +1;
        cout<<randomNumber;
        if(randomNumber == 1){
            randomEvent(c.path, c.advisor, c.discoveryPoints);
        }
    }
}
void checkPlayerProgress(Character c, int subChoice){
    if(subChoice == 1){
        cout<<"Discovery points: "<<c.discoveryPoints<<endl;
    }else if(subChoice ==2){
        cout<<"Experience: "<<c.experience<<endl;
        cout<<"Accuracy: "<<c.accuracy<<endl;
        cout<<"Efficiency: "<<c.efficiency<<endl;
        cout<<"Insight: "<<c.insight<<endl;
    }
}

void reviewCharacter(Character c){
    cout<<"Character name: "<<c.name<<endl;
    if(c.path == 0){
        cout<<"Path: Training fellowship. This path equips your scientist with essential traits(accuracy, efficiency, and insight) needed for future challenges."<<endl;
    }else if(c.path == 1){
        cout<<"Path: Direct lab assignment. This path lets your scientist jump directly into the life of DNA sequencing."<<endl;
    }
}

void checkPosition(int playerIndex, Board myBoard){
    cout<<"Position: "<< myBoard.getPlayerPosition(playerIndex)<<endl;
}


void reviewAdvisor(Character c, int subChoice){
    if(subChoice == 1){
        if(c.advisor == 0){
            cout<<"You do not have an advisor"<<endl;
        }else if(c.advisor == 1){
            cout<<"Your advisor is Dr. Aliquot"<<endl;
        }else if(c.advisor == 2){
            cout<<"Your advisor is Dr. Assembler"<<endl;
        }else if(c.advisor == 3){
            cout<<"Your advisor is Dr. Pop-Gen"<<endl;
        }else if(c.advisor == 4){
            cout<<"Your advisor is Dr. Bio-Script"<<endl;
        }else if(c.advisor == 5){
            cout<<"Your advisor is Dr. Loci"<<endl;
        }
    }else if(subChoice == 2){
        if(c.advisor == 0){
            cout<<"You do not have an advisor"<<endl;
        }else if(c.advisor == 1){
            cout<<"Dr. Aliquot is a master of the \" wet lab\", assisting in avoiding contamination."<<endl;
        }else if(c.advisor == 2){
            cout<<"Dr. Assembler is an expert who helps improve efficiency and streamlines pipelines."<<endl;
        }else if(c.advisor == 3){
            cout<<"Dr. Pop-Gen is a genetics specialist with an insight for identifying rare genetic variants."<<endl;
        }else if(c.advisor == 4){
            cout<<"Dr. Bio-Script is the genius behind data analysis, and can help debug code."<<endl;
        }else if(c.advisor == 5){
            cout<<"Dr. Loci is your biggest supporter, assisting you in learning equiptment."<<endl;
        }
    }
}

void movePlayerForward(int playerIndex, Board myBoard){
    //random number 1-6 simulates spinner
    srand(time(0));
    int randomNum = rand() %6 +1;
    for(int i = 0; i<randomNum; i++){
        myBoard.movePlayer(playerIndex);
    }
}
void displayMenu( Board myBoard, Character c, int playerNum){
    int mainChoice;
    int subChoice;
    cout<<"(1) Check player progress"<<endl;
    cout<<"     (1) Review discovery points"<<endl;
    cout<<"     (2) Review stats"<<endl;
    cout<<"(2) Review character"<<endl;
    cout<<"(3) Check position"<<endl;
    cout<<"(4) Review your advisor"<<endl;
    cout<<"     (1) Review advisor name"<<endl;
    cout<<"     (2) Review advisor specialization"<<endl;
    cout<<"(5) Move forward"<<endl;;

    cout<<"Player "<<playerNum<<" turn: "<<endl;
    cout<<"Select option from main menu: ";
    cin>>mainChoice;
    if(mainChoice == 1){
        cout<<"(1) Review discovery points"<<endl;
        cout<<"(2) Review stats"<<endl;
        cin>>subChoice;
        checkPlayerProgress(c, subChoice);
    }else if(mainChoice == 2){
        reviewCharacter(c);
    }else if(mainChoice == 3){
        checkPosition(playerNum-1, myBoard);
    }else if(mainChoice == 4){
        cout<<"(1) Review advisor name";
        cout<<"(2) Review advisor specialization";
        cin>>subChoice;
        reviewAdvisor(c, subChoice);
    }else if(mainChoice == 5){
        movePlayerForward(playerNum-1, myBoard);
    }
}
int main(){
    //Select scientist and path
    vector<Character> selectedCharacters = selectPathType();
    Board myBoard = Board();
    myBoard.displayBoard();
    int player = 0;
    while(myBoard.getPlayerPosition(0)<52 && myBoard.getPlayerPosition(1)<52){
        if(player ==0){
            displayMenu(myBoard, selectedCharacters[0], 1);
            myBoard.displayBoard();
            player = 1;
            break;
        }else if(player == 1){
            displayMenu(myBoard, selectedCharacters[1], 2);
            myBoard.displayBoard();
            player = 0;
            break;
        }
    }
    int winner;
    if(selectedCharacters[0].discoveryPoints > selectedCharacters[1].discoveryPoints){
        cout<<"Player 1 wins!"<<endl;
        cout<<"Experience: "<<selectedCharacters[0].experience<<endl;
        cout<<"Accuracy: "<<selectedCharacters[0].accuracy<<endl;
        cout<<"Efficiency: "<<selectedCharacters[0].efficiency<<endl;
        cout<<"Insight: "<<selectedCharacters[0].insight<<endl;
    }else if(selectedCharacters[1].discoveryPoints>selectedCharacters[0].discoveryPoints){
        cout<<"Player 2 wins!";
        cout<<"Experience: "<<selectedCharacters[1].experience<<endl;
        cout<<"Accuracy: "<<selectedCharacters[1].accuracy<<endl;
        cout<<"Efficiency: "<<selectedCharacters[1].efficiency<<endl;
        cout<<"Insight: "<<selectedCharacters[1].insight<<endl;
    }else{
        cout<<"Players 1 and 2 tied";
    }
}


