/****************
*PID:uva11491
*Auth:Jonariguez
*****************
̰�Ĳ��ԣ�
���������ҵ�һ���������䣬Ȼ��ɾ���������׸����֣�
Ȼ���Ҳ������������䣬�����������䶼�ǲ����ģ���ô��
ɾ���һ�����֡�
���������ģ��Ļ����϶���ʱ��
���ǿ��Դ�������һ��һ�������ӵ�һ������ʼ�����ڶ�������
�����һ��<�ڶ�������ô��һ���϶�Ҫɾ�ģ���ô���õڶ�����
��һ���ͺ���ıȣ�
�����һ��>�ڶ�����˵�����ڶ�������ɾ��Ҫ����������
���ʱ��>һ����
�ⲻ����ջ��~
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char str[maxn];
int a[maxn],b[maxn],tot;
stack<int> s;

void print(){
    if(s.empty()) return ;
    int x=s.top();s.pop();
    print();
    b[++tot]=x;
}

int main()
{
    int i,j,n,d;
    while(scanf("%d%d",&n,&d)){
        if(n==0 && d==0) break;
        scanf("%s",str+1);
        for(i=1;i<=n;i++)
            a[i]=str[i]-'0';
        for(i=1;i<=n && d;i++){
            if(s.empty())
                s.push(a[i]);
            else {
                while(!s.empty() && d){
                    int x=s.top();
                    if(x<a[i]){
                        s.pop();d--;
                    }else
                        break;
                }
                s.push(a[i]);
            }
        }
        tot=0;
        print();
        for(;i<=n;i++)
            b[++tot]=a[i];
        for(i=1;i<=tot-d;i++)       //���ͨ������ķ�ʽûɾ��d����˵��Ŀǰ���������Ѿ���ȫ���������ˣ�
            printf("%d",b[i]);      //�Ǿ��������dλ
        printf("\n");
    }
    return 0;
}

