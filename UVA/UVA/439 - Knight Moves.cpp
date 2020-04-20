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
#define GCD(a,b)	    __gcd(a,b)
#define Abs(a)		    abs(a)
#define input(a,b)	    scanf("%lld%lld",&a,&b)
#define in1(a)		    scanf("%lld",&a)
#define output(a)	    printf("%lld\n",a);
#define mem(a)          memset(a,-1,sizeof(a))
#define clr(a)          memset(a,0,sizeof (a))
#define mk              make_pair
#define pLL             pair<ll,ll>
#define ff              first
#define ss              second
#define invcos(a)	    (acos(a)*(180/3.14159265))
#define rtan(a)          (tan(a*3.14159265/180.0))
#define pip		        printf("pip")
#define timelimit       1.0*clock()/CLOCKS_PER_SEC
#define pc              __builtin_popcount
#define pcl             __builtin_popcountl
#define pcll            __builtin_popcountll
#define infile          freopen("input.txt","r",stdin)
#define outfile         freopen("output.txt","w",stdout)

//const ll Linf=2e18;
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
///8direction ->        int del_x[]={-1,0,1,0,1,-1,-1,1},del_y[]={0,1,0,-1,-1,-1,1,1};


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+MOD)%MOD;if(p%2)return (bigmod(n,p-1)*n+MOD)%MOD;else{ll x=bigmod(n,p/2);return (x*x+MOD)%MOD;}}
ll modinverse(ll n){return bigmod(n,MOD-2)%MOD;}
bool check_2s_power(ll a) {return (pcll(a)==1?true:false);}


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const ll fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const ll fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

ll level[10][10],visited[10][10];

bool check(ll x, ll y)
{
    if(x>0 && x<=8 && y>0 && y<=8)
    {
        return true;
    }
    return false;
}

int main()
{
    string s,p;
    while(cin >> s >> p && !cin.eof())
    {
        ll i,a,b,x,y;
        ll start_x=s[0]-'a'+1;
        ll start_y=s[1]-'0';
        ll final_x=p[0]-'a'+1;
        ll final_y=p[1]-'0';
        //cout << start_x << " " << start_y << endl;
        //cout << final_x << " " << final_y << endl;
        clr(level);
        clr(visited);
        queue<pLL>Q;
        Q.push(mk(start_x,start_y));
        level[start_x][start_y]=1;
        visited[start_x][start_y]=1;
        bool check1=false;
        while(!Q.empty())
        {
             a=Q.front().ff;
             b=Q.front().ss;
             //cout << a << " " << b << endl;
             Q.pop();
             if(a==final_x && b==final_y)
             {
                 break;
             }
            Rep(i,8)
            {
                x=fx[i]+a;
                y=fy[i]+b;
                //cout << x << y << endl;
                if(check(x,y) && visited[x][y]==0)
                {

                    Q.push(mk(x,y));
                    level[x][y]=level[a][b]+1;
                    visited[x][y]++;
                }
            }
        }
        cout << "To get from " << s << " to " << p << " takes " << (level[final_x][final_y]-level[start_x][start_y]) << " knight moves." << endl;
    }
}
