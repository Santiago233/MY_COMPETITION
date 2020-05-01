/*题目：给点n节点的树，编号为0到n-1，且给定n-1条边权值w，给定整数m，求一个最小x使得去掉树中小于x的边后，根节点能到达的点数目不超过m。n<=20000且w<=10000000 */ 

#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
	int number;
	int w;
	node* next;
};

void search(int, node**, int, int);
int dfs(node**, int, int);

int main(){
	int n, m;
	cin >> n >> m;
	node** tree = new node*[n];
	for(int i = 0; i < n; i++)
		tree[i] = NULL;
	int* weight = new int[n - 1];
	for(int i = 0; i < n - 1; i++){
		int a, b, w;
		cin >> a >> b >> w;
		weight[i] = w;
		if(tree[a] == NULL){
			tree[a] = new node;
			tree[a]->number = b;
			tree[a]->w = w;
			tree[a]->next = NULL;
		}else{
			node* q = tree[a];
			while(q->next != NULL)
				q = q->next;
			q->next = new node;
			q->next->number = b;
			q->next->w = w;
			q->next->next = NULL;
		}
	}
	search(m, tree, 1, 10000000);
} 

void search(int m, node** tree, int start, int end){
	int count = 0;
	if(start == end){
		count = dfs(tree, 0, start);
		if(count > m)
			cout << start + 1 << endl;
		else if(count < m)
			cout << start - 1 << endl;
		else
			cout<< start << endl;
		return;
	}
	int x = (start + end) / 2;
	count = dfs(tree, 0, x); 
	if(count > m)
		search(m, tree, x + 1, end);
	else
		search(m, tree, start, x - 1);
}

int dfs(node** tree, int num, int x){
	int count = 0;
	node* p = tree[num];
	while(p != NULL){
		if(p->w >= x){
			count ++;
			num = p->number;
			count += dfs(tree, num, x);
		}
		p = p->next;
	}
	return count;
}
