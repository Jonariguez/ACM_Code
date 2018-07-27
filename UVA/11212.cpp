/****************
*PID:uva11212
*Auth:Jonariguez
*****************
IDA*
评估函数：设h为后继不正确的数字个数，那么每次剪切
h最多减少3
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=9;
int n,a[maxn],maxd;
bool yes;

bool is_sort(){
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]>=a[i+1]) return false;
    return true;
}

int h(){
    int i,cnt=0;
    for(i=0;i<n-1;i++)
        if(a[i]+1!=a[i+1]) cnt++;   //统计后继不对的个数
    if(a[n-1]!=n) cnt++;
    return cnt;
}

void dfs(int d){
    if(d*3+h()>3*maxd) return ;     //评估函数
    if(yes) return ;
    if(is_sort()){
            yes=true;return ;
    }

    int b[maxn],olda[maxn];
    memcpy(olda,a,sizeof(a));
    int i,j,k,p;
    //将a[i..j]提取出来放在b[]中，然后a[]剩下(设剩了x个)的元素保持
    //其顺序不变，然后将a[i..j]作为一个整体插到x+1个空里形成新的序列
    for(i=0;i<n;i++)
        for(j=i;j<n;j++){
            int cnt=0;
            for(k=0;k<n;k++)
                if(k<i || k>j) b[cnt++]=a[k];

            for(k=0;k<=cnt;k++){
                int cnt2=0,v;
                for(v=0;v<k;v++) a[cnt2++]=b[v];
                for(v=i;v<=j;v++) a[cnt2++]=olda[v];
                for(v=k;v<cnt;v++) a[cnt2++]=b[v];
                dfs(d+1);
                memcpy(a,olda,sizeof(olda));
            }
        }
}

int solve(){
    if(is_sort()) return 0;
    int max_ans=5;          //事实证明一共最多只需要5次即可
    yes=false;
    for(maxd=1;maxd<max_ans;maxd++){
        dfs(0);
        if(yes) return maxd;
    }
    return max_ans;
}

int main()
{
    int i,kcase=1;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("Case %d: %d\n",kcase++,solve());
    }
    return 0;
}
