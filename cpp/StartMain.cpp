#include "FilterList.h"
#include "MaxSumLambda.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	// AUFGABE 1.1
	FilterableList <string> s;
	for (int i = 0; i < 7; i++) {
		s.add(s.randomString());
	}
	cout << "stringList size: " << s.getSize() << endl;
	s.filter([](string x) ->bool {return x.length() >= 3; });
	s.filter([](string x) ->bool {return x.find('s') <= x.length(); });
	
	FilterableList <float> f;
	for (int j = 0; j < 7; j++) {
		f.add(f.numbers());
	}
	cout << 2 % 2 << endl;
	cout << "floatList size: " << f.getSize() << endl;
	f.filter([](float x) ->bool {return x < 0; });
	f.filter([](float x) ->bool {return x <= 5; });
	f.filter([](float x) -> bool
				{
					if (x >= 0.5) {
						x = int (x - 0.5) % 2; 
					}
					else if (x <= -0.5) {
						x = int(x + 0.5) % 2;
					}
					else {
						x = 1 % 2;
					}
					
					return x;
				});

	//AUFGABE 1.2
	int low = -1;
	int high = 2;
	MaxSumLambda ms = MaxSumLambda();
	ms.sum([](int x) ->int {return (x*x) + 7; }, low, high);

	vector<lambda> floatLambdas = {
		[](float x) -> float { return x - 1; },
		[](float x) -> float { return x*x; },
		[](float x) -> float { return x / 5; },
		[](float x) -> float { return ((x*x*x) - (x*x + 2 * x) + 27 * x - 101); }
	};

	ms.max(floatLambdas, -3.1f);
	system("pause");

	return 0;
}
