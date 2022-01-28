#include <iostream>
#include <string>
#include <vector>

if (terrain.get_value(joueur.get_pos())=='+'){ // On rentre dans un couloir
    if (dir == Dir::DROITE){
        joueur->move(Dir::DROITE);
    }
    if (dir == Dir::GAUCHE){
        joueur->move(Dir::DROITE);
    }
    if (dir == Dir::HAUT){
        joueur->move(Dir::DROITE);
    }
    if (dir == Dir::BAS){
        joueur->move(Dir::DROITE);
    }
    // On est vraiment dans le couloir
    while (terrain.get_value(joueur.get_pos()) !='+'){// On n'est pas ressorti
        std::vector<int> pos = joueur.get_pos();
        int x = pos[0];
        int y = pos[1];
        if (dir == Dir::DROITE){
            if (terrain.get_value({x+1,y})== '#'){
                joueur->move(Dir::DROITE);
            }
            else if (terrain.get_value({x,y+1})== '#'){
                joueur->move(Dir::HAUT);
            }
            else if (terrain.get_value({x,y-1})== '#'){
                joueur->move(Dir::BAS);
            }
        }
        else if (dir == Dir::GAUCHE){
            if (terrain.get_value({x-1,y})== '#'){
                joueur->move(Dir::GAUCHE);
            }
            else if (terrain.get_value({x,y+1})== '#'){
                joueur->move(Dir::HAUT);
            }
            else if (terrain.get_value({x,y-1})== '#'){
                joueur->move(Dir::BAS);
            }
        }
        else if (dir == Dir::HAUT){
            if (terrain.get_value({x,y+1})== '#'){
                joueur->move(Dir::HAUT);
            }
            else if (terrain.get_value({x+1,y})== '#'){
                joueur->move(Dir::DROIT);
            }
            else if (terrain.get_value({x-1,y})== '#'){
                joueur->move(Dir::GAUCHE);
            }
        }
        else if (dir == Dir::BAS){
            if (terrain.get_value({x,y-1})== '#'){
                joueur->move(Dir::BAS);
            }
            else if (terrain.get_value({x+1,y})== '#'){
                joueur->move(Dir::DROIT);
            }
            else if (terrain.get_value({x-1,y})== '#'){
                joueur->move(Dir::GAUCHE);
            }
        }
    }
}