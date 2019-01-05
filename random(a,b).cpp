/**
 * 通过Random(0,1)生成Random(a,b)
 * 每一位都随机产生0或1，产生log2(b-a)位(向上取整)，这样就随机产生0~2^(log(b-a)(向上取整)),如果大于b-a的话就再来一遍
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand((int)time(0));
    int a, b, c;
    cin >> a >> b;
    c = log(b - a) / log(2);
    for(int k = 0; k < 10; k++)
    {
        int ran = 0;
        for(int i = 0; i < c + 1 ; i++)
            ran = ran * 2 + rand() % 2;
        if(a + ran > b) 
        	k--;
        else
            cout << a + ran << endl;
    }
}