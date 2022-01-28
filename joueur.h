#pragma once
#include <vector>

enum class Dir{GAUCHE,DROITE,HAUT,BAS};
enum class Potion{VIE};
enum class Arme{EPEE, ARC};


class Entite{
    public:
    Entite(std::vector<int>& pos,char symbole);
    std::vector<int> get_pos()const;
    void set_pos(const std::vector<int>& pos);
    char get_symbole();

    protected:
    std::vector<int> pos;
    char symbole;

};

class Personnage : public Entite{
    public:
    Personnage(std::vector<int>& pos,char symbole);
    void combattre(Personnage adversaire);
    void move(Dir dir);

    protected:
    int PV;
    int force;

};

class Joueur : public Personnage{
    Joueur(std::vector<int>& pos);



    protected:
    int piecesOr;
    std::vector<Potion> potions;
    std::vector<Arme> armes;
    Arme armePrincipale;

};