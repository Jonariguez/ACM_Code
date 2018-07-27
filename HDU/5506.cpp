/****************
*PID:hdu5506
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int maxn=33;
int n,l;
bitset<330> b[maxn];
bool yes;

void dfs(int cur,bitset<330> *ans){
    if(yes) return ;
    int i;
    if(cur==n){
        for(i=0;i<l;i++)
            if(ans[i].count()==0) break;
        if(i>=l) yes=true;              //如果把n个集合都放到l个部分里了，而且各个部分都有公共部分，则YES
        return ;
    }
    bitset<330> temp[6];
    for(i=0;i<l;i++)
        temp[i]=ans[i];         //将ans复制到temp中
    for(i=0;i<l;i++){           //将目前第cur个集合b[cur]尝试着放到这l个部分里
        temp[i]=ans[i]&b[cur];  //看该集合和第i个部分有没有公共部分
        if(temp[i].count()!=0)  //有公共部分说明可以放到里面去，放进去之后则接着递归处理下一个集合，cur+1
            dfs(cur+1,temp);
        temp[i]=ans[i];         //如果不放入，则temp要保持和ans的原样，所以要把ans复制到temp
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            b[i].reset();
        int k,x;
        for(i=0;i<n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);
                b[i][x]=1;
            }
        }
        bitset<330> ans[6];
        for(i=0;i<l;i++)
            for(j=1;j<=300;j++)
                ans[i][j]=1;
        yes=false;
        dfs(0,ans);
        if(yes)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
