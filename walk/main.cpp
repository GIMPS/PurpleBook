#include <iostream>
#include<cstdio>
#include<stack>
using namespace std;
long long N,k;
stack<long long> seq;
const double matricex[] ={-0.5, -0.5, 0.5, 0.5}, matricey[] = {-0.5, 0.5, 0.5 ,-0.5};

// 2 3
// 1 4
long long find_pos(long long x, long long n)
{
//    prlong longf("%d",x);
    if(n<=2)
        return x;
    if(x<=(n*n/4))
    {
        seq.push(1);
        return find_pos((n*n/4-x)+1,n/2);
    }
    else if(x<=(n*n/2))
    {
        seq.push(2);
        return find_pos(x-n*n/4, n/2);
    }
    else if(x<=(n*n*3/4))
    {
        seq.push(3);
        return find_pos(x - n*n/2, n/2);
    }
    else{
        seq.push(4);
        return find_pos(n*n - x+1, n/2);
    }
}

void locate(double x, double y, long long n)
{
//    prlong longf("%lf %lf\n", x,y);
    double newx, newy;
    double rxold = n/4, ryold = n/4;
    double cxold = (double)(n/2+1)/2, cyold = (double)(n/2+1)/2;
    if(n > N)
    {
        cout<<(long long)(cxold+x)<<' '<<(long long)(cyold+y);
        return;
    }
    long long op = seq.top();
//    prlong longf("%d ",op);
    seq.pop();
    if(op == 1)
    {
        newx = y, newy = -x;
        rxold = -rxold, ryold = -ryold;
        rxold += newx, ryold+=newy;
        locate(rxold, ryold, n*2);
    }
    else if(op ==2)
    {
        newx = x, newy = y;
        rxold = - rxold;
        rxold += newx, ryold+=newy;
        locate(rxold, ryold, n*2);
    }
    else if(op == 3)
    {
        newx = x, newy =y;
        rxold += newx, ryold+=newy;
        locate(rxold, ryold, n*2);
    }
    else if(op == 4)
    {
        newx = -y, newy = x;
        ryold = -ryold;
        rxold += newx, ryold+=newy;
        locate(rxold, ryold, n*2);
    }
}
int main() {
    cin>>N>>k;
    long long pos = find_pos(k,N);
    double x, y;
    x = matricex[pos-1], y = matricey[pos-1];
    locate(x,y,4);

}