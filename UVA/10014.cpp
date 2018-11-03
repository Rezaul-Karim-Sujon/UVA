#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
    int n;
    scanf("%d",&n);
    double first,second,c;
    while(n--)
    {
        scanf("%lf%lf%lf",&first,&second,&c);
        double ans=((first+second)/2.00)-c;
        printf("%.02lf\n",ans);
    }
    }
}
