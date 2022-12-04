#include<stdio.h>
#include<stdlib.h>
#define WIN 6
#define DRAW 3
#define LOSS 0

int get_int_val(char ch){
	if(ch <= 67) //value of C in ASCII
	{
		return ch - 65;
	}
	else {
		return ch - 88;
		}
}
int calc_win(int enemy, int me) {
	int r = ((me - enemy) %3) ;
	return r < 0 ? r + 3: r;
}
int calc_points(int  enemy, int me){
	int res = calc_win(enemy, me);
	if(res == 0){
		return DRAW + me + 1;
	}
	else if(res == 1) {
		return WIN + me + 1;
	}
	else {
		return LOSS + me + 1;
	}
}
int main() {

	FILE* input;
	char* BUFFER;
	//for this onw we just need 4 bytes of mem 
	size_t BUFFER_LEN = 4;
	int total_points = 0;
	BUFFER = calloc(BUFFER_LEN, sizeof(char));
	int tmp;
	input = fopen("input_day2.txt", "r");
	
	while(getline(&BUFFER,&BUFFER_LEN, input) != -1 ){
		total_points += calc_points(get_int_val(BUFFER[0]),get_int_val(BUFFER[2]));
	}
	free(BUFFER);
	return EXIT_SUCCESS;
}	
