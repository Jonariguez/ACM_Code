/****************
*ID:uva1406
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int Top=1<<16;

/*
bit[b][v]�������ǣ���2^(b+1)ȡ�����v�����ĸ�����
����n����ӳ�䵽bit�У���������Ȼ���ѯʱ��[0,2^(v+1))
ö��i������i����add��ǣ������vλΪ1�����ۼ�bit[v][i],
���һ��ʼ�����n�����е���i��������Ϊx����ô��ʱbit[v][i]
����һ������xԤ����ʱӳ�䵽������res��Ӧ���ۼ�bit[v][i]

bit��������ʵ����hash
*/
int bit[17][Top];

int main()
{
    int i,j,n,a,kcase=1;
    while(scanf("%d",&n)){
        if(n==-1) break;
        memset(bit,0,sizeof(bit));
        for(i=0;i<n;i++){
            scanf("%d",&a);
            for(j=0;j<16;j++)
                bit[j][a%(1<<(j+1))]++;
        }
        long long res=0,add=0;
        char s[3];
        int v;
        while(scanf("%s",s)){
            if(s[0]=='E') break;
            scanf("%d",&v);
            if(s[0]=='C'){
                add+=v;add%=Top;
            }else{
                int remain=add%(1<<(v+1)),Max=(1<<(v+1));
                for(i=0;i<Max;i++)
                    if((remain+i)&(1<<v))
                        res+=bit[v][i];
            }
        }
        printf("Case %d: %lld\n",kcase++,res);
    }
    return 0;
}
