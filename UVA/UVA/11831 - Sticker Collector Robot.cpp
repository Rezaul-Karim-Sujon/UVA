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
///4direction ->        int del_x[]={-1,1,0,0},del_y[]={0,0,1,-1};
///8direction ->        int del_x[]={-1,0,1,0,1,-1,-1,1},del_y[]={0,1,0,-1,-1,-1,1,1};


#include <bits/stdc++.h>
using namespace std;

ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+MOD)%MOD;if(p%2)return (bigmod(n,p-1)*n+MOD)%MOD;else{ll x=bigmod(n,p/2);return (x*x+MOD)%MOD;}}
ll modinverse(ll n){return bigmod(n,MOD-2)%MOD;}
bool check_2s_power(ll a) {return (pcll(a)==1?true:false);}
int del_x[]={0,1,0,-1},del_y[]={-1,0,1,0};
int n,m;

bool check(int a,int b)
{
    if(a>0 && a<=n && b>0 && b<=m)
    {
        return true;
    }
    return false;
}

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

int main()
{
   for(;;)
   {
       map<char,int>mmap;
   mmap['N']=3,mmap['S']=1,mmap['L']=2,mmap['O']=0;
   int siz,i,j,prev,prev_x,prev_y,total=0,x,y;
   cin >> n >> m >> siz;
   if(n==m && m==siz && siz==0)
   {
       return 0;
   }
   char arr[n+100][m+100];
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           cin >> arr[i][j];
           if(arr[i][j]=='N')
           {
               prev=mmap[arr[i][j]];
               prev_x=i;
               prev_y=j;
           }
           else if(arr[i][j]=='S')
           {
               prev=mmap[arr[i][j]];
               prev_x=i;
               prev_y=j;
           }
           else if(arr[i][j]=='L')
           {
               prev=mmap[arr[i][j]];
               prev_x=i;
               prev_y=j;
           }
           else if(arr[i][j]=='O')
           {
               prev=mmap[arr[i][j]];
               prev_x=i;
               prev_y=j;
           }
       }
   }
   //cout << prev << endl;
   string s;
   cin >> s;
   for(i=0;i<s.size();i++)
   {
       if(s[i]=='F')
       {
           x=del_x[prev]+prev_x;
           y=del_y[prev]+prev_y;
           //cout << x << y << endl;
           if(check(x,y)==true && arr[x][y]!='#')
           {
               prev_x=x;
               prev_y=y;
           }
       }
       else
       {
           if(s[i]=='D')
           {
               prev--;
               prev+=4;
           }
           else
           {
               prev++;
           }
           prev%=4;
           //cout << prev << endl;
       }
       //cout << prev_x << " " << prev_y << endl;
       if(arr[prev_x][prev_y]=='*')
       {
           total++;
           arr[prev_x][prev_y]='.';
       }
   }
   cout << total <<endl;
   }
}
