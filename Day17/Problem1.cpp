#include <bits/stdc++.h>
using namespace std;

int A,B,C;

int combo(int b){
	if(b<=3) return b;
    else if(b==4) return A;
    else if(b==5) return B;
    return C;
}

int main(){
	string p,q,r,s;
	getline(cin,p);
	getline(cin,q);
	getline(cin,r);
	cin.ignore();
	getline(cin,s);

	A=stoi(p.substr(12));
	B=stoi(q.substr(12));
	C=stoi(r.substr(12));

	vector<int> opr;
	for(int i=9;i<s.size();i+=2) opr.push_back(s[i]-'0');

	int ip=0,n=opr.size();

	while(ip < n) {
	    int a = opr[ip], b = opr[ip + 1];

	    if(a == 0) {
	        int m=combo(b);       
	        int div=pow(2,m);
	        A = A / div;
	    }

	    else if(a == 1) B = B ^ b;
	    else if(a == 2) B=combo(b)%8;

	    else if(a == 3) {
	        if(A != 0) {
	            ip = b;
	            continue;
	        }
	    }
	    else if(a == 4) B = B ^ C;

	    else if(a == 5) {
	        int val=combo(b)%8;
	        cout << val <<"," ;
	    }
	    else if(a == 6) {
	        int m=combo(b);       
	        int div=pow(2,m);
	        B = A / div;
	    }
	    else if(a == 7) {
	        int m=combo(b);       
	        int div=pow(2,m);
	        C = A / div;
	    }
	    ip += 2;
	}

	return 0;
}


