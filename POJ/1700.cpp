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

const int maxn=1000+10;
int person[200];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&person[i]);
        if(n==1){
            printf("%d\n",person[1]);continue;
        }
        sort(person+1,person+n+1);      //��n���˹��ӵ�ʱ������person[1]ʱ����̣�person[n]ʱ���
        int res=0;
        while(n>=4)                 //ֻҪʣ�µ��˶��ڵ���4��
        {
            int a,b,x,y;
            a=person[1];b=person[2];x=person[n-1];y=person[n];
            if(2*b<=a+x)            //�õ�һ�ֲ���
                res=res+a+2*b+y;
            else                 //�õڶ��ֲ���
                res=res+2*a+x+y;
            n-=2;       //���������������͹�ȥ�ˣ���ô�������ͼ���2��������һֱѭ��
        }
        if(n==3) //���ʣ3���ˣ�����person[1]��person[3]�͹�ȥ��Ȼ��person[1]���������person[1]��person[2]һ���ȥ
            res+=person[1]+person[2]+person[3];
        else if(n==2)       //ʣ�����˵Ļ���һ���ȥ
            res+=person[2];
        printf("%d\n",res);
    }
}
