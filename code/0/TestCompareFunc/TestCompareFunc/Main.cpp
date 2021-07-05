#include <iostream>
#include <string>
using namespace std;

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

	/*if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;*/
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
int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
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
long get_a_target_long()
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

int main()
{
	//感觉这么写字符串对比，不太对劲呢...
	int flg = compareStrings("abcdefg", "abcdeff");
	cout << flg << endl;

	int flgm = compareStringsMine("abcdefg", "abcdeff");
	cout << flgm << endl;

	system("pause");
	return 0;
}