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
int main()
{
	vector<Item> vi;
	string file;
	cout << "Enter input file name: ";
	cin >> file;
	ifstream istr{file};
	if(!istr) error("Can't open input file!");
	for(Item it;istr >> it;)
	{
		vi.push_back(it);
	}
	sort(vi.begin(),vi.end(),sortbyname);
	sort(vi.begin(),vi.end(),sortbyiid);
	sort(vi.begin(),vi.end(),sortbyvalue);
	for (int i = 0; i < vi.size(); i++)
	{
		cout << vi[vi.size()-i-1];
	}
	Item tmp("horse shoe",99,12.34);
	vi.push_back(tmp);
	tmp.setall("Canon S400", 9988,499.95);
	vi.push_back(tmp);
	erasebyname(vi,"table");
	erasebyname(vi,"apple");
	erasebyiid(vi,6);
	erasebyiid(vi,41);
	cout << '\n';
	for (int i = 0; i < vi.size(); i++)
	{
		cout << vi[vi.size()-i-1];
	}
	return 0;
}
