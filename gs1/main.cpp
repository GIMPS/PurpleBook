#include <iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main() {
    string a = "Baa,Baa!,said the sheep";
    vector<char> b;
    bool isCap=0;
    for(int i=0;i<a.length();i++)
        {
            if(('A'<= a[i] &&a[i]<='Z') || (a[i]>='a' && a[i]<='z'))
            {
                if(a[i] == 'a' || a[i] == 'A')
                {
                    isCap = 1^isCap;
                    continue;

                }
                if(isCap)
                {
                    if(a[i]<'a')
                        b.push_back(a[i]+32);
                    else b.push_back(a[i]-32);
                }
                else
                    b.push_back(a[i]);
            }
            else b.push_back(a[i]);
        }
        for(int i=0;i<b.size();i++)
            printf("%c",b[i]);
    return 0;
}