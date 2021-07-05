#include <iostream>
#include <unordered_map>
#include <string>
#include <thread>

using namespace std;

struct eqstr
{
	bool operator()(const char* s1, const char* s2)const {
		return strcmp(s1, s2) == 0;
	}
};

void display(unordered_map<const char*, int, hash<const char*>, eqstr>& days, string str)
{
	cout << str << endl;
	for (auto& x : days)
		cout << x.first << ":" << x.second << endl;
	cout << endl;

	cout << "bucket操作" << endl;
	unsigned n = days.bucket_count();
	cout << "mymap has " << n << " buckets.\n";

	//注意桶这里，我们也不知道hashFunc是啥，我们只知道，经过一系列骚操作，这个pair数据被放在了某个index下的bucket里面
	for (unsigned i = 0; i < n; ++i)
	{
		cout << "bucket #" << i << "'s size:" << days.bucket_size(i) << " contains: ";
		for (auto it = days.begin(i); it != days.end(i); ++it)
			cout << "[" << it->first << ":" << it->second << "] ";
		cout << endl;
	}
	cout << "january is in bucket " << days.bucket("january") << endl;
}
void func()
{

}
int main()
{
	//////////////////////////////////////////////////////////////////////////

	//参数分别是key，value，hashFunc，对key的对比函数
	unordered_map<const char*, int, hash<const char*>, eqstr> days;
	
	days["january"] = 31;
	days["february"] = 28;
	days["march"] = 31;
	days["april"] = 30;
	days["may"] = 31;
	days["june"] = 30;
	days["july"] = 31;
	days.insert(pair<const char*, int>("august", 31));
	cout << "janyary" << ' ' << days["january"] << endl;
	display(days, "展示无序容器：");


	//////////////////////////////////////////////////////////////////////////
	//unordered_map 不支持thread作为value，这可如何是好？
	//////////////////////////////////////////////////////////////////////////
	//unordered_map<const char*, std::thread> workers;
	//for (int i = 0; i < 3; i++)
	//{
	//	thread t(func);
	//	//workers["work1"] = t;
	//	workers.insert(pair<const char*, std::thread>("work1", t));
	//}
	

	system("pause");
	return 0;
}