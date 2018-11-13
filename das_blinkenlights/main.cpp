#include <iostream>
#include<cstring>
using namespace std;
#define LL long long int
LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

// abs(x) + abs(y) is smallest
void gcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if(!b) { d = a; x = 1; y = 0; }
    else { gcd(b, a % b, d, y, x); y -= x * (a / b); }
}
int main() {
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    if(a*b/gcd(a,b)<=c)
        printf("yes");
    else
        printf("no");
}