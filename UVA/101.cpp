/*
STL运用(vector)
*/
//参考刘汝佳的代码技巧
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int maxn=30;
vector<int> p[maxn];
int n;

//采用引用的方式可以很好的从一个函数得到多个有用结果！！这里就得到了堆和高度两个有用结果！
int getP(int x,int &ph){    //得到编号为x的木块所在的堆号，引用ph记录所在高度
    int i,j;
    for(i=0;i<n;i++){
        int t=p[i].size();
        for(ph=0;ph<t;ph++)
            if(p[i][ph]==x)
                return i;
    }
}

void Move(int x,int h){     //将x堆h高度以上的木块归位
    int i,t;
    for(i=p[x].size()-1;i>h;i--){
        t=p[x][i];
        p[t].push_back(t);
     //   p[x].pop_back();      不用在这里挨个pop ，可以直接用下面的resize
    }
    p[x].resize(h+1);       //保留0~h下标的元素
}

void onto(int a,int h,int b){   //将a堆h高度以上的木块放到b堆上
    int i,l1=p[a].size();
    for(i=h;i<l1;i++)
        p[b].push_back(p[a][i]);
  /*  for(i=h;i<l1;i++)         这里一样可以采用resize
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


