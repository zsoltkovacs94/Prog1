#include <stdio.h>

void funct(char* p, int x)
{
	printf("p is %s and x is %i\n", p, x);
}

int main()
{
	printf("Hello World!\n");
	char* s1 = "Hello";
	char* s2 = "World!";
	printf("%s %s\n", s1, s2);	
	funct("asd",1);
	funct("fgh",2);
	funct("jkl",3);
	funct("qwe",4);
	funct("rtz",5);
	return 0;
}
