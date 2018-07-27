/****************
*PID:poj2376
*Auth:Jonariguez
*****************
̰��
�Ȱ��ŵ�һ��ţ��Ȼ������һ������Ŀǰ��Χ��ţ����ʱ
�ҵ�֮ǰ�Ľ�������ţ�������ȶ���ά����������
�Ӳ������޽�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=25000+10;
struct pp{
    int x,y;
    bool operator < (const pp &r) const {
        return y<r.y;
    }
}s[maxn];

int cmp(const pp &a,const pp &b){
   // if(a.x==b.x)
   //     return a.y>b.y;
    return a.x<b.x;
}

int main()
{
    int i,j,res,n,T;
    scanf("%d%d",&n,&T);
    for(i=0;i<n;i++)
        scanf("%d%d",&s[i].x,&s[i].y);
    sort(s,s+n,cmp);
  //  for(i=0;i<n;i++)
  //      printf("%d %d\n",s[i].x,s[i].y);
    priority_queue<pp> que;
    if(s[0].x!=1){          //��С�Ĳ�����1��ʼ�����޽�
        printf("-1\n");return 0;
    }
    res=1;
    int now=s[0].y; //��ѡ��һ��
    int flag=1;
    for(i=1;i<n;i++){
        if(s[i].x<=now+1)       //������һ��ţ�ķ�Χ�ڻ�����һ��
            que.push(s[i]);
        else {
            pp u;
            if(que.empty()){    //�м���Ҫţʱ��û��ţ���޽�
                flag=0;break;
            }
            u=que.top();que.pop();
            if(u.y<s[i].x-1){
                flag=0;break;
            }
            now=u.y;
            que.push(s[i]);
            res++;
        }
    }
    if(!flag)
        printf("-1\n");
    else {
        if(now!=T){
            if(que.empty()) printf("-1\n");     //���û�ܴﵽ������޽�
            else {
                pp u=que.top();
                if(u.y!=T) printf("-1\n");      //����֮���Բ������޽�
                else printf("%d\n",res+1);
            }
        }else printf("%d\n",res);
    }
    return 0;
}
