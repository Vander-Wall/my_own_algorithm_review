#include <stdio.h>
#include <math.h>
#include<algorithm>
using namespace std;

#define N 6
#define W 21



int B[N][W] = {0};
int w[6] = {0, 2, 3, 4, 5, 9};
int v[6] = {0, 3, 4, 5, 8 ,10};

void knapsack(){
	// C stands for Capacity  , k就是表示第k个商品
	for(int k = 1; k < N; k++){ //
		for(int C = 1; C < W; C++){
			if(w[k] > C)
				B[k][C] = B[k-1][C];
			else{
				int selected = B[k-1][C-w[k]]+v[k];
				int unselected = B[k-1][C];
				B[k][C] = max(selected,unselected);
			}
		}
	}

}


int main(){

	knapsack();
	printf("%d\n", B[5][20]);
	return 0;
}

