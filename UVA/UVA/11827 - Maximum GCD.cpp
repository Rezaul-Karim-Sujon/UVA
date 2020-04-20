#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
        string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int>v;
    int a,i,j,maxi=0;
    while(ss>>a)
    {
        v.push_back(a);
    }
   for(i=0;i<v.size();i++)
   {
       for(j=i+1;j<v.size();j++)
       {
           int gcd=__gcd(v[i],v[j]);
           maxi=max(maxi,gcd);
       }
   }
   cout << maxi << endl;
    }
}
