#include<iostream>
using namespace std;


typedef struct node
{
 char ch;
 int data;
 node * b,*d;
} node , *nodep;

bool operator<=(node a,node b)
{
 return ( a.data < b.data );
}



void msort(node * arr,int b, int d)
{

 if(d-b<=0) return ;

 node * p = new node [d-b+1];

 int mid = (d+b)/2;

 msort(arr,b,mid);
 msort(arr,mid+1,d);



 int i=b,j=mid+1,k=0;

 while(i<=mid && j<=d)
 {
  if(arr[i]<=arr[j])
  {
   p[k++] = arr[i++];
  }
  else
  {
   p[k++] = arr[j++];
  }
 }
 if(i==mid+1)
 {
  int t=j;
  while(j<=d)
  {
   p[k++] = arr[j++];
  }
  j=t;
 }
 else if(j==d+1)
 {
  while(i<=mid)
  {
   p[k++] = arr[i++];
  }
 }
 i=b;k=0;
 while(i<=d)
 {
  arr[i++]=p[k++];

 }







}
void init(node& node,char c,int va);

int main()
{
 nodep arr = new node[10];
 for(int i = 0;i<10;i++)
 {
  init(arr[i],'j'-i,0);
 }

 for(int i=0;i<10;i++)
 {
  cout<<(arr[i].ch)<<' '<<(arr[i].data)<<'\t';
 }
 cout<<endl;

 msort(arr,0,9);

 for(int i=0;i<10;i++)
 {
  cout<<(arr[i].ch)<<' '<<(arr[i].data)<<'\t';
 }
 cout<<endl;
 return 0;
}
void init(node& a,char c,int va)
{
 a.ch = c;
 a.data = va;
 a.b = a.d = NULL;
}
