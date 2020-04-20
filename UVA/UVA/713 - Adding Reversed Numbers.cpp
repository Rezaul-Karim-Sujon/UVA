#define infile          freopen("input.txt","r",stdin)
#define outfile         freopen("output.txt","w",stdout)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    infile;
    outfile;
    int test;
    cin >> test;
    while(test--)
    {
        string s,p,a,b,ans;
    cin >> a >> b;
    p=a;
    s=b;
    int carry=0,i;
    if(a.size()>=b.size())
    {
        swap(s,p);
    }
    while(s.size()!=p.size())
    {
        p+="0";
    }
    for(i=0;i<s.size();i++)
    {
        int fo=(s[i]-'0')+(p[i]-'0')+carry;
        int fe=fo%10;
        char c=fe+'0';
        ans+=c;
        carry=fo/10;
        //cout << ans << endl;
    }
    //cout << ans << endl;
    while(carry!=0)
    {
        int fo=carry%10;
        char c=fo+'0';
        ans+=c;
        carry/=10;
    }
        bool check=false;
    for(i=0;i<ans.size();i++)
    {
        if(ans[i]!='0')
        {
            cout << ans[i];
            check=true;
        }
        else
        {
            if(check)cout << ans[i];
        }
    }
    cout << endl;
    }
}
