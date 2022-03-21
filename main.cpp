#include <bits/stdc++.h>
 
using namespace std;
int s=0;
vector<int> t;
int solve(int ind,int pv){
    if(ind>=0){
        if(t[ind]+pv<=s/2+s%2){
            return solve(ind-1,t[ind]+pv);
        }else{
            return solve(ind-1,pv);
        }
    }else{
        if(pv==s/2){
            return pv;
        }
        return 0;
    }
}
int main()
{
 
    string ch;
    getline(cin,ch);
 
    ch=ch+" ";
    int pos=0;
    string token;
    while ((pos = ch.find(" ")) != string::npos) {
        token = ch.substr(0, pos);
       // cout << token << endl;
        ch.erase(0, pos +1);
        if(token!=" "){
            stringstream monta(token);
            int p=0;
            monta>>p;
            t.push_back(p);
        }
    }
    sort(t.begin(),t.end());
 
    for(int i=0;i<t.size();i++){
        //cout<<t[i]<<" ";
        s+=t[i];
    }//cout<<'\n';
    if(s%2==0)
        solve(t.size()-1,0)==s/2+0?cout<<"YES":cout<<"NO";
    else{
        solve(t.size()-1,0)==s/2+1?cout<<"YES":cout<<"NO";
    }
    return 0;
}
