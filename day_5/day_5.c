#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printar(char **dock){
    printf("dock :\n");
    for(int i = 0; i<9; i++){
        for(int j = 0; j<strlen(dock[i]); j++){
            printf("%c",dock[i][j]);
    }
        printf("\n");
    }
    printf("\n");
}
void reverse_arr(char* array,int i, int n){
    if(i >= n){
        return;
    }
    char val= array[i];

    reverse_arr(array, i+1, n);
    
    array[strlen(array) -i -1] = val;
}
void move_crates(char ** dock, int qty,int source, int dest){
    char tmp;
    for(int i=0; i< qty; i++){
        tmp = dock[source][strlen(dock[source])-1] ;
        dock[source][strlen(dock[source])-1] = 0;
        dock[dest][strlen(dock[dest])] = tmp;
    }
}
int main(){
    FILE* input;
	char* BUFFER;
    char * dock[9];
	size_t BUFFER_LEN = 30;
    size_t d= 90;
	BUFFER = calloc(BUFFER_LEN, sizeof(char));
	int res =0;
      
	input = fopen("input_day5.txt", "r"); 

    for(int i= 0; i<9;i++){
        dock[i] = calloc(d, sizeof(char));
    }
    int k=1;
    int i =0;
    int j =0;
    while(getline(&BUFFER,&BUFFER_LEN, input) != -1 ){
        if(BUFFER[1]== '1'){
            continue;
        }
        if(BUFFER[0]== '\n'){
            break;
        }
        while(k <34){
            
            if(BUFFER[k] == ' ' ){
                k= k+4;
                i++;
                continue;
            }
                while(dock[i][j] != 0){
                    j++;
                }
                dock[i][j] = BUFFER[k];
                i++;
                k = k+4;
                j=0;
        }
        i=0;
        j=0;
        k =1;
    }
    for(i = 0; i<9; i++){
        reverse_arr(dock[i],0, strlen(dock[i]));
    }
    for(i = 0; i<9; i++){
        for(j = 0; j<strlen(dock[i]); j++){
            printf("%c",dock[i][j]);
    }
        printf("\n");
    }
    int moves[3];
    char *token;
    while(getline(&BUFFER,&BUFFER_LEN, input) != -1 ){
        i = 0;
        token = strtok(BUFFER," ");
        while(i<3){
            token = strtok(NULL," ");
            moves[i] = atoi(token);
            token = strtok(NULL," ");
            i++;
            
        }
        move_crates(dock,moves[0],moves[1]-1,moves[2]-1);
    }
    printf("\n");
    printar(dock);
    for(i = 0;i<9;i++){
        printf("%c",dock[i][strlen(dock[i])-1]);
    }
    free(BUFFER);
    return EXIT_SUCCESS;
    
}