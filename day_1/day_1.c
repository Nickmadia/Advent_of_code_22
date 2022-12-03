#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* input;
	char* BUFFER;
	int max = 0;
	size_t BUFFER_LEN = 32;
	int tmp = 0;
	int i = 0;
	input = fopen("input_day1.txt","r");
	BUFFER = calloc(BUFFER_LEN,sizeof(char));

	while(getline(&BUFFER,&BUFFER_LEN,input) != -1){
		if(*BUFFER != '\n'){
		  while(BUFFER[i] !='\n'){
			i++;
			
		  }
		  BUFFER[i] = 0;
		  tmp += atoi(BUFFER);
		  i = 0;
		} else 
		{
			if( tmp > max){
				max = tmp;
			}
			tmp = 0;
			i = 0;
		}
			
	}
	free(BUFFER);
	printf("%d", max);
	return EXIT_SUCCESS;
}

