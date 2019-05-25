#include<iostream>


#define ROW 2
#define N_MAX 1001
using namespace std;
static int is_visited[N_MAX] = { 0 };
int Count = 0;
void dfs(int root[N_MAX][ROW],int start_node,int number) {
	int now=root[start_node][1];
	is_visited[start_node] = 1;
	for (int i = 0; i < number; i++) {
		
		if (is_visited[now - 1] == 0 && root[i][0]==now) {
			is_visited[now - 1] = 1;
			dfs(root, i, number);
			
			
			
			

		}
		continue;

	}
	
	return;
}
int main() {
	
	int list[ROW];
	int N;
	int M;

	int path[N_MAX][ROW];
	for (int i = 0; i < ROW; i++) {
		cin >> list[i];
	}
	N = list[0];
	M = list[1];
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < ROW; j++) {
			cin >> path[i][j];
		}
	}
	
		for (int i = 0; i < N; i++) {
			if (is_visited[i] == false) {
				for (int j = 0; j < M; j++) {
					
					dfs(path, j, M);
					

				}
			Count++;
			
			}
			
		}
		cout << Count << endl;
	
	
	return 0;
}