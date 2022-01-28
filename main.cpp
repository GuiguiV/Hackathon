#include "game.cpp"
#include <string>

int main(){
    Game jeu(std::string("foo.txt"), std::vector<int>({0,0}));
    jeu.lancer();
}
