/****************
*PID:poj3415
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
char a[maxn],b[maxn],s[maxn];
int sa[maxn],temp[maxn],rank[maxn],height[maxn];
int n,k,l;

bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
    int ri=i+k<=n?rank[i+k]:-1;
    int rj=j+k<=n?rank[j+k]:-1;
    return ri<rj;
}

void construct_sa(char *s,int *sa){
    int i;
    for(i=0;i<=n;i++){
        sa[i]=i;
        rank[i]=i<n?s[i]:-1;
    }
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1,cmp);
        temp[sa[0]]=0;
        for(i=1;i<=n;i++)
            temp[sa[i]]=temp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
        for(i=0;i<=n;i++)
            rank[i]=temp[i];
    }
}

void construct_lcp(char *s,int *sa,int *height){
    int i,j,h=0;
    for(i=0;i<=n;i++)
        rank[sa[i]]=i;
    for(i=0;i<=n;i++){
        if(h) h--;
        j=sa[rank[i]-1];
        for(;j+h<n && i+h<n;h++){
            if(s[j+h]!=s[i+h]) break;
        }
        height[rank[i]]=h;
    }
}

void Cat(char *a,char *b,char *s){
    int i;
    strcpy(s,a);
    l=strlen(a);
    s[l]='$';
    n=l+1;
    i=0;
    while(b[i])
        s[n++]=b[i++];
    s[n]='\0';
}

int main()
{
    int i,j,L;
    while(scanf("%d",&L),L){
        scanf("%s%s",a,b);
        Cat(a,b,s);
        printf("l=%d\n",l);
        construct_sa(s,sa);
        construct_lcp(s,sa,height);
        long long res=0;
        for(i=1;i<=n;i++){
            if(height[i]>=L && (sa[i]>l && sa[i-1]<l || sa[i]<l && sa[i-1]>l)){
                long long t=height[i]-L+1;
                res+=t;
            }
        }
        printf("%lld\n",res);

    }
    return  0;
}
