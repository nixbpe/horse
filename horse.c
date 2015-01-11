
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct horses{
	int min_speed,max_speed;
	int luck;
	int color;
	int pos;
}horses[5];

void welcome();
void line(char ch,int n);
void display_menu(int money);
int menu(int money);
void initial();
void horse();
int racing_horse();
void check_horse(int h,int m);
int choose_horse(int *m);
void other_match();
void win();
void lose();
void main(void)
{
	int win_horse = 0;
	int h=0;
	int money = 1000;
	int m=0;
	clrscr();
	textcolor(7);
	welcome();
	initial();
	do{
		win_horse = 0;
		switch(menu(money))
		{
		 case 1 : win_horse = racing_horse(); break;
		 case 2 : h = choose_horse(&m); break;
		 case 3 : check_horse(h,m); break;
		 case 4 : other_match(); h=0; m=0; break;
		 //case 1426 : money=20000; break;
		 case 0 : exit(0);//close(); break;
		 default: break;
		}
		if(h&&win_horse){
			if(h==win_horse)
			{
				printf("\n This round win!");
				money+=m;
			}else
			{
				printf("\n This round lose!");
				money-=m;
			}
			h=0;
			m=0;
			delay(1000);
		}else if(win_horse)
		{
			printf("\nYou don't play this round!!");
			delay(1000);
		}
		if(money>=20000)
		{
			win();
			return ;
		}if(money <=0)
		{
			lose();
			return ;
		}
	}while(1);
	//thank();
}

void welcome()
{
	gotoxy(26,5);
	printf("Welcom to Horse Racing Project!!! \n");

	gotoxy(38,15);
	printf("Presenst By");

	// Plese write name here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	gotoxy(30,20);
	printf("Write Name Here..........");
	delay(1500);
	clrscr();

}
int menu(int money)
{
	int i;
	int n;
	clrscr();
	//initial();
	for(i=0;i<5;i++)
	{       line('-',80);
		gotoxy(horses[i].pos,i*2+2);
		horse(i);
		textcolor(7);
		printf(" >> No.%d max_speed = %d,min_speed = %d !!!",i+1,horses[i].max_speed,horses[i].min_speed);
		printf("\n");
	}
	line('-',80);
	printf("");
	display_menu(money);
	scanf("%d",&n);
	//getch();
	clrscr();
	return n;
}
void line(char ch,int n){
	int i;
	for(i=0;i<n;++i){
		printf("%c",ch);
	}
}
void initial()
{
	int i;
	randomize();
	for(i=0;i<5;i++){
		horses[i].pos = 1;
		horses[i].min_speed = random(2)+1;
		horses[i].max_speed = random(5)+horses[i].min_speed+1;
	}
}
void horse(int i)
{
	textcolor(i+1);
	cprintf("мик╪");
}
void display_menu(int money)
{
	line('+',30);
	printf("\nNow you have money :%d\n",money);
	line('+',30);
	printf("\n1.> Go to Horse Racing!!\n");
	printf("2.> Go to Choose Horse!!\n");
	printf("3.> Go to Check Horse!!\n");
	printf("4.> Change Race Match!!\n");
	printf("0.> Exit from Program!!\n");
	line('+',30);
	printf("\n");
	printf("Plese Select menu(0-4): ");
}
int racing_horse()
{
	int i;
	int ex=0;
	randomize();
	while(ex==0)
	{
		clrscr();
		for(i=0;i<5;i++){
			line('-',80);
			horses[i].pos+=random(horses[i].max_speed-horses[i].min_speed)+horses[i].min_speed;
			gotoxy(horses[i].pos,i*2+2);
			horse(i);
			gotoxy(75,i*2+2);
			textcolor(7);
			printf("|");
		      //	printf("%d",horses[i].pos);
			printf("\n");
		}
		line('-',80);
		for(i=0;i<5;i++)
			if(horses[i].pos >= 70)
			{
				initial();
				getch();
				return i+1;
			}
		delay(200);

	}
	return 0;
}

void other_match()
{
	initial();
}

void check_horse(int h,int m)
{
	clrscr();
	if(h)
	{
		printf("You choose horse number is : %d\n",h);
		printf("Your money for horse is %d",m);
	}else
	{
		printf("You don't choose Horse!!\n");
	}
	printf("\n\n");
	printf("...please any Key to continue!!");
	getch();
}
int choose_horse(int *m)
{
	int h;
	clrscr();
	printf("Please number of your horse: ");
	scanf("%d",&h);
	printf("Please input money for horse: ");
	scanf("%d",m);
	return h;
}
void win()
{
	clrscr();
	printf("You Win!!");

	sound(750);
	delay(50);

	nosound();
	delay(100);

	sound(750);
	delay(50);

	nosound();
	delay(100);

	sound(750);
	delay(50);

	nosound();
	delay(150);

	sound(750);
	delay(350);

	nosound();
	delay(150);

	sound(600);
	delay(250);

	nosound();
	delay(150);

	sound(675);
	delay(325);

	nosound();
	delay(100);

	sound(750);
	delay(100);

	nosound();
	delay(150);

	sound(725);
	delay(75);

	nosound();
	delay(50);

	sound(750);
	delay(1500);

	nosound();

      //	delay(1000);
}
void lose()
{
	clrscr();
	printf("You Lose!!");
	delay(1000);
}