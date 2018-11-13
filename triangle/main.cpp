#include <iostream>
#include <cstdio>
#include<vector>
using namespace std;
int main() {
    vector<int> a,b,c;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int aa,bb,cc;
        scanf("%d",&aa);
        a.push_back(aa);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int aa,bb,cc;
        scanf("%d",&bb);
        b.push_back(bb);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int aa,bb,cc;
        scanf("%d",&cc);
        c.push_back(cc);
    }
    vector<bool> res;
    for(int i=0;i<n;i++)
    {
        if(a[i]+b[i]<=c[i]||a[i]+c[i]<=b[i]||b[i]+c[i]<=a[i])
            res.push_back(false);
        else res.push_back(true);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d", res[i]?1:0);
    }
}