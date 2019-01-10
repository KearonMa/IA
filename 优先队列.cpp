#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
void maxHeapify(int a[],int i,int n)
{
	if(2*i>n) 
		return;
	int maxc=2*i;
	if(maxc+1<=n&&a[maxc]<a[maxc+1])
		maxc++;
	if(a[i]>=a[maxc])
		return;
	swap(a[i],a[maxc]);
	maxHeapify(a,maxc,n);
}

int extract(int a[],int &n)
{
	int maxn=a[1];
	a[1]=a[n];
	n--;
	maxHeapify(a,1,n);
	return maxn;
}
void increase(int a[],int i,int k)
{
	if(k<a[i])
	{
		cout<<"new key is smaller than current key!"<<endl;
		return;
	}
	a[i]=k;
	while(i>1&&a[i]>a[i/2])
	{
		swap(a[i],a[i/2]);
		i/=2;
	}
}
void insert(int a[],int k,int &n)
{
	n++;
	a[n]=-inf;
	increase(a,n,k);
}
int main()
{
	int priQue[110]={0};
	int n=0;
	int op;
	while(1)
	{
		cout<<"0:exit"<<endl;
		cout<<"1:insert"<<endl;
		cout<<"2:extract"<<endl;
		cin>>op;
		switch(op)
		{
			case 0: break;
			case 1: 
			{
				int k;
				cin>>k;
				insert(priQue,k,n);
/*				for(int i=1;i<=n;i++)
					cout<<priQue[i]<<' ';
				cout<<endl;*/
				break;
			}
			case 2:
			{
				cout<<extract(priQue,n)<<endl;
/*				for(int i=1;i<=n;i++)
					cout<<priQue[i]<<' ';
				cout<<endl;*/
				break;
			}
		}
		if(!op)
			break;
	}
}