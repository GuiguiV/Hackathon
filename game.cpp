#include <iostream>
#include <string>
#include <vector>
#include "keyboard-event.cpp"
#include <cstdlib>
#include "joueur.cpp"
#include "terrain.cpp"


class Game
{
    protected:

    Joueur joueur;
    Terrain terrain;

    public:

    game(const std::string&);
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

void Game::lancer(){
    char key='q';
    while (true){
        if (keyEvent()) { // une key a été pressée
            std::cin >> key;
            if (key != 'x') {
                // si ce n'est pas fin de partie on affiche la clé
                std::cout << key << std::endl;
                if (key == 'd' && mouvement_possible(DIR::DROITE, this->joueur, this->terrain)){
                    joueur->move(DIR::DROITE);
                }
                else if (key == 'z' && mouvement_possible(DIR::HAUT, this->joueur, this->terrain)){
                    joueur->move(DIR::HAUT);
                }
                else if (key == 'q' && mouvement_possible(DIR::GAUCHE, this->joueur, this->terrain)){
                    joueur->move(DIR::GAUCHE);
                }
                else if (key == 's' && mouvement_possible(DIR::BAS, this->joueur, this->terrain)){
                    joueur->move(DIR::BAS); 
                }
                this->terrain.add_joueur(this->joueur.get_pos());
                this->terrain.print();
            }
            else {
                // on efface
                std::cout << "END OF GAME" << std::endl;
                exit(2);
            }
        }
    }
}
