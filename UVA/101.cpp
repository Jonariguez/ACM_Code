/*
STL����(vector)
*/
//�ο�����ѵĴ��뼼��
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int maxn=30;
vector<int> p[maxn];
int n;

//�������õķ�ʽ���ԺܺõĴ�һ�������õ�������ý����������͵õ��˶Ѻ͸߶��������ý����
int getP(int x,int &ph){    //�õ����Ϊx��ľ�����ڵĶѺţ�����ph��¼���ڸ߶�
    int i,j;
    for(i=0;i<n;i++){
        int t=p[i].size();
        for(ph=0;ph<t;ph++)
            if(p[i][ph]==x)
                return i;
    }
}

void Move(int x,int h){     //��x��h�߶����ϵ�ľ���λ
    int i,t;
    for(i=p[x].size()-1;i>h;i--){
        t=p[x][i];
        p[t].push_back(t);
     //   p[x].pop_back();      ���������ﰤ��pop ������ֱ���������resize
    }
    p[x].resize(h+1);       //����0~h�±��Ԫ��
}

void onto(int a,int h,int b){   //��a��h�߶����ϵ�ľ��ŵ�b����
    int i,l1=p[a].size();
    for(i=h;i<l1;i++)
        p[b].push_back(p[a][i]);
  /*  for(i=h;i<l1;i++)         ����һ�����Բ���resize
        p[a].pop_back();*/
    p[a].resize(h);
}

int main()
{
    int i,j,k,a,b;
    char s1[10],s2[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        p[i].push_back(i);
    while(scanf("%s",s1)){
        if(s1[0]=='q') break;
        scanf("%d%s%d",&a,s2,&b);
        int pa,pb,ha,hb;
        pa=getP(a,ha);pb=getP(b,hb);
        if(pa==pb) continue;
        if(strcmp(s1,"move")==0)
            Move(pa,ha);
        if(strcmp(s2,"onto")==0)
            Move(pb,hb);
        onto(pa,ha,pb);
    }
    for(i=0;i<n;i++){
        printf("%d:",i);
        for(j=0;j<p[i].size();j++)
            printf(" %d",p[i][j]);
        printf("\n");
    }
    return 0;
}


