#pragma once
#include <vector>

enum class Dir{GAUCHE,DROITE,HAUT,BAS};
enum class Potion{VIE}
enum class Arme{EPEE, ARC}

class Joueur public Personnage{
    Joueur(std::vector<int> pos);


    protected:
    int piecesOr = 0;
    std::vector<Potion> potions;
    std::vector<Arme> armes;

};


class Personnage public Entite{
    public:
    Personnage(std::vector<int> pos);
    void move(Dir dir);

    protected:
    int PV;

}

class Entite{
    Entite(std::vector<int> pos);
    public:
    std::vector<int> get_pos()const;
    void set_pos(std::vector<int> pos);
        
    protected:
    std::vector<int> pos;


}