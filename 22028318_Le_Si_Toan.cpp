#include<bits/stdc++.h>
using namespace std;
void bubble(int n, int a[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i]) swap(a[i], a[j]);
        }
    }
}
void in(int n, int a[])
{
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
void in1(int n, int *a)
{
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
void insertion(int n, int a[])
{
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<j; i++)
        {
            if(a[j]<a[i])
            {
                int temp=a[j];
                for(int t=j; t>=i; t--) a[t]=a[t-1];
                a[i]=temp;
            }
        }
    }
}
int mini(int n, int a[], int t)
{
    int m=10e6, index=0;
    for(int i=t; i<n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
            index = i;
        }
    }
    return index;
}
void selection(int n, int a[])
{
    int m=10e6, t=0, index=0;
    for(int i=t; i<n; i++)
    {
        swap(a[t],a[mini(n, a, t)]);
        t++;
    }
}
void mix(int a[], int left, int mid, int right)
{
    int n1=mid-left+1;
    int n2=right-mid+1;
    int b[n1], c[n2];
    for(int i=0; i<n1; i++) b[i]=a[left+i];
    for(int i=0; i<n2; i++) c[i]=a[mid+1+i];
    int i=0, j=0, k=left;
    while(i<n1 && j<n2)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i++;
            k++;
        }
        else
        {
            a[k]=c[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=c[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int left, int right)
{
    if(right>left)
    {
        int mid=left+(right-left)/2;
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        mix(a, left, mid, right);
    }
}
int partition(int a[], int left, int right)
{
    int p = a[right];
    int i = left ;

    for (int j = left; j < right; j++)
    {
        if (a[j] <= p)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i ;
}
void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = partition(a, left, right);
        quicksort(a, left, mid - 1);
        quicksort(a, mid + 1, right);
    }
}
int main()
{
    int n, a[100];
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    quicksort(a,0,n-1);
    in(n,a);
    return 0;
}
