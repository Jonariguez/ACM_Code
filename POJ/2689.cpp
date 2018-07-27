/****************
*ID:poj2689
*Auth:Jonariguez
*****************
��������
$�������⣬1�������������һ���ӵ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999
typedef long long ll;

const ll maxn=2147483647+10;
bool is[1000005];
vector<int> prime,p;
ll L,U;

void prime_table(){
    int i,j;
    memset(is,0,sizeof(is));
    for(i=2;i<=50000;i++){
        if(!is[i]){
            prime.push_back(i);
            for(j=i*2;j<=50000;j+=i)
                is[j]=1;
        }
    }
}

void solve(){
    ll i,j;
    if(L==1)
        L=2;        //��Ϊ1�����������Ϳ��Բ���������ֱ�Ӱ�L=2����
    memset(is,0,sizeof(is));
    for(i=0;i<prime.size();i++){
        int x=prime[i];
        ll c=L/x;
        while(c*x<L || c<=1)        //c���ܵ���1����Ϊc����1ʱc*x��x��x����������Ӧ���������for��ɸ��
            c++;                    //�����ڱ�֤c*x>=L������£���Ҫʹc���ٵ���2����
        for(j=c*x;j<=U;j+=x)
            if(j>=L)
                is[j-L]=1;
    }
    ll mind=INF,maxd=-INF;
    ll minl,minr,maxl,maxr;
    p.clear();
    for(i=0;i<=U-L;i++)
        if(!is[i])
            p.push_back(i);
    if(p.size()<=1)
        printf("There are no adjacent primes.\n");
    else {
        for(i=0;i<p.size()-1;i++){
            if(p[i+1]-p[i]<mind){
                mind=p[i+1]-p[i];
                minl=p[i];minr=p[i+1];
            }
            if(p[i+1]-p[i]>maxd){
                maxd=p[i+1]-p[i];
                maxl=p[i];maxr=p[i+1];
            }
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",minl+L,minr+L,maxl+L,maxr+L);
    }
}






int main()
{
    int i,j;
    prime_table();
    while(scanf("%lld%lld",&L,&U)!=EOF){
        solve();
    }
    return 0;
}
