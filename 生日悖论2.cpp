#include <bits/stdc++.h>
using namespace std;
int main()
{
	double p1=(364.0/365);
	double p=1.0;
	int i=0;
	while(1)
	{
		i++;
		p=p*p1;
		if(1-p>=0.5)
			break;
	}
	cout<<"至少必须有"<<i<<"人可以保证至少一人和你生日一天"<<endl;
}