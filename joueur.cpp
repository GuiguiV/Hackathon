
#include "joueur.h"


Joueur::Joueur(std::vector<int> pos):pos(pos){
}

std::vector<int> Joueur::get_pos(){
    return this->pos;
}
void Joueur::set_pos(std::vector<int> pos){
    this->pos = pos;
}
void Joueur::move(Dir dir){
    int x = this->pos[0];
    int y = this->pos[1];
    Dir dir(dir);
    switch(dir){
        case Dir::GAUCHE:
            this->set_pos(std::vector<int>(x,y+1));
            break;
        case Dir::DROITE:
            this->set_pos(std::vector<int>());
            break;
        
    }
}