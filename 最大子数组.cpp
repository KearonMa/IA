#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef struct info
{
    int l, r, maxsum;
} info;
info findMaxMid(int a[], int low, int high)
{
    int flag, sum, maxsum;
    int mid = (low + high) / 2;
    sum = 0;
    maxsum = -inf;
    info aa;
    aa.maxsum = 0;
    for(int i = mid; i >= low; i--)
    {
        sum += a[i];
        if(sum > maxsum)
        {
            flag = i;
            maxsum = sum;
        }
    }
    aa.maxsum += maxsum;
    aa.l = flag;
    sum = 0;
    maxsum = -inf;
    for(int i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if(sum > maxsum)
        {
            flag = i;
            maxsum = sum;
        }
    }
    aa.maxsum += maxsum;
    aa.r = flag;
    return aa;
}
info findMax(int a[], int low, int high)
{
    if(low == high)
    {
        info aa;
        aa.l = low;
        aa.r = high;
        aa.maxsum=a[low];
        return aa;
    }
    int mid = (low + high) / 2;
    info ll=findMax(a,low,mid);
    info rr=findMax(a,mid+1,high);
    info lr=findMaxMid(a,low,high);
    if(ll.maxsum>=rr.maxsum&&ll.maxsum>=lr.maxsum)
    	return ll;
    else if(rr.maxsum>=lr.maxsum)
    	return rr;
    else 
    	return lr;
}
int main()
{
    int a[17] = {0, 13, -3, -25, 20, -3, 16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    //int a[20]={0};
    info ans=findMax(a,1,16);
    cout<<"l="<<ans.l<<endl;
    cout<<"r="<<ans.r<<endl;
    cout<<"sum="<<ans.maxsum<<endl;

    /**
     * dp版本 O(n)
     */
    
    int dp[100];
    memset(dp,0,sizeof(dp));
    int maxn=-inf;
    int l=0;
    int r=0;
    for(int i=1;i<17;i++)
    {
    	dp[i]=max(0,dp[i-1]+a[i]);
    	if(dp[i]==0) 
    	{
    		l=i+1;
    		r=i+1;
    	}
    	if(maxn<dp[i])
    	{
    		maxn=dp[i];
    		r=i;
    	}
    }
    cout<<l<<' '<<r<<' '<<maxn<<endl;
}