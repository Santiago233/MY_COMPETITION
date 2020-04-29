#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i = 0; i < T; i++){
		string A, B, re;
		cin>>A>>B;
		string oldA = A, oldB = B;
		if(A.length() < B.length()){
			string tmp = "";
			for(int j = 0; j < A.length(); j++)
				tmp = tmp + A[j];
			//cout<<tmp<<endl;
			A = "";
			for(int j = 0; j < B.length(); j++)
				A = A + B[j];
			//cout<<A<<endl;
			B = "";
			for(int j = 0; j < tmp.length(); j++)
				B = B + tmp[j];
		}
		string newB = B;
		for(int k = 0; k < (A.length()-B.length()); k++)
			newB = "0" + newB;
		int C = 0;
		for(int k = A.length() - 1; k >= 0; k--){
			int number = int(A[k]) + int(newB[k]) + C - 48 * 2;
			if(number < 10){
				C = 0;
				re = char(number + 48) + re;
			} else{
				C = 1;
				re = char(number - 10 + 48) + re;
			}
		}
		if(C == 1)
			re = "1" + re;
		cout<<"Case "<<(i+1)<<":"<<endl<<oldA<<" + "<<oldB<<" = "<<re<<endl;
		if(i != T - 1)
			cout<<endl; 
	} 
} 
