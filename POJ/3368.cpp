/*
线段树（纯手工打造独立完成)
*/
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

#define INF 100005

const int maxn=100000+10;
//left[i]表示下标i所在段的最左段的下标，right同义，num[i]:ith元素所在短 cnt[i]:ith元素所在段的元素个数
int left[maxn],right[maxn],num[maxn],cnt[maxn],a[maxn];
int sum[maxn*4];

void pushUp(int k){
    sum[k]=max(sum[k*2],sum[k*2+1]);
}

//线段树是维护sum[num[]]=cnt[]; 即以段num为区间，cnt为值。
void build(int k,int l,int r){
    if(l==r){
        sum[k]=cnt[l];
    }
    else {
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);pushUp(k);
    }

}

int query(int a,int b,int k,int l,int r){
    if(a<=l && b>=r)
        return sum[k];
    else {
        int ans=-1,m=(l+r)/2;
        if(a<=m)
            ans=max(ans,query(a,b,k*2,l,m));
        if(m<b)
            ans=max(ans,query(a,b,k*2+1,m+1,r));
        return ans;
    }
}

int main()
{
    int i,j,k,n,q;
    while(scanf("%d",&n),n){
        scanf("%d",&q);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        cnt[1]++;left[1]=1;num[1]=1;
        int c=1,s=1;
        for(i=2;i<=n;i++){
            while(i<=n && a[i]==a[i-1])
                i++;
            if(i>n){
                for(j=s;j<=n;j++){
                    right[j]=n;
                    left[j]=s;
                    num[j]=c;
                    cnt[c]=n-s+1;
                }
                break;
            }
            for(j=s;j<i;j++){
                right[j]=i-1;left[j]=s;
                num[j]=c; cnt[c]=i-s;//num[i]表示第i个数所在的段号
            }
            s=i;c++;
        }
        if(a[n]!=a[n-1]){       //最后一个数不同要特殊处理一下
            left[n]=right[n]=n;
            num[n]=c;cnt[c]=1;
        }
        build(1,1,c);
        while(q--){
            int l,r,ans=INF;
            scanf("%d%d",&l,&r);
            if(num[l]==num[r]){
                    printf("%d\n",r-l+1);
                continue;
            }
            ans=max(right[l]-l+1,r-left[r]+1);
            if(num[l]+1<=num[r]-1)
                ans=max(ans,query(num[l]+1,num[r]-1,1,1,c));
            printf("%d\n",ans);
        }
    }
    return 0;
}

/*
10 5
-1 1 1 1 2 2 3 3 3 4
*/
