#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
int sum[maxn],par[maxn],under[maxn];

void Init(){
    for(int i=0;i<maxn;i++){
        par[i]=i;
        under[i]=0;
        sum[i]=1;
    }
}

//注意这里，under[x]本来是从x往下到par[x]一共有多少个，那如果再加上
//par[x]下面的个数，under[x]就更新正确了。我不管par[x]下面有多少，
//反正路径压缩会使在执行这句话的时候让under[par[x]]保证是正确值。。
//至于上面的y，它是层层递归得到的，很明显是路径压缩之后最终的根，所以
//y只是用来par[x]=y，即把沿路遇到的点全部压缩到最终根(即真正的路径压缩)
//这和更新under没有半毛钱关系
int Find(int x){
    if(x==par[x]) return x;
    int y=Find(par[x]);     //这里一定要先递归，因为更新under是从找到最终根然后倒着更新的，
    under[x]+=under[par[x]];                //因为要先把靠近根的更新对，那么之后的更新的才是正确值。
   // sum[y]+=sum[x];
    return par[x]=y;
}

//在路径压缩完成后，就可以把u和v分别看出一个整体，
//如果把u放在v上面，自然v里的全部砖块都要算到under[x]里
void Union(int u,int v){
    if((u=Find(u))==(v=Find(v)))
        return ;
    under[u]+=sum[v];
    par[u]=v;sum[v]+=sum[u];
}

int main()
{
    int i,j,p;
    char s[5];
    Init();
    scanf("%d",&p);
    while(p--){
        scanf("%s",s);
        if(s[0]=='M'){
            int a,b;
            scanf("%d%d",&a,&b);
            Union(a,b);
        }else {
            int x;
            scanf("%d",&x);
            Find(x);        //要先压缩一下，然后再查询
            printf("%d\n",under[x]);
        }
    }
    return 0;
}
