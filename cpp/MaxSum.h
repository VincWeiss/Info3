#ifndef _MAXSUM_H_
#define _MAXSUM_H_
#include "stdafx.h"
#include <algorithm>
#include <functional>

class MaxSum{

public:
	MaxSum();
	~MaxSum();
	int sum(std::function<int(int)> func, int lo, int hi);

};

#endif //_MAXSUM_INCLUDED
