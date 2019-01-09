#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i=2;
	double p=1.0;
	cout<<"一年的天数："<<endl;
	cin>>n;
	while(i++)
	{
		p=p*(n-i+1)/n;
		if(p<=0.5)
			break;
	}
	cout<<"当人数是： "<<i<<"  时至少有两人的生日相同的概率大于50%。"<<endl;
}