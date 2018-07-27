/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int &W){
    int w1,d1,w2,d2,b1,b2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    if(w1==0)
        b1=solve(w1);   //b1,b2ֻ�Ǽ�¼����ֵ�Ƿ�����
    if(w2==0)
        b2=solve(w2);
    W=w1+w2;        //���Ŀǰ��������
    return b1&&b2&&(w1*d1==w2*d2);
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        int w;
        if(solve(w)) printf("YES\n");
        else printf("NO\n");
        if(T)
            printf("\n");
    }
    return 0;
}
