/*
����'.'����\/����ͼ�2������\��/�ͼ�1
ͨ��bool��yes���ж�������'.'�Ƿ���\/����

�������϶�������������\��/�Ǽ�0.5�ģ�
��������һ��ʼ�ۼӵ�ʱ�򰴳�2�㣬�����/2
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxw=110;
char a[maxw][maxw];

int main()
{
    int i,j,h,w,res;
    while(scanf("%d%d",&h,&w)!=EOF){
        for(i=1;i<=h;i++)
            for(j=1;j<=w;j++)
                scanf(" %c",&a[i][j]);
        res=0;
        for(i=1;i<=h;i++){
            bool yes=false;
            for(j=1;j<=w;j++){
                if(a[i][j]=='.' && yes)
                    res+=2;
                if(a[i][j]!='.'){
                    res++;
                    yes=!yes;
                }
            }
        }
        printf("%d\n",res/2);
    }
    return 0;
}
