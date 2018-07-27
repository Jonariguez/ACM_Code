/****************
*ID:uva12171
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=50+5;
const int maxc=1000+1;

int x0[maxn],y0[maxn],z0[maxn],x1[maxn],y1[maxn],z1[maxn];
int n;

int nx,ny,nz;
int xs[maxn*2],ys[maxn*2],zs[maxn*2];

const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};

int color[maxn*2][maxn*2][maxn*2];

struct Cell{
    int x,y,z;
    Cell(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool valid() const {        //�Ƿ����
        return x>=0 && x<nx-1 && y>=0 && y<ny-1 && z>=0 && z<nz-1;
    }
    bool solid() const {        //�Ƿ��ǳ�������
        return color[x][y][z]==1;
    }
    bool getVis() const {       //��ǣ�����BFS
        return color[x][y][z]==2;
    }
    void setVis() const {
        color[x][y][z]=2;
    }
    Cell neighbor(int dir) const {  //��dir��������
        return Cell(x+dx[dir],y+dy[dir],z+dz[dir]);
    }
    int volume() const {            //����ɢ������
        return (xs[x+1]-xs[x])*(ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
    }
    int area(int dir) const {       //����ÿ���dir�����ƶ����γ�һ�������壬��������ĺ���������ʵ���Ǿ���
        if(dx[dir]!=0) return (ys[y+1]-ys[y])*(zs[z+1]-zs[z]);   //����ɢ����dir�����������
        else if(dy[dir]!=0) return (xs[x+1]-xs[x])*(zs[z+1]-zs[z]);//�ĸ��ᶯ�����ĸ���
        return (xs[x+1]-xs[x])*(ys[y+1]-ys[y]);
    }
};

void discretize(int *x,int &n){
    sort(x,x+n);
    n=unique(x,x+n)-x;
}

int getIndex(int *x,int n,int v){
    return lower_bound(x,x+n,v)-x;
}

void floodfill(int &v,int &s){
    v=s=0;
    Cell c;
    c.setVis();
    queue<Cell> que;
    que.push(c);
    while(!que.empty()){
        Cell c=que.front();que.pop();
        v+=c.volume();
        for(int i=0;i<6;i++){
            Cell t=c.neighbor(i);
            if(!t.valid()) continue;
            if(t.solid())               //color[t]=1,������Ѿ��ǳ����壬�򲻻���չ������que��Ķ���֤�ǡ�������
                s+=c.area(i);       //��Ȼque��Ķ��ǿ�������ô����solid(��������)���Ϳ��Լ���������ע����c��area��
            else if(!t.getVis()){
                t.setVis();
                que.push(t);
            }
        }
    }
    v=maxc*maxc*maxc-v;
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        nx=ny=nz=2;
        xs[0]=ys[0]=zs[0]=0;
        xs[1]=ys[1]=zs[1]=maxc;
        for(i=0;i<n;i++){
            scanf("%d%d%d%d%d%d",&x0[i],&y0[i],&z0[i],&x1[i],&y1[i],&z1[i]);
            x1[i]+=x0[i];y1[i]+=y0[i];z1[i]+=z0[i];
            xs[nx++]=x0[i];xs[nx++]=x1[i];
            ys[ny++]=y0[i];ys[ny++]=y1[i];
            zs[nz++]=z0[i];zs[nz++]=z1[i];
        }
        //��ɢ��
        discretize(xs,nx);
        discretize(ys,ny);
        discretize(zs,nz);

        memset(color,0,sizeof(color));
        for(i=0;i<n;i++){
            int X1=getIndex(xs,nx,x0[i]),X2=getIndex(xs,nx,x1[i]);
            int Y1=getIndex(ys,ny,y0[i]),Y2=getIndex(ys,ny,y1[i]);
            int Z1=getIndex(zs,nz,z0[i]),Z2=getIndex(zs,nz,z1[i]);
            for(int x=X1;x<X2;x++)      //���ܵ�X2
                for(int y=Y1;y<Y2;y++)
                    for(int z=Z1;z<Z2;z++)
                        color[x][y][z]=1;
        }

        int v,s;
        floodfill(v,s);
        printf("%d %d\n",s,v);
    }
    return 0;
}
