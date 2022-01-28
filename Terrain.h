#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class Terrain{
    std::vector<char> ground;
    int LineLenght;
    public:
    Terrain(const std::string& filename);
    void add_joueur(std::pair<int, int> pos);
    char get_value(std::vector<int> pos);
    void print();
};