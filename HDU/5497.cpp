/****************
*PID:hdu5497
*Auth:Jonariguez
*****************
Ҫɾ��m���ȵ����䣬��Ϊ���ȹ̶�����ôֻ��ö����㣬Ȼ��ά����
һ��ʼɾ����ͷ��[1,m-1]���䣬���Դ�ʱ���������ֻ������[m,n]�ļ��ɣ�
Ȼ��"m����"����һλ�����ʱ����Ϊ[i,i+m-1],��ô����һλ�����ǣ�
��A[i]����ϣ�A[i+m]ȥ�������£�
[1....i----i+m-1,i+m,~~~~~~n]       (....����Ϊһ��һ����ӵģ���cά����~~~~~~�����Ƿźõ���Ҫһ����ȥ���ģ���d
��nowΪĿǰ�����������
����A[i],�����ӵ��������Ϊ��
��A[i]��ǰ(...����)��A[i]��ģ�   -----------��c BITά��
��A[i+m]�������A[i]С��          -----------��d BITά��
����A[i]:add(c,A[i],1)
ȥ��A[i+m]������ٵ��������Ϊ��
��A[i]����ǰ��A[i+m]���           -----------��c BITά��
��A[i+m]�������A[i+m]С��         -----------��d BITά��
ȥ��A[i+m]:add(d,A[i+m],-1);
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int n,m;
int A[maxn],c[maxn],d[maxn];

void add(int *bit,int i,int v){
    while(i<=n){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int *bit,int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

LL solve(){
    int i,j;
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    LL now=0;
    for(i=n;i>m;i--){
        now+=sum(d,A[i]-1); //ע��������A[i]-1
        add(d,A[i],1);
    }
    LL res=now;
    for(i=1;i+m-1<=n;i++){
        res=min(res,now);
        if(i+m>n) break;
        now+=sum(c,n)-sum(c,A[i])+sum(d,A[i]-1);
        add(c,A[i],1);

        now-=sum(c,n)-sum(c,A[i+m])+sum(d,A[i+m]-1);
        add(d,A[i+m],-1);
    }
    return res;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&A[i]);
        printf("%lld\n",solve());
    }
    return 0;
}
