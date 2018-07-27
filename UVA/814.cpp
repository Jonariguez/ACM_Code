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
        cin>>s>>k;              //s��MTA���࣬k�Ǹ����û��ĸ���
        while(k--){
            cin>>t;
            addr.insert(t+"@"+s);   //ֱ�ӱ��user&mta�ĸ�ʽ
        }
    }

    while(cin>>s && s!="*"){
        parse_add(s,user1,mta1);        //�������˵�ַ

        vector<string> mta;             //������Ҫ���ӵ�mta
        map<string,vector<string> > dest;   //ÿ��mta��Ҫ���͵��û�
        set<string> vis;                //�����ظ����ռ���

        while(cin>>t && t!="*"){
            parse_add(t,user2,mta2);        //�����ռ��˵�ַ
            if(vis.count(t)) continue;
            vis.insert(t);
            if(!dest.count(mta2)){
                mta.push_back(mta2);
                dest[mta2]=vector<string>();
            }
            dest[mta2].push_back(t);
        }

        getline(cin,t);  //�Իس�

        //��������
        string data;
        while(getline(cin,t) && t[0]!='*')
            data+="     "+t+"\n";

        for(i=0;i<mta.size();i++){
            string mta2=mta[i];
            vector<string> users=dest[mta2];        //��dest�и���mtaȡ����Ӧ���û�
            cout<<"Connection between "<<mta1<<" and "<<mta2<<endl;     //mta1�Ƿ����˵�ַ
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
