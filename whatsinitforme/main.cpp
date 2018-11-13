#include <iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<int, int> ii;
const int maxn = 1000+10;
int isfixed[maxn],fixval[maxn],upb[maxn],lob[maxn];
int n;
int sum;
int minsum(int start, int end)
{
    int mmin =0;
    int tmpsum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(i>=start && i<=end) continue;
        if(isfixed[i]==0)
        {
            tmpsum+=mmin;
        }
        else{
            mmin = fixval[i];
            tmpsum += mmin;
        }
    }
    return 100 - tmpsum;
}


int main() {
    vector<string> ing;
    cin>>n;
    sum =100;
    memset(isfixed,1,sizeof(isfixed));

    for(int i=0;i<n;i++)
    {
        string s = "";
        char c;
        while(scanf("%c",&c) && c!=' ')
        {
            if(c=='\n')continue;
            s+=c;
        }
        ing.push_back(s);
        int val=0;
        while(scanf("%c",&c) && isdigit(c))
        {
            val=(c-'0')+val*10;
            fixval[i]=val;
        }
        sum-=val;
        if(c=='?')
        {
            isfixed[i]=0;
        }
    }
    vector<pair<int,int>> blocks;
    bool inblock =false;
    int blockupb[n], blocklob[n];
    int blockstart=0;
    for(int i=0;i<n;i++)
    {
        if(inblock && isfixed[i])
        {
            blocks.push_back(ii(blockstart,i-1));
            inblock =false;
            continue;
        }
        if(!inblock && !isfixed[i])
        {
            inblock = true;
            blockstart = i;
        }
        if(inblock && i==n-1)
        {
            blocks.push_back(ii(blockstart,i));
            inblock =false;
        }
    }
//    printf("%d ad %d",blocks[2].first, blocks[2].second);



    for(int i=0;i<blocks.size();i++)
    {
        int mmax = 100;
        int start=blocks[i].first;
        int end = blocks[i].second;
        if(start!=0)
            mmax = fixval[start-1];
        blockupb[i] = min(minsum(start,end), (end-start+1)*mmax);
    }
    for(int i=0;i<blocks.size();i++)
    {
        int mmin =0;
        int start=blocks[i].first;
        int end = blocks[i].second;
        if(end!=n-1)
            mmin = fixval[end+1];
        int tmpsum =sum;
        for(int j=0;j<blocks.size();j++)
        {
            if(i==j) continue;
            else tmpsum-=blockupb[j];
        }
        blocklob[i] = max(tmpsum,(end-start+1)*mmin);
    }
//    cout<<blockupb[0]<<endl;
//    cout<< sum <<endl;
//    cout << blocklob[0]<<endl;
    for(int i=0;i<blocks.size();i++)
    {
        int start=blocks[i].first;
        int end = blocks[i].second;
        int l = end-start+1;
        int mmin = 0, mmax = 100;
        if(start!=0)
            mmax = fixval[start-1];
        if(end != n-1)
            mmin = fixval[end+1];
        for(int j=start;j<=end;j++)
        {
            int cur = j-start+1;
            upb[j] = min((blockupb[i]-(mmin*(l-cur)))/cur, mmax);
            int a = ceil(double(blocklob[i]-(mmax*(cur-1)))/double(l-cur+1));
            lob[j] = max(a, mmin);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ing[i]<<' ';
        if(isfixed[i]) cout<<fixval[i]<<' '<<fixval[i]<<endl;
        else{
            cout<<lob[i]<<' '<<upb[i]<<endl;
        }
    }
}