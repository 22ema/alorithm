#include<iostream>
#include <stack>
using namespace std;
#define N_MAX 100+1

void dfs(int _node[N_MAX][N_MAX], int _start_node, int _N) {
	int is_visited[N_MAX] = { 0 };     //int 형배열의 초기화 시켜준다.
	stack<int> dfs_stack;              //int stack을 선언해줌
	dfs_stack.push(_start_node);       //시작 노드를 정해준다.
	while (dfs_stack.size()) {         //dfs의 크기가 0이 될때 까지 실행한다.
		int now_node = dfs_stack.top();//현재 노드의 위치는 stack의 맨끝이다.
		dfs_stack.pop();               //stack 에서 꺼낸다.

		//배열 돌면서 해당 노드에 연결되고 방문되지 않은 경우에 stack 에 넣어준다.
		for (int to_node = 0; to_node < _N; to_node++) {				//_N만큼 확인한다
			if (_node[now_node][to_node] ==1 && is_visited[to_node] == 0) { // 현재 노드와 가야되는 노드와 방문했던 노드가 0이여야 된다.
				dfs_stack.push(to_node);								//dfs_stack에 to_node를 넣어준다
				is_visited[to_node] = 1;								//방문했다고 표시해준다.
			}

		}
	}
	for (int n_idx = 0; n_idx < _N; n_idx++) // _N번 만큼 반복한다.
		if (is_visited[n_idx])				 // 방문했던 인덱스를 확인한다.
			_node[_start_node][n_idx] = 1;	 //들고온 노드 배열 n_idx에 1을 표시해준다.
	return ;
}

int main() {
	int N;
	int root[N_MAX][N_MAX];
	cin >> N;
	//input
	for (int r_idx = 0; r_idx < N; r_idx++) {
		for (int c_idx = 0; c_idx < N; c_idx++) {
			cin >> root[r_idx][c_idx];
		}
	}
	for (int node = 0; node < N; node++) {
		dfs(root, node, N);
		
	}
	for (int r_idx = 0; r_idx < N; r_idx++) {
		for (int c_idx = 0; c_idx < N; c_idx++) {
			cout << root[r_idx][c_idx] << " " ;
		}
		cout << endl;
	}
	
}