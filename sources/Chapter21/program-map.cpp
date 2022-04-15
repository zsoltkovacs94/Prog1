#include "std_lib_facilities.h"
void insertfromcin(map<string,int>& m)
{
	string s;
	int n;
	cin >> s >> n;
	m.insert(make_pair(s,n));
}
void write(map<string,int>& m)
{
	for (auto a : m)
	{
		cout << a.first << ' ' << a.second << '\n';
	}
}
void write(map<int,string>& m)
{
	for (auto a : m)
	{
		cout << a.first << ' ' << a.second << '\n';
	}
}
int main()
{
	map<string,int> msi;
	msi["phone"]=69;
	msi["apple"]=32;
	msi["football"]=70;
	msi["diamond"]=6;
	msi["table"]=59;
	msi["piano"]=87;
	msi["hat"]=77;
	msi["basket"]=41;
	msi["engine"]=25;
	msi["tea"]=97;
	write(msi);
	msi.erase(msi.begin(),msi.end());
	for (int i = 0; i < 10; i++)
	{
		insertfromcin(msi);
	}
	write(msi);
	int sum=accumulate(msi.begin(),msi.end(),0,[](int sum, const pair<string,int>& p){ return sum += p.second;});
	cout << "Sum: " << sum << '\n';
	map<int,string> mis;
	for(auto a : msi) mis[a.second]=a.first;
	write(mis);
	return 0;
}
