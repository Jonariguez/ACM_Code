/****************
*PID:poj1012
*Auth:Jonariguez
*****************
������˵˵m��ȡֵ��Χ�����ǿ���һ��ֻʣ��k+1����ʱ��
����������˻���һ��δ����������ô����һ���н���λ��
�ض������һ�����ˣ���ô��ʼλ�������أ������Ҫ��K+2��
�˵Ľ���λ�ã�Ȼ��K+2���˵Ľ���λ�ñض��ǵ�K+2���˻���
��K+1���ˣ������ͳ�������˳�������GGGG.....GGGXB ��
GGGG......GGGBX (X��ʾ��K+2���˵���һ���˳����ˣ�������
K+1���˵���һ�ֵĿ�ʼλ�������ֿ��ܼ���һ��λ�û�K+1��
�Ǹ�λ�ã��޶�m�����ֿ��ܣ�t(k+1) �� t(k+1)+1; t>=1;

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int k,Joseph[15]={0};

bool judge(int m){
    int i,n=k*2,f=0;
    for(i=0;i<k;i++){
        f=(f+m-1)%(n-i);    //֮����m-1������Ϊ��Ŵ�0��ʼ����m����m-1�ţ�m-1�ű�ɱ���������Ǹ�ǰ�Ƶ�m-1��
        if(f<k)                                                          //�ʿ�ʼ��λ�û���m-1�ţ���ȻҪ��%(n-i)
            return false;
    }
    return true;
}


int main()
{
    int i,j,m;
    for(k=1;k<14;k++){
        int t=k+1;
        while(1){
            if(judge(t)){
                Joseph[k]=t;
                break;
            }else if(judge(t+1)){
                Joseph[k]=t+1;
                break;
            }
            t+=k+1;
        }
    }
    while(scanf("%d",&k),k)
        printf("%d\n",Joseph[k]);
    return 0;
}

