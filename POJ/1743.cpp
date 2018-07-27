/****************
*PID:poj1743
*Auth:Jonariguez
*****************
后缀数组求最长不重复子串
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=20000+10;
int sa[maxn],temp[maxn],rank[maxn],height[maxn],a[maxn];
int n,k;

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
    int i,maxv=sa[0],minv=sa[0];
    for(i=0;i<=n;i++){
        if(height[i]>=x){
            maxv=max(maxv,sa[i]);
            minv=min(minv,sa[i]);
            if(maxv-minv>x)        //这里等于也行。 不过这里用>可以和后面的res++,由前后两项作差的因为体会一下。。
                return true;
        }else
            maxv=minv=sa[i];
    }
    return false;
}

int main()
{
    int i;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
            a[i]=a[i+1]-a[i]+90;
        n--;
        a[n]=a[n-1];
        construct_sa(a,sa);
        construct_lcp(a,sa,height);
        int l=1,r=n,res=0;
        while(l<=r){
            int m=(l+r)/2;
            if(C(m)){
                res=max(res,m);
                l=m+1;
            }
            else r=m-1;
        }
        res++;          //如果是n个数满足的话，那么他们的相邻差只有n-1个，所以
        if(res<5)
            printf("0\n");
        else
            printf("%d\n",res);
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
*/
