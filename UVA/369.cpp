#define ll long long int
#define output(n,m,ans) printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,ans);
#include <bits/stdc++.h>
using namespace std;

ll converts(string s)
{
    ll sie=s.size();
    ll ans=0,a,b=1;
    for(ll i=sie-1;i>=0;i--)
    {
        a=s[i]-48;
        a*=b;
        ans+=a;
        b*=10;
    }
    return ans;
}

int main()
{
    for(;;){
    string s,q,p;
    getline(cin,s);
    stringstream str(s);
    str>>p;
    str>> q;
        ll m,n;
        n=converts(p);
        m=converts(q);
    if(n==m && m==0)
    {
        return 0;
    }
    ll maxi=max(m,(n-m));
    ll mini=min(m,(n-m));
    ll ans=1,ans1=1,fe=mini;
    for(ll i=maxi+1;i<=n;i++)
    {
        if(fe>0)
        {
            ans1*=fe;
            fe--;
        }
        ll fo=i;
        ll gcd;
        gcd=__gcd(fo,ans1);
        ans1/=gcd;
        fo/=gcd;
        ans*=fo;
    }
    output(n,m,ans);
    }
}
