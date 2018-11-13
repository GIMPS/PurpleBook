#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;
#define LL long long int
LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }
const int maxn= 112345;
LL a[maxn];
vector<pair<LL,int> > dp[maxn];
int main() {
    int T,n;
    cin >> T;
    while(T--)
    {
        cin >>n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        LL res = a[n-1];
        for(int i=0;i<maxn;i++)
            dp[i].clear();
        dp[n-1].push_back(make_pair(a[n-1],1));
        for(int i=n-2;i>=0;i--)
        {
            LL oldgcd = a[i];
            dp[i].push_back(make_pair(a[i],1));
            for(auto x: dp[i+1])
            {
                LL newgcd = gcd(x.first,a[i]);
                if(oldgcd != newgcd)
                {
                    dp[i].push_back(make_pair(newgcd,x.second+1));
                    oldgcd = newgcd;
                }
                else
                {
                    dp[i][dp[i].size()-1].second =max(x.second+1, dp[i][dp[i].size()-1].second);
                }
            }
//            cout << "no. " <<i <<endl;
//            for(auto x:dp[i])
//            {
//                cout << x.first << ' '<< x.second << endl;
//            }
        }
        for(int i=0;i<n;i++)
            for(auto x:dp[i])
                res = max(res, x.first * x.second);
        cout << res << endl;
    }
}