#define nl              "\n"
#define ll              long long int
#define ull             unsigned long long
#define pb              push_back
#define SIZE(a)           (int)a.size()
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define ff              first
#define ss              second
#define sq(a)           ((a)*(a))
#define For(i,a,b)      for(int i=a;i<=b;i++)
#define Rof(i,a,b)      for(int i=a;i>=b;i--)
#define Rep(i,b)        for(int i=0;i<b;i++)
#define MOD             1000000007
#define PI              acos(-1.0)
#define eps             1e-9
#define Linf            2e18
#define inf             1<<30
#define MX5             100005
#define MX6             1000006
#define GCD(a,b)	__gcd(a,b)
#define Abs(a)		abs(a)
#define input(a,b)	scanf("%lld%lld",&a,&b)
#define in1(a)		scanf("%lld",&a)
#define output(a)	printf("%lld",a);
#define mem(a)          memset(a,-1,sizeof(a))
#define clr(a)          memset(a,0,sizeof a)
#define mk              make_pair
#define pLL             pair<ll,ll>
#define ff              first
#define ss              second
#define invcos(a)	(acos(a)*(180/3.14159265))




#include <bits/stdc++.h>
using namespace std;

ll arr[MX6],size[MX6];

void initialized(int a)
{
    for(int i=1;i<=a;i++)
    {
        arr[i]=i;
        size[i]=1;
    }
}
ll root(ll x)
{
    while(arr[x]!=x)
    {
        arr[x]=arr[arr[x]];
        x=arr[x];
    }
    return x;
}

void wei_union(ll a,ll b)
{
    ll rootA=root(a);
    ll rootB=root(b);
    if(size[rootA]<size[rootB])
    {
        arr[rootA]=arr[rootB];
        size[rootB]+=size[rootA];
    }
    else
    {
        arr[rootB]=arr[rootA];
        size[rootA]+=size[rootB];
    }

}
bool find(ll a,ll b)
{
    if(root(a)==root(b))
    {
        return true;
    }
    else
        return false;
}
int main()
{
    ll t,test,a,b;
    in1(test);
    char s[1000];
    char c;
    for(t=1;t<=test;t++)
    {
        ll success=0,unsuccess=0;
        ll n;
    cin >> n;
    getchar();
    initialized(n);
    while(true)
    {
        gets(s);
        if(strcmp(s, "")==0 || feof(stdin)) break;
        sscanf(s ,"%c %lld %lld",&c,&a,&b);
        if(c=='c')
        {
            wei_union(a,b);
        }
        else
        {
            bool x=find(a,b);
            //cout << arr[a] << arr[b] << endl;
            if(x==true)
            {
                success++;
            }
            else
            {
                unsuccess++;
            }

        }
    }
    cout << success << "," << unsuccess << endl;
    if(t!=test)
    {
        cout << endl;
    }
    else
    {
        return 0;
    }
    }
    return 0;
}
