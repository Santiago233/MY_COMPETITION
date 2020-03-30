#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T; 
	for(int ca_se = 1; ca_se <= T; ca_se++){
		int count;
		cin>>count;
		int* sequence = new int[count];
		for(int number = 0; number < count; number++)
			cin>>sequence[number];
		/*int start = 0, end = 0, sum = sequence[0];
		for(int i = 0; i < count; i++){
			int sum_tmp = 0, max = sequence[i], stop = i;
			for(int j = i; j < count; j++){
				sum_tmp += sequence[j];
				if(sum_tmp > max){
					max = sum_tmp;
					stop = j;
				}
			}
			if(max > sum){
				sum = max;
				start = i;
				end = stop;
			}
		}*/
		int start = 0, end = 0, sum = sequence[0], max = 0;	//sum & max表示意义相反 
		int start_now = 0, end_now = 0;
		for(int number = 0; number < count; number++){
			if(max >= 0) {
				max += sequence[number];
				end_now = number;
			}else{
				max = sequence[number];
				start_now = number;
				end_now = number;
			}
			if(max > sum){
				start = start_now;
				end = end_now;
				sum = max;
			}
		}
		cout<<"Case "<<ca_se<<":"<<endl<<sum<<" "<<(start + 1)<<" "<<(end + 1)<<endl;
		if(ca_se != T)
			cout<<endl;
	}
} 
