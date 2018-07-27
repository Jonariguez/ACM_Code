#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int vis[11],a[11],n,flag;

set<int> s;

//判断x是否是5位数
bool add(int x){
    int cnt=0;
    while(x){
        s.insert(x%10);
        cnt++;
        x/=10;
    }
    return cnt==5;
}

//只要保证分母是从小到大枚举，那么整个式子就是从小到大的，无需再最结果排序，直接输出即可
void dfs(int cur,int sum){
    if(sum>98765/n) return ;      //如果此时的fghij太大了，就不用枚举了
    int i;
    if(cur==5){
        int res;
        s.clear();
        for(i=0;i<5;i++){
            s.insert(a[i]);
        }
        res=n*sum;
        if(!add(res)) return ;
        if(s.size()==10){
            flag=1;
            printf("%d / ",res);
            for(i=0;i<5;i++) printf("%d",a[i]);
            printf(" = %d\n",n);
        }
        return ;
    }
    for(i=0;i<10;i++)
        if(vis[i]==0){
            vis[i]=1;
            a[cur]=i;
            dfs(cur+1,sum*10+i);
            vis[i]=0;
        }
}

int main()
{
    int i,j,k=0,mp[80];
    memset(mp,0,sizeof(mp));
    while(scanf("%d",&n),n){
        if(k++)
            printf("\n");
        flag=0;
        if(mp[n]){      //mp做个标记，如果mp为1说明n是无解的，优化
            printf("There are no solutions for %d.\n",n);
            continue;
        }
        memset(vis,0,sizeof(vis));
        dfs(0,0);
        if(!flag){
            mp[n]=1;
            printf("There are no solutions for %d.\n",n);
        }
    }
    return 0;
}
