#include "MaxSumLambda.h"
#include <functional>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//Constructor. Creates a default MaxSumLambda object.
MaxSumLambda::MaxSumLambda() {

}

//Destructor. Deletes a MaxSumLambda object.
MaxSumLambda::~MaxSumLambda() {

}

//@param function<int(int)> func, int lo, int hi
//summs all function values to one result between the lo and hi operator 
// return int result
int MaxSumLambda::sum(std::function<int(int)> func, int lo, int hi) { // 5 und 10
	int result = 0;
	for (int i = (lo+1); i < hi; i++) {
		result = result + func(i);
	}
	cout << "the result of sum between "<< lo <<" and " << hi << " is : " << result << endl;
	return result;
}


//@param vector<lambda> functions, float x
//gets a vector with lambda expressions and finds the biggest float x value 
//in each of the functions. Returns a function at index biggest x found.
//return vector<lambda> functions
lambda MaxSumLambda::max(vector<lambda> functions, float x) { //vector = x -1 ; x*x ; x/5 und x = 2.5
	if (functions.size() == 0) {
		return nullptr;
		//return raus machen !!!
	}

	vector<float> results(functions.size());
	for (int i = 0; i < functions.size(); i++) {
		results[i] = functions[i](x);
		cout << "Result at index " << i << " is " << (float)results[i] << endl;
	}

	vector<float>::iterator maxElementIterator = max_element(results.begin(), results.end());
	cout << "the max element is : " << maxElementIterator[0] << endl;
	return functions[distance(results.begin(), maxElementIterator)];

}

