#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int maxn=110;
int A,B,C;
int a,b,vis[maxn][maxn];

typedef struct oper{
	int op,x,y,par;		//op=1 FILL;op=2 DROP;op=3 POUR;
}ope;

ope s[maxn*maxn];

struct sta{
	int t[3];
}st[maxn*maxn];

bool check(sta v){
	return v.t[1]==C || v.t[2]==C;
}

int FILL(int v,int u){
	if(v==1) return A-u;
	return B-u;
}

void DROP(int v){
	(v==1?a:b)=0;
}

void POUR(int v,int u){
	if(v==1){
		if(a<=B-b){
			b+=a;a=0;
		}
		else {
			a-=(B-b);b=B;
		}
	}
	else{
		if(b<=A-a){
			a+=b;b=0;
		}
		else {
			b-=(A-a);a=A;
		}
	}
}

int bfs(){
	int res=0,i;
	memset(vis,0,sizeof(vis));
	a=b=0;
	queue<ope> que;
	sta u;
	u.t[1]=u.t[2]=0;
	que.push(u);
	while(!que.empty()){
		sta u=que.front();
		que.pop();
		for(i=1;i<=2;i++){
			if(FILL(i,u.t[i])){
				sta t;
				t.t

	


	








int main()
{
	int i,res;
	scanf("%d%d%d",&A,&B,&C);	//c==a || c==b