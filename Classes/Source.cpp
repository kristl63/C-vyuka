#include <iostream>

using namespace std;

class Person
{
public:
	bool gender;
	int height;
	void setAge(int ageValue);
	int getAge();
	Person(bool genderValue, int heightValue, int ageValue);
private:
	int age;
protected:

};
Person::Person(bool genderValue, int heightValue, int ageValue)
{
	gender = genderValue;
	height = heightValue;
	age = ageValue;
}
void Person::setAge(int ageValue)
{
	age = ageValue;
}
int Person::getAge()
{
	return age;
}


int main() {

	Person tomas(0,175,22);

	//tomas.setAge(20);

	////tomas.age = 20;
	//tomas.gender = 0;
	//tomas.height = 170;

	//cin >> tomas.age;

	cout << tomas.getAge() << endl;
	cout << tomas.gender << endl;
	cout << tomas.height << endl;

	return 0;
}


