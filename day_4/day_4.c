#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){

    FILE* input;
	char* BUFFER;
    char* token;
    char* token2;
    int first[2];
    int second[2];
	size_t BUFFER_LEN = 100;
	BUFFER = calloc(BUFFER_LEN, sizeof(char));
	int res =0;
	 input = fopen("input_day4.txt", "r"); 
    
    while(getline(&BUFFER,&BUFFER_LEN, input) != -1 ){
        if(BUFFER[strlen(BUFFER)-1] == '\n')
        {
            BUFFER[strlen(BUFFER)-1] = '\0';
        } 
        token = strtok(BUFFER,",");
        token2 = strtok(NULL,",");
        
        first[0] = atoi(strtok(token,"-"));
        first[1] = atoi(strtok(NULL,"-"));
       
        second[0] = atoi(strtok(token2,"-"));
        second[1] = atoi(strtok(NULL,"-"));  
        

        if(first[0] <= second[0] && first[1] >= second[1] || first[0] >= second[0] && first[1] <= second[1]){
            res ++;

        }
    }
    free(BUFFER);
    printf("result : %d\n", res);
    return EXIT_SUCCESS;
}