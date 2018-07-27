/****************
*PID:timusOJ_1748
*Auth:Jonariguez
*****************
������
ǰ13��������˻����1e16
ǰ15��������˻����1e18
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
const ULL inf=~0ULL;

vector<int> prime;
bool vis[1002];
ULL n,res,cnt;

void get_table(){
    int i,j;
    for(i=2;i<=1000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=1000;j+=i)
                vis[j]=1;
        }
    }
}
//�ɷ����������ʿ�֪��������ԽС����ָ��Խ�󣬼�
//���������2����t����3����t'������ô����t'<=t
//�ɴ����Ż���
void dfs(int cur,int limit,ULL sum,int num){
    if(sum>n) return ;
    if(cur>=14) return ;        //�н��ۿɵã����ᳬ��13��
    if(num>cnt){
        cnt=num;
        res=sum;
    }
    if(num==cnt && sum<res) res=sum;    //һ��Ҫ��
    int i;
    for(i=1;i<=limit;i++){
        if(n/prime[cur]<sum) break;
        dfs(cur+1,i,sum*prime[cur],num*(i+1));
        sum*=prime[cur];
    }
}

int main()
{
    get_table();
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%llu",&n);
        res=inf;
        cnt=0;
        dfs(0,60,1,1);
        printf("%llu %llu\n",res,cnt);
    }
    return 0;
}
