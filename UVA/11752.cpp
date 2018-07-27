/****************
*PID:uva11752
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
#define top(a) ceil(64/(log(a)/log(2)))-1
const ULL maxn=66000+10;
const ULL inf=~0ULL;
bool vis[maxn];
vector<ULL> prime;

set<ULL> s;

void prime_table(){
    ULL i,j;
    for(i=2;i<maxn;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=2*i;j<maxn;j+=i)
                vis[j]=1;
        }
    }
}

ULL quick_pow(ULL a,ULL b){
    ULL res=1;
    while(b){
        if(b&1){
            res=res*a;
        }
        b/=2;
        a=a*a;
    }
    return res;
}

int main()
{
    prime_table();
    ULL i,j;
    ULL tot=0;
    for(i=2;i<(1<<16);i++){     //这里要枚举[2,2^16],而不是只枚举其中的素数
        ULL tp=top(i);
        for(j=4;j<=tp;j++)
            if(vis[j]){
                ULL t=quick_pow(i,j);
                s.insert(t);
            }
    }
    printf("1\n");
  //  sort(s,s+tot);
    set<ULL>::iterator it;
    it=s.begin();
    while(it!=s.end()){
        printf("%llu\n",*it);
        it++;
    }
    return 0;
}
