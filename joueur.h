#include <vector>
#pragma once

enum class Dir{GAUCHE,DROITE,HAUT,BAS};

class Joueur{

    Joueur(std::vector<int>);
    std::vector<int> get_pos();
    void set_pos(std::vector<int> pos);
    void move(Dir dir);



    int piecesOr = 0;
    //ajouter des enum pour les trucs suivants : 
    int nbPotionsHeal = 0;
    int typeArme = 1; //1 : epee, 2:arc
    std::vector<int> pos;

};