#include "stdafx.h"
#include "MaxSum.h"
#include <functional>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
	//Standard Konstruktor zum erstellen einer leeren Liste
	MaxSum::MaxSum(){
		
	}

	//Destruktor zum l?schen der Liste
	MaxSum::~MaxSum(){

	}

	int MaxSum::sum(std::function<int(int)> func, int lo, int hi) { // 5 und 10
		int result = 0;
		for (int i = lo; i < hi; i++) {
			result += func(i);
		}
		cout << "the result is : " << result << endl;
		return result;
	}
