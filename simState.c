#include <stdio.h>
#include <stdlib.h>
/*
Michael Karimizadeh 500831189
Personalized state Machine:
[0]A F A
[1]B D C
[2]C G E
[3]D H A
[4]E A G
[5]F C B
[6]G B H
[7]H E D

STARTING state IS: F
*/
int main(int argc, char * argv[]){
	int i, garb, j=0;
	char input[3];
	//State data type
	typedef struct states{ 
	// Each state has a name (letter), next state address when input is high (0), and when input is low (0)
		char letter; 
		struct states* high;
		struct states* low;
	}states;

	states s[8];
	states *start = (&s[5]);

	s[0].letter = 'A'; 
	s[0].high = &s[0];
	s[0].low = &s[5]; 
	s[1].letter = 'B';
	s[1].high = &s[2];
	s[1].low = &s[3];
	s[2].letter = 'C';
	s[2].high = &s[4];
	s[2].low = &s[6];
	s[3].letter = 'D';
	s[3].high = &s[0];
	s[3].low = &s[7];
	s[4].letter = 'E';
	s[4].high = &s[6];
	s[4].low = &s[0];
	s[5].letter = 'F';
	s[5].high = &s[1];
	s[5].low = &s[2];
	s[6].letter = 'G';
	s[6].high = &s[7];
	s[6].low = &s[1];
	s[7].letter = 'H';
	s[7].high = &s[3];
	s[7].low = &s[4];

	//Current state address variable
	states *curr = &s[5];
	fprintf( stdout,"Starting:%c\n",start->letter);
	printf("Please insert commands w/o spaces between characters\n");
	printf("Ex// 1F to print next state of F with input '1'\n");
	printf("To conclude command, type character x\n");

	while(j!=1){
    //Obtaining input
		for(i=0;i<3;i++){
			scanf("%c",&input[i]);
			if(input[i]=='\n'){
				break;
			}
		}
    //Complete command
		if(input[0]=='X'|| input[0]=='x'){
			j=1;
		}
        //Printing of states
        if(input[0]=='P'|| input[0]=='p'){ //Since p is a single command, first index is taken
        	for(i=0;i<8;i++){
        		fprintf(stdout,"%c %c %c \n",s[i].letter, s[i].low->letter, s[i].high->letter);
        	}
        }
		//Single low
        if(input[0]=='0')
        {
        	fprintf(stdout,"%c\n",(curr->low)->letter);
        	curr = (curr->low);
        }
		//Single high
        if(input[0]=='1')
        {
        	fprintf(stdout,"%c\n",(curr->high)->letter);
        	curr = (curr->high);
        }
        //Change 0
        if((input[0]=='C'||input[0]=='c')&& input[1]=='0'){ // If c is selected then next state input is 0
        	if(input[5]=='A'||input[5]=='a'){
        		(curr->low)=&s[0]; 
        		curr = &s[0];
        	}
        	else if(input[5]=='B'||input[5]=='b'){
        		(curr->low)=&s[1]; 
        		curr = &s[1];
        	}
        	else if(input[5]=='C'||input[5]=='c'){
        		(curr->low)=&s[2]; 
        		curr = &s[2];
        	}
        	else if(input[5]=='D'||input[5]=='d'){
        		(curr->low)=&s[3]; 
        		curr = &s[3];
        	}
        	else if(input[5]=='E'||input[5]=='e'){
        		(curr->low)=&s[4]; 
        		curr = &s[4];
        	}
        	else if(input[5]=='F'||input[5]=='f'){
        		(curr->low)=&s[5]; 
        		curr = &s[5];
        	}
        	else if(input[5]=='G'||input[5]=='g'){
        		(curr->low)=&s[6]; 
        		curr = &s[6];
        	}
        	else if(input[5]=='H'||input[5]=='h'){
        		(curr->low)=&s[7]; 
        		curr = &s[7];
        	}
        }
        //Change 1
        if((input[0]=='C'||input[0]=='c')&& input[1]=='1'){// If c is selected then next state input is 1
        	if(input[5]=='A'||input[5]=='a'){
        		(curr->high)=&s[0]; 
        		curr = &s[0];
        	}
        	else if(input[5]=='B'||input[5]=='b'){
        		(curr->high)=&s[1]; 
        		curr = &s[1];
        	}
        	else if(input[5]=='C'||input[5]=='c'){
        		(curr->high)=&s[2]; 
        		curr = &s[2];
        	}
        	else if(input[5]=='D'||input[5]=='d'){
        		(curr->high)=&s[3]; 
        		curr = &s[3];
        	}
        	else if(input[5]='E'||input[5]=='e'){
        		(curr->high)=&s[4]; 
        		curr = &s[4];
        	}
        	else if(input[5]=='F'||input[5]=='f'){
        		(curr->high)=&s[5]; 
        		curr = &s[5];
        	}
        	else if(input[5]=='G'||input[5]=='g'){
        		(curr->high)=&s[6]; 
        		curr = &s[6];
        	}
        	else if(input[5]=='H'||input[5]=='h'){
        		(curr->high)=&s[7]; 
        		curr = &s[7];
        	}
        	else{
        		fprintf(stdout,"Can only compute from A-H");
        	}
        }

        //Garbage
        if(input[0]=='G'||input[0]=='g'){
        	int check[8] = {0,0,0,0,0,0,0,0};
        	garb=0;
			//Checks all the states
        	for(i=0; i<8; i++)
        	{
        		if (((s[i].low)->letter) == 'A' || ((s[i].high)->letter)== 'A')
        			check[0]++;
        		if (((s[i].low)->letter)== 'B' || ((s[i].high)->letter)== 'B')
        			check[1]++;
        		if (((s[i].low)->letter) == 'C' || ((s[i].high)->letter)== 'C')
        			check[2]++;
        		if (((s[i].low)->letter) == 'D' || ((s[i].high)->letter)== 'D')
        			check[3]++;
        		if (((s[i].low)->letter) == 'E' || ((s[i].high)->letter)== 'E')
        			check[4]++;
        		if (((s[i].low)->letter) == 'F' || ((s[i].high)->letter)== 'F')
        			check[5]++;
        		if (((s[i].low)->letter) == 'G' || ((s[i].high)->letter)== 'G')
        			check[6]++;
        		if (((s[i].low)->letter) == 'H' || ((s[i].high)->letter)== 'H')
        			check[7]++;
        	}
        	garb=1;
        	for (i=0; i<8; i++){
        		if (check[i] > 0)
				garb++; //If all 8 indexes>1, all states can be reached therefore no garbage
		}
		if (garb > 8)
			fprintf(stdout, "There is no garbage\n");
		else{
			printf("Garbage: ");
			if (check[0] < 1)
				fprintf(stdout,"A ");
			if (check[1] < 1)
				fprintf(stdout,"B ");
			if (check[2] < 1)
				fprintf(stdout,"C ");
			if (check[3] < 1)
				fprintf(stdout,"D ");
			if (check[4] < 1)
				fprintf(stdout,"E ");
			if (check[5] < 1)
				fprintf(stdout,"F ");
			if (check[6] < 1)
				fprintf(stdout,"G ");
			if (check[7] < 1)
				fprintf(stdout,"H ");	
		}	
	}
}
return(0);
}
