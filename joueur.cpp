#include "joueur.h"


Personnage::Personnage(std::vector<int> pos):Entite(pos),PV(10){}

std::vector<int> Entite::get_pos()const{
    return this->pos;
}
void Entite::set_pos(std::vector<int> pos){
    this->pos = pos;
}
void Personnage::move(Dir dir){
    int x = this->pos[0];
    int y = this->pos[1];
    switch(dir){
        case Dir::GAUCHE:
            this->set_pos(std::vector<int>(x-1,y));
            break;
        case Dir::DROITE:
            this->set_pos(std::vector<int>(x+1,y));
            break;
        case Dir::HAUT:
            this->set_pos(std::vector<int>(x+1,y));
            break;
        case Dir::BAS:
            this->set_pos(std::vector<int>(x+1,y));
            break;
    }
}
Joueur::Joueur(std::vector<int> pos):Personnage(pos){

}
Entite::Entite(std::vector<int> pos):pos(pos){}