#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,ans=1,x;
    vector<long long int>v;
    for(i=0;i<40;i++)
    {
        x=ans<<i;
        v.push_back(x);
    }
    for(;;)
    {
        long long int a,counter=0;
    cin >> a;
    if(a==0)
    {
        return 0;
    }
    for(i=0;i<v.size();i++)
    {
        if(v[i]>=a)
        {
            counter=v[i];
            break;
        }
    }
    ans=counter-(2*(counter-a));
    cout << ans << endl;
    }
}
