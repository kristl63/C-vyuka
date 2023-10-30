#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream myFile("aoc.txt");
    std::vector<int> cisla;

    if (!myFile.is_open()) {
        std::cerr << "Failed to open aoc.txt" << std::endl;
        return 1;
    }

    std::string radek;
    while (getline(myFile, radek)) {
        cisla.push_back(std::stoi(radek));
    }
    myFile.close();

    int size = cisla.size();

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
                for(int k = j + 1; k < size; ++k){
                if (cisla[i] + cisla[j] + cisla[k] == 2020) {
                    std::cout << "Found 3 numbers that add up to 2020: " << cisla[i] << " and " << cisla[j] << " and " << cisla[k] << std::endl;
                    std::cout << "Their product is: " << cisla[i] * cisla[j]*cisla[k] << std::endl;
                    return 0; 
                }
            }
        }
    }

    std::cout << "No two numbers add up to 2020 were found." << std::endl;

    return 0;
}