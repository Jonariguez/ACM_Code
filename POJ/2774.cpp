/****************
*PID:poj2774
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
int n,k,l;
int temp[maxn],sa[maxn],rank[maxn],height[maxn];

bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
    int ri=i+k<=n?rank[i+k]:-1;
    int rj=j+k<=n?rank[j+k]:-1;
    return ri<rj;
}

void construct_sa(char *s,int *sa){
    int i,j;
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
    int i,h;
    for(i=0;i<=n;i++)
        rank[sa[i]]=i;
    h=0;
    for(i=0;i<=n;i++){
        if(h) h--;
        int j=sa[rank[i]-1];
        while(s[j+h]==s[i+h])
            h++;
        height[rank[i]]=h;
    }
}


void Cat(char *a,char *b,char *c){
    int i,lb,lc;
    l=strlen(a);
    strcpy(c,a);
    lb=strlen(b);
    n=strlen(c);
    c[n++]='$';
    for(i=0;i<lb;i++)
        c[n++]=b[i];
    c[n]='\0';
}

int main()
{
    int i,res;
    scanf("%s%s",a,b);
    Cat(a,b,s);
    construct_sa(s,sa);
    construct_lcp(s,sa,height);
    res=-1;
    for(i=0;i<=n;i++){
        if(sa[i]<l && sa[i-1]>l || sa[i]>l && sa[i-1]<l)
            res=max(res,height[i]);
    }
    printf("%d\n",res);
    return 0;
}
