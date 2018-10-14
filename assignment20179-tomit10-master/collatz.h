#ifndef COLLATZ_H
#define COLLATZ_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdint>
#include "counting_iterator.h"
#include "transformreduce.h"

// Do not add any extra #includes without asking on the KEATS discussion forum

uint64_t collatz(uint64_t n) {

	if(n == 1)
	{
	     return(1);
	}
	else
	{
	     if(n % 2 == 0)
	     {return(collatz(n / 2)+1);}
	     else
	     {return(collatz(3*n + 1)+1);}
	}

}

std::pair<uint64_t, uint64_t> collatz_max(uint64_t bound) {
  
    // TODO: your code goes here


}

// Do not edit anything below this line

#endif
