/****************
*PID:
*Auth:Jonariguez
*****************
�ƻ�Ϊ����Ȼ��������������У��ֱ�̰�������٣�res�������ټ��𰸡�
�ƻ�Ҫö��ÿ�����ơ���λ�á�
̰�ľ���ֱ�Ӱ�1����λ��1����2����λ��2����
��֤���������ţ���Ϊ������ֱ�ӵġ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int n,a[maxn];
int s1[maxn],s2[maxn];

int solve(int *s){
    int i,j,t,res=0;
    for(i=0;i<n;i++){
        if(s[i]==i+1)
            continue;
        for(j=i;j<n;j++)
            if(s[j]==i+1) break;
        t=s[i];s[i]=s[j];s[j]=t;
        res++;
    }
    return res;
}

int main()
{
    int i,j,p;
    while(scanf("%d",&n),n){
        int p;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int res=1000;
        for(p=0;p<n;p++){
            int cnt=0;
            for(i=p,j=p;cnt<n;i++,j--,cnt++){
                s1[cnt]=a[i%n];
                s2[cnt]=a[(j%n+n)%n];
            }
            res=min(res,min(solve(s1),solve(s2)));
        }
        printf("%d\n",res);
    }
    return 0;
}
