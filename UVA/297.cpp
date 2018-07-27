/****************
*ID:uva297
*Auth:Jonariguez
*****************
�ķ���������������о���ȷ��һ������
����������ɫ�����µݹ飬������ɫ���ڸû�����
ͳ�ƺ�ɫ��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int len=32;   //��������32*32��С������
const int maxn=1024+10;

int buf[33][33],cnt;
char s[maxn];


//��s[p..]�������ԣ�r��c��Ϊ���Ͻǣ��߳�Ϊw�Ļ�������
void draw(const char* s,int& p,int r,int c,int w){
    char ch=s[p++];
    if(ch=='p'){
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }else if(ch=='f'){
        for(int i=r;i<r+w;i++)
            for(int j=c;j<c+w;j++)
                if(buf[i][j]==0){
                    buf[i][j]=1;cnt++;
                }
    }
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        memset(buf,0,sizeof(buf));
        cnt=0;
        for(i=0;i<2;i++){
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}
