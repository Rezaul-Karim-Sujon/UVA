#include <bits/stdc++.h>
using namespace std;
int main()
{
    double h,m;
    for(;;)
    {
    scanf("%lf:%lf",&h,&m);
    if(h==0 && m==0)
    {
        return 0;
    }
    double hour_minute=(h*60)+m;
    double hour_angle=hour_minute*(0.5);
    double minute_angle=m*6;
    double first=abs(hour_angle-minute_angle);
    double second=360.00-max(hour_angle,minute_angle)+min(minute_angle,hour_angle);
    //cout << hour_angle<< " " << minute_angle << endl;
    double ans;
    //cout << first << " " << second << endl;
    ans=min(first,second);
    printf("%0.3lf\n",ans);
    }
}
