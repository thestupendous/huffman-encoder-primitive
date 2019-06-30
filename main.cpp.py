#define kya int main()
#include "head.h"
#include "msort.cpp"
#include<queue>
void init(nodep x,const char& c,const u& va);
void init(nodep x);
kya
{


	string text,line;
	while(getline(cin,line))
	{
		if(line == "^D")
			break;
		line += "\n";
		text += line;
	}

	nodep arr[255] = {0};
	for(u i=0;i<255;i++) { init(arr[i],i,0); }
	u akh=0;

	//creating/filling initial arraay
	for(u i=0;i<text.length();i++)
	{
		init( arr[ text[i] ]  );
		cout<<"found "<<(int) text[i] <<" at "<<i<<endl;
	}
	
	arr[10]->data--;

	cout<<"saved \n";
	
	//calculating size akh
	for(u i=0;i<255;i++)
	{
		if(arr[i]->data>0) { cout<<(int)arr[i]->ch<<' '; ++akh; }
	}
	cout<<endl;
	
	
	//creating huff array
	nodep harr[akh];u j=0;
	for(u i=0;i<akh;i++) { harr[i] = new node; }
	for(u i=0;i<255;i++)
	{
		if(arr[i]->data)
		{
			//harr[j++] = arr[i];
			init(harr[j++],i,arr[i]->data);
		}
	}

	cout<<"created huffman's array found "<<akh<<" different characters\n";
	
	for(u i=0; i<akh; i++)
	{
		cout<<i+1<<' '<<(int)harr[i]->ch<<' '<<harr[i]->data<<endl;
	}
	cout<<endl<<endl;


	msort(harr,0,akh-1);
	cout<<"after sorting--\n";
	for(u i=0; i<akh; i++)
	{
		cout<<i+1<<' '<<(int)harr[i]->ch<<' '<<harr[i]->data<<endl;
	}

	akh--;
	
	//creating huffman's tree
	while(akh>=1)
	{
		//creating new node
		nodep n = new node;
		n->data = harr[akh]->data + harr[akh-1]->data;
/**/		cout<<"adding "<<harr[akh]->data<<" and "<<harr[akh-1]->data<<endl;
		n->ch = '\0';

		//joining two nodes to one,
		bool f=0;
		if(harr[akh]->data<=harr[akh-1]->data) f=0;
		else f=1;
		if (!f) { n->b = harr[akh] ; n->d = harr[akh-1]; }
		else { n->b = harr[akh-1] ; n->d = harr[akh] ; }
		
		harr[akh-1] = n;
		akh--;
		msort(harr,0,akh);
	}

	cout<<"created huffman's tree!\n";
	
	char c;
	cin>>c;
	cout<<endl;
	return 0;
}

//to traverse huffman's tree
static int xy=0;
void traverse (nodep head)
{
    if (head==NULL)
    {
        return;
    }
    
    //going left
    if( (head->b) !=NULL)
    {
        xy*=10 + 2;
        traverse(head->b);
    }
    
    //traversing this element, clearing static variable.
    if ( (head->b)== NULL && (head->d) == NULL )
    {
        cout<<"character "<< (head->ch) << xy;
        xy=0;
    }
    
    //going right
    if( (head->d) != NULL )
    {
        xy*=10 + 3;
        traverse(head->d);
    }
}

void init(nodep  a,const char & c,const u& va)
{
    a = new node;
	a->ch = c;
	a->data = va;
	a->b = a->d = NULL;
}
void init(nodep a)
{
	a->data ++ ;
}
