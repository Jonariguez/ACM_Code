/*
��ϯ��+�鲢��
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
const int SIZE=(1<<18)-1;
int a[maxn],b[maxn];
vector<int> dat[maxn*4];        //����Ҫ��SIZEֵ��maxn*4��������maxn*2����RE

void Init(int k,int l,int r){
    if(r==l){
        dat[k].push_back(a[l]);
    }
    else {
        int m=(l+r)/2,lc=k*2,rc=k*2+1;
        Init(lc,l,m);
        Init(rc,m+1,r);
        dat[k].resize(r-l+1);
        merge(dat[lc].begin(),dat[lc].end(),dat[rc].begin(),dat[rc].end(),dat[k].begin());  //���һ��������Ҫ��dat[k]
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
    scanf("%d%d",&n,&m);        //ע������Ҫ���õ������ݣ���Ҫд��while(EOF)�Ķ������ݣ���WA����Ϊdat[]��ȫ�ֵģ��������ݻ���������Ӱ��
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
