#include "FilterList.h"
#include "MaxSumLambda.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	// AUFGABE 1.1
	FilterableList <string> s;
	FilterableList <string> sRes;
	for (int i = 0; i < 7; i++) {
		s.add(s.randomString());
	}
	cout << "all elements of string list : ";
	s.printResult(s.getAll());
	s.remove("ghum");
	sRes = s.filter([](string x) ->bool {return x.length() >= 3; });
	cout << "all strings with word length >= 3 : ";
	sRes.printResult(sRes.getAll());
	sRes = s.filter([](string x) ->bool {return x.find('s') <= x.length(); });
	cout << "all strings with an 's' : ";
	sRes.printResult(sRes.getAll());
	cout << endl << endl;

	FilterableList <float> f;
	FilterableList <float> fRes;
	for (int j = 0; j < 7; j++) {
		f.add(f.randomNumbers());
	}
	cout << "all elements of float list : ";
	f.printResult(f.getAll());
	f.remove(f.getFirst());
	fRes = f.filter([](float x) ->bool {return x < 0; });
	cout << "all elements < 0 : ";
	fRes.printResult(fRes.getAll());
	fRes = f.filter([](float x) ->bool {return x <= 5; });
	cout << "all elements <=5 : ";
	fRes.printResult(fRes.getAll());
	fRes = f.filter([](float x) -> bool
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
	cout << "all odd elements : ";
	fRes.printResult(fRes.getAll());
	cout << endl << endl;

	//AUFGABE 1.2
	int low = -1;
	int high = 2;
	int res;
	MaxSumLambda ms = MaxSumLambda();
	res = ms.sum([](int x) ->int {return (x*x) + 7; }, low, high);
	cout << "the result of sum between " << low << " and " << high << " is " << res << endl << endl;

	vector<lambda> floatLambdas = {
		[](float x) -> float { return x - 1; },
		[](float x) -> float { return x*x; },
		[](float x) -> float { return x / 5; },
		[](float x) -> float { return ((x*x*x) - (x*x + 2 * x) + 27 * x - 101); }
	};

	ms.max(floatLambdas, -3.1f);
	//cout << "the function bla bla jetzt " << ms.max(floatLambdas, -3.1f) << endl;
	system("pause");

	return 0;
}
