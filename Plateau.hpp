#ifndef PLATEAU
#define PLATEAU

class Plateau {
private:
    static int x, y;
public:
    Plateau(int x, int y){
        this->x = x;
        this->y = y;
    }
    static int getLength() {
        return x;
    }
    static int getWidth() {
        return y;
    }
};

int Plateau:: x;
int Plateau:: y;

#endif