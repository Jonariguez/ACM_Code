/*
先找出出现次数最多数的出现的次数
然后尺取
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn],vis[maxn*10];
map<int,int> cnt;

int main()
{
    int i,j,s,t,n,indexs,indext,res,maxv;
    while(scanf("%d",&n)!=EOF){
        maxv=-1;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]++;
            maxv=max(maxv,vis[a[i]]);
        }
        cnt.clear();
        s=t=indexs=indext=0;res=n+2;
        for(;t<n;t++){
            while(t<n && ++cnt[a[t]]<maxv){
                    t++;
            }
        //    printf("t=%d\n",t);
            if(cnt[a[t]]<maxv) break;
            if(res>t-s+1){
                indexs=s;indext=t;
                res=t-s+1;
            }
            cnt[a[s]]--;
            if(a[s]!=a[t]){
                cnt[a[t]]--;t--;
            }
            s++;
        }
        printf("%d %d\n",indexs+1,indext+1);
    }
    return 0;
}
