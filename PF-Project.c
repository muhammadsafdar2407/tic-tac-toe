/*
Project Title: TIC TAC TOE
Group Members:
Muhammad Safdar  22k-4304  BCS-1B
Abdul Rafiu  22k-4162  BCS-1B
Syed Mohammed Rayyan Imam  22k-4153  BCS-1B
*/





#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <TIME.h>

typedef struct record {
	char username[20];
	struct pvp{
		int win;
		int draw;
		int loss;
	}P;
	struct easy{
		int win;
		int draw;
		int loss;
	}E;
	struct hard{
		int win;
		int draw;
		int loss;
	}H;
}record;

char name0[20];
char name[20];

char square[10] = { 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
void Easy(void);
void medium(void);
void PlayervPlayer(void);
void board(char *);
int checkwin(char *);
int EasyBot(char *);
int MediumBot(char *);
int validmove(char,int, char *);
void restart(char *);
int signin (void){
	int found=0;
	printf("Enter Username\n");
	fflush(stdin);
	gets(name);
	record R;
	FILE *fp;
	fp=fopen("record.txt","r");
	if (fp==NULL)
	{
		printf("Cannot open File");
	}
	while(fread(&R,sizeof(record),1,fp))
	{
		if (strcmp(R.username,name)==0)
		{
			found=1;
			fclose(fp);
		}
	}
	if (found==0)
	{
		printf("Username does not exsist kindly sign up\n");
		fclose(fp);
	}
	return found;
};
int signup (void){
	int found=1;
	
	record R;
	FILE *fp;
	fp=fopen("record.txt","r");
	if (fp==NULL)
	{
		printf("Cannot open File");
	}
	
	printf("Enter Username\n");
	fflush(stdin);
	gets(name);
	
	while(fread(&R,sizeof(record),1,fp))
	{
		if (strcmp(R.username,name)==0)
		{
			found=0;
			printf("Username Already exsists\n");
			fclose(fp);
		}
	}
	if (found==1)
	{
//		printf("1\n");
		record *R;
		fseek(fp,0,SEEK_END);
//		printf("2\n");
		int n=ftell(fp)/sizeof(record);
//		printf("3\n");
		R= (record*)calloc(n+1,sizeof(record));
		fclose(fp);
//		printf("4\n");
		if (n==0)
		{
//			printf("5\n");
			fp=fopen("record.txt","w");
			if (fp==NULL)
			{
				printf("Cannot open File");
			}
//		printf("6\n");
		strcpy(R[n+1].username,name);
		R[n+1].P.win=0;
		R[n+1].P.draw=0;
		R[n+1].P.loss=0;
		R[n+1].E.win=0;
		R[n+1].E.draw=0;
		R[n+1].E.loss=0;
		R[n+1].H.win=0;
		R[n+1].H.draw=0;
		R[n+1].H.loss=0;
		fwrite(&R[n+1],sizeof(record),1,fp);
		fclose(fp);
	}
	else
	{
		fp=fopen("record.txt","a");
		if (fp==NULL)
		{
			printf("Cannot open File");
		}
		strcpy(R[n+1].username,name);
		R[n+1].P.win=0;
		R[n+1].P.draw=0;
		R[n+1].P.loss=0;
		R[n+1].E.win=0;
		R[n+1].E.draw=0;
		R[n+1].E.loss=0;
		R[n+1].H.win=0;
		R[n+1].H.draw=0;
		R[n+1].H.loss=0;
		fwrite(&R[n+1],sizeof(record),1,fp);
		fclose(fp);
	}
	free(R);
	}
	
	return found;
};
void display (void){
	//printf("100\n");
	record R;
	FILE *fp;
	fp=fopen("record.txt","r");
	
	while(fread(&R,sizeof(record),1,fp))
	{
		if (strcmp(R.username,name)==0)
		{
			printf("Name: %s\n",R.username);
			printf("Easy Wins: %d\t",R.E.win);
			printf("Easy Loses: %d\t",R.E.loss);
			printf("Easy Draws: %d\n",R.E.draw);
			printf("Hard Wins: %d\t",R.H.win);
			printf("Hard Loses: %d\t",R.H.loss);
			printf("Hard Draws: %d\n",R.H.draw);
			printf("PVP Wins: %d\t",R.P.win);
			printf("PVP Loses: %d\t",R.P.loss);
			printf("PVP Draws: %d\n",R.P.draw);
		}
	}
	fclose(fp);
};
int main(){
	printf("\t\tTIC-TAC-TOE\n\n");
	int play=1,s=0;
	int choice,difficulty;
	
	
	while(s!=1)
	{
	printf("1:Signup   2:Signin\nEnter Choice:");
	scanf("%d",&choice);
	if (choice==1)
	{
		s=signup();
	}
	else if (choice==2)
	{
		s=signin();
	}
}
	display();
	printf("1:Player vs Player   2:Player vs Computer\nEnter Choice:");
	scanf("%d",&choice);
	
	while(choice>2 || choice<1)
	{
		printf("\nInvalid Input, Enter Choice:");
		scanf("%d",&choice);
	}
	
	if (choice==2)
	{
		printf("\n\n1:Easy   2:hard\nChoose Difficulty:");
		scanf("%d",&difficulty);
		
		while(difficulty<1 || difficulty>2)
		{
			printf("Invalid Input, Enter Difficulty:");
			scanf("%d",&difficulty);
		}
		if (difficulty==1)
		{
			Easy();
		}
		else 
		{
			medium();
		}
		
	}
	else
	{
		
		
		s=0;
		while(s!=1)
	{
	strcpy(name0,name);
	printf("Player 2:\n");	
	printf("1:Signup   2:Signin\nEnter Choice:");
	scanf("%d",&choice);
	if (choice==1)
	{
		s=signup();
	}
	else if (choice==2)
	{
		s=signin();
	}
}
	PlayervPlayer();
	}
//	printf("\n\nPress 1 to play again and 0 to Exit: ");
//	scanf("%d",&play);
	
	return 0;
}
void PlayervPlayer(void){
	record R;
	FILE *fp;
	FILE *fp1;
    int player = rand()%2, i, choice , x,play;

    char mark;
    do
    {
    	restart(square);
    	do
    	{
        	board(square);
        	player = (player % 2) ? 1 : 2;

        	printf("Player %d, enter a number:  ", player);
        	scanf("%d", &choice);

        	mark = (player == 1) ? 'X' : 'O';
        	x=validmove(mark,choice,square);    
        	if (x==0)
        	{
            	printf("Invalid move ");
            	fflush(stdin);
            	sleep(1);
            	continue;
        	}
        	i = checkwin(square);

        	player++;
    	}while (i ==  - 1);
    
    	board(square);
    
    	if (i == 1)
        	printf("==>\aPlayer %d win ", --player);
        	if(player==1)
        	{
        		fp=fopen("record.txt","r");
				fp1=fopen("temp.txt","w");
				while(fread(&R,sizeof(record),1,fp))
				{
					if (strcmp(R.username,name0)==0)
						{
							R.P.win+=1;
						}
					fwrite(&R,sizeof(record),1,fp1);
				}
			fclose(fp);
			fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.P.loss+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		}
		else if (player==2)
		{
			fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.P.win+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name0)==0)
			{
				R.P.loss+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		}
		
        
    else
    {
    	printf("==>\aGame draw");
    	{
        	fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name0)==0)
			{
				R.P.draw+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.P.draw+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		}
		}
		printf("\nPress 1 to play again or 0 to exit: ");
		scanf("%d", &play);
		if (play==0){
			display();
			strcpy(name,name0);
			printf("\n");
			display();
		}
	}while(play==1);
           
}
int EasyBot(char *ptr){
	int x=0;
	while (*(ptr+x)!=' ')
	{
		x = rand() % 9;
		x++;
	}
	return x;
}
void Easy(void){
	record R;
	FILE *fp;
	FILE *fp1;
	srand(time(0));
    int player = rand()%2, i, choice , x,play;

    char mark;
    do
    {
    	restart(square);
    	do
    	{
        	board(square);
        	player = (player % 2) ? 1 : 2;
			if(player==1){
        	printf("Enter a number:  ");
        	scanf("%d", &choice);}
        	if(player==2)
        	choice =EasyBot(square);

        	mark = (player == 1) ? 'X' : 'O';

        	x=validmove(mark,choice,square);
            
        	if (x==0&&player==1)
        	{
		   
		    	printf("Invalid move ");
            	fflush(stdin);
            	sleep(1);
            	continue;
        	
        	}
        	else if (x==0)
        	{
        		continue;
			}
        
        	i = checkwin(square);

        	player++;
    	}while (i ==  - 1);
    
    	board(square);
    
    	if (i == 1)
    	if (--player==1)
    	{
        	printf("==>\aYou win ");
        
        
		
			fp=fopen("record.txt","r");
			fp1=fopen("temp.txt","w");
			while(fread(&R,sizeof(record),1,fp))
			{
				if (strcmp(R.username,name)==0)
				{
					R.E.win+=1;
				}
				fwrite(&R,sizeof(record),1,fp1);
			}
			fclose(fp);
			fclose(fp1);
		
			fp=fopen("record.txt","w");
			fp1=fopen("temp.txt","r");
        
        	while(fread(&R,sizeof(record),1,fp1))
        	{
        		fwrite(&R,sizeof(record),1,fp);
			}
			fclose(fp);
			fclose(fp1);
    	}
        else
        {
        	printf("==>\aComputer Wins");
		
		fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.E.loss+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		}
        
    else
    {
    	printf("==>\aGame draw");
    	fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.E.draw+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		}
		printf("Press 1 to play again or 0 to exit: ");
		scanf("%d", &play);
		if (play==0){
			display();
		}
 	}while(play ==1);
	}
