#include<iostream>
using namespace std;

typedef struct a
{
	int data;
}a,*ap;

void change(ap* x)
{
	x[0]->data=23;
	x[1]->data=22;
	x[2]->data=20;
}

int main()
{
	ap x[3];
	x[0] = new a;
	x[1] = new a;
	x[2] = new a;
	change(x);

	

	cout<< x[0]->data << ' ' << x[1]->data << ' '<< x[2]->data <<endl;
	return 0;
}
