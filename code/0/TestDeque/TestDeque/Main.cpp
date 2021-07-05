#include <iostream>
#include <list>
#include <time.h>
#include <stdio.h>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

string get_a_target_string()
{
	long target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int main()
{
	long value = 100000;
	cout << "\ntest_list()....\n";
	deque<string> c;
	char buf[10];
	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& p)
		{
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;
	cout << "list.size()= " << c.size() << endl;
	cout << "list.max_size()= " << c.max_size() << endl;
	cout << "list.front()= " << c.front() << endl;
	cout << "list.back()= " << c.back() << endl;

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);
	cout << "find(),milli-seconds: " << (clock() - timeStart) << endl;

	if (pItem != c.end())
		cout << "found, " << *pItem << endl;
	else
		cout << "not found! " << endl;

	timeStart = clock();
	//c.sort();
	sort(c.begin(), c.end());
	cout << "c.sort(),milli-seconds: " << (clock() - timeStart) << endl;


	system("pause");
	return 0;
}