void medium(void){
	record R;
	FILE *fp;
	FILE *fp1;
	srand(time(0));
    int player = rand() %2, i, choice , x,play;

    char mark;
    do{
    	restart(square);
    do
    {
        board(square); 
        player = (player % 2) ? 1 : 2;
		if(player==1){
        printf("Enter a number:  ");
        scanf("%d", &choice);}
        if(player==2)
        choice =MediumBot(square);

        mark = (player == 1) ? 'X' : 'O';

        x=validmove(mark,choice,square);
            
        if (x==0&&player==1)
        {
		   
		    printf("Invalid move ");
            fflush(stdin);
            sleep(1);
            continue;
        	
        }
        else if (x==0)
        {
        	continue;
		}
        
        i = checkwin(square);

        player++;
    }while (i ==  - 1);
    
    board(square);
    
    if (i == 1)
    {
    	if (--player==1)
    	{	printf("==>\aYou win ");
    		fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.H.win+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
    }
    
        else
        printf("==>\aComputer Wins");
        fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.H.loss+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
    }
    else
    {
    	printf("==>\aGame draw");
    	fp=fopen("record.txt","r");
		fp1=fopen("temp.txt","w");
		while(fread(&R,sizeof(record),1,fp))
		{
			if (strcmp(R.username,name)==0)
			{
				R.H.draw+=1;
			}
			fwrite(&R,sizeof(record),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		
		fp=fopen("record.txt","w");
		fp1=fopen("temp.txt","r");
        
        while(fread(&R,sizeof(record),1,fp1))
        {
        	fwrite(&R,sizeof(record),1,fp);
		}
		fclose(fp);
		fclose(fp1);
	}
		printf("\nPress 1 to play again or 0 to exit: ");
		scanf("%d", &play);
		if (play==0){
			display();
		}
	}while(play==1);
}
int checkwin(char *ptr){
    if (*(ptr +1) == *(ptr +2) && *(ptr +2) == *(ptr +3) && *(ptr +1)!=' ')
        return 1;
        
    else if (*(ptr +4) == *(ptr +5) && *(ptr +5) == *(ptr +6) && *(ptr +4)!=' ')
        return 1;
        
    else if (*(ptr +7) == *(ptr +8) && *(ptr +8) == *(ptr +9) && *(ptr +7)!=' ')
        return 1;
        
    else if (*(ptr +1) == *(ptr +4) && *(ptr +4) == *(ptr +7) && *(ptr +1)!=' ')
        return 1;
        
    else if (*(ptr +2) == *(ptr +5) && *(ptr +5) == *(ptr +8) && *(ptr +2)!=' ')
        return 1;
        
    else if (*(ptr +3) == *(ptr +6) && *(ptr +6) == *(ptr +9) && *(ptr +3)!=' ')
        return 1;
        
    else if (*(ptr +1) == *(ptr +5) && *(ptr +5) == *(ptr +9) && *(ptr +1)!=' ')
        return 1;
        
    else if (*(ptr +3) == *(ptr +5) && *(ptr +5) == *(ptr +7) && *(ptr +3)!=' ')
        return 1;
        
    else if (*(ptr +1) != ' ' && *(ptr +2) != ' ' && *(ptr +3) != ' ' &&
        *(ptr +4) != ' ' && *(ptr +5) != ' ' && *(ptr +6) != ' ' && *(ptr +7) 
        != ' ' && *(ptr +8) != ' ' && *(ptr +9) != ' ')

        return 0;
    else
        return  - 1;
}
void board(char *ptr){
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \t\t     |     |     \n");
    printf("  %c  |  %c  |  %c \t\t  %c  |  %c  |  %c \n", *(ptr+1), *(ptr+2), *(ptr+3),'1','2','3');

    printf("_____|_____|_____\t\t_____|_____|_____\n");
    printf("     |     |     \t\t     |     |     \n");

    printf("  %c  |  %c  |  %c \t\t  %c  |  %c  |  %c \n", *(ptr+4), *(ptr+5), *(ptr+6),'4','5','6');

    printf("_____|_____|_____\t\t_____|_____|_____\n");
    printf("     |     |     \t\t     |     |     \n");

    printf("  %c  |  %c  |  %c \t\t  %c  |  %c  |  %c \n", *(ptr+7), *(ptr+8), *(ptr+9),'7','8','9');

    printf("     |     |     \t\t     |     |     \n");
}
int MediumBot(char *ptr){
	int x=0;
	if (*(ptr +1)=='O'&&*(ptr +2)=='O'&& *(ptr +3)==' ')
	x=3;
	else if (*(ptr +2)=='O'&&*(ptr +3)=='O' && *(ptr +1)==' ')
	x=1;
	else if (*(ptr +1)=='O'&&*(ptr +3)=='O' && *(ptr +2)==' ')
	x=2;
	else if (*(ptr +4)=='O'&&*(ptr +5)=='O'&& *(ptr +6)==' ')
	x=6;
	else if (*(ptr +5)=='O'&&*(ptr +6)=='O'&& *(ptr +4)==' ')
	x=4;
	else if (*(ptr +4)=='O'&&*(ptr+6)=='O'&& *(ptr +5)==' ')
	x=5;
	else if (*(ptr +7)=='O'&&*(ptr +8)=='O'&& *(ptr +9)==' ')
	x=9;
	else if (*(ptr +8)=='O'&&*(ptr +9)=='O'&& *(ptr +7)==' ')
	x=7;
	else if (*(ptr +7)=='O'&&*(ptr +9)=='O'&& *(ptr +8)==' ')
	x=8;
	else if (*(ptr +1)=='O'&&*(ptr +4)=='O'&& *(ptr +7)==' ')
	x=7;
	else if (*(ptr +4)=='O'&&*(ptr +7)=='O'&& *(ptr +1)==' ')
	x=1;
	else if (*(ptr +1)=='O'&&*(ptr +7)=='O'&& *(ptr +4)==' ')
	x=4;
	else if (*(ptr +2)=='O'&&*(ptr +5)=='O'&& *(ptr +8)==' ')
	x=8;
	else if (*(ptr +5)=='O'&&*(ptr +8)=='O'&& *(ptr +2)==' ')
	x=2;
	else if (*(ptr +2)=='O'&&*(ptr +8)=='O'&& *(ptr +5)==' ')
	x=5;
	else if (*(ptr +3)=='O'&&*(ptr +6)=='O'&& *(ptr +9)==' ')
	x=9;
	else if (*(ptr +6)=='O'&&*(ptr +9)=='O'&& *(ptr +3)==' ')
	x=3;
	else if (*(ptr +3)=='O'&&*(ptr +9)=='O'&& *(ptr +6)==' ')
	x=6;
	else if (*(ptr +1)=='O'&&*(ptr +5)=='O'&& *(ptr +9)==' ')
	x=9;
	else if (*(ptr +5)=='O'&&*(ptr +9)=='O'&& *(ptr +1)==' ')
	x=1;
	else if (*(ptr +1)=='O'&&*(ptr +9)=='O'&& *(ptr +5)==' ')
	x=5;
	else if (*(ptr +3)=='O'&&*(ptr +5)=='O'&& *(ptr +7)==' ')
	x=7;
	else if (*(ptr +5)=='O'&&*(ptr +7)=='O'&& *(ptr +3)==' ')
	x=3;
	else if (*(ptr +3)=='O'&&*(ptr +7)=='O'&& *(ptr +5)==' ')
	x=5;
	
	else if (*(ptr +1)=='X'&&*(ptr +2)=='X'&& *(ptr +3)==' ')
	x=3;
	else if (*(ptr +2)=='X'&&*(ptr +3)=='X' && *(ptr +1)==' ')
	x=1;
	else if (*(ptr +1)=='X'&&*(ptr +3)=='X' && *(ptr +2)==' ')
	x=2;
	else if (*(ptr +4)=='X'&&*(ptr +5)=='X'&& *(ptr +6)==' ')
	x=6;
	else if (*(ptr +5)=='X'&&*(ptr +6)=='X'&& *(ptr +4)==' ')
	x=4;
	else if (*(ptr +4)=='X'&&*(ptr +6)=='X'&& *(ptr +5)==' ')
	x=5;
	else if (*(ptr +7)=='X'&&*(ptr +8)=='X'&& *(ptr +9)==' ')
	x=9;
	else if (*(ptr +8)=='X'&&*(ptr +9)=='X'&& *(ptr +7)==' ')
	x=7;
	else if (*(ptr +7)=='X'&&*(ptr +9)=='X'&& *(ptr +8)==' ')
	x=8;
	else if (*(ptr +1)=='X'&&*(ptr +4)=='X'&& *(ptr +7)==' ')
	x=7;
	else if (*(ptr +4)=='X'&&*(ptr +7)=='X'&& *(ptr +1)==' ')
	x=1;
	else if (*(ptr +1)=='X'&&*(ptr +7)=='X'&& *(ptr +4)==' ')
	x=4;
	else if (*(ptr +2)=='X'&&*(ptr +5)=='X'&& *(ptr +8)==' ')
	x=8;
	else if (*(ptr +5)=='X'&&*(ptr +8)=='X'&& *(ptr +2)==' ')
	x=2;
	else if (*(ptr +2)=='X'&&*(ptr +8)=='X'&& *(ptr +5)==' ')
	x=5;
	else if (*(ptr +3)=='X'&&*(ptr +6)=='X'&& *(ptr +9)==' ')
	x=9;
	else if (*(ptr +6)=='X'&&*(ptr +9)=='X'&& *(ptr +3)==' ')
	x=3;
	else if (*(ptr +3)=='X'&&*(ptr +9)=='X'&& *(ptr +6)==' ')
	x=6;
	else if (*(ptr +1)=='X'&&*(ptr +5)=='X'&& *(ptr +9)==' ')
	x=9;
	else if (*(ptr +5)=='X'&&*(ptr +9)=='X'&& *(ptr +1)==' ')
	x=1;
	else if (*(ptr +1)=='X'&&*(ptr +9)=='X'&& *(ptr +5)==' ')
	x=5;
	else if (*(ptr +3)=='X'&&*(ptr +5)=='X'&& *(ptr +7)==' ')
	x=7;
	else if (*(ptr +5)=='X'&&*(ptr +7)=='X'&& *(ptr +3)==' ')
	x=3;
	else if (*(ptr +3)=='X'&&*(ptr +7)=='X'&& *(ptr +5)==' ')
	x=5;
	else if(*(ptr+5)=='X'&& *(ptr+9)=='X'&&*(ptr+3)==' ')
	x=3;
	else if((*(ptr+1)=='X' || *(ptr+2)=='X' || *(ptr+3)=='X' || *(ptr+4)=='X' || *(ptr+6)=='X' || *(ptr+7)=='X' || *(ptr+8)=='X' || *(ptr+9)=='X') && ( *(ptr+5)== ' '))
	x=5;
	else if(*(ptr+1)=='X' && *(ptr+2)==' ')
	x=2;
	else if(*(ptr+3)=='X'&& *(ptr+2)==' ')
	x=2;
	else if(*(ptr+7)=='X'&& *(ptr+8)==' ')
	x=8;
	else if(*(ptr+9)=='X'&& *(ptr+8)==' ')
	x=8;
	else if(*(ptr+5)=='X'&& *(ptr+1)==' ')
	x=1;
	
	else 
	{	
		while (square[x]!=' ')
		{
			x = rand() %9;
			x++;
		}
	}
	return x;
	
}
int validmove(char mark,int choice,char *ptr){
	
	if (choice == 1 && *(ptr +1) == ' ')
	{
		*(ptr +1) = mark;
		return 1;
	}
    else if (choice == 2 && *(ptr +2) == ' ')
    {
    	*(ptr +2) = mark;
    	return 1;
	}
    else if (choice == 3 && *(ptr +3) == ' ')
    {
    	*(ptr +3) = mark;
    	return 1;
	}
    else if (choice == 4 && *(ptr +4) == ' ')
    {
    	*(ptr +4) = mark;
    	return 1;
	}
    else if (choice == 5 && *(ptr +5) == ' ')
    {
    	*(ptr +5) = mark;
    	return 1;
	}
    else if (choice == 6 && *(ptr +6) == ' ')
    {
    	*(ptr +6) = mark;
    	return 1;
	}
    else if (choice == 7 && *(ptr +7) == ' ')
    {
    	*(ptr +7) = mark;
    	return 1;
	}
    else if (choice == 8 && *(ptr +8) == ' ')
    {
    	*(ptr +8) = mark;
    	return 1;
	}
    else if (choice == 9 && *(ptr +9) == ' ')
    {
    	*(ptr +9) = mark;
    	return 1;
	}
	else
	return 0;
}
void restart(char *ptr){
	int i;
	for(i=1;i<=9;i++)
	{
		*(ptr+i)=' ';
	}
}


