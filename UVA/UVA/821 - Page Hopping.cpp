#define nl              "\n"
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define SIZE(a)         (int)a.size()
#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.rbegin(),v.rend())
#define REV(v)          reverse(v.begin(),v.end())
#define ff              first
#define ss              second
#define sq(a)           ((a)*(a))
#define For(i,a,b)      for(i=a;i<=b;i++)
#define Rof(i,a,b)      for(i=a;i>=b;i--)
#define Rep(i,b)        for(i=0;i<b;i++)
#define MOD             1000000007
#define PI              acos(-1.0)
#define eps             1e-9
#define Linf            2e18
#define inf             1<<30
#define MX5             100005
#define MX6             1000006
#define MX3             1005
#define GCD(a,b)      __gcd(a,b)
#define Abs(a)        abs(a)
#define input(a,b)      scanf("%lld%lld",&a,&b)
#define in1(a)        scanf("%lld",&a)
#define output(a)     printf("%lld\n",a);
#define mem(a)          memset(a,-1,sizeof(a)) // complexity O(n)
#define clr(a)          memset(a,0,sizeof (a))
#define mk              make_pair
#define pLL             pair<ll,ll>
#define ff              first
#define ss              second
#define invcos(a)     (acos(a)*(180/3.14159265))
#define rtan(a)          (tan(a*3.14159265/180.0))
#define pip           printf("pip")
#define timelimit       1.0*clock()/CLOCKS_PER_SEC
#define pc_one              __builtin_popcount
#define pcl_one             __builtin_popcountl
#define pcll_one            __builtin_popcountll
#define parity              __builtin_parity
#define parityl             __builtin_parityl
#define parityll            __builtin_parityll
#define infile          freopen("input.txt","r",stdin)
#define outfile         freopen("output.txt","w",stdout)
#define debug(x)        cerr << #x << " is " << x << endl
//const ll Linf=2e18;
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
///8direction ->        int del_x[]={-1,0,1,0,1,-1,-1,1},del_y[]={0,1,0,-1,-1,-1,1,1};


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

ll bigmod(ll n, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return (n + MOD) % MOD;
    if (p % 2)
        return (bigmod(n, p - 1) * n + MOD) % MOD;
    else
    {
        ll x = bigmod(n, p / 2);
        return (x * x + MOD) % MOD;
    }
}
ll modinverse(ll n)
{
    return bigmod(n, MOD - 2) % MOD;
}
bool check_2s_power(ll a)
{
    return (pcll_one(a) == 1 ? true : false);
}


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

vector<ll>v[200];
ll visited[200],sum=0,counter=0,level[200],couter=0,p_couter=-1;
double ans;
set<ll>mset;
int main()
{
    ll a,b,zero=0;
    for(;;)
    {
        for(;;)
        {
            input(a,b);
            if(a==b && b==0)
            {
                zero++;
                if(zero==2)
                {
                    return 0;
                }
                else
                {
                    couter++;
                    break;
                }
            }
            else
            {
                zero=0;
                v[a].pb(b);
                mset.insert(a);
                mset.insert(b);
            }
        }
        if(zero==1 && a==0 && b==0)
        {
            ll siz=mset.size(),i=1;
        for(auto i:mset)
        {
            clr(visited);
            clr(level);
            queue<ll>Q;
            Q.push(i);
            visited[i]=1;
            level[i]=1;
            while(!Q.empty())
            {
                ll u=Q.front();
                Q.pop();
                for(auto x:v[u])
                {
                    if(visited[x]==0)
                    {
                        visited[x]=1;
                        counter++;
                        Q.push(x);
                        level[x]=level[u]+1;
                        sum+=level[u];
                        //cout << sum << endl;
                    }
                }
            }
        }
        double sum1=sum,counter1=counter;
        ans=(double)(sum1/counter1);
        //cout << sum << " " << counter << endl;
        //cout << ans << endl;
        printf("Case %lld: average length between pages = %.3lf clicks\n",couter,ans);
        sum=0;
        counter=0;
        for(auto i:mset)
        {
            v[i].clear();
        }
        }
    }
}
