/*
��Ҫע��ľ��������i�������ҵ�����ôi+1����
Ҳ�п������󵹡�
���о�������1,2
*/
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int x[maxn],h[maxn];

int main()
{
    int i,n,res;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&x[i],&h[i]);
    res=1;  //��һ�ÿ϶��ܵ�
    for(i=1;i<n-1;i++){
        if(h[i]<x[i]-x[i-1]){
            res++;
        }
        else if(h[i]<x[i+1]-x[i]){
            x[i]+=h[i];     //������ҵ��Ļ����൱��x[i]������
            res++;
        }
    }
    res++;  //���һ���ÿ϶��ܵ�
    if(n==1 || n==2)
        res=n;
    printf("%d\n",res);
    return 0;
}
