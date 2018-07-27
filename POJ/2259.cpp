/*
��һ������que1ά�������ŶӵĶ��������(��Ϊ
ͬһ��������˻�������һ��)
Ȼ����һ����������que2����Ϊÿһ�����鿪һ��
���У�ά���ö�����ÿ����Ա��˳��
����ʱ��ͨ������ҵ�������������t�����ж�que1
���Ƿ���t���У���que2[t]��׷�Ӵ��˱�ţ�û�У�
����que1��׷��t,��que2[t]��׷�Ӵ��˱�š�
�����ж�que1������t��������Ҫʲôӳ�䣬ֻ��
�ж�que2[t]�Ƿ�Ϊ�ռ���
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int maxt=1000+10;
queue<int> que1,que2[maxt];
short team[1000000];

int main()
{
    int i,j,n,kcase=1;
    char s[20];
    while(scanf("%d",&n),n){
        printf("Scenario #%d\n",kcase++);
        while(!que1.empty()) que1.pop();
        for(i=1;i<=n;i++){
            while(!que2[i].empty())
                que2[i].pop();
            int k,x;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);team[x]=i;
            }
        }
        while(scanf("%s",s)){
            if(s[0]=='S') break;
            if(s[0]=='E'){
                int x;
                scanf("%d",&x);
                if(que2[team[x]].empty())
                    que1.push(team[x]);
                que2[team[x]].push(x);
            }else {
                int t=que1.front();
                printf("%d\n",que2[t].front());
                que2[t].pop();
                if(que2[t].empty())
                    que1.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
