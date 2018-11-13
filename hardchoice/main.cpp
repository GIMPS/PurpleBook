#include <iostream>
#include <cstdio>
int main() {
    int have[3];
    for(int i=0;i<3;i++)
        scanf("%d",&have[i]);
    int sum=0;
    for(int i=0;i<3;i++)
    {
        int c;
        scanf("%d",&c);
        if(c>have[i])
            sum+=(c-have[i]);
    }
    printf("%d",sum);
}