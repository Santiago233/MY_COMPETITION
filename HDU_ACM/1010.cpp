#include <iostream>
using namespace std;

struct List{
	char value;	//位置内容 
	int flag;	//位置是否遍历过 
}; 

int findway(List**, int, int, int, int, int, int&);

int main(){
	int N, M, T;
	cin>>N>>M>>T;
	while(N != 0 && M != 0 && T != 0){
		//TODO
		List** maze = new List* [N];
		for(int i = 0; i < N; i++)
			maze[i] = new List[M];
		int Srow = 0, Scol = 0, Drow = 0, Dcol = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				maze[i][j].flag = 0;
				char x;
				cin>>x;
				while(x == ' ' || x == '\n')	//据说测试样例后面有空格... 
					cin>>x;
				maze[i][j].value = x;
				//cin>>maze[i][j].value;
				if(maze[i][j].value == 'S'){
					Srow = i;
					Scol = j;
				}
			}
		}
		/*cout<<Srow<<' '<<Scol<<endl;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++)
				cout<<maze[i][j];
			cout<<endl;
		}*/ 
		int min = M * N;
		int distance = 0;
		int flag = findway(maze, Srow, Scol, N, M, distance, min);
		if(flag == 0)
			cout<<"NO"<<endl;
		else{
			if(min <= T && (T - min) % 2 == 0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		cin>>N>>M>>T;
	} 
	return 0; 
}

int findway(List** maze, int Srow, int Scol, int N, int M, int distance, int& min){
	if(maze[Srow][Scol].value == 'D'){
		if(distance < min)
			min = distance;
		return 1;
	}
	if(maze[Srow][Scol].value == 'X')
		return 0;
	
	maze[Srow][Scol].flag = 1;
	
	int upper = 0, lower = 0, left = 0, right = 0;
	if(Srow != 0 && maze[Srow - 1][Scol].flag == 0){
		upper = findway(maze, Srow - 1, Scol, N, M, distance + 1, min);
		maze[Srow - 1][Scol].flag = 0;
	}
	if(Srow != N - 1 && maze[Srow + 1][Scol].flag == 0){
		lower = findway(maze, Srow + 1, Scol, N, M, distance + 1, min);
		maze[Srow + 1][Scol].flag = 0;
	}
	if(Scol != 0 && maze[Srow][Scol - 1].flag == 0) {
		left = findway(maze, Srow, Scol - 1, N, M, distance + 1, min);
		maze[Srow][Scol - 1].flag = 0;
	}
	if(Scol != M - 1 && maze[Srow][Scol + 1].flag == 0){
		right = findway(maze, Srow, Scol + 1, N, M, distance + 1, min);
		maze[Srow][Scol + 1].flag = 0;
	}
	int sum = upper + lower + left + right; 
	if(sum != 0)
		return 1;
	else
		return 0;
}
