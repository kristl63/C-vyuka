#include <iostream>

using namespace std;

void Secti(int a, int b, int* vysledek);

int Main()
{
    int n = 1004;
    char c = 'n';
    int* p = &n;
    char* f = &c;

    printf("hodnota n=%d hodnota c=%c\n",*p,*f);
    printf("pointer na cislo=%p poinetr na cislo=%p\n",&n,&c);

    int* u;

    //inicializace
    u=new int;
    //nebo
    //u = (int*)malloc(sizeof(int));
    //nebo
    //u=&n;

    *u=2022;//dereferencing

    printf("\npointer u=%p,cisloa=%d\n",u,*u);

    //uvolneni pameti ukazatele
    delete u;
    //nebo
    //free(u);
    //
    //free(p);//nebyl dinamicky alokovan delete/free ne bude fungovat(stack)


    //ukazatel na ukazovatele

    int* a;
    int** b;
    b = &a;

    *b = &n;

    printf("\nhodnota cisla n=%d",n);
	printf("\nadresa cisla n=%p", &n);
	printf("\nhodnota ukazatele a=%p", a);
	printf("\nadresa ukazatele a=%p", &a);
	printf("\nhodnota ukaztele b=%p\n", b);


	**b = 50; //zm�na hodnoty ��sla n p�es dvojit� dereferencing
	printf("hodnota cisla n po zmene=%d\n", n);

	//predavani parametru do funkci

	int x = 5;
	int y = 6;
	int vysledek;

	Secti(x, y, &vysledek);

	printf("Vysledek je : % d", vysledek);

}