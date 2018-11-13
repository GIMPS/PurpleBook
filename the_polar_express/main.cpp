#include <iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int maxn=221;
//const int maxm =1234;
int p[maxn],tmp[maxn];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    vector<int> ops;
    while(1)
    {
        int blockL=1;
        int blockBegin=n-1,blockEnd=n-1;
        bool isAsc=false;
        if(p[n-2]-p[n-1]==1)
        {
            for(int i=n-2;i>=0;i--)
            {
                if(p[i]-p[i+1]==1)
                {
                    blockEnd=i;
                    blockL++;
                }
                else
                    break;
            }
        }
        if(p[n-2]-p[n-1]==-1)
        {
            isAsc=true;
            for(int i=n-2;i>=0;i--)
            {
                if(p[i]-p[i+1]==-1)
                {
                    blockEnd=i;
                    blockL++;
                }
                else break;
            }
        }
        if(blockL==n && isAsc)
            break;
        if(blockL==n && !isAsc)
        {
            ops.push_back(n);
            break;
        }
        int target,targetLoc;
        if(isAsc)
            target = (p[blockBegin]+n+1)%n;
        else
            target = (p[blockBegin]+n-1)%n;
        if(target == 0)
            target =n;
//        8 1 4 5 6 2 7 8 3
        for(int i=0;i<n;i++)
            cout<<p[i]<<' ';
        cout<<endl;
        cout<<"-------------------------------------"<<endl;
        for(int i=blockEnd-1;i>=0;i--)
        {
            if(p[i]==target)
            {
                targetLoc = i;
                break;
            }
        }
        ops.push_back(targetLoc+1);
        for(int i=targetLoc+1;i<n;i++)
        {
            tmp[i-targetLoc-1] = p[i];
        }
        for(int i=targetLoc;i>=0;i--)
        {
            tmp[n-i-1] = p[i];
        }
        for(int i=0;i<n;i++)
            p[i]=tmp[i];
    }
    cout<<ops.size()<<endl;
    for(auto i:ops)
        cout<<i<<endl;
}