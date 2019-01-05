/**
 * 假设你希望以1/2概率输出0和1。
 * 你可以自由使用一个输出0和1的过程BIASED-RANDOM。
 * 它以概率p输出1，概率1-p输出0，其中0<p<1，但是p的值未知。
 *
 * x为第一次随机产生的数，y为第二次
 * P(x=1 y=0)=p*(1-p)
 * P(x=0 y=1)=(1-p)*p
 *可知两次不等时概率相等，即不等时返回第一次随机产生的数即可，相等时重复此过程
 * 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand((int)time(0));
	int x,y;
	while(1)
	{
		x=rand()%2;
		y=rand()%2;
		if(x!=y)
		{
			cout<<x<<endl;
			break;
		}
	}
}