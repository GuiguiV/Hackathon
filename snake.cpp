#include <iostream>
#include <string>
#include <vector>
#include "keyboard-event.cpp"
#include <cstdlib>

const int LINES = 20;
const int COLUMNS = 30;
const char GROUND='.';
const char WALL_TOP = '_';
const char WALL_SIDE = '|';
const int ms = 200;
const char END_OF_GAME = 'x';

void drawPlayground (const std::vector<std::vector<char>>& playground){
    // affiche la matrice (le playground)
    for (int i=0 ; i<playground.size() ; i++){
        for (int j=0 ; j<playground[i].size() ; j++){
            std::cout << playground[i][j];
        }
        std::cout << std::endl;
    }
}

void playgroundSetup(std::vector<std::vector<char>>& playground){
  // vide le playground
  for (int i=0 ; i<playground.size(); i++){
    for (int j=0 ; j<playground[0].size(); j++){
        playground.at(i).at(j)=GROUND;
    }
  }
  for (int i=0 ; i<playground.size(); i++){
      playground.at(i).at(0)=WALL_SIDE;
       playground.at(i).at(playground[0].size()-1)=WALL_SIDE;
  }
  for (int j=0 ; j<playground[0].size(); j++){
    playground.at(0).at(j)=WALL_TOP;
  }
  for (int j=1 ; j<playground[0].size()-1; j++){
      playground.at(playground.size()-1).at(j)=WALL_TOP;
  }
}


void backgroundClear(){
  // efface la sortie
  int out = system("clear");
  if (out != 0){
    std::cerr << "clear command failed" << std::endl;
    exit(3);
  }
}

void moveFruit (std::vector<int>& posfruit){
  // fait bouger le fruit de manière random
  int x=rand()%(LINES-2);
  int y=rand()%(COLUMNS-2);
  posfruit={x+1,y+1};
}

std::vector<std::vector<int>> createSnake (int i){ // i=longueur du serpent
// crée le serpent au milieu
  std::vector<std::vector<int>> s;
  for (int j=0 ; j<i ; j++){
    std::vector<int> s_j= {LINES/2,COLUMNS/2 + j};
    s.push_back(s_j);
  }
  return s;
}

void moveSnake(std::vector<std::vector<int>>& s, char key, std::vector<int>& posfruit){
  // fait avancer le serpent
  int n=s.size();
  if (s[0]== posfruit){
    s.push_back(s[n-1]);
    moveFruit(posfruit);
  }
  for (int i=0 ; i<n-1 ; i++){
    s[n-i-1]=s[n-i-2];
  }
  if (key == 'd'){
    s[0][1]=s[0][1]+1;
  }
  else if (key == 'z'){
    s[0][0]=s[0][0]-1;
  }
  else if (key == 'q'){
    s[0][1]=s[0][1]-1;
      
  }
  else if (key == 's'){
    s[0][0]=s[0][0]+1; 
  }
  for (int i=1; i<n;i++){
    if (s[i]==s[0]){
      backgroundClear();
      std::cout << "Aie ma tête" << std::endl;
      exit(2);
    }
  }
}



void drawSnake(std::vector<std::vector<int>>& s, std::vector<std::vector<char>>& playground, std::vector<int>& posfruit){
  // fait apparaitre le serpent dans le playground
  playgroundSetup(playground);
  for (int i=1; i<s.size();i++){
    int x = s[i][0];
    int y = s[i][1];
    playground[x][y]='o';
  }
  playground[s[0][0]][s[0][1]]='O';
  playground.at(posfruit[0]).at(posfruit[1])='f';
}





void startGame(const int ms, std::vector<std::vector<char>> &bg, std::vector<std::vector<int>>& snake, std::vector<int>& posfruit)
{char key='q';
  while (true)
    {
      // on efface le playground
      backgroundClear();
      // on dessine le playground
      drawPlayground(bg);
      // le jeu est une boucle sans fin qu'on temporise de ms entre deux mouvements du serpent (on règle comme cela la vitesse du serpent)
      sleepOneLap(ms);
      if (keyEvent()) {
        std::cin >> key;
        // une key a été pressée
        if (key != END_OF_GAME) {
        // si ce n'est pas fin de partie on affiche la clé
          std::cout << key << std::endl;
          moveSnake(snake, key, posfruit);
          if ((snake[0][0] == 0) || (snake[0][0] == LINES) || (snake[0][1] == 0) || (snake[0][1] == COLUMNS)){
            // La tete du serpent heurte un bord
            backgroundClear();
            std::cout<< "Aye ma tête"<<std::endl;
            exit(2);
          }
          drawSnake(snake, bg, posfruit);
        } else {
          // on efface
          backgroundClear();
          std::cout << "END OF GAME" << std::endl;
          exit(2);
        }
      }
      else {
        moveSnake(snake, key, posfruit);
        if ((snake[0][0] == 0) || (snake[0][0] == LINES) || (snake[0][1] == 0) || (snake[0][1] == COLUMNS)){
          // La tete du serpent heurte un bord
          backgroundClear();
          std::cout<< "Aye ma tête"<<std::endl;
          exit(2);
        }
        drawSnake(snake, bg, posfruit);
      }
    }
}

int main (int argc, char** argv){
    std::vector<char> x (COLUMNS, GROUND);
    std::vector<std::vector<char>> playground (LINES, x);
    playgroundSetup(playground);
    drawPlayground (playground);
    std::vector<int> posfruit = {4,9};
    std::vector<std::vector<int>> snake = createSnake(6);
    startGame(ms, playground, snake,posfruit);
}