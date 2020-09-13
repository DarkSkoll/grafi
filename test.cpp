#include <iostream> 
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <cmath>

struct Punto{
    float x;
    float y;
};

std::vector<struct Punto> puntos;

void generadorParteSuperior(){
    std::cout << "Entra a parte superior" << std::endl;
    struct Punto tmp;
    float y;
    for(float x = -2; x < 2; x += 0.01){
        tmp.x = (float) x;
        y = sqrt(1-pow((abs(x)-1),2));
        tmp.y = (float) y;
        puntos.push_back(tmp);
    }
} 

std::vector<int> serie;

void generadorNumeros(){
    serie.push_back(0);
    serie.push_back(1);
    int x;
    for(int i = 1; i < 25; i++){
        x = serie[i]+serie[i-1];
        serie.push_back(x);
    }
} 

int main(int argc, char **argv){
    generadorNumeros();
    std::cout << "fibo" << std::endl;
    for(int i = 0; i < serie.size(); i++){
        std::cout << serie[i] << std::endl;
    }
    return 0;
}
