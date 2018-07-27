/****************
*PID:uva11525
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxk=50000+10;
int sum[maxk*4],k,vis[maxk];

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void build(int k,int l,int r){
    if(l==r){
        sum[k]=1;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

int Insert(int s,int k,int l,int r){
    if(l==r){
        sum[k]=0;return l;
    }
    int m=(l+r)/2,res;
    if(sum[k*2]>=s){
        res=Insert(s,k*2,l,m);
        sum[k*2]--;
    }
    else{
        res=Insert(s-sum[k*2],k*2+1,m+1,r);
        sum[k*2+1]--;
    }
    return res;
}

int main()
{
    int i,j,T,s;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&k);
        build(1,1,k);
        scanf("%d",&s);
        printf("%d",s+1);
        Insert(s+1,1,1,k);
        for(i=1;i<k;i++){
            scanf("%d",&s);
            s++;
            printf(" %d",Insert(s,1,1,k));
        }
        printf("\n");
    }
    return 0;
}
