/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(LL u,LL d,LL sum){     //sum维护的是以当前节点u为根的子树的节点个数
    a[cnt++]=sum;           //直接存下sum即可，那么以u的兄弟节点为根的怎么算的呢，下面算
    if(u==1) return ;
    LL x;                 //u&1说明是父亲节点的右孩子
    if(u&1)                 //如果u是右孩子，则其左兄弟是一个满二叉树，层数是height-d+1 (x)
        x=height-d+1;
    else x=height-d;      //如果u是左孩子，则其右兄弟是一个满二叉树，层数是height-d  (x)
    cal(x);             //以u为根节点的子树的节点个数是sum，那么以u的兄弟节点为根节点的子树的节点个数用cal(层数)算
    dfs(u/2,d-1,sum+(1LL<<x));
}
解释一下sum+(1<<x)，我们知道size(u)=sum,我们是往上递归的，设v是u的父亲，在我们
向上递归到v时，那时应该size(v)=sum(u)+sum(p)+1; 而已知sum(p)=2^x(层数)-1,那么sum(p)+1恰好等于2^x
