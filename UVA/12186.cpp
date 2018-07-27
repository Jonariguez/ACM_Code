/****************
*PID:uva12186
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int n,T;
vector<int> son[maxn];

int dp(int u){
    if(son[u].size()==0) return 1;
    int i,c,k;
    vector<int> s;              //为了各层递归使用s互不影响，那么s应该在dp函数内部定义，而不能用全局变量
    k=son[u].size();
    for(i=0;i<k;i++)
        s.push_back(dp(son[u][i]));
    sort(s.begin(),s.end());
    c=(k*T-1)/100+1;
    int res=0;
    for(i=0;i<c;i++)
        res+=s[i];
    return res;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&T)){
        if(n==0 && T==0) break;
        for(i=0;i<=n;i++) son[i].clear();
        int x;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            son[x].push_back(i);
        }
        printf("%d\n",dp(0));
    }
    return 0;
}
