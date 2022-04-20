#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "joueur.h"


class Terrain{
    std::vector<char> _ground;
    std::vector<char> _oldground;
    int _LineLenght;
    public:
    Terrain(const std::string& filename);
    void add(std::vector<int> pos, char key);
    void add(Entite Entite);
    char get_value(std::vector<int> pos) const;
    void print();

};