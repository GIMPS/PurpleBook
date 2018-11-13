#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    char c;
    cin >> c;
    if(c == 'D')
    {
        scanf("%c", &c);
        char t;
        while(scanf("%c", &c)==1)
        {
            if(c==' ') continue;
            if('0'<=c && c<='9')
            {
                for(int i=0;i<c-'0'-1;i++)
                    cout<<t;
            }
            else
            {
                cout << c;
                t =c;
            }
        }
    }
    else{
        scanf("%c", &c);
        char t;
        int cnt = 0;
        int init=0;
        while(scanf("%c", &c)==1)
        {
            if(c==' ') continue;
            init++;
            if(t==c && init!=1 )
            {
                cnt++;
            }
            else
            {
                if(init!=1)
                {
                    cout << cnt+1;
                    cnt =0;
                }

                cout << c;
                t=c;
            }
        }
        if(cnt!=0)
        {
            cout << cnt+1;
        }
    }
}