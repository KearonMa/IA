#include <bits/stdc++.h>
using namespace std;
const int maxn=10;
const int inf=0x3f3f3f3f;
int l[maxn/2+1],r[maxn/2+1];
void myMerge(int a[],int low,int high)
{
    cout<<low<<' '<<high<<':'<<endl;
    int mid=(low+high)/2;
    int i,j;
    for(i=low,j=0;i<=mid;i++)
        l[j++]=a[i];
    for(i=mid+1,j=0;i<=high;i++)
        r[j++]=a[i];
    i=j=0;
    int k=low;
    while(i<=mid-low&&j<=high-(mid+1))
        if(l[i]<=r[j])
            a[k++]=l[i++];
        else
            a[k++]=r[j++];
    if(i>mid-low)
        for(;j<=high-(mid+1);j++)
            a[k++]=r[j];
    else
        for(;i<=mid;i++)
            a[k++]=l[i];
}
void mergeSort(int a[],int low,int high)
{
    if(low>=high) return ;
    int mid=(low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    myMerge(a,low,high);
}
int main()
{
    int a[maxn]={12,4,5,7,1,2,3,6};
    mergeSort(a,0,7);
    for(int i=0;i<=7;i++)
        cout<<a[i]<<' ';
    return 0;
}
