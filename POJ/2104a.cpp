/*
主席树+归并树
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
const int SIZE=(1<<18)-1;
int a[maxn],b[maxn];
vector<int> dat[maxn*4];        //这里要用SIZE值或maxn*4，不能用maxn*2，会RE

void Init(int k,int l,int r){
    if(r==l){
        dat[k].push_back(a[l]);
    }
    else {
        int m=(l+r)/2,lc=k*2,rc=k*2+1;
        Init(lc,l,m);
        Init(rc,m+1,r);
        dat[k].resize(r-l+1);
        merge(dat[lc].begin(),dat[lc].end(),dat[rc].begin(),dat[rc].end(),dat[k].begin());  //最后一个参数不要是dat[k]
    }
}

int query(int a,int b,int v,int k,int l,int r){
    if(b<l || a>r)
        return 0;
    else if(a<=l && r<=b){
            int c=upper_bound(dat[k].begin(),dat[k].end(),v)-dat[k].begin();
            return c;
    }
    else {
        int res=0,m=(l+r)/2;
        res+=query(a,b,v,k*2,l,m);
        res+=query(a,b,v,k*2+1,m+1,r);
        return res;
    }
}


int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);        //注意这里要采用单组数据，不要写成while(EOF)的多组数据，会WA，因为dat[]是全局的，上组数据会多下组产生影响
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    Init(1,1,n);
    while(m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int L=0,R=n;
        while(R-L>1){
            int M=(L+R)/2;
            int t=query(l,r,b[M],1,1,n);
            if(t>=k)
                R=M;
            else
                L=M;
        }
        printf("%d\n",b[R]);
    }
    return 0;
}
