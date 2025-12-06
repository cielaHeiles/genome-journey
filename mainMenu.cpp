using namespace std;
#include <iostream>;
#include "player.cpp";
void mainMenu(){
    cout<<"(1) Check Player Progress"<<endl;
    cout<<"     (1) Review Discover Points"<<endl;
    cout<<"     (2) Review trait stats"<<endl;
    cout<<"(2) Review character"<<endl;
    cout<<"     (1) Review character name"<<endl;
    cout<<"     (2) Review character training"<<endl;
    cout<<"(3) Check Position"<<endl;
    cout<<"(4) Review your advisor"<<endl;
    cout<<"(5) Move Forward"<<endl;
}

void checkPlayerProgress(int option, Character c){
    if(option ==1){
        cout<<c.name<<" discovery points: "<<c.discoveryPoints<<endl;
    }else if(option ==2){
        cout<<c.name<<" stats: "<<endl;
        cout<<"Experience: "<<c.experience<<endl;
        cout<<"Accuracy: "<<c.accuracy<<endl;
        cout<<"Efficiency: "<<c.efficiency<<endl;
        cout<<"Insight: "<<c.insight<<endl;
    }else{
        cout<<"The option you selected is not available. Please select a different menu option."<<endl;
        mainMenu();
    }
}

void reviewCharacter(int option, Character c){
    if(option == 1){
        cout<<"Name: "<<c.name<<endl;
    }else if(option == 2){
        cout<<"Training: ";
        if(c.path == 0){
            cout<<"You are on the Training Fellowship path. Your scientist is being equipped with essential traits (accuracy, efficiency, and insight) needed for future challenges."<<endl;
        }else if(c.path == 1){
            cout<<"You are on the Direct Lab Assignment path. Your scientist jumped directly into the life of DNA sequencing and is learning through on-the-job training."<<endl;
        }
    }else{
        cout<<"The option you selected is not available. Please select a different menu option."<<endl;
        mainMenu();
    }
}