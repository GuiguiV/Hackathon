#include "game.cpp"

int main(){
    Game jeu(std::string("Terrain.txt"), std::vector<int>({3,5}));
    jeu.lancer();
}
