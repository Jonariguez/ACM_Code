/*
CF 552C ����ת��
��Ŀ���⣺����һ����ƽ�����������Ϊw��0~100���ݣ�
ÿ������ֻ��һ����������Է������̻������̡�������
Ʒ������m�����Ƿ���һ�ַ�������ƽ����ƽ��
����˼·����m��Ϊw���ƣ��Ľ�����ֻ����0,1����w-1��
��Ϊw-1��ô�൱������Ʒ���ŵ������һ�����룬Ȼ����
��һ�̼���w�������뼴�ɡ�ֱ��w��������ǰλ��0������
һλ+1���ɡ����w�������Ƿ�������һ��01������

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,flag,m,w,k,bit[40];
    while(scanf("%d%d",&w,&m)!=EOF){
        k=0;flag=1;
        while(m){
            bit[k++]=m%w;
            m/=w;
        }
        for(i=0;i<k;i++){
            if(bit[i]==0 || bit[i]==1) continue;
            if(bit[i]>=w){
                bit[i]-=w;
                bit[i+1]++;
            }
            if(bit[i]==w-1)
                bit[i+1]++;
            else if(bit[i]>1){
                flag=0;break;
            }
        }
        if(flag)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool solve(int w,int m){
    while(m>0){
        int v=m%w;
        if(v==0) m/=w;
        else if(v==1) m=(m-1)/w;
        else if(v==w-1) m=(m+1)/w;
        else return false;
    }
    return true;
}

int main()
{
    int i,j,m,w;
    while(scanf("%d%d",&w,&m)!=EOF){
        if(solve(w,m))
            puts("YES");
        else puts("NO");
    }
    return 0;
}
