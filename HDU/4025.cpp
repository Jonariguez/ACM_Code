/****************
*PID:hdu4025
*Auth:Jonariguez
*****************
系数矩阵a是二维的，然后把每一列压缩成一个LL型的整数，
压缩成一维，然后dfs暴力前m/2个x解，中途相遇法计算答案。
aij取{0,1}，si取{0,1,2,3}，两者相乘的结果集合为{0,1,2,3}
能够用一个两位的二进制表示。
最多30个式子，共60位二进制，可用long long表示。
1*x1 ^ 1*x2 ^ 0*x3 = 0;
0*x1 ^ 1*x2 ^ 1*x3 = 0;
1*x1 ^ 0*x2 ^ 0*x3 = 0；
第一列为 1 0 1 ，可写为a1 = 11 00 11, 假设x1取2, 则第一列 s1 = 10 10 10, s1&a1 = 10 00 10 即为第一列的状态
第二列 a2 = 11 11 00 设x2 = 1 则 s2 = 01 01 01, 第二列状态为 a2&s2 = 01 01 00
第三列 a3 = 00 11 00 设x3 = 3 则 s3 = 11 11 11, 第三列状态为 a3&s3 = 00 11 00
对每列状态异或 (a1&s1) ^ (a2&s2) ^ (a3&s3) = 11 10 10 !=0，故不为解。
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
