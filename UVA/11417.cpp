#include <bits/stdc++.h>
using namespace std;
int main()
{
    for(;;)
    {
        int n,i,j;
    cin >> n;
    if(n==0)
    {
        return 0;
    }
    int sum=0;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            sum+=__gcd(i,j);
        }
    }
    cout << sum << endl;
    }
}
