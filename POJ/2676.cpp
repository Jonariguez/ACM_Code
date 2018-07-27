#include <stdio.h>
#include <string.h>

const int maxn=10;
bool flag;
int map[maxn][maxn];
int row[maxn][maxn];
int col[maxn][maxn];
int grid[maxn][maxn];

int cal(int i,int j){
	return 3*((i-1)/3)+(j-1)/3+1;
}

void print(){
	int i,j;
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++)
			printf("%d",map[i][j]);
		printf("\n");
	}
}

void dfs(int x,int y){
	if(flag) return ;
	if(x==10){		
		print();
		flag=true;
		return ;
	}
	if(map[x][y]!=0){		//如果不为0，说明已填数，直接跳过
		if(y<9)
			dfs(x,y+1);
		else
			dfs(x+1,1);
		return ;
	}
	int v;
	for(v=1;v<=9;v++){		// 遍历1~9，
		int t=cal(x,y);
		if(!row[x][v] && !col[y][v] && !grid[t][v]){		//然后行、列、块都没用过v,则填入
			row[x][v]=1;col[y][v]=1;grid[t][v]=1;map[x][y]=v;
			if(y<9)
				dfs(x,y+1);
			else
				dfs(x+1,1);
			row[x][v]=0;col[y][v]=0;grid[t][v]=0;map[x][y]=0;		//回溯
		}
	}
}


int main()
{
	int i,T,j,k;
	scanf("%d",&T);
	while(T--){
		char c;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(grid,0,sizeof(grid));
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++){
				scanf(" %c",&c);
				int t=c-'0';
				map[i][j]=t;
				if(t!=0){
					row[i][t]=1;
					col[j][t]=1;
					grid[cal(i,j)][t]=1;
				}
			}

		flag=false;
		dfs(1,1);
	}
	return 0;
}
		
