#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int e,a,n,i;
  cin >> e;
  vector<int>v[2599];
  for(i=0;i<e;i++)
  {
    cin >> n;
    for(int j=0;j<n;j++)
    {
      cin >> a;
      v[i].push_back(a);
    }
  }
  int t,source,test;
cin >> t;
for (size_t test = 0; test < t; test++) {
  cin >> source;
  int visit[e+5]={0},level[e+5]={0};
  visit[source]=1;
  level[source]=0;
  queue<int>Q;
  map<int,int>mmap;
  Q.push(source);
  while(!Q.empty())
  {
    n=Q.front();
    Q.pop();
    for (size_t u = 0; u <v[n].size(); u++) {
      if(visit[v[n][u]]==0)
      {
        Q.push(v[n][u]);
        level[v[n][u]]=level[n]+1;
        visit[v[n][u]]=1;
        int fo=level[v[n][u]];
        mmap[fo]++;
      }
    }
  }
map<int,int>:: iterator it;
int m=0,d;
for(it=mmap.begin();it!=mmap.end();it++)
{
  if(m<(it->second))
{
  d=it->first;
  m=it->second;
}
}
if(m==0)
{
  cout << m << endl;
}
else
{
  cout << m << " " << d << endl;
}
}
  return 0;
}
