#include<iostream>
#include <stack>
using namespace std;
#define N_MAX 100+1

void dfs(int _node[N_MAX][N_MAX], int _start_node, int _N) {
	int is_visited[N_MAX] = { 0 };     //int ���迭�� �ʱ�ȭ �����ش�.
	stack<int> dfs_stack;              //int stack�� ��������
	dfs_stack.push(_start_node);       //���� ��带 �����ش�.
	while (dfs_stack.size()) {         //dfs�� ũ�Ⱑ 0�� �ɶ� ���� �����Ѵ�.
		int now_node = dfs_stack.top();//���� ����� ��ġ�� stack�� �ǳ��̴�.
		dfs_stack.pop();               //stack ���� ������.

		//�迭 ���鼭 �ش� ��忡 ����ǰ� �湮���� ���� ��쿡 stack �� �־��ش�.
		for (int to_node = 0; to_node < _N; to_node++) {				//_N��ŭ Ȯ���Ѵ�
			if (_node[now_node][to_node] ==1 && is_visited[to_node] == 0) { // ���� ���� ���ߵǴ� ���� �湮�ߴ� ��尡 0�̿��� �ȴ�.
				dfs_stack.push(to_node);								//dfs_stack�� to_node�� �־��ش�
				is_visited[to_node] = 1;								//�湮�ߴٰ� ǥ�����ش�.
			}

		}
	}
	for (int n_idx = 0; n_idx < _N; n_idx++) // _N�� ��ŭ �ݺ��Ѵ�.
		if (is_visited[n_idx])				 // �湮�ߴ� �ε����� Ȯ���Ѵ�.
			_node[_start_node][n_idx] = 1;	 //���� ��� �迭 n_idx�� 1�� ǥ�����ش�.
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