#define infile          freopen("input.txt","r",stdin)
#define outfile         freopen("output.txt","w",stdout)

#include <bits/stdc++.h>
using namespace std;

const int del_x[]={-1,0,1,0};
const int del_y[]={0,1,0,-1};

int count_value[30],arr[30][30],visited[30][30];
int m,n;

bool check(int x,int y)
{
    if(x>=0 && x<m && y>=0 && y<n)
    {
        return true;
    }
    return false;
}

void dfs(int x,int y,int value,int land)
{
    visited[x][y]=value;
    count_value[value]++;
    for(int i=0;i<4;i++)
    {
        int a=del_x[i]+x;
        int b=del_y[i]+y;
        if(b==n)b=0;
        if(b<0)b=n-1;
        if(check(a,b) && visited[a][b]==0 && arr[a][b]==land)
        {
            dfs(a,b,value,land);
            //cout << a  << " " << b << endl;
        }
    }
}

int main()
{
    //infile;
    //outfile;
    while(cin >> m >>n && !cin.eof()){
    int i,j,counter=0,king_x,king_y,maxi=0,land,couter=0;
    char c;
    map<char,int>mmap;
    memset(count_value,0,sizeof(count_value));
    memset(arr,0,sizeof(arr));
    memset(visited,0,sizeof(visited));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> c;
            if(mmap[c]==0)
            {
                couter++;
                mmap[c]=couter;
            }
            arr[i][j]=mmap[c];
        }
    }
    cin >> king_x >> king_y;
    counter++;
    land=arr[king_x][king_y];
    //cout << land << endl;
    dfs(king_x,king_y,counter,land);
    //cout << count_value[counter] << endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==land && visited[i][j]==0)
            {
                counter++;
                dfs(i,j,counter,land);
                //cout << counter << endl;
                maxi=max(maxi,count_value[counter]);
            }
            //cout << visited[i][j];
        }
        //cout << endl;
    }
   cout << maxi << endl;
    }
}
