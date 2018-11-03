#include <bits/stdc++.h>
using namespace std;

void initialized(int arr[],int siz[],int x)
{
    for(int i=1;i<=x;i++)
    {
        arr[i]=i;
        siz[i]=1;
    }
}

int root(int i,int arr[])
{
    while(arr[i]!=i)
    {
        arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}

void wei_union(int arr[],int siz[],int a,int b)
{
    int rootA=root(a,arr);
    int rootB=root(b,arr);
    if(rootA==rootB)
    {
        return;
    }
    int maxi=max(rootA,rootB);
    int mini=min(rootA,rootB);
    arr[mini]=arr[maxi];
    siz[maxi]+=siz[mini];
}

int main()
{
    int c,r,i;

    for(;;)
    {
        cin >> c >> r;
        if(c==r && r==0)
        {
            return 0;
        }
        int arr[c+6],siz[c+6];
    string s;
    map<string,int>mmap;
    initialized(arr,siz,c);
    for(i=1;i<=c;i++)
    {
        cin >> s;
        mmap[s]+=i;
    }
    string p;
    for(i=1;i<=r;i++)
    {
        cin >> s >> p;
        int a=mmap[s];
        int b=mmap[p];
        wei_union(arr,siz,a,b);
    }
    int maxi=0;
    for(i=1;i<=c;i++)
    {
        int a=arr[i];
        maxi=max(siz[a],maxi);
    }
    cout << maxi << endl;
    }
}
