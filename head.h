#define u int
#include<iostream>
using namespace std;


typedef struct node
{
	char ch;
	u data;
	node * b,*d;
} node , *nodep;

bool operator>=(node a,node b)
{
	return ( a.data >= b.data );
}

