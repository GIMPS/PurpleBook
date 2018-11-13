#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
struct Node{
    Node *ch[2];
    int r;
    int v;
    bool operator < (const Node& rhs) const{
        return r<rhs.r;
    }
    int cmp(int x) const {
        if (x==v ) return -1;
        return x<v? 0:1;
    }
};

void rotate(Node* &o, int d)
{
    Node* k = o->ch[d^1] ;
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o = k;
}

void insert(Node* &o, int x){
    if(o == NULL){
        o = new Node();
        o->ch[0] = o->ch[1] = NULL;
        o->v = x;
        o->r = rand();
    }
    else{
        int d = o->cmp(x);
        insert(o->ch[d],x);
        if(o->ch[d] > o) rotate(o, d^1);
    }
}

void remove(Node* &o, int x)
{
    int d = o->cmp(x);
    if(d == -1){
        if(o->ch[0] == NULL)
            o = o->ch[1];
        else if(o->ch[1] == NULL) o = o->ch[0];
        else {
            int d2 = (o->ch[0] > o->ch[1]? 1 : 0);
            rotate(o, d2);
            remove(o->ch[d2], x);
        }
    }
    else remove(o->ch[d],x);
}

int find(Node* o,int x)
{
    while(o != NULL)
    {
        int d = o->cmp(x);
        if(d == -1) return 1;
        else o = o->ch[d];

    }

    return 0;
}

int main()
{
    clock_t start = clock();
    Node* root;
    for(int i=0;i<1e6;i++)
    {
        if(find(root, i) == 1) continue;
        insert(root, i);
    }
    for(int i=1;i<2;i++)
    {
        remove(root, i);
    }
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}
