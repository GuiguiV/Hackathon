#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "keyboard-event.cpp"
#include <cstdlib>
#include "joueur.cpp"
#include "Terrain.cpp"


class Game
{
    protected:

    Joueur joueur;
    Terrain terrain;

    public:

    game(const std::string&, const std::vector<int>&);
    void lancer();
    void background_clear();
    void afficher();
};

Game::game(const std::string& Path, const std::vector<int>& Position) : terrain(Path), joueur(Position) {}

void Game::background_clear(){
  // efface la sortie
  int out = system("clear");
  if (out != 0){
    std::cerr << "clear command failed" << std::endl;
    exit(3);
  }
}

void Game::afficher(){
    this->terrain->affiche();
    this->joueur->affiche();
}

bool mouvement_possible (Dir dir, const Joueur& joueur, const Terrain& terrain){
    std::vector<int> pos=joueur.get_pos();
    std::vector<int> new_pos {pos[0], pos[1]};
    if (dir == Dir::DROITE){
        new_pos[0] += 1;
    }
    if (dir == Dir::GAUCHE){
        new_pos[0] -= 1;
    }
    if (dir == Dir::HAUT){
        new_pos[1] += 1;
    }
    if (dir == Dir::BAS){
        new_pos[1] -= 1;
    }
    return (terrain.get_value(new_pos) != '|' && terrain.get_value(new_pos) != '-');
}

void Game::lancer(){
    char key='q';
    while (true){
        if (keyEvent()) { // une key a été pressée
            std::cin >> key;
            if (key != 'x') {
                // si ce n'est pas fin de partie on affiche la clé
                std::cout << key << std::endl;
                if (key == 'd' && mouvement_possible(Dir::DROITE, this->joueur, this->terrain)){
                    joueur->move(Dir::DROITE);
                }
                else if (key == 'z' && mouvement_possible(Dir::HAUT, this->joueur, this->terrain)){
                    joueur->move(Dir::HAUT);
                }
                else if (key == 'q' && mouvement_possible(Dir::GAUCHE, this->joueur, this->terrain)){
                    joueur->move(Dir::GAUCHE);
                }
                else if (key == 's' && mouvement_possible(Dir::BAS, this->joueur, this->terrain)){
                    joueur->move(Dir::BAS); 
                }
                this->background_clear();
                this->terrain.add(this->joueur.get_pos(),'@');
                this->terrain.print();
            }
            else {
                // on efface
                this->background_clear();
                std::cout << "END OF GAME" << std::endl;
                exit(2);
            }
        }
    }
}
