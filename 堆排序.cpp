#include <bits/stdc++.h>
using namespace std;

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
void buildHeap(int a[],int n)
{
	for(int i=n ;i>=1;i--)
		maxHeapify(a,i,n);
}
void heapSort(int a[],int n)
{
	int size=n;
	for(int i=n;i>=2;i--)
	{
		swap(a[1],a[i]);
		size--;
		maxHeapify(a,1,size);
	}
}
int main()
{
	int n=10;
	int a[11]={0,5,7,8,9,1,2,4,3,6,0};
	buildHeap(a,n);
	heapSort(a,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}