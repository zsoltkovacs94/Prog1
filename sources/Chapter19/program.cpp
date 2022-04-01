#include "std_lib_facilities.h"

template<typename T>
struct S
{
	S(){}
	S(T nval) : val(nval){}
	T& get();
	const T& get() const;
	//void set(T nval){	val=nval;}
	S& operator=(const T&);
	private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& nval)
{
	val = nval;
	return *this;
}

template<typename T>
void read_val(T& val)
{
	cin >> val;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	os << '{';
	int i = 0;
	for (i; i < v.size()-1; i++)
	{
		os << v[i] << ',';
	}
	os << v[i] << '}';
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
	char c;
	is >> c;
	if(c != '{') return is;
	for (T nval; is >> nval;)
	{
		v.push_back(nval);
		is >> c;
		if(c != ',') return is;
	}
	return is;
}

int main()
{
	/*
	S<int> s1 = 7;
	S<char> s2 = 'a';
	S<double> s3 = 10.01;
	string s = "nes";
	S<string> s4 = s;
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	S<vector<int>> s5 = v;
	*/
	cout << "int\n";
	S<int> s1; read_val(s1.get());
	cout << "char\n";
	S<char> s2; read_val(s2.get());
	cout << "double\n";
	S<double> s3; read_val(s3.get());
	cout << "string\n";
	S<string> s4; read_val(s4.get());
	cout << "vector<int> format:{val,val,val...}\n";
	S<vector<int>> s5;
	read_val(s5.get());
	//s1.set(8);
	//s1=8;
	cout << s1.get() << '\n';
	cout << s2.get() << '\n';
	cout << s3.get() << '\n';
	cout << s4.get() << '\n';
	cout << s5.get() << '\n';
	return 0;
}
