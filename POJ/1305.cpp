/****************
*ID:poj1305
*Auth:Jonariguez
*****************
��ԭ�ıϴ����˹��Ԫ��:
x=m^2 - n^2
y=2mn
z=m^2 + n^2
m>n,�һ��أ�����ż�Բ�ͬ

&���鲻ͬ�ı�ԭ��Ԫ��(x1,y1,z1),(x2,y2,z2)
��������ͬ���������в��ܼ򵥵�ÿ���ü�����
+=3�������������������±������
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
bool vis[maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void solve(int t){
    int i,j,n,m,cnt=0;
    memset(vis,0,sizeof(vis));
    for(n=1;n*n<=t;n++){
        for(m=n+1;m*m<=t;m++){
            if(n*n+m*m>t) break;
            if(gcd(n,m)==1 && (n&1)!=(m&1)){    //��������ż�Բ�ͬ
                cnt++;
                int x=m*m-n*n;
                int y=2*m*n;
                int z=m*m+n*n;
                for(i=1;;i++){
                    if(i*z>t) break;
                    vis[i*x]=vis[i*y]=vis[i*z]=1;
                }
            }
        }
    }
    printf("%d ",cnt);
    cnt=0;
    for(i=1;i<=t;i++)
        if(!vis[i]) cnt++;
    printf("%d\n",cnt);
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
        solve(n);
    return 0;
}
