#include "Terrain.h" 

Terrain::Terrain(const std::string& filename):ground(){
    std::ifstream input_file(filename);
        if (!input_file.is_open()){
            std::cerr << "cannot open file '" << filename << "'" << std::endl;
            exit(0);
        }
        std::string line;
        while (getline(input_file, line)){
            std::istringstream iss(line);
            std::string x;
            int i;
            while (iss >> x){
                for (char c : x){
                    ground.push_back(c);
                }
            }
            LineLenght = i;
        }
}

void Terrain::print(){
    for (int i = 0; i < ground.size(); i++){
        std::cout << ground[i];
    }
}