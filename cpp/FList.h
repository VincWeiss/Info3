#ifndef _FLIST_H_
#define _FLIST_H_
#include "stdafx.h"
#include "FList.h"
#include <cstdlib>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template <class type>
class FilterableList
{

private:

	vector <type> filterList;


public:
	//Standard Konstruktor zum erstellen einer leeren Liste
	FilterableList()
	{
		filterList;
	}

	//Destruktor zum l?schen der Liste
	~FilterableList()
	{
		//removeFirst();
	}

	//Filtert die Liste bez?glich der Elemente
	vector <type> filter(std::function<bool(type)> func) {
		vector <type> lambdaResult;
		for (int i = 0; i < filterList.size(); i++) {
			if (func(filterList[i])) {
				lambdaResult.push_back(filterList[i]);
				cout << "added to lambda result List : "<< filterList[i] << endl;
			}
		}
		return lambdaResult;
	}

	//Todo.. Lambda quatsch m?sst ich grad selber nachschauen und muss essen gehen ;P

	//Funktion um zu ermitteln ob die Liste leer ist
	bool empty()
	{
		if (filterList.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Funktion um ein Element (@param value) hinten an die Liste anzuf?gen
	void add(type value)
	{
		filterList.push_back(value);
		cout << "added a : " << value << " to list " << endl;
	}

	size_t getSize()
	{
		return filterList.size();
	}


	//Funktion um ein Element, das vorne an der Liste steht, zu l?schen
	void removeFirst()
	{
		if (filterList.size() != 0)
		{
			filterList.erase(0);
		}
	}


	//Funktion um ein Element an Stelle #index zu l?schen
	void remove(type value) {
		if (value != NULL) {
			filterList.erase(0);
		}
	}


	//Methode zur R?ckgabe des LE am angegebenen Index
	type& has(type valueWanted)
	{
		boolean hasE = false;
		if (valueWanted != NULL) {
			for (int i = 0; i <= filterList.size(); i++) {
				if (filterList[i] == valueWanted) {
					hasE = true;
				}
				else {
					hasE = false;
				}
			}
		}

		return hasE;
	}

	//generate random Floats ---> neue Methde finden, die immer neue Zahlen generiert!!!!
	float numbers(int num) {
		float x = 0.0f;
		if (num < 1) {
			cout << "You have to add at least one number." << endl;
		}
		else {
			for (int i = 0; i < num; i++) {
				x = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)+1)*100);
			}
		}
		return x;
	}

	//generate random strings
	std::string randomString() {
		std::string word = "";
		char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
		int wordlenght = rand() % 20;
		for (int i = 0; i < wordlenght; ++i) {
			word += alphabet[rand() % (sizeof(alphabet) - 1)];
		}
		return word;
	}

};
#endif //_LISTE_INCLUDED

