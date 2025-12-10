// Final Exam I | Toma Dimov | COMSC210
#include <iostream>
#include <fstream>
#include <map>
#include <list>

using namespace std;
//Milestone 4: Final polishing, and make sure your driver program exercises all the milestones of this assignment.

const string INPUTFILE = "data.txt", BAR = "====================================\n";
const int ORIGINPLUSDESTSIZE = 2;
//Range testing Consts.
const int LOWRANGE1 = 3,LOWRANGE2 = 14, HIGHRANGE1 = 15, HIGHRANGE2 = 40;

void import_file(map <string, int>&, string);
void print(map <string, int>);
void print_highest_traffic(map <string, int>);
void print_within_range(map <string, int>, int,int);

int main(){
    map <string, int> log;
    import_file(log,INPUTFILE);
    print(log);
    cout<<BAR;
    print_highest_traffic(log);
    cout<<BAR;
    print_within_range(log, LOWRANGE1,HIGHRANGE1);
    cout<<endl;
    print_within_range(log, LOWRANGE2,HIGHRANGE2);
    return 0;
}

void import_file(map <string, int> &M, string input){
    fstream file(input);
    if(file.is_open()){
        string token;
        while(file>>token){ //read until whitespace
            if(M.find(token)==M.end()){ //element not already in map
                pair<string,int> Pair = {token,1}; //make pair, traffic value starts at 1
                M.insert(Pair);
            }
            else{   //element already in map
                M[token] += 1; //bump it up by 1
            }
        }
        file.close();
    }
    else{
        cout<<"Input file not found. Aborting.\n";
        return;
    }
}

void print(map <string, int>M){
    cout<<"All airport traffic counts: \n";
    for(auto it : M){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void print_highest_traffic(map <string, int> M){
    cout<<"Busiest Airports: \n";
    list<pair<string,int>> busiest;     //list of busiest airports.
    int max = 0;
    for(auto it: M){
        if(it.second>max){ //clear the list and hold this as our new max. ties get added at else if below.
            max = it.second;
            busiest.clear();
            busiest.push_back(it);
        }
        else if(it.second == max){ //ties get added here.
            busiest.push_back(it);
        }
    }
    //now print the list
    for(auto it : busiest){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void print_within_range(map <string, int>M, int low,int high){
    cout<<"Airports within traffic ranges: "<<low<< " - " <<high <<endl;
    list<pair<string,int>> range;
    for(auto it : M){
        if(it.second>=low && it.second<=high){
            range.push_back(it);
        }
    }
    //print the range
    for(auto it : range){
        cout<<it.first<<" "<<it.second<<endl;
    }
}