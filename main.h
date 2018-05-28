
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

void fillVector(std::vector<int>& v, const unsigned int& SIZE)
{
    
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(0, (SIZE * 9) );

		for (unsigned int i = 0; i < SIZE; ++i)
		{
            v.push_back(distribution(generator));
		}
}