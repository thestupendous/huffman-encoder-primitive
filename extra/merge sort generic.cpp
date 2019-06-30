//x is the data structure of the array
//u is the integer substitution
#define x node
void msort(x * arr,u b, u d)
{
	cout<<"entered " <<b<<' '<<d<<endl;
	if(d-b<=0) return ;

	x * p = new x [d-b+1];

	u mid = (d+b)/2;

	msort(arr,b,mid);
	msort(arr,mid+1,d);


	//then merge
	u i=b,j=mid+1,k=0;

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
		u t=j;
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
	cout<<' ';
	for(i=0;i<(d-b+1);i++)
	{
		cout<< p[i].data << ' ';
	}
	cout<<endl;

}
