#include "std_lib_facilities.h"

class B1
{
	public:
	virtual void vf(){ cout << "B1:vf()\n";}
	void f(){ cout << "B1:f()\n";}
	virtual void pvf() = 0;
};

class D1 : public B1
{
	public:
	void vf() override { cout << "D1:vf()\n";}
	void f() { cout << "D1:f()\n";}
	void pvf() override { cout << "D1:pvf()\n";}
};

class D2 : public D1
{
	public:
	void pvf() override { cout << "D2:pvf()\n";}
};

class B2
{
	public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
	public:
	string s;
	void pvf() override { cout << s << "\n";}
};

class D22 : public B2
{
	public:
	int i;
	void pvf() override { cout << i << "\n";}
	void f(B2& b2) { b2.pvf();}
};

int main()
{
	/*
	B1 b;
	b.vf();
	b.f();
	b.pvf();
	*/
	D1 d;
	d.vf();
	d.f();
	d.pvf();
	B1& ref = d;
	ref.vf();
	ref.f();
	ref.pvf();
	D2 dd;
	dd.vf();
	dd.f();
	dd.pvf();
	D21 d21;
	d21.s = "string";
	D22 d22;
	d22.i = 22;
	d22.f(d21);
	d22.f(d22);
	return 0;
}
