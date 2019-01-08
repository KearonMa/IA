#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[25];
	for(int i=0;i<20;i++)
		a[i]=i;
	srand((int)time(0));
	for(int i=0;i<20;i++)
		swap(a[i],a[rand()%(20-i)+i]);
	for(int i=0;i<20;i++)
		printf("%d ",a[i]);
	printf("\n");
}
