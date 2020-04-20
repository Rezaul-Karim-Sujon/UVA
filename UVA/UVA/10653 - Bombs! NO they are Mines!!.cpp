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
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
///8direction ->        int del_x[]={-1,0,1,0,1,-1,-1,1},del_y[]={0,1,0,-1,-1,-1,1,1};


#include <bits/stdc++.h>
using namespace std;

ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+MOD)%MOD;if(p%2)return (bigmod(n,p-1)*n+MOD)%MOD;else{ll x=bigmod(n,p/2);return (x*x+MOD)%MOD;}}
ll modinverse(ll n){return bigmod(n,MOD-2)%MOD;}
bool check_2s_power(ll a) {return (pcll(a)==1?true:false);}


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

ll del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};

bool check(ll x ,ll y, ll r, ll c)
{
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}

int main()
{
  ll r,c,n,row,column,source_x,source_y,des_x,des_y,i,j,a;
  for(;;)
  {
      queue<pLL>Q;
  input(r,c);
  if(r==c && r==0)
  {
      return 0;
  }
  ll visited[r+100][c+100],level[r+100][c+100];
  clr(visited);
  clr(level);
  in1(n);
  Rep(i,n)
  {
      input(row,a);
      Rep(j,a)
      {
          in1(column);
          visited[row][column]=1;
      }
  }
  input(source_x,source_y);
  input(des_x,des_y);
  Q.push(mk(source_x,source_y));
  visited[source_x][source_y]=1;
  while(!Q.empty())
  {
      row=Q.front().ff;
      column=Q.front().ss;
      Q.pop();
      if(row==des_x && column==des_y)
      {
          break;
      }
      Rep(i,4)
      {
        ll x=del_x[i]+row;
        ll y=del_y[i]+column;
        if(check(x,y,r,c) && visited[x][y]==0)
        {
            visited[x][y]=1;
            Q.push(mk(x,y));
            level[x][y]=level[row][column]+1;
        }
      }
  }
  ll ans=level[des_x][des_y]-level[source_x][source_y];
  output(ans);
  }

  /*Rep(i,r)
  {
      //cout << i << "->";
      Rep(j,c)
      {
          cout << visited[i][j] << " ";
      }
      cout << endl;
  }*/
}
