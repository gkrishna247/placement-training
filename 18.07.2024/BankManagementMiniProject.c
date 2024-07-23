#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define nou 50//number of users
#define nos 20//number of statement
void vacnt( int usi);//user index array or struct
void vstmt(int usi);
void date(int*d,int*m,int*y,int *h,int *min,int*s);//date
void read();//read userdata
void readst(int usi);
void signup(int *usi);
void login(int uc);//total user count
void forpwd(int uc);//forgot password
void printname();
void afterlogin(int usi);//user index
void instate(int usi);//intialize first statement
struct user
{
	int sn;//serial number
	int dc[6];//date created
	char name[20];//account holder name
	char fname[20];//father name
	char mname[20];//mother name
	char ph[10];//phone number
	int dob[3]; //date of birth
	char at[20];//account type (savings/current)
	float bkbl;//book balance
	float bl;//credit balance
	char uid[20];//user id
	char pass[20];//pass word
	int an;//account number
}    u[nou];
struct statement
{
	int sno;
	int dop[6];//date of payment
	char des[20];//description
	float cr;//credit-deposit
	float db;//debit-withdrawn
	float bal;//balance
}s[nos];//number of statement records
int main()
{
	int op, usi ;
	read();
    do
    {
	printname();
	usi=0;
	while(u[usi].dc[2]==2023)
	{
		usi++;
	}
    printf("\n1. Sign up a account\n2. login to the account\n3. Forget password\n4. Exit\n");
    printf("\nEnter the choice:");
    scanf("%d",&op);
    switch (op)
    {
	case 1:
		signup(&usi);
		break;
	case 2:
		login(usi+1);
		break;
	case 3:
		forpwd(usi+1);
		break;
	case 4:
		break;
	default:
		printf("\nEnter the correct choice:");
		break;
    }
    system("cls");
    }while(op!=4);
	return 0;
}
void signup(int *usi)
{
	int i,act,ui=*usi;
	FILE *p4u;//all users
	p4u=fopen("userdata.txt","a+");
	u[ui].sn=ui+1;
	date(&u[ui].dc[0],&u[ui].dc[1],&u[ui].dc[2],&u[ui].dc[3],&u[ui].dc[4],&u[ui].dc[5]);//created date an d time
	printf("\nEnter your name:");
	scanf("%s",u[ui].name);
	printf("\nEnter your father name:");
	scanf("%s",u[ui].fname);
	printf("\nEnter your mother name:");
	scanf("%s",u[ui].mname);
	printf("\nEnter your phone number:");
	scanf("%s",u[ui].ph);
	printf("\nEnter your date of birth:");
	for(i=0;i<3;i++)  {
	scanf("%d",&u[ui].dob[i]);
	}
	printf("\n 1.savings account(initial deposit: 1000)\n 2.current account(initial deposit: 5000) ");
	printf("\nEnter your account type:");
	do{
	scanf("%d",&act);//account type
	if(act!=1&&act!=2)//and return true if both true
		printf("\nEnter the correct choice: ");
	}while (act!=1&&act!=2);//
	if (act==1)
	{
		strcpy(u[ui].at,"Savings_account");
		printf("\nEnter your initial deposit for creating savings account(not less than 1000): ");
		do{
			scanf("%f",&u[ui].bkbl);
			if(u[ui].bkbl<1000)
				printf("\nYour amount is low.Please re-enter:");
		}while(u[ui].bkbl<1000);
		u[ui].bl=u[ui].bkbl-1000;
	}
	if (act==2)
	{
		strcpy(u[ui].at,"current_account");
		printf("\nEnter your initial deposit for creating current account(not less than 5000): ");
		do{
			scanf("%f",&u[ui].bkbl);
			if(u[ui].bkbl<5000)
				printf("\nYour amount is low.Please re-enter:");
		}while(u[ui].bkbl<5000);
		u[ui].bl=u[ui].bkbl-5000;
	}
	printf("\nEnter your username:");
	scanf("%s",u[ui].uid);
	printf("\nEnter your password:");
	scanf("%s",u[ui].pass);
	u[ui].an=2223123+((ui+11)*(ui+9));
	printf("\nYour account number is:  %d",u[ui].an);
	fprintf(p4u,"%d %d %d %d %d %d %d %s %s %s %s %d %d %d %s %.2f %.2f %s %s %d ",
			u[ui].sn,u[ui].dc[0],u[ui].dc[1],u[ui].dc[2],u[ui].dc[3],u[ui].dc[4],
			u[ui].dc[5],u[ui].name,u[ui].fname,u[ui].mname,u[ui].ph,u[ui].dob[0],u[ui].dob[1],
			u[ui].dob[2],u[ui].at,u[ui].bkbl,u[ui].bl,u[ui].uid,u[ui].pass,u[ui].an);
	printf("\n Signed up successfully........\n PRESS ANY KEY TO CONTINUE ");
	instate(ui);
	*usi++;
	getch();
	fclose(p4u);
}
void login(int uc)
{
	int i,c=0;//no of user=user count
	char us[20],ps[20];
	read();
    printf("\nEnter your user id:");
	scanf("%s",us);
	for(i=0;i<uc;i++)
	{
		if(strcmp(u[i].uid,us)==0)
		{
			printf("\nEnter your password:");
			scanf("%s",ps);
			if(strcmp(u[i].pass,ps)==0)
			{
				printf("\n YOU ARE LOGGED IN......");
				printf("\nPRESS ANY KEY TO CONTINUE..........");
				getch();
				afterlogin(i);
			}
			else
			{
                printf("\nInvalid password");
                printf("\nPRESS ANY KEY TO GO BACK........");
				getch();
			}
			break;
		}
			c++;
	}
	if(c==uc)
	{
		printf("\nInvalid username");
		printf("\nPRESS ANY KEY TO GO BACK........");
		getch();
	}
}
void forpwd(int uc)
{

	char us[20],pno[10];
	int db[3],i,j,c=0,d=0;
	read ();
	printf("\nEnter your user id:");
	scanf("%s",us);
	for(i=0;i<uc;i++)
	{
		if(strcmp(u[i].uid,us)==0)
		{
			printf("\nEnter your date of birth:");
			for(j=0;j<3;j++)
			{
				scanf("%d",&db[j]);
				if(db[j]==u[i].dob[j])
					d++;
			}
			printf("\nEnter your phone number:");
			scanf("%s",pno);
			if(strcmp(pno,u[i].ph)==0)
			{
				d++;
			}
			if(d==4)
			{
				printf("\nYour password is %s",u[i].pass);
				getch();
				break;
			}
			else if(d!=4)
			{
				printf("\nIncorrect date of birth or phone number");
				getch();
				break;
			}
		}
		else
			c++;
	}
	if(c==uc)
	{
		printf("\nUser ID not found ");
		getch();
	}
}
void printname()
{
    printf(  "************************************************************************************************************");
    printf("\n* ZZZZZZZZZZZZ  EEEEEEEEEE  NNNN       NNN   *  BBBBBBBBB           AAAAA   NNNN        NNN   KKKK   KKKK  *");
    printf("\n* ZZZZZZZZZZZ   EEEEEEEEEE  NNNNNN      NNN  *  BBBBBBBBBB         AAAAAAA  NNNNNN       NNN  KKK   KKK    *");
    printf("\n*        ZZZ    EEE         NNN NNN     NNN  *  BBB     BBB       AAA  AAA  NNN NNN      NNN  KKK  KKK     *");
    printf("\n*       ZZZ     EEEE        NNN  NNN    NNN  *  BBB      BBB     AAA   AAA  NNN  NNN     NNN  KKK KK       *");
    printf("\n*      ZZZ      EEEEEEEEEE  NNN   NNN   NNN  *  BBBBBBBBBBB     AAAAAAAAAA  NNN    NNN   NNN  KKKKK        *");
    printf("\n*     ZZZ       EEEE        NNN    NNN  NNN  *  BBB     BBB    AAAAAAAAAAA  NNN     NNN  NNN  KKKKKK       *");
    printf("\n*    ZZZ        EEE         NNN     NNN NNN  *  BBB      BBB  AAA      AAA  NNN      NNN NNN  KKK  KKK     *");
    printf("\n*   ZZZZZZZZZZ  EEEEEEEEEE  NNN      NNNNNN  *  BBBBBBBBBBB  AAA       AAA  NNN       NNNNNN  KKK   KKK    *");
    printf("\n*  ZZZZZZZZZZZ  EEEEEEEEEE   NNN       NNNN  *  BBBBBBBBBB  AAA        AAA   NNN        NNNN  KKKK   KKKK  *");
    printf("\n************************************************************************************************************");
}
void afterlogin(int usi)
{
	int j,op,k;
	char fn[20];
	do{
	system ("cls");
	printname();
	printf("\nWELCOME  MR.%s",u[usi].name);
	printf("\n1 . View account details\n2 . View account statement\n3 . Logout");
	printf("\nEnter your option : ");
	scanf("%d",&op);
	switch(op)
	{
	case 1:
		vacnt(usi);
		break;
	case 2:
		vstmt(usi);
		break;
	case 3:
		break;
	default:
		printf("\nEnter correct choice:");
		printf("\nPRESS ANY KEY TO GO BACK");
		getch();
		break;
	}
	}while(op!=3);
}
void date(int*d,int*m,int*y,int *h,int *min,int*s)
{
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    *d=tm.tm_mday,*m=tm.tm_mon + 1,*y=tm.tm_year + 1900;
    *h=tm.tm_hour, *min=tm.tm_min, *s=tm.tm_sec;
}
void instate(int usi)
{
	char fn[20],de[20];
	read();
	FILE *p4s;
	date(&s[0].dop[0],&s[0].dop[1],&s[0].dop[2],&s[0].dop[3],&s[0].dop[4],&s[0].dop[5]);
	sprintf(fn,"user%d.txt",usi+1);
	p4s=fopen(fn,"w+");
	strcpy(de,"account_creation");
	fprintf(p4s,"1 %d %d %d %d %d %d %s %.2f 0.00 %.2f ",s[0].dop[0],
			s[0].dop[1],s[0].dop[2],s[0].dop[3],s[0].dop[4],s[0].dop[5],
			de,u[usi].bkbl,u[usi].bkbl);
	fclose(p4s);
}
void read()
{
	FILE *p4u;
	p4u=fopen("userdata.txt","r");
	int i=0;
	for(i=0;i<nou;i++)
	{
        fscanf(p4u,"%d%d%d%d%d%d%d%s%s%s%s%d%d%d%s%f%f%s%s%d",
			&u[i].sn,&u[i].dc[0],&u[i].dc[1],&u[i].dc[2],&u[i].dc[3],&u[i].dc[4],&u[i].dc[5],
			u[i].name,u[i].fname,u[i].mname,u[i].ph,&u[i].dob[0],&u[i].dob[1],&u[i].dob[2],
			u[i].at,&u[i].bkbl,&u[i].bl,u[i].uid,u[i].pass,&u[i].an);
	}
	fclose(p4u);
}
void vacnt(int usi)
{
	read();
	printf("\nYOUR ACCOUNT DETAILS ARE HERE");
	printf("\nNAME\t       : %s\nACCOUNT NUMBER : %d\nACCOUNT TYPE   : %s",
			u[usi].name,u[usi].an,u[usi].at);
	printf("\nFATHER NAME    : %s\nMOTHER NAME    : %s\nPHONE NUMBER   : %s",
			u[usi].fname,u[usi].mname,u[usi].ph);
	printf("\nBIRTH DATE     : %d/%d/%d\nBOOK BALANCE   : $ %.2f\nCREDIT BALANCE : $ %.2f",
			u[usi].dob[0],u[usi].dob[1],u[usi].dob[2],u[usi].bkbl,u[usi].bl);
	printf("\nUSER ID\t       : %s\nACCOUNT CREATED DATE : %d/%d/%d",u[usi].uid,
			u[usi].dc[0],u[usi].dc[1],u[usi].dc[2]);
	printf("\nPRESS ANY KEY TO GO BACK");
	getch();
}
void vstmt(int usi)
{
	char i=0;
	readst(usi);
	printf("\nS .NO      DATE  OF      TIME  OF            NOTE          \tCREDIT\t\tDEBIT\t\tBALANCE");
	printf("\n         TRANSACTIONS  TRANSACTIONS\n");
	for(i=0;s[i].dop[2]==2023;i++)
	{
		printf("\n  %d       %d/%d/%d      %d:%d:%d      %s\t\t%.2f\t\t%.2f\t\t%.2f \n",s[i].sno,
			s[i].dop[0],s[i].dop[1],s[i].dop[2],s[i].dop[3],s[i].dop[4],s[i].dop[5],
			s[i].des,s[i].cr,s[i].db,s[i].bal);
	}
	printf("\nPRESS ANY KEY TO GO BACK");
	getch();
}
void readst(int usi)
{
	char fn[10];
	int i=0;
	sprintf(fn,"user%d.txt",usi+1);
	FILE *p4s;
	p4s=fopen(fn,"r");
	for(i=0;i<nos;i++)
	{
		fscanf(p4s,"%d%d%d%d%d%d%d%s%f%f%f",&s[i].sno,
			&s[i].dop[0],&s[i].dop[1],&s[i].dop[2],&s[i].dop[3],&s[i].dop[4],
			&s[i].dop[5],s[i].des,&s[i].cr,&s[i].db,&s[i].bal);
	}
	fclose(p4s);
}












