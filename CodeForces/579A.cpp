/****************
*PID:cf579A
*Auth:Jonariguez
*****************
�����ü�����һ����exactly x��,
�������x�Ķ��������м��������1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,x,res;
    while(scanf("%d",&x)!=EOF){
        res=0;
        while(x){
            if(x&1) res++;
            x/=2;
        }
        printf("%d\n",res);
    }
    return 0;
}
