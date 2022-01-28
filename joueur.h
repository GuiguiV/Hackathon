#pragma once
#include <vector>

enum class Dir{GAUCHE,DROITE,HAUT,BAS};
enum class Potion{VIE};
enum class Arme{EPEE, ARC};


class Entite{
    public:
    Entite(const std::vector<int>& pos,char symbole);
    std::vector<int> get_pos()const;
    void set_pos(const std::vector<int>& pos);
    char get_symbole();
    void ramasser_piece();
    void ramasser_arme(Arme arme);
    void ramasser_potion(Potion potion);

    protected:
    std::vector<int> _pos;
    char _symbole;

};

class Personnage : public Entite{
    public:
    Personnage(const std::vector<int>& pos,char symbole);
    void combattre(Personnage adversaire);
    void move(Dir dir);

    protected:
    int _PV;
    int _force;

};

class Joueur : public Personnage{
    public :
    Joueur(const std::vector<int>& pos);



    protected:
    int _piecesOr;
    std::vector<Potion> _potions;
    std::vector<Arme> _armes;
    Arme _armePrincipale;

};