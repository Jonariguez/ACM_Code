/****************
*PID:hdu1272
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
LL par[maxn],Rank[maxn],n,m;

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

int main()
{
    int i,j,a,b;
    while(scanf("%d%d",&a,&b)){
        if(a==-1 && b==-1) break;
        if(a==0 && b==0){
            printf("Yes\n");continue;
        }
        for(i=1;i<=100000;i++){
            par[i]=i;Rank[i]=1;
        }
        par[a]=b;Rank[b]++;
        int yes=1;
        while(scanf("%d%d",&a,&b)){
            if(a==0 && b==0) break;
            if(yes==0) continue;
            a=find(a);b=find(b);
            if(a==b){
                yes=0;continue;
            }
            if(Rank[a]>Rank[b]){
                par[b]=a;Rank[a]+=Rank[b];
            }else if(Rank[a]<Rank[b]){
                par[a]=b;Rank[b]+=Rank[a];
            }else {
                par[a]=b;Rank[b]++;
            }
        }
        if(yes==0){
            puts("No");continue;
        }
        int cnt=0;
        for(i=1;i<=100000;i++)
            if(find(i)==i && Rank[i]>1) cnt++;
        if(cnt==1)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
