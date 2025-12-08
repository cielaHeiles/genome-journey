using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>


string generateStrand(int len){
    
    string bases[4] = {"A", "T", "C", "G"};
    string strand;
    for(int i = 0; i < len; i++){
        int base = rand() % 4;
        strand += bases[base];
    }
    return strand;
}

string generateTargetStrand(){
    //length is 4
    string bases[4] = {"A", "T", "C", "G"};
    string strand;
    for(int i = 0; i < 4; i++){
        int base = rand() % 4;
        strand += bases[base];
    }
    return strand;
}

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

/*
Generate strands and display
Display task
Take in user input
Return if correct or not/change points
*/

int executeDNATask1(){
    srand(time(0));
    string strand1 = generateStrand(8);
    string strand2 = generateStrand(8);
    int points;
    double playerSimilarityScore;
    double correctSimilarityScore;
    cout<<"For the followng two DNA strands, calculate the similarity score based on the number of matching bases at corresponding positions with the following formula:"<<endl<<"Similarity = total matches/total positions"<<endl;
    cout<<strand1<<endl<<strand2<<endl;
    cout<<"Enter similarity score: ";
    cin>>playerSimilarityScore;
    //round both these values to 2 decimal places later
    correctSimilarityScore = DNATask1(strand1, strand2);
    if(playerSimilarityScore == correctSimilarityScore){
        cout<<"Correct answer!";
        points = 50;
    }else{
        cout<<"Incorrect answer";
        points = -50;
    }
    return points;
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
    return bestIndex;
}

int executeDNATask2(){
    string input_strand = generateStrand(8);
    string target_strand = generateTargetStrand();
    int points;
    int playerStartingIndex;
    int correctStartingIndex = DNATask2(input_strand, target_strand);
    cout<<"For these two strands of different legths, slide the shorter strand along the longer strand and find the location with the best alignment between the two strands. Indicate the starting index of that position."<<endl;
    cout<<"Enter starting index: ";
    cin>>playerStartingIndex;
    if(playerStartingIndex = correctStartingIndex){
        cout<<"Correct answer!";
        points = 50;
    }else{
        cout<<"Incorrect answer.";
        points = -50;
    }
    return points;
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

int executeDNATask3(){
    string input_strand = generateStrand(8);
    string target_strand = generateTargetStrand();
    //Write this
    return 1;
}

string DNATask4(string strand){
    //Task 4(brown): Transcribe DNA sequence to RNA by replacing all occurances of T with U, print RNA sequence to console
    string RNAStrand=strand;
    for(int i = 0; i<(int)strand.size(); i++){
        if(RNAStrand.at(i)=='T'){
            RNAStrand.at(i)='U';
        }
    }
    return RNAStrand;
}

int executeDNATask4(){
    string strand = generateStrand(8);
    string playerRNAStrand;
    string correctRNAStrand = DNATask4(strand);
    int points;
    cout<<"Transcribe the DNA strand to RNA by replacing all occurances of thymine('T') with uracil('U')"<<endl;
    cout<<"Enter RNA strand: ";
    cin>>playerRNAStrand;
    if(playerRNAStrand == correctRNAStrand){
        cout<<"Correct answer!"<<endl;
        points = 50;
    }else{
        cout<<"Incorrect answer."<<endl;
        points = -50;
    }
    return points;
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