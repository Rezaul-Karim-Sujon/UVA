#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n,q;
    while(cin >> n >> q && !cin.eof())
    {
        printf("%.0lf\n",pow(q,(1.0/n)));
    }
}
