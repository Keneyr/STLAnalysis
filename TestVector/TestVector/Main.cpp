#include <iostream>0
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio> //snprintf()
#include <ctime>
#include <algorithm>
using namespace std;

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}
long get_a_target_long()
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}
int compareStrings(const void* a, const void* b)
{
	string* tmpa = (string*)a;
	string* tmpb = (string*)b;

	if (tmpa > tmpb)
		return 1;
	else if (tmpa < tmpb)
		return -1;
	else
		return 0;
}
int compareStringsMine(char* a, char* b)
{
	while (*(char*)a != '\n'&&*(char*)b != '\n')
	{
		if (*(char*)a > *(char*)b)
			return 1;
		else if (*(char*)a < *(char*)b)
			return -1;
		a++;
		b++;
	}
}
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
	cout << "\ntest_vector().....\n";
	vector<string>c;
	char buf[10];
	clock_t timeStart = clock();
	

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch(exception& p)
		{
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;
	cout << "vector.size()= " << c.size() << endl;
	cout << "vector.front()= " << c.front() << endl;
	cout << "vector.back()= " << c.back() << endl;
	cout << "vector.data()= " << c.data() << endl;

	cout << "vector.capacity()= " << c.capacity() << endl;

	string target = get_a_target_string();
	{
		timeStart = clock();
		auto pItem = find(c.begin(), c.end(), target);
		cout << "find(),milli-seconds: " << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;
	}
	{
		timeStart = clock();
		sort(c.begin(), c.end());
		string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareStrings);
		cout << "sort()+bseearch(), milli-seconds: " << (clock() - timeStart) << endl;

		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found! " << endl;
	}
	system("pause");
	return 0;
}
