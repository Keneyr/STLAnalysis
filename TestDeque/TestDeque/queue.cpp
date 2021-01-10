#include <iostream>
#include <queue>
#include <time.h>
#include <string>
#include <list>
using namespace std;

int main()
{
	long value = 100000;
	queue<string> c;
	char buf[10];
	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push(string(buf));
		}
		catch (exception& p)
		{
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;
	cout << "stack.size()= " << c.size() << endl;
	//cout << "stack.pop()= " << c.top() << endl;
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	//cout << "stack.top()= " << c.top() << endl;

	system("pause");
	return 0;
}