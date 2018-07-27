/****************
*ID:uva1575
*Auth:Jonariguez
*****************
��f(k)=n
���k�����ֽ⣬k=p1^k1 * p2^k2 *...* ps^ks
��ôn��Ӧ���ǣ�
sigma{ki}!/(k1!*k2!*..*ks!)             (#) (�ù�ʽ�ܹ������������)
��������ظ�Ԫ�ص�ȫ���и�����
�ȴ��Ȼ��ö��ÿ�������Ĵ���������k��n��Ȼ���¼�𰸵�res��.

�����������(#) ����������ı��ʽ:C(n,k) = n!/(k!*(n-k)!)
������sigma{ki}!/(k1!*k2!*..*ks!)������һ��kr,��kr=2����sigma������2�������ĸҲ���һ��2��
�������¼��㣬ֱ����ԭ����ʽ���ϳ���C(sigma+2,2),��
sigma{ki}!/(k1!*k2!*..*ks!) * (sigma+2)!/(sigma!*2!)    Լ�ּ���
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

const ULL M=(1ULL<<63);
vector<ULL> prime;
bool vis[102];
ULL c[65][65];
map<ULL,ULL> res;

void prime_table(){
    ULL i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=100;i++)
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=100;j+=i)
                vis[j]=1;
        }
}

void comb_table(){
    int i,j;
    for(i=0;i<=62;i++){
        for(j=0;j<=i;j++)
            if(j==0 || j==i)
                c[i][j]=1ULL;
            else if(c[i-1][j]<M && c[i-1][j-1]<M)
                c[i][j]=c[i-1][j]+c[i-1][j-1];
            else c[i][j]=M;
    }
}

/*f(k)=n    res[n]=k
cur ��ǰ������primeָ�룬
k   ��ǰcur�����������������k
n   f(k)=n
sigma   ����(#)ʽ�е�sigma(ki),���sigma��ֵ��˵���Ѿ��������һ��k n��
*/
void dfs(int cur,ULL k,ULL n,int sigma){    //ע��sigma�ĳ�ʼҪ��0��������1
    if(sigma){
        int cnt=res.count(n);
        if(cnt==0 || cnt && k<res[n])
            res[n]=k;
    }
    ULL x=k;
    for(int i=1;prime[cur]<=M/x;i++){       //����k�����������prime[cur]
        x*=prime[cur];
        if(c[sigma+i][i]<=M/n)        //��һ��������(��)����n������Ҫ�ж�n*c[sigma][i]�Ƿ񳬷�Χ
            dfs(cur+1,x,n*c[sigma+i][i],sigma+i);
    }
}

int main()
{
    prime_table();
    comb_table();
    res.clear();
    dfs(0,1,1,0);
    ULL n;
    while(scanf("%llu",&n)!=EOF)
        printf("%llu %llu\n",n,res[n]);
    return 0;
}
