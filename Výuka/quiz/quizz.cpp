#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

struct Otazka{
    std::string otazka;
    std::string a;
    std::string b;
    std::string c;
    char spravnaOdpoved;
};

using namespace std;

int main() {
    std::ifstream file("otazky.txt");
    std::vector<Otazka> otazky;
    if(file.is_open()){
        std::string radek;
        while(getline(file,radek)){
            Otazka otazka;
            std::stringstream ss(radek);
            getline(ss,otazka.otazka,';');
            getline(ss,otazka.a,';');
            getline(ss,otazka.b,';');
            getline(ss,otazka.c,';');
            ss >> otazka.spravnaOdpoved;
            otazky.push_back(otazka);
        }
        file.close();
    }
    
    int spravne = 0;
    for(int i = 0; i < otazky.size(); i++){
        std::cout << otazky[i].otazka << std::endl;
        std::cout << "A) " << otazky[i].a << std::endl;
        std::cout << "B) " << otazky[i].b << std::endl;
        std::cout << "C) " << otazky[i].c << std::endl;
        char odpoved;
        std::cin >> odpoved;
        if(odpoved == otazky[i].spravnaOdpoved){
            spravne++;
        }
    }
    std::cout << "Spravne odpovedi: " << spravne << "/" << otazky.size() << std::endl;

    return 0;
}