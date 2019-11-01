#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
	std::cout << "Beauty is only skin-deep" << std::endl;
}

int main()
{
	//function_1();
	std::thread T1(function_1); //t1 starts running
	T1.join(); //main thread waits for t1 to finish
	T1.detach(); //t1 will freely  on its own -- daemon process
	return 0;
}