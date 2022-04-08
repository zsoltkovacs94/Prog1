#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1,Iter1 e1, Iter2 f2)
{
		for (f1; f1 != e1; f1++)
		{
			*f2=*f1;
			f2++;
		}
		return f2;		
}

int main()
{
	int ia[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> iv = {0,1,2,3,4,5,6,7,8,9};
	list<int> il = {0,1,2,3,4,5,6,7,8,9};
	int ia2[10];
	vector<int> iv2;
	list<int> il2;
	auto it = il.begin();
	
	for (int i = 0; i < 10; i++)
	{
		ia2[i]=ia[i]+2;
		iv2.push_back(iv[i]+3);
		il2.push_back(*it+5);
		it++;
	}
	
	it = il2.begin();
	for (int i = 0; i != 10; i++)
	{
		cout << ia2[i] << ' ' << iv2[i] << ' ' << *it << '\n';
		it++;
	}
	
	copy2(&ia2[0],&ia2[9],iv2.begin());
	copy2(il2.begin(),il2.end(),&ia2[0]);
	it = il2.begin();
	for (int i = 0; i != 10; i++)
	{
		cout << ia2[i] << ' ' << iv2[i] << ' ' << *it << '\n';
		it++;
	}
	
	auto f1 = find(iv2.begin(),iv2.end(),3);
	if (f1!=iv2.end()) cout << "A vektor tartalmazza a 3-t a " << distance(iv2.begin(),f1) << " indexen\n";
	else cout << "A vektor nem tartalmazza a 3-t\n";
	
	auto f2 = find(il2.begin(),il2.end(),27);
	if (f2!=il2.end()) cout << "A lista tartalmazza a 27-et a " << distance(il2.begin(),f2) << " indexen\n";
	else cout << "A vektor nem tartalmazza a 27-et\n";
	return 0;
}
