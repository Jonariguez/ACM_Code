/*
�������ڻ��߳�ȡ
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn],last[maxn];

map<int,int> mp;

int main()
{
    int i,j,n,T,s,t,res;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(!mp.count(a[i])) last[i]=-1;     //ע������Ҫ��count��������ֱ����mp[a[i]]��ֵ��ԭ�����0�������
            else last[i]=mp[a[i]];              //�±꣬��ȻҲҲ������mp[]ֵ���жϣ���ѭ����Ӧ��1��ʼ
            mp[a[i]]=i;
        }
        s=t=res=0;
        while(t<n){
            while(t<n && last[t]<s)
                t++;
            res=max(res,t-s);
            s++;
        }
        printf("%d\n",res);
    }
    return 0;
}
