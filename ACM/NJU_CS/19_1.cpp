/*题目：求集合[n,m]中满足每位数字与相邻数字均相差1且不是一位数的整数个数*/ 

#include <iostream>
using namespace std;

void func1(int n, int m){
	int count = 0;
	for(int i = n; i <= m; i++){
		int x[10];
		for(int j = 0; j < 10 ; j++)
			x[j] = -1;
		int num = i;
		int no = 0;
		while(num != 0){
			x[no] = num % 10;
			num = num / 10;
			no ++;
		}
		int len = 0;
		for(int j = 0; j < 10; j++){
			if(x[j] != -1){
				len ++;
			}
		}
		if(len == 1){
			continue;
		}
		if(x[0] != x[1] + 1 && x[0] != x[1] - 1){
			continue;
		}
		if(x[len - 1] != x[len - 2] + 1 && x[len - 1] != x[len - 2] - 1){
			continue;
		}
		int flag = 0;
		for(int j = 1; j <= len -2; j++){
			if(x[j] != x[j - 1] + 1 && x[j] != x[j - 1] - 1){
				flag = 1;
				continue;
			}
			if(x[j] != x[j + 1] + 1 && x[j] != x[j + 1] - 1){
				flag = 1;
				continue;
			}
		}
		if(flag == 0){
			count ++;
		}
		//cout<<i<<endl;
	}
	cout<<"func1:"<<count<<endl;
} 

int dfs(int n, int m, int i){
	int count = 0;
	int num = i % 10;
	if(num == 0){
		int num1 = i * 10 + 1;
		if(num1 >= n && num1 <= m){
			//cout<<num1<<endl;
			count ++;
			count += dfs(n, m, num1);
		}
		else if(num1 < n){
			count += dfs(n, m, num1);
		}
	}
	else if(num == 9){
		int num1 = i * 10 + 8;
		if(num1 >= n && num1 <= m){
			//cout<<num1<<endl;
			count ++;
			count += dfs(n, m, num1);
		}
		else if(num1 < n){
			count += dfs(n, m, num1);
		}
	}
	else{
		int num1 = i * 10 + num - 1;
		if(num1 >= n && num1 <= m){
			//cout<<num1<<endl;
			count ++;
			count += dfs(n, m, num1);
		}
		else if(num1 < n){
			count += dfs(n, m, num1);
		}
		int num2 = i * 10 + num + 1;
		if(num2 >= n && num2 <= m){
			//cout<<num2<<endl;
			count ++;
			count += dfs(n, m, num2);
		}
		else if(num2 < n){
			count += dfs(n, m, num2);
		}
	}
	return count;
}

void func2(int n, int m){
	int count = 0;
	for(int i = 1; i <= 9; i++){
		count += dfs(n, m ,i);
	}
	cout<<"func2:"<<count<<endl;
}

int main(){ 
	int m,n;
	cin>>n>>m;
	func1(n, m);
	func2(n, m);
	return 0;
}
