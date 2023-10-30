#include <iostream>

unsigned long long factorial(int n) {
    if (n < 0) {
        std::cerr << "Chyba: Faktoriál nelze počítat pro záporná čísla." << std::endl;
        return 0;
    }

    unsigned long long cislo= 1;
    for (int i = 1; i <= n; ++i) {
        cislo *= i;
    }
    return cislo;
}

int main() {
    int n;
    std::cout << "Zadejte číslo pro výpočet faktoriálu: ";
    std::cin >> n;

    unsigned long long cislo = factorial(n);
    std::cout << "Faktoriál " << n << " je " << cislo << std::endl;

    return 0;
}

/*
int cislo=5;
faktorial=1;
for(int i=2;i<=cislo;i++){
    faktorial*=i;
}
cout<<faktorial<<endl;
*/