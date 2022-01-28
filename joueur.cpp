#pragma once
#include "joueur.h"


Joueur::Joueur(const std::vector<int>& pos):pos(pos){
}

std::vector<int> Joueur::get_pos() const {
    return this->pos;
}
void Joueur::set_pos(const std::vector<int>& pos){
    this->pos = pos;
}
void Joueur::move(Dir dir){
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