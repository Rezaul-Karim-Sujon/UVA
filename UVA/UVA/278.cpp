#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
            char c;
    int a,b;
    cin >> c;
    cin >> a >> b;
    int maxi=max(a,b);
    int mini=min(a,b);
    if(c=='r')
    {
        int ans=min(a,b);
        cout << ans << endl;
    }
    else if(c=='k')
    {
        if(maxi==2 || mini==2)
        {
            if(maxi>=4)
            {
                a=maxi*mini;
                a/=2;
            }
            else
            {
                if(maxi==3)
                {
                    cout << "4" << endl;
                }
                else
                {
                    a=maxi*mini;
                    cout << a << endl;
                }
            }
        }
        else
        {
            int ans=a*b;
            if(ans%2==0)
            {
                cout << ans/2 << endl;
            }
            else
            {
                ans/=2;
                cout << ans+1 << endl;
            }
        }
    }
    else if(c=='K')
    {
     if(maxi%2==1)
     {
         maxi++;
     }
     if(mini%2==1)
     {
         mini++;
     }
     maxi/=2;
     mini/=2;
     cout << maxi*mini << endl;
    }
    else
    {
        if(a==b)
        {
            cout << a-1 << endl;
        }
        else
        {
            cout << mini << endl;
        }
    }
    }
}
