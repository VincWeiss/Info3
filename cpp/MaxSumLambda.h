#pragma once
#ifndef _MAXSUMLAMBDA_H_
#define _MAXSUMLAMBDA_H_
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

typedef function<float(float)> lambda;
class MaxSumLambda {
	
public:
	//Constructor. Creates a default MaxSumLambda object.
	MaxSumLambda();

	//Destructor. Deletes a MaxSumLambda object.
	~MaxSumLambda();

	//@param function<int(int)> func, int lo, int hi
	//summs all function values to one result between the lo and hi operator 
	// return int result
	int sum(std::function<int(int)> func, int lo, int hi);

	//@param vector<lambda> functions, float x
	//gets a vector with lambda expressions and finds the biggest float x value 
	//in each of the functions. Returns a function at index biggest x found.
	//return vector<lambda> functions
	lambda max(vector<lambda> functions, float x);

};

#endif //_MAXSUMLAMBDA_INCLUDED

