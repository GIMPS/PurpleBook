#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
const int maxn = 7000+10;
const int maxa = 200000+10;
ll a[maxn];
int p[maxa];
int n, T;

int main() {
    ll idx, num;
    cin >> T;
    int Kase = 0;
    while (T--){
        Kase++;
        memset(p, 0, sizeof(p));
        ll cntone = 0;
        ll cntz = 0;
        ll n1, n2;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (a[i] == 1)
                cntone++;
            if (a[i] == 0)
                cntz++;
            p[a[i]]++;
        }
        ll cnt = 0;
        if (cntone > 2) {
            cnt += cntone * (cntone-1) * (cntone-2) / 6;
        }
        if (cntz > 1) {
            cnt += (n-cntz) * cntz * (cntz-1) / 2;
        }
        if (cntz > 2) {
            cnt += cntz * (cntz-1) * (cntz-2) / 6;
        }
        sort(a, a + n);
        for (int i = n - 1; i >= 2; i--) {
            num = a[i];
            if (num == 1 || num == 0)
                break;
            int l = 0, r = i - 1;
            if (a[r] == num) {
                if (cntone) {
                    cnt += cntone * p[num] * (p[num]-1) / 2;
                }
                while (a[i-1] == num)
                    i--;
                r = i-1;
            }
            while(a[l] <= 1)
                l++;
            while (l < r) {
                idx= a[l] * a[r];
                if (idx> num) {
                    r-=1;
                } else if (idx< num) {
                    l+=1;
                } else {
                    if (a[l] == a[r]) {
                        cnt += p[a[l]] * (p[a[l]]-1) / 2;
                        break;
                    }
                    cnt += p[num] * p[a[l]] * p[a[r]];
                    n1 = a[l];
                    n2 = a[r];
                    while (a[l] == n1 && l < r)
                        l+=1;
                    while (a[r] == n2 && l < r)
                        r-=1;
                }
            }
        }
        cout << "Case #" << Kase << ": ";
        printf("%lld\n", cnt);
    }
}