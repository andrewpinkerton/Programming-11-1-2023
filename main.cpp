// Name: Andrew Pinkerton
// Program Description: Multiple Inheritance
// Date: Nov, 1 2023

#include <iostream>
#include <string>
#include <vector>

using namespace std;
// super class (AKA base class, AKA parent class): cereal
// dervied class #1: health
// derived class #2: price
// join class: brand

class Cereal { //super class
public:
	void setMainIng(string text) {
		mainIng = text;
	}
	void setVolume(double number)
	{
		volume = number;
	}
	string getMainIng()
	{
		return mainIng;
	}
	double getVolume()
	{
		return volume;
	}

private:
	string mainIng;
	double volume;
};

class Health : public Cereal { // derived class #1
public:
	void setCarbs(double number)
	{
		carbs = number;
	}
	void setSodium(double number)
	{
		sodium = number;
	}
	double getCarbs()
	{
		return carbs;
	}
	double getSodium()
	{
		return sodium;
	}

private:
	double carbs, sodium;

};

class Price : public Cereal // derived class #2
{
public:
	void setCost(double number)
	{
		cost = number;
	}
	double getCost()
	{
		return cost;
	}
private:
	double cost;

};

class Brand : public Health, public Price { //join class
public:
	void setName(string text)
	{
		name = text;
	}
	void setMascot(string text)
	{
		mascot = text;
	}
	string getName()
	{
		return name;
	}
	string getMascot()
	{
		return mascot;
	}
private:
	string name, mascot;
};

int main()
{
	// create instance of join class
	vector<Brand> kellogs;
	string sTemp;
	double dTemp;

	for (int a = 0; a < 3; a++)
	{
		// create a temp instance of brand
		Brand temp;

		cout << "Enter Cereal Name: ";
		getline(cin, sTemp);
		temp.setName(sTemp);

		cout << "Enter Cereal Mascot: ";
		getline(cin, sTemp);
		temp.setMascot(sTemp);

		cout << "Enter Cereal Cost: $";
		cin >> dTemp;
		temp.setCost(dTemp);

		cout << "Enter Cereal Carbs: ";
		cin >> dTemp;
		temp.setCarbs(dTemp);

		cout << "Enter Cereal Sodium: ";
		cin >> dTemp;
		temp.setSodium(dTemp);

		cin.ignore();

		cout << "Enter Main Ingredient: ";
		getline(cin, sTemp);
		temp.Cereal::setMainIng(sTemp);

		cout << "Enter Cereal Volume: ";
		cin >> dTemp;
		temp.Cereal::setVolume(dTemp);

		kellogs.push_back(temp);
		cout << endl;
		cin.ignore();
	}

	for (int a = 0; a < kellogs.size(); a++) //1 function in join class, use ouput function lmao
	{
		cout << "Cereal Name: " << kellogs[a].getName() << endl;
		cout << "Cereal Macot: " << kellogs[a].getMascot() << endl;
		cout << "Cost $: " << kellogs[a].getCost() << endl;
		cout << "Carbs: " << kellogs[a].getCarbs() << endl;
		cout << "Sodium Content: " << kellogs[a].getSodium() << endl;
		cout << "Main Ingredient: " << kellogs[a].Cereal::getMainIng() << endl;
		cout << "Cereal Box Volume: " << kellogs[a].Cereal::getVolume() << endl << endl;
	}

	return 0;
}
