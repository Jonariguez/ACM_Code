/****************
*PID:
*Auth:Jonariguez
*****************
���Ȱ��ս�ֹʱ����Ⱥ����򡣶���������������a��b��
���a�Ľ�ֹʱ����b֮ǰ����a�ļӹ�ʱ���b������ô
������a������ȻҪ����b�������������أ����b�ļӹ�
ʱ�䳬���˽�ֹʱ�䣬��ô����֮ǰ�Ķ�����ɾ���ӹ�ʱ
������Ǹ��������������ܵĶ�����û�б仯�����ܵļӹ�ʱ��
����ˣ�Ϊ�Ժ���ܸ��ඩ����׼����
��Ҫ�ܾ�һЩ�����ģ����������ȶ���ά��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=800000+10;

struct pp{
    int need,due;
    pp(int n=0,int d=0):need(n),due(d){}
    bool operator < (const pp &rhs) const {     //����<�ţ�������sort��priority_queue�����෴
        if(due==rhs.due)
            return need<rhs.need;
        return due<rhs.due;
    };
}s[maxn];

int main()
{
    int i,j,T,res,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&s[i].need,&s[i].due);
        }
        sort(s,s+n);
        priority_queue<int> pq;
        int now=0;
        res=0;
        for(i=0;i<n;i++){
            pq.push(s[i].need);
            now+=s[i].need;
            if(now>s[i].due){
                now-=pq.top();
                pq.pop();
            }
        }
        printf("%d\n",(int)pq.size());
        if(T)
            printf("\n");
    }
    return 0;
}
