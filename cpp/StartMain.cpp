#include "FilterList.h"
#include "MaxSumLambda.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// AUFGABE 1.1
	cout << "main started " << endl;
	FilterableList <string> s;
	s.add(s.randomString());
	s.add(s.randomString());
	FilterableList <float> f;
	f.add(f.numbers(3));
	f.add(f.numbers(5));
	f.add(f.numbers(7));
	f.add(f.numbers(1));
	f.add(f.numbers(2));
	f.add(f.numbers(-5));
	f.add(f.numbers(400));
	f.add(-0.5f);
	cout << "floatList size: " << f.getSize() << endl;
	f.filter([](float x) ->bool {return x < 0; });
	f.filter([](float x) ->bool {return x <= 5; });
	f.filter([](int x) ->bool {return x % 2; });
	cout << "stringList size: " << s.getSize() << endl;
	s.filter([](string x) {return x.length() >= 3; });
	s.filter([](string x) {return x.find('s'); });

	//AUFGABE 1.2
	MaxSumLambda ms = MaxSumLambda();
	ms.sum([](int x) ->int {return (x*x) + 7*x; }, 2, 4);

	vector<lambda> floatLambdas = {
		[](float x) -> float { return x - 1; },
		[](float x) -> float { return x*x; },
		[](float x) -> float { return x / 5; }
	};

	ms.max(floatLambdas, 2.5);
	system("pause");

	return 0;
}
