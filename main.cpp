#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAXWIDTH  50
#define MAXHIGHT  20
int xb,yb,xg,yg, LifeIndex = 100;
float OldDistance , NewDistance = sqrt(pow(xg-xb,2)+pow(yg-yb,2));
char move ;
int  xm = 1 + rand()%MAXWIDTH;
int  ym = 1 + rand()%MAXHIGHT;
int  xp = 1 + rand()%MAXWIDTH;
int  yp = 1 + rand()%MAXHIGHT;
void GotoXY(int x, int y);
void gotoxy(int x, int y);
void LOGOEIDIA2(int s);
void BOMB();
void Map();
void PLUS();
void map();
void Draw();
void load();
void Print();
void Generate();
void input();
void gameover();




int Scoreonly();
void record();
int Score();



void sleep(clock_t duree){
	clock_t time_out = clock();
	while((time_out + duree) > clock());
}

/************/


int main(int argc, char *argv[]) {
	system("color 9");
    Print();
    system("cls");
    load();
	Map();
	do{
		sleep(0);
		Draw();
		input();
	}while((xg!=xb||yg!=yb)&&LifeIndex!=0);
	if(xg==xb&&yg==yb&&LifeIndex>=0){
		system("cls");
		printf("\t\tYOU WON !!!");
	}else{
	 gameover();
	}
	
	
	record();
	
	
	
	return 0;
}

/************/


void LOGOEIDIA2(int s){ 
int i;
int k=3;
char charr[]="ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\ncccccqqqqqqqqqqqqqqqccccqqqqqqqqqqqqqqcccccqqqqcccccccccccccqqqqqqqqqqqqqqcccccccccccccccccccccqccccccccccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqcccqqcccccccccccccccccqqccccccccccccccccccccccccccqcqcccccccccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqccccqqqcccccccccccccccqqcccccccccccccccccccccccccqcccqccccccccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqccccccqqccccccccccccccqqccccccccccccccccccccccccqcccccqcccccccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqcccccccqqcccccccccccccqqcccccccccccccccccccccccqcccccccqccccccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqccccccccqqccccccccccccqqccccccccccccccccccccccqqqqqqqqqqqcccccccccccccccc\ncccccqqqqqqqqqqqqqqqccccccccccqqcccccccccccqcccccccccqqqccccccccccqqcccccccccccccccccccccqcccccccccccqccccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqcccccccccqqqccccccccccqqccccccccccccccccccccqcccccccccccccqcccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqccccccccqqccccccccccccqqcccccccccccccccccccqcccccccccccccccqccccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqcccccccqqcccccccccccccqqccccccccccccccccccqcccccccccccccccccqcccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqccccccqqccccccccccccccqqcccccccccccccccccqcccccccccccccccccccqccccccccccc\ncccccqccccccccccccccccccccccccqqcccccccccccqccccqqqcccccccccccccccqqccccccccccccccccqcccccccccccccccccccccqcccccccccc\ncccccqqqqqqqqqqqqqqqccccqqqqqqqqqqqqqqcccccqqqqqccccccccccccqqqqqqqqqqqqqqcccccccccqcccccccccccccccccccccccqccccccccc\nccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\nccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
for(i=0;i<1850;i++){
if (charr[i]=='c'){

printf(" ");
}
else if (charr[i]=='q') {
printf("%c",184);
}
else {
printf("%c",charr[i]); // Pour renplire
}
if (s!=0){/*                   sinon si s=0 en aura EIDIA FIGER                  */
          /*             */
Sleep(s);/*        POUR AFFICHER LIGNE PAR Ligne                               */
}             }
}// END FONCTION LOGOEIDIA2()
void Draw(){
	system("cls");
	int i,j;
	printf("  life index : %d %%\n",LifeIndex);
	for(i=0; i<=LifeIndex/20; i++){
	printf("  %c", 3);

	}
		printf("\t\t");
		
    PLUS();
	BOMB();
	printf("\n");
	for( i =0 ;i<MAXHIGHT;i++){
		for( j=0;j<MAXWIDTH;j++){
			if(i==0 || i == MAXHIGHT-1) printf(" %c",169);
			else if (j==0 || j == MAXWIDTH-1) printf(" %c",186);
			else if (i == yg && j == xg) printf(" %c",2); 
		
		
		/*
			else if (i == yb && j == xb) printf(" %c",2);
			else if (i == ym && j == xm) printf(" %c",3);
			else if (i == yp && j == xp) printf(" %c",4);
			   */
			else printf("  ");
		}
		printf("\n");
	}
}

