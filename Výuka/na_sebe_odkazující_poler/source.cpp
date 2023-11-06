#include<iostream>

using namespace std;

struct Pole {
    int value;
    Pole* otherField;
};

void printPole(Pole* pole) {
    cout << pole->value << endl;
    if (pole->otherField != NULL) {
        cout << "otherField: " << pole->otherField->value << endl;
    }
    else {
        cout << "otherField: NULL" << endl;
    }
};

Pole* newPole(int value) {
    Pole* newPole = new Pole();
    newPole->value = value;
    newPole->otherField = NULL;//šipky pro poin ter jinak .value
    return newPole;
}

int main() {

    Pole* pole1 = newPole(10);
    printPole(pole1);
    Pole* pole2 = newPole(20);
    printPole(pole2);

    pole1->otherField = pole2;
    printPole(pole1);

    
    return 0;
}

Pole* addNextPole(int value, Pole* pole) {
    Pole* newPole = new Pole();
    newPole->value = value;
    newPole->otherField = NULL;
    pole->otherField = newPole;
    return newPole;
}

void delNextNode(Pole* pole) {
    Pole* erased = pole->otherField;
    pole->otherField = erased->otherField;
    delete erased;
}

Pole* getPole(Pole* LL, int idx){
    Pole* cur_node = LL;
    for (int i = 0; i < idx; i++) {
        cur_node = cur_node->otherField;
    }
    return cur_node;
}
