/*
˵���˾��ǿ���ݹ顣
��д�ĺ�LRJ��ķ���û�뵽����ô���ƣ�˵���Ҹ���
���뷨����һ���ɡ�
�ٴθ�̾�����βεĴ���ַ��ʽ����ȷʵ���ó���д
�ź������
����������˼����ǣ���ÿһ�㣬�ݹ�(�����Ҫ
�Ļ�)������left���ұ�right�����أ�Ȼ���жϵ�ǰ
���Ƿ�ƽ�⡣
(��Ȼ˼��ʹ��붼��࣬�͸������ļ�һ������)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

bool yes;
ll sum_left,sum_right;

void solve(ll &weight){
    ll w1,d1,w2,d2;
    scanf("%lld%lld%lld%lld",&w1,&d1,&w2,&d2);
    if(!w1) solve(w1);    //������������������ݹ���һ�ߵ�������
    if(!w2) solve(w2);
    if(w1*d1!=w2*d2)
        yes=false;
    weight+=w1+w2; //Ȼ������������ȫ���ش���weigh
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        yes=true;
        ll W;
        solve(W);       //��ʵ���W��û�õģ�������Ҳֻ��Ϊ�˵���solve�����и����βΡ��ɴ�
        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
        if(T)
            printf("\n");
    }
    return 0;
}
