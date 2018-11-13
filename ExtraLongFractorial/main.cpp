//#include <bits/stdc++.h>

#include<iostream>
#include<vector>
using namespace std;

// Complete the extraLongFactorials function below.

vector<int> bigmMult(vector<int> &aa, vector<int> &bb)
{
    vector<int> res,a,b;
    for(int i=0;i<aa.size();i++) a.push_back(aa[i]);
    for(int i=0;i<bb.size();i++) b.push_back(bb[i]);
    a.push_back(0);
    b.push_back(0);
    for(int i=0;i<(a.size()+b.size());i++)
        res.push_back(0);
    int c=0,r=0;
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
        {
            r = (a[i]*b[j]+c+res[i+j])%10;
            c = (a[i]*b[j]+c+res[i+j])/10;
            res[i+j]=r;
        }
    res[a.size()+b.size()-1] = c;
    return res;
}
void extraLongFactorials(int n) {
    vector<int> res;
    res.push_back(1);
    for(int i=1;i<=n;i++)
    {
        vector<int> ivec;
        int temp=i;
        ivec.push_back(temp%10);
        while(temp/10>0)
        {
            temp/=10;
            ivec.push_back(temp%10);
        }
        res = bigmMult(res,ivec);
    }
    bool isBegin =false;
    for(int i=res.size()-1;i>=0;i--)
    {
        if(res[i]==0&&!isBegin) continue;
        if(res[i]!=0 && !isBegin) isBegin = true;
        if(isBegin) printf("%d",res[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
