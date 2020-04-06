#include <iostream>
#include <iomanip>
using namespace std;

void quicksort(int*, double*, int, int);

int main(){
	int M,N;
	cin>>M>>N;
	while(M != -1 && N != -1){
		//TODO
		if(N == 0){
			cout<<setiosflags(ios::fixed)<<setprecision(3);
			cout<<0.000<<endl;
		}
		else{
		double* J = new double[N];
		double* F = new double[N];
		double* per = new double[N];
		for(int i = 0; i < N; i++){
			cin>>J[i]>>F[i]; 
			if(F[i] != 0){
				per[i] = J[i] / F[i];
			}else{
				per[i] = -1;
			}
		}
		int* max_per = new int[N];
		for(int i = 0; i < N; i++)
			max_per[i] = i;
		quicksort(max_per, per, 0, N - 1);
		for(int i = 0; i < N; i++)
			cout<<max_per[i]<<endl; 
		double pay = M;
		double obtain = 0;
		for(int i = 0; i < N; i++){
			if(pay > 0){
				if(pay >= F[max_per[i]]){
					obtain += J[max_per[i]];
					pay -= F[max_per[i]];
				}else{
					obtain = obtain + pay / F[max_per[i]] * J[max_per[i]];
					pay = 0;
				}
			}else{
				if(F[max_per[i]] == 0){
					obtain += J[max_per[i]];
				}else{
					break;
				}
			}
		} 
		cout<<setiosflags(ios::fixed)<<setprecision(3);
		cout<<obtain<<endl;
		}
		cin>>M>>N; 
	} 
	return 0;
}

void quicksort(int* max_per, double* per, int start, int end){
	/*if(end - start >= 1){
		int pivot = start;
		int left = start + 1;
		int right = end;
		for(int i = left; i <= right; i++){
			if(per[max_per[pivot]] == -1){
				break;
			}
			if(per[max_per[i]] == -1 || (per[max_per[i]] >= per[max_per[pivot]])){
				int tmp = max_per[pivot];
				max_per[pivot] = max_per[i];
				max_per[i] = tmp;
				pivot++;
			}else{
				while((right >= left) && per[max_per[right]] < per[max_per[pivot]] && per[max_per[right]] != -1){
					right--;
				}
				if(right >= left){
					int tmp = max_per[right];
					max_per[right] = max_per[i];
					max_per[i] = max_per[pivot];
					max_per[pivot] = tmp;
					pivot++;
				}
			}
		}
		quicksort(max_per, per, start, pivot - 1);
		quicksort(max_per, per, pivot + 1, end);
	}*/
	if(start < end){
		int i = start, j = end;
		double pivot = per[max_per[start]];
		while(i < j){
			while(i < j && per[max_per[j]] <= pivot && per[max_per[j]] != -1)
				j--;
			if(i < j){
				int tmp = max_per[i];
				max_per[i] = max_per[j];
				max_per[j] = tmp;
				i++;
			}
			while(i < j && (per[max_per[i]] > pivot || per[max_per[i]] == -1))
				i++;
			if(i < j){
				int tmp = max_per[i];
				max_per[i] = max_per[j];
				max_per[j] = tmp;
				j--;
			}
		}
		//max_per[i] = max_per[start];
		quicksort(max_per, per, start, i - 1);
		quicksort(max_per, per, i + 1,  end);
	} 
}
