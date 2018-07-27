#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> str[1004];
string line;
int w[200];

int Max(int x,int y){
    if(x>y) return x;
    return y;
}

void print(string t,int len){
    int i;
    cout<<t;
    for(i=t.length();i<len;i++) printf(" ");
}

int main()
{
    int i,j,k,len;
    string s;
    priority_queue<int> que[200];
    int row=0,maxv=-1;
    while(getline(cin,line)){
        stringstream ss(line);
        int col=0;
        str[row].clear();
        while(ss>>s){
            str[row].push_back(s);
            que[col++].push(s.length());
        }
        maxv=Max(maxv,(int)str[row].size());
        row++;
     //   if(row==4) break;
    }
    for(i=0;i<maxv;i++)
        w[i]=que[i].top();
    for(i=0;i<row;i++){
        for(j=0;j<str[i].size()-1;j++)
            print(str[i][j],w[j]+1);
        cout<<str[i][j]<<endl;
    }
    return 0;

}
/*
lsdfjlsjdf slfj shdf lf;la
asfs l flsdf sssaaa
sfl jfs oooooo
qqqqqo h uiosna almjl
auoujoi sdflafdfa
*/
