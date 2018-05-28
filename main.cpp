#include "FunctionalClock.h"

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
void fillVector(std::vector<int>& v, const unsigned int& SIZE);


int main()
{
    // Make Vector of Random Ints
    std::vector<int> rVector;
    rVector.reserve(500000);
    fillVector(rVector, 500000);

    // Store the sort in a lambda to pass to the timing function
    std::function<void()> func = [&]()mutable {std::sort(rVector.begin(), rVector.end()); };
    
    // Send sorting F(x) to timing class and return the time as a double
    double time = FunctionalClock::high_res_timer(func);

    // Output the Result
    std::cout << "Time:\t" << time <<std::endl;
    std::cin.get();
    return 0;
}


void fillVector(std::vector<int>& v, const unsigned int& SIZE)
{
    
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(0, (SIZE * 9) );

		for (unsigned int i = 0; i < SIZE; ++i)
		{
            v.push_back(distribution(generator));
		}
}