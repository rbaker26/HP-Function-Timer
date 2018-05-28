#include "FunctionalClock.h"

#include "main.h"

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


