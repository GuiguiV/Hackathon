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
            int i = 0;
            while (iss >> x){
                for (char c : x){
                    ground.push_back(c);
                    i++;
                }
            }
            LineLenght = i;
        }
}

void Terrain::print(){
    int i = 0;
    for (char c : ground){
        std::cout << c;
        if (i == LineLenght - 1){
            std::cout << std::endl;
            i = -1;
        }
        i++;
    }
}

char Terrain::get_value(const std::vector<int>& pos) const{
    int x = pos[0];
    int y = pos[1];
    int where = LineLenght * y + x;
    return ground[where];
}

void Terrain::add(const std::vector<int>& pos, char key){
    int x = pos[0];
    int y = pos[1];
    int where = LineLenght * y + x;
    ground[where] = key;
}