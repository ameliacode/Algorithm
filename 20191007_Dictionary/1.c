#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *A;
int n;


int rFE(int k, int l, int r) {

	int mid = (l + r) / 2;
	if (l > r) {
		//printf("%d %d\n", A[l], A[r]);
		if (k > *(A + r)) 
			return r;
		else return -1;
	}
	if (k == *(A + mid))
		return mid;
	else if (k < *(A + mid))
		return rFE(k, l, mid - 1);
	else if (k > *(A + mid))
		return rFE(k, mid + 1, r);
}

int findElement(int k) {
	return rFE(k, 0, n - 1);
}

int main() {

	int K;
	int i;

	scanf("%d %d", &n, &K);
	A = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	printf(" %d\n", findElement(K));


	return 0;
}