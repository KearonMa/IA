#include <bits/stdc++.h>
using namespace std;
const int maxn=10;
const int inf=0x3f3f3f3f;
int l[maxn/2+1],r[maxn/2+1];
void myMerge(int a[],int low,int high)
{
    cout<<low<<' '<<high<<':';
    int mid=(low+high)/2;
    int i,j;
    for(i=low,j=0;i<=mid;i++)
        l[j++]=a[i];
    l[j]=inf;
    for(i=mid+1,j=0;i<=high;i++)
        r[j++]=a[i];
    r[j]=inf;
    i=j=0;
    for(int k=low;k<=high;k++)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
    }
    for(int k=low;k<=high;k++)
        cout<<a[k]<<' ';
    cout<<endl;
}
void mergeSort(int a[],int low,int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    myMerge(a,low,high);
}
int main()
{
    int a[maxn]={2,4,5,7,1,2,3,6};
    mergeSort(a,0,7);
    for(int i=0;i<=7;i++)
        cout<<a[i]<<' ';
}
