#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <execution>

#include "../HPFT.FunctionTImer/FunctionalClock.h"

void fillVector(std::vector<int>& v, const unsigned int& SIZE);
void printTest(std::string test_name, double time);


int main()
{
    for (long i = 100; i <= 1000000000; i *= 10)
    {
        // Make Vector of Random Ints
        std::vector<int> rVector;
        rVector.reserve(i);
        fillVector(rVector, i);

        // Store the sort in a lambda to pass to the timing function
        std::function<void()> func = [&]()mutable {std::sort(std::execution::seq, rVector.begin(), rVector.end()); };
        // Send sorting F(x) to timing class and return the time as a double
        double time_sort = hpft::timer(func);
        // Output the Result
        std::ostringstream oss;
        oss << i;
        printTest("std::sort(seq) - n=" + oss.str(), time_sort);
    }

    for (long i = 100; i <= 1000000000; i *= 10)
    {
        // Make Vector of Random Ints
        std::vector<int> rVector;
        rVector.reserve(i);
        fillVector(rVector, i);

        // Store the sort in a lambda to pass to the timing function
        std::function<void()> func = [&]()mutable {std::sort(std::execution::par, rVector.begin(), rVector.end()); };
        // Send sorting F(x) to timing class and return the time as a double
        double time_sort = hpft::timer(func);
        // Output the Result
        std::ostringstream oss;
        oss << i;
        printTest("std::sort(par) - n=" + oss.str(), time_sort);
    }

    for (long i = 100; i <= 1000000000; i *= 10)
    {
        // Make Vector of Random Ints
        std::vector<int> rVector;
        rVector.reserve(i);
        fillVector(rVector, i);

        // Store the sort in a lambda to pass to the timing function
        std::function<void()> func = [&]()mutable {std::sort(std::execution::par_unseq, rVector.begin(), rVector.end()); };
        // Send sorting F(x) to timing class and return the time as a double
        double time_sort = hpft::timer(func);
        // Output the Result
        std::ostringstream oss;
        oss << i;
        printTest("std::sort(par_unseq) - n=" + oss.str(), time_sort);
    }

    


    


    // Inline Declaration with no lambda
    double time_print = hpft::timer([]() {std::cout << "Hello World\n"; });
    // Output the Result
    printTest("std::cout", time_print);


    // Inline Declaration with no lambda
    time_print = hpft::timer([]() {
        std::cout << "Hello World" << std::endl;
        std::cout << std::endl << std::endl;
        });
    // Output the Result
    printTest("std::cout - endl", time_print);


    std::cin.get();
    return 0;
}



void fillVector(std::vector<int>& v, const unsigned int& SIZE)
{

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, (SIZE * 9));

    for (unsigned int i = 0; i < SIZE; ++i)
    {
        v.push_back(distribution(generator));
    }
}


void printTest(std::string test_name, double time)
{
    std::cout << test_name << ":\t\t\tTime: " << time << std::endl;
}