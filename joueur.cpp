#include "joueur.h"


Personnage::Personnage(const std::vector<int>& pos,char symbole):Entite(pos,symbole),_PV(10),_force(1){}

char Entite::get_symbole(){return this-> _symbole;}


std::vector<int> Entite::get_pos()const{
    return this->_pos;
}
void Entite::set_pos(const std::vector<int>& pos){
    this->_pos = pos;
}
void Personnage::move(Dir dir){
    int x = this->_pos[0];
    int y = this->_pos[1];
    switch(dir){
        case Dir::GAUCHE:
            this->_pos = std::vector<int>(x-1,y);
            break;
        case Dir::DROITE:
            this->_pos = std::vector<int>(x+1,y);
            break;
        case Dir::HAUT:
            this->_pos = std::vector<int>(x,y-1);
            break;
        case Dir::BAS:
            this->set_pos(std::vector<int>(x,y+1));
            break;
    }
}
Joueur::Joueur(const std::vector<int>& pos):Personnage(pos,'@'),_piecesOr(0){}
Entite::Entite(const std::vector<int>& pos,char symbole):_symbole(symbole),_pos(pos){}

