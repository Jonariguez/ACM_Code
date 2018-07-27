/****************
*PID:poj3581
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+5;
int a[maxn],rev[maxn*2],sa[maxn*2],rank[maxn*2];
int k,n,temp[maxn*2];

bool cmp(int i,int j){
    if(rank[i]!=rank[j])
        return rank[i]<rank[j];
    int ri=i+k<=n?rank[i+k]:-1;
    int rj=j+k<=n?rank[j+k]:-1;
    return ri<rj;
}

void construct_sa(int *s,int n,int *sa){
    int i,j;
    for(i=0;i<=n;i++){
        sa[i]=i;
        rank[i]=i<n?s[i]:-1;
    }
    printf("sa: ");
        for(i=0;i<=n;i++)
            printf("%d ",sa[i]);
        printf("\n");
        printf("ra: ");
        for(i=0;i<=n;i++)
            printf("%d ",rank[i]);
        printf("\n\n");
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1,cmp);
        printf("k=%d\n",k);
        printf("sa: ");
        for(i=0;i<=n;i++)
            printf("%d ",sa[i]);
        printf("\n");

        temp[sa[0]]=0;
        for(i=1;i<=n;i++)
            temp[sa[i]]=temp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
        for(i=0;i<=n;i++)
            rank[i]=temp[i];
            printf("ra: ");
        for(i=0;i<=n;i++)
            printf("%d ",rank[i]);
        printf("\n\n");
    }
};

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    construct_sa(a,n,sa);
    return 0;
}
/*
11
1 2 5 1 3 1 4 1 2 5 1
*/
