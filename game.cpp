#include <iostream>
#include <string>
#include <vector>
#include "keyboard-event.cpp"
#include <cstdlib>
#include "joueur.cpp"
#include "terrain.cpp"


class game
{
    protected:

    joueur joueur;
    terrain terrain;

    public:

    game(const std::string&);
    void lancer();
    void background_clear();
    void afficher();
};

game::game(const std::string& Path, const std::vector<int>& Position) : terrain(Path), joueur(Position) {}

void game::background_clear(){
  // efface la sortie
  int out = system("clear");
  if (out != 0){
    std::cerr << "clear command failed" << std::endl;
    exit(3);
  }
}

void game::afficher(){
    this->terrain->affiche();
    this->joueur->affiche();
}

void game::lancer(){
    char key='q';
    while (true){
        if (keyEvent()) { // une key a été pressée
            std::cin >> key;
            if (key != END_OF_GAME) {
                // si ce n'est pas fin de partie on affiche la clé
                std::cout << key << std::endl;
                if (is_possible_move(Joueur this->joueur))
                this->joueur.move()
                moveSnake(snake, key, posfruit);
                drawSnake(snake, bg, posfruit);
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
