#include <iostream>
#include<set>
#include<cstdio>
#include<time.h>
using  namespace std;
multiset<int> S;
int main() {
    clock_t start = clock();
    for(int i=0;i<1e6;i++)
        S.insert(i);

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}