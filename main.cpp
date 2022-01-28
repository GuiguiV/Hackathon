#include "game.cpp"

int main(){
    Game jeu(std::string("foo2.txt"), std::vector<int>({3,5}));
    jeu.lancer();
}
