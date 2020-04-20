#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,test;
    cin >> test;
    for(t=1;t<=test;t++)
    {
        int n;
        cin >> n;
        string s;
    cin >> s;
    int counter=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
            counter++;
            s[i]='#';
            s[i+1]='#';
            s[i+2]='#';
        }
    }
    printf("Case %d: %d\n",t,counter);
    }
}
