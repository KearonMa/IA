#include <bits/stdc++.h>
using namespace std;
int l[10];
int sum = 0;
void myMerge(int a[], int low, int high)
{
    cout << low << ' ' << high << ':' << endl;
    for(int i = low; i <= high; i++)
        l[i] = a[i];
    int i = low;
    int j = (low + high) / 2 + 1;
    int mid = (low + high) / 2;
    int k = low;
    while(i <= mid && j <= high)
    {
        if(l[i] <= l[j])
        {
            a[k] = l[i];
            k++;
            i++;
        }
        else
        {
            a[k] = l[j];
            sum = sum + (j - k);
            k++;
            j++;
        }
    }
    if(i > mid)
        for(; j <= high; j++)
            a[k++] = l[j];
    else
        for(; i <= mid; i++)
            a[k++] = l[i];
}
void fun(int a[], int low, int high)
{
    if(low >= high) return;
    int mid = (low + high) / 2;
    fun(a, low, mid);
    fun(a, mid + 1, high);
    myMerge(a, low, high);
}
int main()
{
    //int a[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int a[] = {2, 3, 8, 6, 7};
    sum = 0;
    fun(a, 0, 4);
    for(int i = 0; i <= 4; i++)
        cout << a[i] << ' ';
    cout << endl << sum << endl;
}
