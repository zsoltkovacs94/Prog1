#include "std_lib_facilities.h"
template<typename a>
void write(vector<a> v)
{
	cout << "Writing vector to console...\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}
int main()
{
	vector<double> vd;
	string file;
	cout << "Enter input file name: ";
	cin >> file;
	ifstream istr{file};
	if(!istr) error("Can't open input file!");
	for(double d;istr >> d;)
	{
		vd.push_back(d);
	}
	write(vd);
	vector<int> vi(vd.size());
	copy(vd.begin(),vd.end(),vi.begin());
	cout << "vd and vi values\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << ',' << vi[i] << '\n';
	}
	double sumvd = accumulate(vd.begin(),vd.end(),0.0);
	int sumvi = accumulate(vi.begin(),vi.end(),0);
	cout << "The sum of vd is: " << sumvd << '\n';
	cout << "The difference between the sum of vd and vi is: " << abs(sumvd-sumvi) << '\n';
	reverse(vd.begin(),vd.end());
	write(vd);
	cout << "The mean value of vd is: " << sumvd/vd.size() << '\n';
	vector<double> vd2;
	for (int i = 0; i < vd.size(); i++)
	{
		if(vd[i]<sumvd/vd.size()) vd2.push_back(vd[i]);
	}
	write(vd2);
	sort(vd.begin(),vd.end());
	write(vd);
	return 0;
}
