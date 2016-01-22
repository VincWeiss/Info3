#ifndef _FILTERLIST_H_
#define _FILTERLIST_H_
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <typeinfo>

using namespace std;

template <class type>
class FilterableList{

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
	FilterableList <type> filter(std::function<bool(type)> func) {
		FilterableList <type> lambdaResult;
		for (int i = 0; i < filterList.size(); i++) {
			if (func(filterList[i])) {
				lambdaResult.add(filterList[i]);
			}
		}
		return lambdaResult;
	}

	//@param type value
	//adds a float or string type to the vector
	void add(type value){
		filterList.push_back(value);
	}

	//@param type value
	//search the value in list and deletes it if found
	void remove(type value) {
		for (int i = 0; i < filterList.size(); i++) {
			if (filterList[i] == value) {
				cout << "deleted : " << value << endl;
				filterList.erase(filterList.begin() + i);
			}
		}
	}

	//gets the first element from list
	//return filterList[0]
	type getFirst() {
		return filterList[0];
	}


	//@param type valueWanted
	//searches the list for element and returns true if element was found
	//return bool hasE
	bool has(type valueWanted){
		bool hasE = false;
		for (int i = 0; i <= filterList.size(); i++) {
			if (filterList[i] == valueWanted) {
				hasE = true;
			}
		}
		return hasE;
	}

	//returns the size of actual list
	//return size_t 
	size_t getSize() {
		if (filterList.size() == 0) {
			throw invalid_argument("vector size is 0");
		}
		return filterList.size();
	}

	//gets all elements from the FilterableList to a vector 
	//returns a vector with these elements
	//return allListElements
	vector <type> getAll() {
		vector <type> allListElements;
		if (filterList.size() == 0) {
			throw invalid_argument("vector to copy is empty");
		}
		for (int i = 0; i < filterList.size(); i++) {
			allListElements.push_back(filterList[i]);
		}
		return allListElements;
	}

	//@param vector <type> vec
	//method to print all results of the vector
	//if i == vector size - stopp (endl) 
	void printResult(vector <type> vec) {
		if (vec.size() == 0) {
			throw invalid_argument("vector to print is empty");
		}
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " || ";
			if (i == (vec.size() - 1)) {
				cout << endl;
			}
		}
	}

	//@param int num
	//generates a random float for the list
	//return float x
	float randomNumbers() {
		float x;
		float y;
		x = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 10);
		y = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * -10);
		return x + y;
	}

	//generate random strings for string list
	//return string word
	string randomString() {
		string word = "";
		char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
		int wordlenght = rand() % 10;
		for (int i = 0; i < wordlenght; ++i) {
			word += alphabet[rand() % (sizeof(alphabet) - 1)];
		}
		return word;
	}

};
#endif //_LISTE_INCLUDED
