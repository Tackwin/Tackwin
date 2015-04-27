#pragma once
#include <ctime>

class Timer {
private :
	clock_t start = 0;
	float timer = 0;

public :
	Timer(float timer) : timer(timer), start(clock()) {};
	~Timer() {};

	inline float getTimer() const {
		return timer;
	};

	inline float elapsed() const {
		return clock() - start;
	};

	bool isOver(bool r = true) {
		if (clock() - start >= timer) {
			if (r)
				restart();
			return true;
		}
		return false;
	};

	void restart() {
		start = clock();
	};
};