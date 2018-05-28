#pragma once

#include <chrono>
#include <functional>

class FunctionalClock
{
public:
	FunctionalClock() {}
	~FunctionalClock() {}

	static double high_res_timer(std::function<void()> lambda)
	{
		// auto = std::chrono::time_point<std::chrono::steady_clock>;
		auto start = std::chrono::high_resolution_clock::now();
		lambda();
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> time = end - start;
			
		return time.count();
	}

};