void BOMB(){
	 if(xg==xm &&yg ==ym){
	LifeIndex=LifeIndex-20;
	printf("\t Oops ! A BOMB !! Be More careful next time!\n");
   srand(time(NULL));
	xm = 1 + rand()%MAXWIDTH;
	ym = 1 + rand()%MAXHIGHT;
}
}
void PLUS(){
	if(xg==xp &&yg ==yp){
	LifeIndex=LifeIndex+20;
	printf("\t Congrats you have just found an extra life  .\n");
    srand(time(NULL));
	 xp = 1 + rand()%MAXWIDTH;
	 yp = 1 + rand()%MAXHIGHT;
}
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void load()
{
    int row,col,r,c,q;
    gotoxy(30,12);
    system("color 9");
    printf("loading...");
    gotoxy(30,13);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    getch();
}
void Print()
{
	LOGOEIDIA2(3);
	getch();
	system("cls");
    printf("\t\t\t\tWelcome to JUMANJI game . \n");
    printf("\n Game instructions : You need to find the hidden treasure somewhere in the platform .\n But be careful , there are mines everywhere in the plateform and they may cost you a 20 %% of your life  .\n Also there are prizes everywhere in the plateform and they may give you an extra life 20 %% .");
    printf("\n\n Press any key to play the game...");
    getch();
    system("cls");
    if(getch()==27)
    exit(0);
}

void Generate(){
	srand(time(NULL));
	 xb = 1 + rand()%MAXWIDTH;
	 yb = 1 + rand()%MAXHIGHT;
}
void gameover()
{
	system("color 4");
	printf("****       **       ***      ***\n");
	printf("*                *    *   *     *     *   *\n");
	printf("*               *      *  *     *     *   *   \n");
	printf("*               ****  *     *     *   *\n");
	printf("*     **    *      *  *     *     *   ****\n");
	printf("*           *   *      *  *     *     *   *\n");
	printf("*           *   *      *  *     *     *   *\n");
	printf("****     *      *  *     *     *    ****\n");
	printf("\n");
    printf(" ***    *        *   *** ***\n");
    printf("*         *   *        *  *         *        *\n");
    printf("*         *   *        *  *         *        *\n");
	printf("*         *   *        *  *         *       *\n");
	printf("*         *   *        *  ***  ***\n");
	printf("*         *   *        *  *         *      *\n");
	printf("*         *   *        *  *         *        *\n");
	printf("*         *    *      *   *         *         *\n");
	printf(" ***         *       **** *         *\n");

}


void Map(){
	MAXWIDTH ;
    MAXHIGHT ;
    Generate();
    xg = MAXWIDTH/2;
    yg = MAXHIGHT/2;
    
}
void input(){
     move = getch();
	 if((move==75)&&(xg>1)){
	   		xg--;
	   			LifeIndex=LifeIndex-2;
	    }else if((move==77)&&(xg<MAXWIDTH-2)){
	   		xg++;
	   		LifeIndex=LifeIndex-2;
	    }else if((move==72)&&(yg>1)){
		    yg--;
		   	LifeIndex=LifeIndex-2;
		}else if((move==80)&&(yg<MAXHIGHT-2)){
		    yg++;
		LifeIndex=LifeIndex-2;
		}
	
		OldDistance = NewDistance; 
		
		
		system("cls"); 
}

void record()
{
	system("color 9");
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    getch();
    system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]",plname);
    //********
    for(j=0; plname[j]!='\0'; j++) //to convert the first letter after space to capital
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';
    //***********
    //sdfprintf(info,"\t\t\tPlayers List\n");
    fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date:%s",ctime(&mytime));
    //**********
    fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    //fprintf(info,"\nLevel:%d\n",10);//call level to display level
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records press 'y'\n");
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}



int Scoreonly()
{
    int score=Score();
    system("cls");
    return score;
}
int Score()
{
    int score;
    GotoXY(20,8);
    score= MAXHIGHT-5;
    printf("SCORE : %d",( MAXHIGHT-5));
    score= MAXHIGHT-5;
    GotoXY(50,8);
    printf("Life : %d",LifeIndex);
    return score;
}
