#include<iostream>
using namespace std;
#define u int
#define x int *

void swap (x,x);

void qsort(x* arr,u b,u d)
{
	if (d-b<=0) return;
	
	//partitioning, pivot based on first value
	u piv = b;
	u m,n;
	m= *arr[piv+1];
	n= *arr[d];
	while(m<n)
	{
        //find left candidate
        while( *arr[m] <= *arr[piv])
        {
            ++m;
        }
        
        //find right candidate
        while(*arr[n] > *arr[piv])
        {
            n--;
        }
        
        //swap
        if(m<n) swap(arr[m],arr[n]);
        m++;n--;
    }
    
    //print arranged array
    for(u i=b;i<=d;i++)
    cout<< *arr[i]<<' ';
    cout<<endl;
}
	
void print(x* a,u s)
{
	for(u i=0;i<s;i++)
	{
		cout<< *(*(a+i)) << ' ';
	}
	cout<<endl;
}

int main()
{
	x arr[10];
	for(u i=0;i<10;i++) arr[i] = new int;
	*(arr[0]) = 34;
	*(arr[1]) = -4;
	*(arr[2]) =  4;
	*(arr[3]) = 302;
	*(arr[4]) = 5;
	*(arr[5]) = 10;
	*(arr[6]) = -412;
	*(arr[7]) = 90;
	*(arr[8]) = 62;
	*(arr[9]) = 1;
/*
	x a;
	x b;
	u m,n;
	m=3;n=4;
	a=&m;
	b=&n;
	swap(a,b);
	*/
	qsort(arr,0,9);
	print(arr,10);
	cout<<endl;
	return 0;
}


void swap(x a,x b)
{
    x c = a;
    a = b;
    b = c;
}
