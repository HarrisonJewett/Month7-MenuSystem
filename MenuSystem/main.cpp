#include "stdIncludes.h"
#include "doSomething.h"

doSomething play;

class DTSTimer
{
	unsigned int startTime;
public:
	DTSTimer() { reset(); }

	void reset() { startTime = clock(); }

	unsigned int getElapsedTime()
	{
		return (clock() - startTime);
	}

	static void delay(const unsigned int milli)
	{
		unsigned int st = clock();
		while (clock() - st < milli) {}
	}

};

int main(int argc, char ** argv)
{
	play.start();
	return 0;
}