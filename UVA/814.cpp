/****************
*ID:uva814
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void parse_add(const string& s,string& user,string& mta){
    int k=s.find('@');
    user=s.substr(0,k);
    mta=s.substr(k+1);
}

int main()
{
    int i,j,k;
    string s,t,user1,mta1,user2,mta2;
    set<string> addr;

    while(cin>>s && s!="*"){
        cin>>s>>k;              //s是MTA种类，k是该种用户的个数
        while(k--){
            cin>>t;
            addr.insert(t+"@"+s);   //直接变成user&mta的格式
        }
    }

    while(cin>>s && s!="*"){
        parse_add(s,user1,mta1);        //处理发件人地址

        vector<string> mta;             //所有需要连接的mta
        map<string,vector<string> > dest;   //每个mta需要发送的用户
        set<string> vis;                //处理重复的收件人

        while(cin>>t && t!="*"){
            parse_add(t,user2,mta2);        //处理收件人地址
            if(vis.count(t)) continue;
            vis.insert(t);
            if(!dest.count(mta2)){
                mta.push_back(mta2);
                dest[mta2]=vector<string>();
            }
            dest[mta2].push_back(t);
        }

        getline(cin,t);  //吃回车

        //输入正文
        string data;
        while(getline(cin,t) && t[0]!='*')
            data+="     "+t+"\n";

        for(i=0;i<mta.size();i++){
            string mta2=mta[i];
            vector<string> users=dest[mta2];        //从dest中根据mta取出对应的用户
            cout<<"Connection between "<<mta1<<" and "<<mta2<<endl;     //mta1是发件人地址
            cout<<"     HELO "<<mta1<<"\n";
            cout<<"     250\n";
            cout<<"     MAIL FROM:<"<<s<<">\n";
            cout<<"     250\n";
            bool ok=false;
            for(j=0;j<users.size();j++){
                cout<<"     RCPT TO:<"<<users[j]<<">\n";
                if(addr.count(users[j])){
                    ok=true;cout<<"     250\n";
                }
                else cout<<"     550\n";
            }
            if(ok){
                cout<<"     DATA\n";
                cout<<"     354\n";
                cout<<data;
                cout<<"     .\n";
                cout<<"     250\n";
            }
            cout<<"     QUIT\n";cout<<"     221\n";
        }
    }
    return 0;
}
