#include "std_lib_facilities.h"

struct Item
{
	Item(){};
	Item(string n, int i, double v)
	{
		name=n;
		iid=i;
		value=v;
	}
	void setall(string n, int i, double v)
	{
		name=n;
		iid=i;
		value=v;
	}
	string name;
	int iid;
	double value;
};
istream& operator>>(istream& is, Item& it)
{
	string n;
	int i;
	double v;
	is >> n >> i >> v;
	Item tmp{n,i,v};
	it=tmp;
	return is;
}
ostream& operator<<(ostream& os, Item& i)
{
	os << i.name << ' ' << i.iid << ' ' << i.value << '\n';
	return os;
}
bool sortbyname(Item& a,Item&b){ return a.name<b.name;}
bool sortbyiid(Item& a,Item&b){ return a.iid<b.iid;}
bool sortbyvalue(Item& a,Item&b){ return a.value<b.value;}
void erasebyname(vector<Item>& vi, string en)
{
	auto it = vi.begin();
	while(it!=vi.end()) 
	{
	if(it->name==en)
	{
		vi.erase(it);
		return;
	}
	it++;
	}
	cout << "No item found by the name " << en << '\n';
}
void erasebyiid(vector<Item>& vi, int i)
{
	auto it = vi.begin();
	while(it!=vi.end()) 
	{
	if(it->iid==i)
	{
		vi.erase(it);
		return;
	}
	it++;
	}
	cout << "No item found by the iid " << i << '\n';
}
void erasebyname(list<Item>& li, string en)
{
	auto it = li.begin();
	while(it!=li.end()) 
	{
	if(it->name==en)
	{
		li.erase(it);
		return;
	}
	it++;
	}
	cout << "No item found by the name " << en << '\n';
}
void erasebyiid(list<Item>& li, int i)
{
	auto it = li.begin();
	while(it!=li.end()) 
	{
	if(it->iid==i)
	{
		li.erase(it);
		return;
	}
	it++;
	}
	cout << "No item found by the iid " << i << '\n';
}
int main()
{
	list<Item> li;
	string file;
	cout << "Enter input file name: ";
	cin >> file;
	ifstream istr{file};
	if(!istr) error("Can't open input file!");
	for(Item it;istr >> it;)
	{
		li.push_back(it);
	}
	li.sort(sortbyname);
	li.sort(sortbyiid);
	li.sort(sortbyvalue);
	for (auto it = --li.end();it!=--li.begin();it--)
	{
		cout << *it;
	}
	Item tmp("horse shoe",99,12.34);
	li.push_back(tmp);
	tmp.setall("Canon S400", 9988,499.95);
	li.push_back(tmp);
	erasebyname(li,"table");
	erasebyname(li,"apple");
	erasebyiid(li,6);
	erasebyiid(li,41);
	cout << '\n';
	for (auto it = li.begin();it!=li.end();it++)
	{
		cout << *it;
	}
	return 0;
}
