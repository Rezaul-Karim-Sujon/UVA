#include <bits/stdc++.h>
using namespace std;

vector<int>v[1000010];
int mmap[1000010];
int main()
{
    int n,m;
    int i,k,q,a;
    while(cin >> n >> m && !cin.eof())
    {
        for(i=0;i<=1000000;i++)
        {
            v[i].clear();
        }
    memset(mmap,0,sizeof (mmap));
    for(i=0;i<n;i++)
    {
        cin >> a;
        mmap[a]++;
        v[a].push_back(i+1);
    }
    while(m--)
    {
        cin >> k >> q;
        if(mmap[q]==0 || mmap[q]<k)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << v[q][k-1] << endl;;
        }
    }
    }
}
