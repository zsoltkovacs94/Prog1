#include "std_lib_facilities.h"

struct Person{
	Person(){};
	Person(string fn, string sn, int a){
		string illegal = ";:\"'[]*&^%$#@!";
		for (int i = 0; i < fn.size(); i++)
		{
			for (int j = 0; j < illegal.size(); j++)
			{
				if(fn[i]==illegal[j]) error("Illegal character in name");
			}
			
		}
		for (int i = 0; i < sn.size(); i++)
		{
			for (int j = 0; j < illegal.size(); j++)
			{
				if(sn[i]==illegal[j]) error("Illegal character in name");
			}
			
		}
		fname=fn;
		sname=sn;
		if(!(a>150 || a<0)) ag=a;
		else error("age out of range");
	}
	int age() const { return ag;}
	string first_name() const { return fname;}
	string second_name() const { return sname;}
	private:
	string fname;
	string sname;
	int ag;
};

istream& operator>>(istream& is, Person& p)
{
	string fn;
	string sn;
	int a;
	is >> fn >> sn >> a;
	p = Person(fn,sn,a);
	return is;
}

ostream& operator<<(ostream& os, Person& p)
{
	os << p.first_name() << ' ' << p.second_name() << ' ' << p.age() << '\n';
	return os;
}

int main() try{
	//Person a = Person("Goofy",63);
	Vector<Person> a;
	Person b;
	while(cin >> b){
		a.push_back(b);
	}
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	
	//cout << a.name() << ' ' << a.age() << '\n';
	return 0;
}

catch (exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 0;
}
catch (...) {
    cerr << "Unknown error!\n";
    return 0;
}

