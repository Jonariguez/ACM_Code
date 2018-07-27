/****************
*PID:poj3261
*Auth:Jonariguez
*****************
后缀数组解法
K定义了一个局部，又定义了一个全局，WA到死。。。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=20000+10;
int sa[maxn],temp[maxn],a[maxn],height[maxn],rank[maxn];
int n,k,K;
bool cmp(int i,int j){
    if(rank[i]!=rank[j]) return rank[i]<rank[j];
    int ri=i+k<=n?rank[i+k]:-1;
    int rj=j+k<=n?rank[j+k]:-1;
    return ri<rj;
}

void construct_sa(int *s,int *sa){
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

void construct_lcp(int *s,int *sa,int *height){
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

bool C(int x){
    int i,cnt=1;        //注意cnt的初始值是1，因为一旦有height[i]>=x，其实此时是有两个串的
    for(i=1;i<=n;i++){
        if(height[i]>=x){
            cnt++;
            if(cnt>=K) return true;
        }else
            cnt=1;
    }
    return false;
}

int main()
{
    int i;
    scanf("%d%d",&n,&K);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    a[n++]=-1;
    construct_sa(a,sa);
    construct_lcp(a,sa,height);
    int l=0,r=n,res;
    while(l<r-1){
        int m=(l+r)/2;
        if(C(m))
            l=m;
        else
            r=m;
    }
    printf("%d\n",l);
    return 0;
}
