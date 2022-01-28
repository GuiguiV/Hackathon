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

void lancer(){
    while(true){
        if (key_event()
