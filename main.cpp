#include "FunctionalClock.h"

#include "main.h"

int main()
{
    // Make Vector of Random Ints
    std::vector<int> rVector;
    rVector.reserve(500000);
    fillVector(rVector, 500000);

    std::cout << "Is sorted\t" << std::is_sorted(rVector.begin(), rVector.end()) << std::endl;
    // Store the sort in a lambda to pass to the timing function
    std::function<void()> func = [&]()mutable {std::sort(rVector.begin(), rVector.end()); };
    // Send sorting F(x) to timing class and return the time as a double
    double time = FunctionalClock::high_res_timer(func);
    // Output the Result
    std::cout << "std::sort() - Time:\t" << time << std::endl << std::endl;
    std::cout << "Is sorted\t" << std::is_sorted(rVector.begin(), rVector.end()) << std::endl;

    // Inline Declaration with no lambda
    double time2 = FunctionalClock::high_res_timer([](){std::cout << "Hello World\n";});
    // Output the Result
    std::cout << "std::cout - Time:\t" << time2 <<std::endl;
 

    std::cin.get();
    return 0;
}


