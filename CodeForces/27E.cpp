/****************
*PID:cf27E
*Auth:Jonariguez
*****************
反素数
*/
#include <iostream>
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
ULL res;
int n;

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
    if(num>n) return ;
    if(num==n){
        res=min(res,sum);
        return ;
    }
    int i;
    for(i=1;i<=63;i++){
        if(res/prime[cur]<sum) break;       //不能一直递归。
        dfs(cur+1,sum*prime[cur],num*(i+1));
        sum*=prime[cur];//num*=(i+1);
    }
}

int main()
{
    get_table();
    while(scanf("%d",&n)!=EOF){
        res=inf;
        dfs(0,1,1);
        cout<<res<<endl;
    }
    return 0;
}
