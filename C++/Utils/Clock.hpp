#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#endif

struct Clock {
private:
	double T = 0;
	double L = 0;
	bool flag = false;

	static inline double now(void) {
		#ifdef __ANDROID__
		timespec s;
		clock_gettime(CLOCK_REALTIME, &s);
		return 1000.0 * (1000.0 * s.tv_sec + (double)s.tv_nsec / 1e6) / (double)CLOCKS_PER_SEC;
		#endif
		#ifdef _WIN32
		LARGE_INTEGER i;
		if(QueryPerformanceFrequency(&i)) {
			LARGE_INTEGER n;
			QueryPerformanceCounter(&n);
			return ((1000LL * n.QuadPart) / i.QuadPart) / 1000.0;
		} else {
			return GetTickCount() / 1000.0;
		}
		#endif
	} 

public:
	double timer = 0.f;

	Clock(double timer = 0.0) : timer(timer), L(now()) {}
	~Clock() {}

	inline double start(){
		L = now();
		flag = false;
		return T;
	}
	inline double pause(){
		T += now() - L;
		flag = true;
		return T;
	}
	inline double restart(){
		double t = (flag) ? T : T + now() - L;
		T = 0;
		start();
		return t;
	}
	inline double elapsed() const {
		if(flag)
			return T;
		else
			return T + now() - L;
	}
	inline bool isOver() const{
		return elapsed() >= timer;
	}
	inline bool isPaused() const {
		return flag;
	}

};

#endif