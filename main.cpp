// Final Exam I | Toma Dimov | COMSC210
#include <iostream>
#include <fstream>
#include <map>

const string INPUTFILE = "data.txt";
/*
Milestone 1: In this assignment's details page, download and install the text file as your data source for this project. In it, each line contains two airport codes representing a particular flight's origin and destination, for example:
JFK LAX
ORD DEN
LAX SFO

Create an std::map<std::string, int> that maps an airport code to its traffic count. Read the file, and for each flight, insert origin and destination airports into the map if they do not exist yet; and increment each airport’s count once.
Your driver program should build the map from the file and print all airports and their counts in the natural sorted order of the map. 

Milestone 2: Add code that finds the highest traffic count to represent the busiest airport. Print all airports that have this maximum count (in other words, handle ties).
Your driver program should build the map, print all counts, and then print the busiest airport(s) and their count. 

Milestone 3: Add a function that prints only airports whose traffic counts fall within a specified inclusive range [low, high].
Your driver program should build the map and call the function at least twice with different ranges, clearly showing which airports fall in each range. Do not code user input. 

Milestone 4: Final polishing, and make sure your driver program exercises all the milestones of this assignment.*/

using namespace std;

void import_file(map <string, int>, string);

int main(){
    map <string, int> log;
    import_file(log,INPUTFILE);
    return 0;
}

void import_file(map <string, int> M, string input){
    fstream file(input);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            string dest;
            string origin;
            //parse the string to store dest and origin
            bool first = true;
            for (char c : line) {   //range based loop for all characters in the line. a space (' ') char is our delimeter
                if(c==' '){
                    if(!first) //we've reached the end
                        break;
                    first==false; //otherwise, we move onto dest
                }
                if(first){
                    origin += c;
                }
                else{
                    dest+=c;
                }
            }
            //now we store them in the map. we will use an array to speed up the process utilizing a for loop to write our code without copy-pasting for both origin and dest.
            string both[2] = {origin,dest};


            if(M.find(origin)!=M.end()){ //element not already in map
                pair<string,int> originPair = {origin,1}; //make pair, traffic value starts at 1
                M.insert(originPair);
            }
            else{
                M[origin] += 1;
            }
            if(M.find(dest)!=M.end()){ //element not already in map
                pair<string,int> destPair = {dest,1}; //make pair, traffic value starts at 1
                M.insert(destPair);
            }
            else{
                M[dest] += 1;
            }
        }
        file.close();
    }
    else{
        cout<<"Input file not found. Aborting.\n";
        return;
    }
}