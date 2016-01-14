#include "stdafx.h"
#include "main.h"
#include "LE.h"
#include "Liste.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	cout << "main started " << endl;
	FilterableList <string> l;
	l.add("hallo");
	l.add("blabla");
	FilterableList <float> f;
	f.add(f.Numbers());
	f.add(f.Numbers());
	f.add(f.Numbers());
	return 0;
}

