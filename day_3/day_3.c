#include<stdio.h>
#include<stdlib.h>

int get_int_val(char ch){
	if(ch >= 97 ) 
	{
		return ch - 96 ;
	}
	else {
		return ch - 38;
		}
}
int main(){
	FILE* input;
	char* BUFFER;
	size_t BUFFER_LEN = 100;
	BUFFER = calloc(BUFFER_LEN, sizeof(char));
	int res;
	int i = 0;
	input = fopen("input_day3.txt", "r");
	
	while(getline(&BUFFER,&BUFFER_LEN, input) != -1 ){
		while(BUFFER[i] != '\n'){
			i++;	
		}
		for(int j =0; j<(i/2); j++){
			for(int k=i/2; k<i; k++){
				if(BUFFER[j] == BUFFER[k]){
					
					res += get_int_val(BUFFER[j]);
					goto out;
				}
		}	
		}
		out:
		i=0;
	}
	printf("result = %d\n",res);
	free(BUFFER);
	return EXIT_SUCCESS;
	
}
