#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=20000+10;
int sum[MAX<<2];//ͳ���µױ��ܳ���
int segnum[MAX<<2];//ͳ��û�б����ǵ����߸���
bool lseg[MAX<<2],rseg[MAX<<2];//��ʾĳ����������ߺ����ұ��Ƿ����µױ߶����ϵױ�
int mark[MAX<<2];//��ʾ�µױ߱��ϵױ߶�ĸ���

struct seg{
    int l,r,h,d;
    seg(){}
    seg(int x1,int x2,int H,int c):l(x1),r(x2),h(H),d(c){}
    bool operator <(const seg&a)const{
        if(h == a.h)return d>a.d;//����һ������ȥ��,������������:2 0 0 4 4 0 4 4 8
        return h<a.h;
    }
}s[MAX];

void Upfather(int n,int left,int right){
    if(mark[n]){
        sum[n]=right-left+1;
        lseg[n]=rseg[n]=true;
        segnum[n]=2;//�����䱻һ���ױ�ȫ������,��������Ϊ2
    }
    else if(left == right)sum[n]=lseg[n]=rseg[n]=segnum[n]=0;
    else{
        sum[n]=sum[n<<1]+sum[n<<1|1];
        segnum[n]=segnum[n<<1]+segnum[n<<1|1];
        lseg[n]=lseg[n<<1];
        rseg[n]=rseg[n<<1|1];
        if(rseg[n<<1] && lseg[n<<1|1])segnum[n]-=2;//���������ཻ(�ױ��������غ�)�������������
    }
}

void Update(int L,int R,int d,int n,int left,int right){
    if(L<=left && right<=R){
        mark[n]+=d;
        Upfather(n,left,right);
        return;
    }
    int mid=left+right>>1;
    if(L<=mid)Update(L,R,d,n<<1,left,mid);
    if(R>mid)Update(L,R,d,n<<1|1,mid+1,right);
    Upfather(n,left,right);
}

int main(){
    int n,x1,x2,y1,y2;
    while(cin>>n){
        int k=0,left=INF,right=-INF;
        for(int i=0;i<n;++i){
            cin>>x1>>y1>>x2>>y2;
            s[k++]=seg(x1,x2,y1,1);
            s[k++]=seg(x1,x2,y2,-1);
            left=min(left,x1);
            right=max(right,x2);
        }
        sort(s,s+k);
        int ans=0,last=0;
        for(int i=0;i<k;++i){
            if(s[i].l<s[i].r)Update(s[i].l,s[i].r-1,s[i].d,1,left,right);
            ans+=segnum[1]*(s[i+1].h-s[i].h);//�������ӵ��ܳ�
            ans+=abs(sum[1]-last);//�ױ����ӵ��ܳ�
            last=sum[1];
        }
        printf("%d\n",ans);
    }
}
