#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>
using Numeric_lib::Matrix;

void sqrt_from_cin()
{
	int value;
	cin >> value;
	if(value>=0) cout << sqrt(value) << '\n';
	else cout << "no square root\n";
	return;
}

int main()
{
	cout 	<< "Sizeof() types\n"
			<< "char " << sizeof(char) 
			<< "\nshort " << sizeof(short)
			<< "\nint " << sizeof(int)
			<< "\nlong " << sizeof(long)
			<< "\nfloat " << sizeof(float)
			<< "\ndouble " << sizeof(double)
			<< "\nint* " << sizeof(int*)
			<< "\ndouble* " << sizeof(double *) << '\n';
			
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	
	cout 	<< "Sizeof() matrixes\n"
			<< "Matrix<int> a(10) " << sizeof(a)
			<< "\nMatrix<int> b(100) " << sizeof(b)
			<< "\nMatrix<double> c(10) " << sizeof(c)
			<< "\nMatrix<int,2> d(10,10) " << sizeof(d)
			<< "\nMatrix<int,3> e(10,10,10) " << sizeof(e) << '\n';
	cout 	<< "Number of elements of matrixes\n"
			<< "Matrix<int> a(10) " << a.size()
			<< "\nMatrix<int> b(100) " << b.size()
			<< "\nMatrix<double> c(10) " << c.size()
			<< "\nMatrix<int,2> d(10,10) " << d.size()
			<< "\nMatrix<int,3> e(10,10,10) " << e.size() << '\n';
	cout << "Enter a number\n";
	sqrt_from_cin();
	
	cout << "Enter 10 floats\n";
	Matrix<double> m1(10);
	for (int i = 0; i < 10; i++) cin >> m1[i];
	cout << m1 << '\n';
	
	cout << "Enter n and m values\n";
	int m, n;
	cin >> n >> m;
	Matrix<double, 2> m2(n,m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			m2(i,j) = i * j;
		}
	}
	cout << m2 << '\n';
	
	cout << "Enter 10 complex numbers\n";
	Matrix<complex<double>> m3(10);
	for (int i = 0; i < 10; i++) cin >> m3[i];
	complex<double> sum = 0;
	for (int i = 0; i < 10; i++) sum += m3[i];
	cout << "Sum " << sum << '\n';
	cout << "Enter six ints\n";
	Matrix<int,2> m4(2,3);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> m4[i][j];
		}
	}
	cout << m4 << '\n';
	return 0;
}
