#pragma once
#include <vector>

enum class Dir{GAUCHE,DROITE,HAUT,BAS};

class Joueur{

    public:

    Joueur(const std::vector<int>&);
    std::vector<int> get_pos() const;
    void set_pos(const std::vector<int>& pos);
    void move(Dir dir);


    protected:

    int piecesOr = 0;
    //ajouter des enum pour les trucs suivants : 
    int nbPotionsHeal = 0;
    int typeArme = 1; //1 : epee, 2:arc
    std::vector<int> pos;

};