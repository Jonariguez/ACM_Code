/*
n������
���ȥ��������ͬ��Ԫ�أ���ôԭ���е�
��Ԫ��������������Ȼ�Ƕ�Ԫ�ء�
������res��¼����cnt��¼��res��ȵĸ�����
��������res��ȵ�cnt++������cnt--��
cnt=0ʱΪres���¸��ơ� ���res���Ǵ�
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int i,n,res,cnt,x;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(cnt==0){
                res=x;cnt++;
            }else if(res==x)
                cnt++;
            else if(res!=x) cnt--;
        }
        printf("%d\n",res);
    }
    return 0;
}
