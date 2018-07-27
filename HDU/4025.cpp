/****************
*PID:hdu4025
*Auth:Jonariguez
*****************
ϵ������a�Ƕ�ά�ģ�Ȼ���ÿһ��ѹ����һ��LL�͵�������
ѹ����һά��Ȼ��dfs����ǰm/2��x�⣬��;����������𰸡�
aijȡ{0,1}��siȡ{0,1,2,3}��������˵Ľ������Ϊ{0,1,2,3}
�ܹ���һ����λ�Ķ����Ʊ�ʾ��
���30��ʽ�ӣ���60λ�����ƣ�����long long��ʾ��
1*x1 ^ 1*x2 ^ 0*x3 = 0;
0*x1 ^ 1*x2 ^ 1*x3 = 0;
1*x1 ^ 0*x2 ^ 0*x3 = 0��
��һ��Ϊ 1 0 1 ����дΪa1 = 11 00 11, ����x1ȡ2, ���һ�� s1 = 10 10 10, s1&a1 = 10 00 10 ��Ϊ��һ�е�״̬
�ڶ��� a2 = 11 11 00 ��x2 = 1 �� s2 = 01 01 01, �ڶ���״̬Ϊ a2&s2 = 01 01 00
������ a3 = 00 11 00 ��x3 = 3 �� s3 = 11 11 11, ������״̬Ϊ a3&s3 = 00 11 00
��ÿ��״̬��� (a1&s1) ^ (a2&s2) ^ (a3&s3) = 11 10 10 !=0���ʲ�Ϊ�⡣
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=35;
vector<LL> S[maxn];
map<LL,LL> Hash;
LL a[maxn],x[maxn],m,n,st,en,res;

void dfs(LL cur,LL stop,LL now,int f){
    LL i;
    if(cur>stop){
        if(f)
            Hash[now]++;
        else res+=Hash[now];
        return ;
    }
    for(i=0;i<S[cur].size();i++){
        LL v=S[cur][i];
        LL temp=v&a[cur];
        dfs(cur+1,stop,now^temp,f);
    }
}

int main()
{
    LL i,j,T;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&m);
        Hash.clear();
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                LL te;
                scanf("%I64d",&te);
                if(te)
                    a[j]|=(3LL<<(2*(i-1)));
            }
        }
        for(i=1;i<=m;i++){
            int k;
            S[i].clear();
            scanf("%d",&k);
            while(k--){
                LL u,temp=0;
                scanf("%I64d",&u);
                for(LL z=0;z<n;z++)
                    temp|=(u<<(2*z));
                S[i].push_back(temp);
            }
        }
        res=0;
        dfs(1,m/2,0,1);
        dfs(m/2+1,m,0,0);
        printf("%I64d\n",res);
    }
    return 0;
}
