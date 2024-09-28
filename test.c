#include <stdio.h>
int main(){

	int test [10] = {1,2,3,4,5,6,7,8,9,10};	
	
	#pragma omp parallel for
	for (int i = 0; i < 10; i++) {
		test[i]*=2;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n",test[i]);
	}

}
