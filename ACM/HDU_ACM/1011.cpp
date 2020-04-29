#include <iostream>
#include <stdio.h>
using namespace std;

struct tunnel{
	int serial;
	tunnel* next;
};

struct cave{
	int number;
	int possibility;
	tunnel* list;
};

void caculate(cave*, int, int, int, int&);

int main(){
	int N, M;
	cin>>N>>M;
	while(N != -1 && M != -1){
		cave* base = new cave[N + 1];
		for(int i = 1; i <= N; i++){
			cin>>base[i].number>>base[i].possibility;
			base[i].list = new tunnel;
			base[i].list->serial = -1;
			base[i].list->next = NULL;
		}
		for(int i = 0; i < N - 1; i++){
			int loca, serial;
			cin>>loca>>serial;
			/*if(base[loca].list->serial == -1){
				base[loca].list->serial = serial;
				base[loca].list->next = NULL;
			}else{
				tunnel* p = base[loca].list;
				while(p->next != NULL){
					p = p->next;
				}
				p->next = new tunnel;
				p->next->serial = serial;
				p->next->next = NULL;
			}*/
			tunnel* p = base[loca].list;
			while(p->serial != -1)
				p = p->next;
			p->serial = serial;
			p->next = new tunnel;
			p->next->serial = -1;
			p->next->next = NULL;
		}
		int max = 0;
		/*for(int i = 1; i <= N; i++){
			tunnel* p = base[i].list;
			while(p != NULL && p->serial != -1){
				cout<<p->serial<<' ';
				p = p->next;
			}
			cout<<endl;
		}*/
		caculate(base, 1, 0, M, max);
		cout<<max<<endl;
		cin>>N>>M; 
	}
	return 0; 
} 

void caculate(cave* base, int loca, int tmp, int trooper, int& max){
	if(trooper * 20 >= base[loca].number){
		/*if(base[loca].number / 20 * 20 < base[loca].number){
			trooper = trooper - base[loca].number / 20 - 1;
		}else{
			trooper = trooper - base[loca].number / 20;
		}*/
		trooper = trooper - (base[loca].number + 19) / 20;
		tmp += base[loca].possibility;
		tunnel* p = base[loca].list;
		while(p->serial != -1){
			int serial = p->serial;
			caculate(base, serial, tmp, trooper, max);
			p = p->next;
		}
		if(tmp > max)
			max = tmp;
	}else{
		if(tmp > max)
			max = tmp;
	}
}
