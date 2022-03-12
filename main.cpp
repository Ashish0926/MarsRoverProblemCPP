#include <iostream>
#include <sstream>
#include <vector>
#include "Rover.hpp"
#include "Plateau.hpp"
#include <string>
#include <unordered_map>
using namespace std;

void printOutput(vector<Rover> &rovers){
    for(int i=0; i<rovers.size(); i++){
        rovers[i].processMovement();
        cout << rovers[i].getX() << " " << rovers[i].getY() << " " << rovers[i].getDirection() << endl;
    }
}

int main() {
    int r, c, i = 0;
    vector<Rover> rovers;
    int x, y;
    char dir;
    string movement;
    string s;
    while(getline(cin, s)){
        if(s.length() == 0){
            break;
        }
        stringstream ss(s);
        string text;
        if(i == 0){
            ss >> text;
            r = stoi(text);
            ss >> text;
            c = stoi(text);
            Plateau p(r, c);
        }
        else if(i % 2 != 0){
            ss >> text;
            x = stoi(text);
            ss >> text;
            y = stoi(text);
            ss >> text;
            dir = text[0];
        }else{
            Rover rov(x, y, dir, s);
            rovers.push_back(rov);
        }
        i++;
    }
    printOutput(rovers);
    return 0;
}