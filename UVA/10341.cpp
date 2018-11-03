#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int p,q,r,s,t,u;
  double x;
  cin >> p >> q >> r >> s;
  double first=0,last=1,mid;
  bool xo=false;
  while(last-first>.000001)
  {
    double mid=(first+last)/2.00;
    double ans=p*exp((-1)*mid)+(q*sin(mid))+(r*cos(mid))+(t*mid*mid)+u+(s*tan(mid));
    cout << ans << endl;
    if(ans==0.0000000000000000)
    {
      xo=true;
      x=mid;
      break;
    }
    else if(ans>0.00)
    {
      last=mid;
    }
    else
    {
      first=mid;
    }
  }
  if(xo==true)
  {
    printf("%.3lf\n",x);
  }
  else
  {
    printf("No solution\n");
  }
  return 0;
}
