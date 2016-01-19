#ifndef _FILTERLIST_H_
#define _FILTERLIST_H_
#include "FilterLIst.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template <class type>
class FilterableList
{

private:
	//variable initializing
	vector <type> filterList;


public:
	//Constructor. Creates an empty FilterableList object
	FilterableList()
	{
		filterList;
	}

	//Destructor. Deletes the FilterableList object
	~FilterableList()
	{
		
	}

	//@param function<bool(type)> func
	//gets a lambda expression and returns true if element in the vector is conform with expression
	//safes all comform elements to new list
	//return vector <type> lambdaResult
	vector <type> filter(std::function<bool(type)> func) {
		vector <type> lambdaResult;
		for (int i = 0; i < filterList.size(); i++) {
			if (func(filterList[i])) {
				lambdaResult.push_back(filterList[i]);
				cout << "added to lambda result List : " << filterList[i] << endl;
			}
		}
		return lambdaResult;
	}

	//@param type value
	//adds a float or string type to the vector
	void add(type value)
	{
		filterList.push_back(value);
		cout << "added a : " << value << " to list " << endl;
	}

	//@param type value
	//search the value in list and delates it if found
	void remove(type value) {
		if (value != NULL) {
			for (int i = 0; i < filterList.size(); i++) {
				if (filterList[i] == value) {
					filterList.erase(i);
				}
				else {
					cout << "element to delate not found in list" << endl;
				}
			}
		}
	}


	//@param type valueWanted
	//searches the list for element and returns true if element was found
	//return bool hasE
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

	//returns the size of actual list
	//return size_t 
	size_t getSize() {
		return filterList.size();
	}

	//@param int num
	//generates a random float for the list
	//return float x
	float numbers(int num) {
		float x = 0.0f;
		if (num < 1) {
			cout << "You have to add at least one number." << endl;
		}
		else {
			for (int i = 0; i < num; i++) {
				x = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + 1) * 100);
			}
		}
		return x;
	}

	//generate random strings for string list
	//return string word
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
