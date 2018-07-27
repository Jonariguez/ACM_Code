/*
step[i]��ʾn�������ܹ����i�õ��ܲ����������е�����ô��Ŭ���ܱ��i��
cnt[i]��ʾ�ľ���n������ܹ����i�����ĸ�����
���Ա���cnt[i]==n��step[i]��ȡ��Сֵ

ע�⣺һ���������ڳ�2�Ĺ����У���ֹһ�ε��������������������50->25->12->6->3
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn],step[maxn*2],cnt[maxn*2];

int main()
{
    int i,j,x,y,d,n,maxv;
    while(scanf("%d",&n)!=EOF){
        maxv=-1;
        memset(step,0,sizeof(step));
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
            maxv=max(maxv,a[i]);
        }
        for(i=0;i<n;i++){
            x=a[i];
            int c=0;
            while(x<=maxv){
                x*=2;
                c++;
                step[x]+=c;
                cnt[x]++;
            }
            x=a[i];c=0;
            while(x){
                if(x&1 && x!=1){
                    x/=2;
                    c++;
                    step[x]+=c;
                    cnt[x]++;
                    int t=x,y=c;
                    while(t<=maxv){
                        t*=2;
                        y++;
                        step[t]+=y;
                        cnt[t]++;
                    }
                }
                else {
                    x/=2;
                    c++;
                    step[x]+=c;
                    cnt[x]++;
                }
            }
        }
        int res=-1;
        for(i=1;i<=maxv;i++)
            if(cnt[i]==n && (res==-1 || res>step[i]))
                res=step[i];
        printf("%d\n",res);
    }
    return 0;
}
