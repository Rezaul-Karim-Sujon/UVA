#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node;
    long long int test=0;
    for(;;)
    {
           cin >> node;
    if(node==0)
    {
        return 0;
    }
    long long int a,b,i,j,counter=0,x,y;
    map<long long int,int>mmap;
    vector<int>v[1000];
    set<int>mset;
    for(i=0;i<node;i++)
    {
        cin >> a >> b;
        mset.insert(a);
        if(counter!=mset.size())
        {
            counter=mset.size();
            mmap[a]=counter-1;
        }
        mset.insert(b);
        if(counter!=mset.size())
        {
            counter=mset.size();
            mmap[b]=counter-1;
        }
        x=mmap[a];
        y=mmap[b];
        v[x].push_back(y);
        v[y].push_back(x);
    }

    long long int s;
    int source,cost;
for(;;)
{
        cin >> s >> cost;
        if(s==0 && cost==0)
        {
            break;
        }
        else
        {
            int visited[1000]={0},level[1000]={0};
        int u,n,ans=0;
    source=mmap[s];
    visited[source]=1;
    level[source]=0;
    queue<int>Q;
    Q.push(source);
    while(!Q.empty())
    {
        n=Q.front();
        Q.pop();
        for(u=0;u<v[n].size();u++)
        {
            if(visited[v[n][u]]==0)
            {
                level[v[n][u]]=level[n]+1;
                if(level[v[n][u]]<=cost)
                {
                    ans++;
                }
                Q.push(v[n][u]);
                visited[v[n][u]]=1;
            }
        }
    }
    test++;
    ans=mset.size()-ans-1;
    printf("Case %lld: %d nodes not reachable from node %lld with TTL = %d.\n",test,ans,s,cost);
        }
}
    }
}
