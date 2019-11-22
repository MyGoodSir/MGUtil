#include "Tracer.h"
#include "Timer.h"

#define BENCH_MODE 1
#if BENCH_MODE
#define BENCHMARK_SCOPE(name) Timer t##__LINE__(name)
#else
#define BENCHMARK_SCOPE(name)
#endif

void fun1(int num) {
	BENCHMARK_SCOPE("fun1");
	for (int i = 0; i < num; i++) {
		std::cout << i*num;
	}
}
void fun2(int num) {
	BENCHMARK_SCOPE("fun2");
	for (int i = 0; i < num; i++) {
		std::cout << i;
	}
}
void RuntimeCheck()
{
	BENCHMARK_SCOPE("RuntimeCheck");
	int num = 500;
	fun1(num);
	fun2(num);
}

int main()
{

	Tracer::get().beginSession("Test");
	RuntimeCheck();
	Tracer::get().endSession();

}