#include <iostream>
#include <thread>
#include <string>

using namespace std;

void function_1()
{
	std::cout << "Beauty is only skin-deep" << std::endl;
}

class Fctor 
{
public:
	/*
	void operator()() 
	{
		cout << endl;
		for (int i = 0; i > -100; i--) 
		{
			cout << "from T1" << i << endl;
		}
		cout << endl;
	}
	*/
	void operator()(string &msg) 
	{
		cout << "T1 says: " << msg << endl;
		msg = "Trust is the mother of deceit.";
	}
};

int main()
{
	string s = "Where there is no trust, there is no love";
	std::thread T1((Fctor()), std::ref(s)); //t1 starts running
	T1.join();
	cout << "Main say: " << s << endl;

	//function_1();
	//std::thread T1(function_1); t1 starts running
	 
	/*
	Fctor fc;
	std::thread T1(fc);

	try 
	{
		cout << endl;
		for (int i = 0; i < 100; i++)
			cout << "from main: " << i << endl;
	}
	catch (...)
	{
		T1.join();
		throw;
	}
	
	T1.join(); //main thread waits for t1 to finish
	*/

	/*T1.detach(); //t1 will freely  on its own -- daemon process
	if (T1.joinable())
	{
		T1.join();
	}*/
	

	return 0;
}