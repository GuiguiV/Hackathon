#include "joueur.h"
int main(){}

Personnage::Personnage(std::vector<int>& pos,char symbole):Entite(pos,symbole),PV(10),force(1){}

char Entite::get_symbole(){return this-> symbole;}


std::vector<int> Entite::get_pos()const{
    return this->pos;
}
void Entite::set_pos(const std::vector<int>& pos){
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
Joueur::Joueur(std::vector<int>& pos):Personnage(pos,'@'),piecesOr(0){}
Entite::Entite(std::vector<int>& pos,char symbole):symbole(symbole),pos(pos){}

