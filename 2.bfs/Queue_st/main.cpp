/*������ http://22ema.github.io
queue ������ ����*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 9; // ����� ����
int visit[9]; // �湮 �ߴ��� Ȯ���ϴ� �迭
vector<int> a[10]; // ���͸� ����� ��θ� ������ Ȯ����

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		// ť�� ���� ���� ��� ��� �ݺ� ����
		// ť�� ���� �ִ�. => ���� �湮���� ���� ��尡 ���� �Ѵ�.
		int x = q.front();	// queue�� front�� x�� �����Ѵ�.
		q.pop();			// �� �տ� �ִ°��� pop ��Ų��.
		printf("%d", x);	// x�� ���� ����Ѵ�.
		for (int i = 0; i < a[x].size(); i++) {// a[x](vector)�� ũ�� ��ŭ �ݺ��Ѵ�.
			int y = a[x][i];//�ش� ������ i��ġ�� ���� y�� �ִ´�.
			if (!visit[y]) {//�湮����������
				q.push(y);  //q�� y�� push�Ѵ�.
				visit[y] = true; // �湮�ߴٰ� ǥ���Ѵ�.
			}
		}
	}
}
int main() {
	for (int i = 0; i < number; i++) { // �湮�ߴٴ� ����
		int N, M;
		cin >> N >> M;
		a[N].push_back(M);
		a[M].push_back(N);

	}
	bfs(1);
	return 0;
}