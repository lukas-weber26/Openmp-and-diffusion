#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

void print_array(double_t * t){
	for (int x = 0; x<10; x++) {
		printf("%lf, ", t[x]);
	} 	
	printf("\n");
}

int main(){

	int domain_size = 100000;
	int time_steps = 10000000;
	
	double_t * source = malloc(domain_size*sizeof(double_t));
	double_t * target = malloc(domain_size*sizeof(double_t));
	double_t * temp;
	
	for (int x = 0; x<domain_size; x++) {
		source[x] = 1000*sin(3.14*x*1.0/domain_size);		
		target[x] = 1000*sin(3.14*x*1.0/domain_size);		
	} 
 
	printf("gpu %d seems to be present\n", omp_is_initial_device());
	
		
	for (int t = 0; t < time_steps; t++){
			
		//#pragma omp target teams distribute parallel for simd 
		for (int i= 1; i< domain_size-1; i++) { 
			target[i] = 0.3*source[i-1] + 0.4*source[i] + 0.3*source[i+1];
		} 
 
		temp = target;
		target = source;
		source = temp;

		//print_array(source);
		//print_array(target);
	}	
	//	FILE * output_file = fopen("mpi_out.txt","w");
	//	fprintf(output_file, "height,\n");
	//		
	//	for (int f = 0; f<domain_size; f++) {
	//		fprintf(output_file, "%lf,\n", source[f]);
	//	} 

	//	fclose(output_file);
	
	print_array(source);
	print_array(target);
		
	//#pragma omp parallel for num_threads(12)
	//#pragma omp parallel for simd
		//#pragma omp target 
		//#pragma omp loop
		
	free(target);
	free(source);

}
