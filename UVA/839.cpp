/*
˵���˾��ǿ���ݹ顣
��д�ĺ�LRJ��ķ���û�뵽����ô���ƣ�˵���Ҹ���
���뷨����һ���ɡ�
�ٴθ�̾�����βεĴ���ַ��ʽ����ȷʵ���ó���д
�ź������
����������˼����ǣ���ÿһ�㣬�ݹ�(�����Ҫ
�Ļ�)������left���ұ�right�����أ�Ȼ���жϵ�ǰ
���Ƿ�ƽ�⡣
�����������д������棬��û�кܺõļ򻯴���
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

bool yes;
ll sum_left,sum_right;

void dfs(ll &weight){
    ll w1,d1,w2,d2;
    scanf("%lld%lld%lld%lld",&w1,&d1,&w2,&d2);
    ll left=0,right=0;
    if(w1 && w2){       //Ҷ�ӽڵ��ֱ���ж��Ƿ�ƽ��
        left=w1;right=w2;
    }else if(w1==0 && w2){    //����������Ҫ�ݹ飬��ô�ұ߾���w2�������ʱ��sum_left����ȥ���㼴��
        right=w2;
        dfs(left);      //�ݹ�õ���ߵ�ȫ��������Ȼ���ж�
    }else if(w2==0 && w1){
        left=w1;
        dfs(right);
    }else if(w1==0 && w2==0){
        dfs(left);
        dfs(right);
    }
    if(left*d1!=right*d2)
        yes=false;
    weight+=left+right; //Ȼ������������ȫ���ش���weigh
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        yes=true;
        sum_left=sum_right=0;
        ll w1,d1,w2,d2;
        scanf("%lld%lld%lld%lld",&w1,&d1,&w2,&d2);
        if(w1 && w2){
            sum_left=w1;
            sum_right=w2;
        }else if(w1==0 && w2){
            sum_right=w2;
            dfs(sum_left);
        }else if(w2==0 && w1){
            sum_left=w1;
            dfs(sum_right);
        }if(w1==0 && w2==0){
            dfs(sum_left);
            dfs(sum_right);
        }
        if(yes && sum_left*d1==sum_right*d2)    //�����˻����ж�yes
            printf("YES\n");
        else
            printf("NO\n");
        if(T)
            printf("\n");
    }
    return 0;
}
