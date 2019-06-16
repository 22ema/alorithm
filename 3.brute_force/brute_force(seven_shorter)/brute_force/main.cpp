#include<iostream>
#define N_MAX 9
#define MAX 101
using namespace std;
int Short[N_MAX];
void find_shorter() {
	int total = 0;
	int result = 0;
	for (int i = 0; i < N_MAX; i++) {
		total = Short[i] + total;
		
	}
	for (int i = 0; i < N_MAX; i++) {
		for (int j = 0; j < N_MAX; j++) {
			if (i != j) {
				result = total - Short[i] - Short[j];
			}
			if (result == 100) {
				for (int k = 0; k < N_MAX; k++) {
					if (k == i || k == j) {
						
					}
					else {
						cout << Short[k] << endl;
					}
					
				}
				result = 0;
				break;
			}
		}
	}
}

int main() {
	for (int i = 0; i < N_MAX; i++) {
		cin >> Short[i];
	}
	find_shorter();
	return 0;
}