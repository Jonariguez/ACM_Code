/****************
*PID:hdu4542
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int maxk=47777+10;
const LL MAX = (1LL)<<62;

int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
LL res;
int k,d[maxk];

void get_d(){
    int i,j;
    for(i=1;i<maxk;i++){
        for(j=i;j<maxk;j+=i)
            d[j]++;
        if(!d[i-d[i]]) d[i-d[i]]=i;     //d[i]��ʾ[1,i]��i�����Ӹ�����i-d[i]�������в���i�����ӵĸ�����
        d[i]=0;                         //����i-d[i]�Ĵ�d[i-d[i]]��Ӧ����i(��Ϊi�Ǵ�С����ö�٣���ʱ��i������С)
    }
}

void dfs(int cur,int limit,LL sum,int num){
    if(num>k) return ;
    if(num==k && sum<res){
        res=sum;return ;
    }
    int i;
    for(i=1;i<=limit;i++){
        if(res/prime[cur]<sum || num*(i+1)>k) break;    //��֦
        sum*=prime[cur];
        if(k%(num*(i+1))==0)        //��֦    ...����kд��n�ˣ�һֱTLE
            dfs(cur+1,i,sum,num*(i+1));
    }
}

int main()
{
    int i,T,o,kcase=1;
    get_d();
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&o,&k);
        if(o==0){
            res=(MAX-1)*2;
            dfs(0,62,1,1);
        }else
            res=d[k];
        printf("Case %d: ",kcase++);
        if(res==0)
            printf("Illegal\n");
        else if(res>MAX)
            printf("INF\n");
        else
            printf("%I64d\n",res);
    }
    return 0;
}
