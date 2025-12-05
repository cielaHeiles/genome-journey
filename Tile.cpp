using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

double DNATask1(string strand1, string strand2){
    //Task 1(blue): calculate similarity score(total matches/total positions) for two strands of equal length
    double similarityScore;
    double totalMatches;
    double totalPositions;
    for(int i = 0; i<(short) strand1.length(); i++){
        if(strand1.at(i)==strand2.at(i)){
            totalMatches++;
        }
        totalPositions++;
    }
    similarityScore = totalMatches/totalPositions;
    return similarityScore;
}

int DNATask2(string input_strand, string target_strand){
    //Task 2(pink): Slide the target strand(shorter) along the input strand(longer), return the starting index of the position with the highest similarity score
    int mostMatches=-1;
    int bestIndex=-1;
    for(int i = 0; i<(int)input_strand.size()-(int)target_strand.size(); i++){
        string substr = input_strand.substr(i, i+(int) target_strand.size());
        int matches=0;
        for(int j=0; j<(int) target_strand.size(); j++){
            if(substr.at(j)== target_strand.at(j)){
                matches++;
            }
        }
        if(matches>mostMatches){
            mostMatches = matches;
            bestIndex = i;
        }
    }
    cout<< "Best similarity score: "<<mostMatches/target_strand.length()<<endl;
    return bestIndex;
}

void DNATask3(string input_strand, string target_strand){
    //Task 3(red): Slide target_strand(shorter) along input_strand(longer) to get optimal position, then identify all substitutions, deletions, and insertions
    int optimalStartingIndex = DNATask2(input_strand, target_strand);
    cout<<optimalStartingIndex;
    for(int i = 0; i<optimalStartingIndex; i++){
        cout<<"Deletion at position "<<i<<": "<<input_strand.at(i)<<" is deleted in target strand"<<endl;
    }
    int j=0;
    for(int i = optimalStartingIndex; i<optimalStartingIndex+(short) target_strand.length(); i++){
        if(input_strand.at(i)!=target_strand.at(j)){
            cout<<"Substitution at position "<<i<<": "<<input_strand.at(i)<<" -> "<<target_strand.at(j)<<endl;
        }
        j++;
    }
    for(int i=optimalStartingIndex + (short) target_strand.length(); i<(short) input_strand.length(); i++){
        cout<<"Deletion at position "<<i<<": "<<input_strand.at(i)<<" is deleted in target strand"<<endl;
    }
}

void DNATask4(string strand){
    //Task 4(brown): Transcribe DNA sequence to RNA by replacing all occurances of T with U, print RNA sequence to console
    string RNAStrand=strand;
    for(int i = 0; i<(int)strand.size(); i++){
        if(RNAStrand.at(i)=='T'){
            RNAStrand.at(i)='U';
        }
    }
    cout<<RNAStrand;
}

bool randomRiddle(){
    //Read lines from riddles.txt into riddles vector, select a random riddle using an rng, print riddle to console and prompt user for answer, return boolean value for correctness
    
    //Read from riddles.txt into riddles vector
    ifstream inFile("riddles.txt");
    string riddle;
    vector<string> riddles(1);
    if(inFile.fail()){
        cout<<"Failed to open file riddles.txt";
    }
    while(getline(inFile, riddle)){
        riddles.push_back(riddle);
    }
    inFile.close();
    //Select random riddle
    srand(time(0));
    int randomNum = rand() % (int)riddles.size() + 1;
    string randRiddle = riddles[randomNum].substr(0, riddles[randomNum].find('|'));
    string randAnswer = riddles[randomNum].substr(riddles[randomNum].find('|')+1, (int)riddles[randomNum].length()-riddles[randomNum].find('|'));
    cout<<randRiddle<<endl;
    //get player answer, compare to randAnswer. Return true if correct, false if incorrect.
    string playerAnswer;
    cin>>playerAnswer;
    if(playerAnswer == randAnswer){
        return true;
    }else{
        return false;
    }
}


struct Event{
    string event;
    int path;
    int advisor;
    int points;
};
int randomEvent(int pathType, int advisor, int currentDiscoveryPoints){
    /*
    Parameters: path type, advisor, current discovery points
    read random_events.txt to a 2D array
    Use rng to pick random event
    Read random event into Event struct
    evaluate effect using path type and advisor
    add/subtract from discovery points, return final discovery points
    */
    //open file
    ifstream inFile("random_events.txt");
    string event;
    vector <string> allEvents(0);
    if(inFile.fail()){
        cout<<"Failed to open file random_events.txt";
    }
    //Read every individual line into a vector
    while(getline(inFile, event)){
        allEvents.push_back(event);
    }
    inFile.close();
    //Read allEvents vector into a 2D array
    int numberOfEvents = (int)allEvents.size();
    string allEventsArray[numberOfEvents][4];
    for(size_t i = 0; i<numberOfEvents; i++){
        stringstream ss(allEvents[i]);
        string item;
        int j=0;
        while(getline(ss, item, '|')){
            allEventsArray[i][j]=item;
            j++; 
        }
        j=0;
    }
    //select random event
    srand(time(0));
    int randomNum = rand() % numberOfEvents + 1;
    Event randomEvent = {allEventsArray[randomNum][0], stoi(allEventsArray[randomNum][1]), stoi(allEventsArray[randomNum][2]), stoi(allEventsArray[randomNum][3])};
    cout<<randomEvent.event<<endl;;
    cout<<randomEvent.path<<endl;
    cout<<randomEvent.advisor<<endl;
    cout<<randomEvent.points<<endl;
    //evaluate effect of event using path type and advisor
    if(randomEvent.points <0){
        if(pathType != randomEvent.path && advisor != randomEvent.advisor){
            currentDiscoveryPoints += randomEvent.points;
        }
    }else{
        if(pathType == randomEvent.path && advisor == randomEvent.advisor){
            currentDiscoveryPoints += randomEvent.points;
        }
    }
    return currentDiscoveryPoints;
}