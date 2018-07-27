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

const int maxn=200000+10;

int n,k;
int rank[maxn],temp[maxn],sa[maxn],a[maxn],rev[maxn];

bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
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
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n,cmp);
        temp[sa[0]]=0;
        for(i=1;i<=n;i++){
            temp[sa[i]]=temp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
        }
        for(i=0;i<=n;i++)
            rank[i]=temp[i];
    }
}





int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    reverse_copy(a,a+n,rev);
    construct_sa(rev,n,sa);

    int p1;
    for(i=0;i<n;i++){
        p1=n-sa[i];
        if(sa[i]>=2 && p1>=1) break;
    }
    int m=n-p1;
    reverse_copy(a+p1,a+n,rev);
    reverse_copy(a+p1,a+n,rev+m);
    construct_sa(rev,m*2,sa);
    int p2;
    for(i=0;i<m*2;i++){
        p2=p1+m-sa[i];
        if(p2-p1>=1 && n-p2>=1) break;
    }
    reverse(a,a+p1);
    reverse(a+p1,a+p2);
    reverse(a+p2,a+n);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
