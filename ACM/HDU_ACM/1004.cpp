#include <iostream>
#include <string> 
#include <stdlib.h>
using namespace std;

struct ballon{
	string color;
	int number;
	ballon* next;
};

int judge(string, string);

int main(){
	int N;
	cin>>N;
	while(N != 0){
		//TODO
		ballon* line = NULL;
		for(int i = 0; i < N; i++){
			string color;
			cin>>color;
			ballon* point = line;
			int flag = 0;
			while(point != NULL){
				if(judge(point->color, color) == 1){
					//cout<<"Yes"<<endl;
					point->number ++;
					flag = 1;
					break;
				}else{
					point = point->next;
				}
			}
			if(flag == 0){
				ballon* add = new ballon;
				add->color = color;
				add->number = 1;
				add->next = NULL;
				if(line == NULL){
					line = add;
				}else{
					ballon* p = line;
					while(p->next != NULL){
						p = p->next;
					}
					p->next = add;
				}
				/*ballon* test = line;
				while(test != NULL){
					cout<<test->color<<endl;
					test = test->next;
				}*/
			}
		}
		string max_color = "";
		int max_number = 0;
		ballon* q = line;
		while(q != NULL){
			if(q->number > max_number){
				max_color = q->color;
				max_number = q->number;
			}
			q = q->next;
		} 
		cout<<max_color<<endl;
		cin>>N;
	}
	return 0;
} 

int judge(string a, string b){
	int len1 = 0, len2 = 0;
	for(int i = 0; a[i] != '\0'; i++)
		len1++;
	for(int i = 0; b[i] != '\0'; i++)
		len2++;
	if(len1 != len2){
		return 0;
	}else{
		for(int i = 0; i < len1; i++){
			if(a[i] != b[i])
				return 0;
		}
		return 1;
	}
}
