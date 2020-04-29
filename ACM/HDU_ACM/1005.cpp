#include <iostream>
using namespace std;

int main(){
	int A,B,n;
	cin>>A>>B>>n;
	while(A != 0 && B != 0 && n != 0){
		/*if(n == 1){
			cout<<1<<endl;
		}else if(n == 2){
			cout<<1<<endl;
		}else{
			int a = 1, b = 1;
			for(int i = 3; i <= n; i++){
				int tmp = (A * b + B * a) % 7;
				a = b;
				b = tmp;
			}
			cout<<b<<endl;
		}*/
		int queue[49];
		for(int i = 0; i < 49; i++)
			queue[i] = 0;
		queue[0] = 1;
		queue[1] = 1;
		for(int i = 2; i < 49; i++)
			queue[i] = (A * queue[i-1] + B * queue[i-2]) % 7;
		cout<<queue[(n - 1) % 49]<<endl;
		cin>>A>>B>>n; 
	} 
	return 0;
}
