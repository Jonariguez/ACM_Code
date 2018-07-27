/****************
*PID:uva11729
*Auth:Jonariguez
*****************
̰�ģ� J����Ȱ���
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;

struct pp{
    int B,J;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.J>y.J;
}

int main()
{
    int i,j,n,res,kcase=1;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].B,&s[i].J);
        sort(s,s+n,cmp);
        int now=0;
        res=0;
        for(i=0;i<n;i++){
            now+=s[i].B;            //now����Ŀǰ��������ʱ��
            res=max(res,now+s[i].J);    //res����Ŀǰ�ı����ʲôʱ�����
        }
        printf("Case %d: %d\n",kcase++,res);
    }
    return 0;
}
