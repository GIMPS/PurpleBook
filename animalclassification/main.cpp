#include <iostream>
#include<cstdio>
#include<cstring>
#include<utility>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int value,ub,lb;
};

const int maxn = 1e5+10;
int relab[maxn];
int cnt=0;
int count_same=0;
const int M=10000001;
pair<int,int> hashv[M];
Node* build_tree1()
{
    Node* root=new Node();
    root->value=-1,root->ub=-1,root->lb=-1;
    root->left=NULL;
    root->right=NULL;
    int d;
    if(scanf("%d",&d)==1)
    {
        cnt++;
        root->value=cnt;
        root->lb=cnt;
        root->ub=cnt;
        relab[d]=cnt;
        return root;
    }
    char c='-';
    while(c!=')')
    {
        scanf("%c",&c);
        if(c=='(')
        {
                root->left = build_tree1();
        }
        if(c==',') {
            root->right = build_tree1();
        }
    }
    return root;
}
Node* build_tree2()
{
    Node* root=new Node();
    root->value=-1,root->ub=-1,root->lb=-1;
    root->left=NULL;
    root->right=NULL;
    int d;
    if(scanf("%d",&d) == 1)
    {
        root->value=relab[d];
        root->lb=relab[d];
        root->ub=relab[d];
        return root;
    }
    char c='-';
    while(c!=')')
    {
        scanf("%c",&c);
        if(c=='(')
        {
            root->left = build_tree2();
        }
        if(c==',') {
            root->right = build_tree2();
        }
    }
    return root;
}
void hash1(Node* root)
{
    if(root->value==-1)
    {
        if(root->left!=NULL)
        {
            hash1(root->left);
            root->lb = root->left->lb;
            root->ub = root->left->ub;
            root->value=root->left->value;
        }
        if(root->right!=NULL)
        {
            hash1(root->right);
            if(root->right->lb<root->lb)
                root->lb = root->right->lb;
            if(root->right->ub>root->ub)
                root->ub = root->right->ub;
            root->value+=root->right->value;
        }
        root->value %= M;
        hashv[root->value]=make_pair(root->ub,root->lb);
    }
}
void hash2(Node* root)
{
    if(root->value==-1)
    {
        if(root->left!=NULL)
        {
            hash2(root->left);
            root->lb = root->left->lb;
            root->ub = root->left->ub;
            root->value=root->left->value;
        }
        if(root->right!=NULL)
        {
            hash2(root->right);
            if(root->right->lb<root->lb)
                root->lb = root->right->lb;
            if(root->right->ub>root->ub)
                root->ub = root->right->ub;
            root->value+=root->right->value;
        }
        root->value %= M;
        if(hashv[root->value].first== root->ub && hashv[root->value].second== root->lb)
            count_same++;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    memset(relab,0,sizeof(relab));
    for(int i=0;i<M;i++)
        hashv[i] = make_pair(-1,-1);
    Node* t1 = build_tree1();
    Node* t2 = build_tree2();

    hash1(t1);
    hash2(t2);
//    printf("%d\n",t1->value);
//    printf("%d\n",t2->value);
    printf("%d", count_same+n);
//    for(int i=1;i<M;i++)
//        if(hashv[i].first!=-1) printf("%d ",hashv[i].first);
}