#include <bits/stdc++.h>
using namespace std;

int arr[100009];
int size[100009];

int root(int i)
{
    while (arr[i]!=i) {
      arr[i]=arr[arr[i]];
      i=arr[i];
    }
    return i;
}
void weighted_union(int a, int b)
{
  int root_A=root(a);
  int root_B=root(b);
  if(root_A==root_B)
    return ;
  if(size[root_A] < size[root_B ])
        {
    arr[ root_A ] = arr[root_B];
    size[root_B] += size[root_A];
    }
        else
        {
    arr[ root_B ] = arr[root_A];
    size[root_A] += size[root_B];
    }
}


int main()
{
    int test;
    cin >> test;
    while(test--)
    {


memset(arr,0,sizeof(arr));
memset(size,0,sizeof(size));
    int n,i,counter=0;
    cin >> n;
    map<string,int>mmap;
    string s,t;
    int x,y;
    for(i=0;i<n;i++)
    {
        cin >> s >> t;
        if(mmap[s]==0)
        {
            counter++;
            mmap[s]=counter;
            arr[counter]=counter;
            size[counter]=1;
            //cout << s << " " << counter << endl;
        }
        x=mmap[s];
        if(mmap[t]==0)
        {
            counter++;
            mmap[t]=counter;
            arr[counter]=counter;
            size[counter]=1;
            //cout << t << " " << counter << endl;
        }
        y=mmap[t];
        weighted_union(x,y);
        int ans=root(x);
        cout << size[ans] << endl;

    }
    }
}
