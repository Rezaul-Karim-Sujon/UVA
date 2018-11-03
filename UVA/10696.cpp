#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    for(;;)
    {
        cin >> n;
        if(n==0)
        {
            return 0;
        }
        else
        {
            cout << "f91(" << n << ") = ";
            cout << ((n<=100)?(n-n+91):n-10) << endl;
        }
    }
}
