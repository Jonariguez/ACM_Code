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
void dfs(LL u,LL d,LL sum){     //sumά�������Ե�ǰ�ڵ�uΪ���������Ľڵ����
    a[cnt++]=sum;           //ֱ�Ӵ���sum���ɣ���ô��u���ֵܽڵ�Ϊ������ô����أ�������
    if(u==1) return ;
    LL x;                 //u&1˵���Ǹ��׽ڵ���Һ���
    if(u&1)                 //���u���Һ��ӣ��������ֵ���һ������������������height-d+1 (x)
        x=height-d+1;
    else x=height-d;      //���u�����ӣ��������ֵ���һ������������������height-d  (x)
    cal(x);             //��uΪ���ڵ�������Ľڵ������sum����ô��u���ֵܽڵ�Ϊ���ڵ�������Ľڵ������cal(����)��
    dfs(u/2,d-1,sum+(1LL<<x));
}
����һ��sum+(1<<x)������֪��size(u)=sum,���������ϵݹ�ģ���v��u�ĸ��ף�������
���ϵݹ鵽vʱ����ʱӦ��size(v)=sum(u)+sum(p)+1; ����֪sum(p)=2^x(����)-1,��ôsum(p)+1ǡ�õ���2^x
