#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

struct Punto{
    int x;
    int y;
};

void printPunto(struct Punto punto){
    std::cout << "x = " << punto.x << std::endl;
    std::cout << "y = " << punto.y << std::endl;
    return;
}

int main(int argc, char *argv[]){
    srand (time(NULL));
    std::vector<struct Punto> puntos;
    struct Punto tmp;
    for(int i = 0; i < 10; i++){
        tmp.x = rand() % 10 + 1;
        tmp.y = rand() % 10 + 1;
        puntos.push_back(tmp);
    }
    for(int i = 0; i < puntos.size(); i++){
        std::cout << "Punto #" << i << std::endl;
        printPunto(puntos[i]);
    }
}
