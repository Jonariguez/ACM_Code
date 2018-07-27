/****************
*PID:SWUSTOJ626
*Auth:Jonariguez
*****************
������������
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int maxd,ok;
ll res[maxn],v[maxn];
ll A,B;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

//��������a/b>=1/c����С��c��ת��һ�µã�c>=b/a(����ȡ��)
ll get_first(ll a,ll b){
    return (b+a-1)/a;
}

bool better(int d){
    int i;
    for(i=0;i<=d;i++)
        if(v[i]!=res[i])    //��Ŀǰ����ķ�����Ŀǰ�Ѿ��õ��Ĵ�������в�һ���ģ���ͨ�������һ�������ж��ĸ�
            return res[i]==-1 || res[i]>v[i];   //���ţ���ô���res[i]��û���£���v[i]��res[i]ҪС����v�Ǹ��ŵ�
    return false;
}

//d:��ǰ��ȣ�f:��ĸ����С��f�� ʣ�µķ���֮��Ӧ�õ���a/b
bool dfs(int d,int f,ll a,ll b){
    if(d==maxd){
        if(b%a) return false;       //�ѵ����һ��ʣ�µ�a/bӦ���ǰ�������(a/bԼ�ֺ����Ϊ1)�ŷ���
        v[d]=b/a;             //��¼���
        if(better(d))       //���Ŀǰ����ĸ��ţ�����´�res
            memcpy(res,v,sizeof(ll)*(d+1));
        return true;
    }
    bool yes=false;
    f=max(f,(int)get_first(a,b));
    for(int i=f;;i++){
        int D=maxd-d+1;
        if(D*b<=i*a) break;         //���ʣ�µ�(maxd-d+1)������ȫ����1/i��ȻС��a/b,��
        ll aa=a*f-b,bb=b*f;                 //ôi�����˾͸������ܵ�a/b,��֦
        ll g=gcd(aa,bb);
        v[d]=i;                 //��¼��ǰ��������Լ��
        if(dfs(d+1,i+1,aa/g,bb/g))
            yes=true;
    }
    return yes;
}

int main()
{
    int i,j;
    ll g;
    scanf("%lld/%lld",&A,&B);
    g=gcd(A,B);
    A/=g;B/=g;
    if(A==1){
        printf("1/%lld\n",B);
        return 0;
    }
    memset(v,0,sizeof(v));
    ok=0;

    for(maxd=1;;maxd++){        //ö�����
        memset(res,-1,sizeof(res));
        if(dfs(0,get_first(A,B),A,B)){
            ok=1;break;
        }
    }
    if(ok){
        printf("1/%lld",res[0]);
        for(int i=1;i<=maxd;i++)
            printf(" + 1/%lld",res[i]);
        printf("\n");
    }
    return 0;
}
