/*
While loop
*/

#include <iostream>

using namespace std;

int main()
{
	int i = 100;
	while (i<=500)
	{
		if (i % 3 == 0 && i % 5 == 0) {
			cout << i<<"\n";
		}
		i++;
	}

	int number;
	cout << "Number: ";
	cin >> number;

	if (number == 0) {
		cout << "Zadal jsi nulu \n";
	}
	else {
		if (number < 0) {
			number *= -1;
		}
		int counter = 0;
		while (number > 0) {
			number /= 10;
			counter++;
		}
		cout << "Pocet cislic " << counter << endl;
	}
}