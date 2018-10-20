#ifndef MST_NANOSECONDS_H_
#define MST_NANOSECONDS_H_

#include <chrono>

inline long long int nanoseconds(std::chrono::time_point<std::chrono::high_resolution_clock> & since, std::chrono::time_point<std::chrono::high_resolution_clock> & until) {
	return std::chrono::duration_cast<std::chrono::nanoseconds>(until - since).count();
}

#endif //MST_NANOSECONDS_H_
