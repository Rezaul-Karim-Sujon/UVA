#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        string s;
    vector<string>st;
    vector<int>v[1000];
    int counter=-1,i,j,couter=0;
    map<string,int>mmap;
    map<int,string>m2;
    for(;;)
    {
        cin >> s;
        counter++;
        if(s=="*")
        {
            break;
        }
        else
        {
            st.push_back(s);
            mmap[s]=counter;
            m2[counter]=s;
        }
    }
    sort(st.begin(),st.end());
    for(i=0;i<st.size();i++)
    {
        for(j=i+1;j<st.size();j++)
        {
            string a,b;
            a=st[i];
            b=st[j];
            couter=0;
            if(a.size()==b.size() && a!=b)
            {
                couter=0;
                for(int k=0;k<a.size();k++)
                {
                    if(a[k]!=b[k])
                    {
                        couter++;
                    }
                }
                if(couter==1)
                {
                    int x,y;
                    x=mmap[a];
                    y=mmap[b];
                    v[x].push_back(y);
                    v[y].push_back(x);
                }
            }
        }
    }
    cin.ignore();
    string line;
    while(getline(cin,line) && line!="")
    {
        stringstream ss(line);
        string sta,ds;
        ss >> sta >> ds;
        int visited[1000]={0},n,u,source,destination,level[1000]={0};
    counter=0;
    source=mmap[sta];
    destination=mmap[ds];
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
                    counter++;
                    Q.push(v[n][u]);
                    visited[v[n][u]]=1;
                }
            }
    }
    //cout << level[destination] << " " << level[source] << " ";
    cout << sta << " " << ds << " ";
    cout << level[destination]-level[source] << endl;
    }
    if(test)
    {
        cout << endl;
    }
    }
}
