/****************
*PID:zoj2562
*Auth:Jonariguez
*****************
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

void dfs(int cur,ULL sum,int num){
    if(sum>n) return ;
    if(cur>=14) return ;        //�н��ۿɵã����ᳬ��13��
    if(num>cnt){
        cnt=num;
        res=sum;
    }
    if(num==cnt && sum<res) res=sum;    //һ��Ҫ��
    int i;
    for(i=1;i<=63;i++){
        if(n/prime[cur]<sum) break;
        dfs(cur+1,sum*prime[cur],num*(i+1));
        sum*=prime[cur];
    }
}

int main()
{
    get_table();
    while(scanf("%llu",&n)!=EOF){
        res=inf;
        cnt=0;
        dfs(0,1,1);
        printf("%llu\n",res);
    }
    return 0;
}
