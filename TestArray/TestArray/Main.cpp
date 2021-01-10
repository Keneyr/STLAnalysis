#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib> //qsort bsearch NULL
using namespace std;
#define ASIZE 100000 //Ì«´óÁË£¬»á±Àµô..

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
int main()
{
	cout << "\ntest_array().......\n";
	
	array<long, ASIZE> c;
	
	clock_t timeStart = clock();
	for (long i = 0; i < ASIZE; ++i)
	{
		c[i] = rand();
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;
	cout << "array.size()= " << c.size() << endl;
	cout << "array.front()= " << c.front() << endl;
	cout << "array.back()= " << c.back() << endl;
	cout << "array.data()= " << c.data() << endl;

	long target = get_a_target_long();
	timeStart = clock(); //ms
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);
	long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
	cout << "qsort()+bsearch(),milli-seconds: " << (clock() - timeStart) << endl;

	if (pItem != NULL)
		cout << "found, " << *pItem << endl;
	else
		cout << "not found!!" << endl;

	system("pause");
	return 0;
}