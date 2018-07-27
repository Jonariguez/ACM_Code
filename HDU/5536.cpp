/****************
*PID:hdu5536
*Auth:Jonariguez
*****************
Trie
��n*(n-1)/2���Ͳ��뵽trie��(n*(n-1)/2��ԭ���Ǳ�֤si+sj�е�i��j��ͬ)
Ȼ��Ϊ�˱�֤sk�е�k��i��j����ͬ����ö��sk��Ȼ��trie�к�k�йصĺ���
��trie��ɾ����
��trieҪ֧�ֲ����ɾ����
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
            for(j=1;j<i;j++) trie.Delete((LL)a[i]+a[j]);    //��ɾ��
            for(j=i+1;j<=n;j++) trie.Delete((LL)a[i]+a[j]);
            res=max(res,trie.ask(a[i]));
            for(j=1;j<i;j++) trie.Insert((LL)a[i]+a[j]);    //�ٲ����ȥ
            for(j=i+1;j<=n;j++) trie.Insert((LL)a[i]+a[j]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}


