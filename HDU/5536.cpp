/****************
*PID:hdu5536
*Auth:Jonariguez
*****************
Trie
将n*(n-1)/2个和插入到trie中(n*(n-1)/2个原因是保证si+sj中的i和j不同)
然后为了保证sk中的k和i，j均不同，故枚举sk，然后将trie中和k有关的和项
从trie中删除。
故trie要支持插入和删除。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+5;
int a[maxn];

struct Trie{
    int chi[16000000][2],Size,val[16000000];
    void init(){
        memset(chi[0],0,sizeof(chi[0]));Size=1;
        val[0]=0;
    }
    void Insert(LL v){
        int i,now=0;
        for(i=32;i>=0;i--){
            int temp=((v>>i)&1),t=0;
            if(temp) t=1;
            if(chi[now][t]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                val[Size]=0;
                chi[now][t]=Size++;
            }
            now=chi[now][t];
            val[now]++;
        }
       // val[now]++;
    }
    void Delete(LL v){
        int i,now=0;
        for(i=32;i>=0;i--){
            int temp=((v>>i)&1),t=0;
            if(temp) t=1;
            now=chi[now][t];
            val[now]--;
        }
       // val[now]--;
    }
    LL ask(LL v){
        int i,now=0;
        LL res=0;
        for(i=32;i>=0;i--){
            int temp=((v>>i)&1),t=0;
            if(temp) t=1;
            if(val[chi[now][1-t]]){
                res|=(1<<i);
                now=chi[now][1-t];
            }else if(val[chi[now][t]]==0)
                return res;
            else now=chi[now][t];
        }
        return res;
    }
}trie;

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        trie.init();
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                trie.Insert(a[i]+a[j]);
            }
        }
        LL res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<i;j++) trie.Delete((LL)a[i]+a[j]);    //先删除
            for(j=i+1;j<=n;j++) trie.Delete((LL)a[i]+a[j]);
            res=max(res,trie.ask(a[i]));
            for(j=1;j<i;j++) trie.Insert((LL)a[i]+a[j]);    //再插入进去
            for(j=i+1;j<=n;j++) trie.Insert((LL)a[i]+a[j]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}


