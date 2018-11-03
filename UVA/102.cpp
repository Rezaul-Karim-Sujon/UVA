#define ll long long int

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ll b1,g1,c1,b2,g2,c2,b3,g3,c3,i;
  while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3 && !cin.eof())
  {
    ll bgc,bcg,cbg,cgb,gcb,gbc;
    bgc=b2+b3+g1+g3+c1+c2;
    bcg=b2+b3+c1+c3+g1+g2;
    cbg=c2+c3+b1+b3+g1+g2;
    cgb=c2+c3+g1+g3+b1+b2;
    gcb=g2+g3+c1+c3+b1+b2;
    gbc=g2+g3+b1+b3+c1+c2;
    std::vector<string>s;
    std::vector<ll> v;
    v.push_back(bgc);
    v.push_back(bcg);
    v.push_back(cbg);
    v.push_back(cgb);
    v.push_back(gcb);
    v.push_back(gbc);
    s.push_back("BGC");
    s.push_back("BCG");
    s.push_back("CBG");
    s.push_back("CGB");
    s.push_back("GCB");
    s.push_back("GBC");
    for (size_t i = 0; i < v.size(); i++) {
      for (ll j = i+1; j < v.size(); j++) {
        if(v[i]>v[j])
        {
          swap(v[i],v[j]);
          swap(s[i],s[j]);
        }
        else if(v[i]==v[j])
        {
          if(s[i]>s[j])
          {
            swap(v[i],v[j]);
            swap(s[i],s[j]);
          }
        }
      }
    }
    for(i=0;i<1;i++)
    {
      cout << s[i] << " " << v[i] << endl;
    }
  }

  return 0;
}
