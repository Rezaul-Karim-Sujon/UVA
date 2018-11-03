#define nl              "\n"
#define ll              long long
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
int main()
{
  int n;
  while(cin >> n && !cin.eof())
  {
    int i,a,money;
    map<int,int>mmap;
    for(i=0;i<n;i++)
    {
      cin >> a;
      mmap[a]++;
    }
    std::cin >> money;
    int maxi=0,mini=0,difference=10000000;
    std::map<int, int>::iterator it;
    for (it = mmap.begin(); it!=mmap.end(); it++) {
      int x=it->ff;
      int khuj=money-x;
      //cout << khuj << endl;
          if(khuj>=0)
          {
            if(khuj==x && mmap[x]>1)
            {
              maxi=x;
              mini=x;
              difference=maxi-mini;
            }
            else
            {
              if(mmap[khuj]>0 && mmap[x]>0)
              {
                if (difference>(abs(khuj-x))) {
                  maxi=max(khuj,x);
                  mini=min(khuj,x);
                  difference=abs(khuj-x);
                }
              }
            }
          }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n",mini,maxi);
  }

}
