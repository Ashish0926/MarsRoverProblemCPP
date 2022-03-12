#ifndef ROVER
#define ROVER

#include "Plateau.hpp"
#include <unordered_map>
#include <string>
using namespace std;

class Rover {
private:
    int x;
    int y;
    int dirInt; // integer direction (0 --> N, 1 --> W, 2 --> S, 3 --> E)
    char dirChar; // character direction (N, S, E, W)
    string movement;
    unordered_map<int, char> intToChar;
    unordered_map<char, int> charToInt;
    unordered_map<char, pair<int, int>> move;
    void initializeMap();
    bool isValidMove(int length, int width);

public:
    Rover(int x, int y, char direction, string movement) {
        initializeMap();
        this->x = x;
        this->y = y;
        dirChar = direction;
        dirInt = charToInt[direction];
        this->movement = movement;
    }
    
    void processMovement() {
        for(int k=0; k<movement.length(); k++){
            if(movement[k] == 'L'){
                dirInt = (dirInt + 1) % 4;
                dirChar = intToChar[dirInt];
            }else if(movement[k] == 'R'){
                dirInt = (dirInt + 3) % 4;
                dirChar = intToChar[dirInt];
            }else {
                int moveInX = move[dirChar].first;
                int moveInY = move[dirChar].second;
                if(isValidMove(x + moveInX, y + moveInY)){
                    x += moveInX;
                    y += moveInY;
                }
            }
        }
    }

    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    char getDirection() {
        return dirChar;
    }
};

void Rover::initializeMap() {
        intToChar[0] = 'N';
        intToChar[1] = 'W';
        intToChar[2] = 'S';
        intToChar[3] = 'E';

        charToInt['N'] = 0;
        charToInt['W'] = 1;
        charToInt['S'] = 2;
        charToInt['E'] = 3;

        move['N'] = {0, 1};
        move['S'] = {0, -1};
        move['E'] = {1, 0};
        move['W'] = {-1, 0};
}

bool Rover::isValidMove(int x, int y) {
    if(x >= 0 && y >= 0 && x <= Plateau::getLength() && y <= Plateau::getWidth()){
        return true;
    }
    return false;
}

#endif