#include<conio.h>
#include<stdio.h>
void menu();
void header();
void newfile();
void add();
void login();
void search();
void display();
void deleted();
void update();
int ch,count=0,f=0;
char tid[10];
char uname[20]="aadhaar";
char pass[20]="aadhar";
struct aadhar
{
	char en[18],name[10],fn[10],addr[10],dob[10],gender[10],phn_no[10];
}rec;
struct aadhar rec1={0};
void main()
{
	login();
}
void login()
{
	char un[10];
	char ps[10];
	header();
	while(count<3)
	{
		printf("\nusername:");
		scanf("%s",un);
		printf("password:");
		scanf("%s",ps);
		 if(strcmp(un,uname)==0&&strcmp(ps,pass)==0)
		 {
			 printf("***welcome***");
			 menu();
		 }
		 else
		 {
			 printf("try again!!:(");
			 count++;
			 getch();
			 login();
		 }
	 }

	if(count==3)
	 {
		 printf("Sorry!ur attempts are over :(");
		 getch();
		 exit();
	 }	


	 getch();
}
void menu()
{
	header();
	gotoxy(23,9);
	printf("\n1.CREATE A NEW APPLICATION");
	gotoxy(23,10);
	printf("\n2.ADD A NEW APPLICATION");
	gotoxy(23,11);
	printf("\n3.SEARCH A APPLICATION");
	gotoxy(23,12);
	printf("\n4.DISPLAY A APPLICATION");
	gotoxy(23,13);
	printf("\n5.DELETE A APPLICATION");
	gotoxy(23,14);
	printf("\n6.UPDATE A APPLICATION");
	gotoxy(23,15);
	printf("\n7.EXIT");
	gotoxy(23,16);
	printf("\nENTER UR CHOICE");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:newfile();
			break;
		case 2:add();
			break;
		case 3:search();
			break;
		case 4:display();
			break;
		case 5:deleted();
			break;
		case 6:update();
			break;
		case 7:exit(0);
	}
	getch();
}
void newfile()
{
	FILE *fp;
	fp=fopen("aadhar.txt","w");
	printf("\n ONE NEW FILE CREATED SUCCESFULLY");
	getch();
	fclose(fp);
	getch();
	menu();
}
void add()
{
	FILE *fp;
	fp=fopen("aadhar.txt","a+");
	if(fp==NULL)
	{
		printf("FILE IS NOT OPENED !!:(");
		getch();
		exit(0);
	}
	printf("\n ENTER ENROLLMENT NUMBER: ");
	scanf("%s",&rec.en);
	printf("\ENTER  NAME: ");
	scanf("%s",&rec.name);
	printf("\n ENTER FATHER NAME: ");
	scanf("%s",&rec.fn);
	printf("\n ENTER ADDRESS: ");
	scanf("%s",&rec.addr);
	printf("\n ENTER DATE OF BIRTH: ");
	scanf("%s",&rec.dob);
	printf("\n ENTER GENDER: ");
	scanf("%s",&rec.gender);
	printf("\n ENTER PHONE NUMBER: ");
	scanf("%s",&rec.phn_no);
	fwrite(&rec,sizeof(rec),1,fp);
	printf("\nYOUR NEW APPLICATION CREATED SUCCESFULLY!!:)");
	getch();
	fclose(fp);
	menu();
}
void search()
{
	FILE *fp;
	fp=fopen("aadhar.txt","r+");
	if(fp==NULL)
	{
		printf("FILE IS NOT OPENED");
		getch();
		exit(0);
	}
	printf("ENTER YOUR  ENROLLMENT ID TO BE SEARCHD:");
	scanf("%s",&tid);
	while(fread(&rec,sizeof(rec),1,fp))
	{
		if(!strcmp(rec.en,tid))
		{
			f=1;
			printf("\n\t\t\tAPPLICATION IS FOUND");
			printf("\nENROLLMENT ID :%s",rec.en);
			printf("\nNAME :%s",rec.name);
			printf("\nFATHER NAME:%s",rec.fn);
			printf("\nADDRESS:%s",rec.addr);
			printf("\nDATE OF BIRTH:%s",rec.dob);
			printf("\nGENDER:%s",rec.gender);
			printf("\nPHONE NUMBER:%s",rec.phn_no);
			printf("\n\n");
			getch();
		}
	}
	if(f==0)
		printf("\n\n\t\t\tAPPLICATION is not FOUND :(");
	getch();
	fclose(fp);
	menu();
}
void display()
{
	FILE *fp;
	fp=fopen("aadhar.txt","r+");
	if(fp==NULL)
	{
		printf("FILE IS NOT OPENED");
		getch();
		exit(0);
	}
	while(fread(&rec,sizeof(rec),1,fp))
	{
		if(strcmp(rec.id,'\0'))
		{
			f=1;
			printf("\nENROLLMENT ID :%s",rec.en);
			printf("\nNAME :%s",rec.name);
			printf("\nFATHER NAME:%s",rec.fn);
			printf("\nADDRESS:%s",rec.addr);
			printf("\nDATE OF BIRTH:%s",rec.dob);
			printf("\nGENDER:%s",rec.gender);
			printf("\nPHONE NUMBER:%s",rec.phn_no);
			printf("\n\n");
			getch();
		}
	}
	if(f==0)
		printf("\n\n\t\t\tAPPLICATION NOT FOUND :(");
	getch();
	fclose(fp);
	menu();
}
void deleted()
{
	FILE *fp;
	fp=fopen("aadhar.txt","r+");
	if(fp==NULL)
	{
		printf("FILE IS NOT OPENED");
		getch();
		exit(0);
	}
	printf("ENTER UR ENROLLMENT ID TO BE DELETED:");
	scanf("%s",&tid);
	while(fread(&rec,sizeof(rec),1,fp))
	{
		if(!strcmp(rec.id,tid))
		{
			f=1;
			printf("\n\t\t\tONE RECORD IS DELETED SUCCESSFULLY :)");
			printf("\nENROLLMENT ID :%s",rec.en);
			printf("\nNAME :%s",rec.name);
			printf("\nFATHER NAME:%s",rec.fn);
			printf("\nADDRESS:%s",rec.addr);
			printf("\nDATE OF BIRTH:%s",rec.dob);
			printf("\nGENDER:%s",rec.gender);
			printf("\nPHONE NUMBER:%s",rec.phn_no);
			printf("\n\n");
			getch();
			fseek(fp,ftell(fp)-sizeof(rec),0);
			fwrite(&rec1,sizeof(rec),1,fp);
		}
	}
	if(f==0)
	printf("\n\n\t\t\tAPPLICATION NOT FOUND :(");
	getch();
	fclose(fp);
	menu();
}
void update()
{
	FILE *fp;
	fp=fopen("aadhar.txt","r+");
	if(fp==NULL)
	{
		printf("FILE IS NOT OPENED");
		getch();
		exit(0);
	}
	printf("ENTER UR ID TO BE UPDATED:");
	scanf("%s",&tid);
	while(fread(&rec,sizeof(rec),1,fp))
	{
		if(!strcmp(rec.id,tid))
		{
			f=1;
			printf("\nENROLLMENT ID :%s",rec.en);
			printf("\nNAME :%s",rec.name);
			printf("\nFATHER NAME:%s",rec.fn);
			printf("\nADDRESS:%s",rec.addr);
			printf("\nDATE OF BIRTH:%s",rec.dob);
			printf("\nGENDER:%s",rec.gender);
			printf("\nPHONE NUMBER:%s",rec.phn_no);
			printf("\n\n");
			getch();
			printf("1.ENROLLMENT ID\n2.NAME \n3.FATHER NAME \n4.ADDRESS\n5.DATE OF BIRTH\n6.GENDER\n7.PHONE NUMBER\n");
			printf("enter ur choice :");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:printf("Enter your new Enrollment ID:");
					scanf("%s",rec.en);
					break;
				case 2:printf("Enter your new name:");
					scanf("%d",&rec.name);
					break;
				case 3:printf("Enter your Father name:");
					scanf("%s",rec.fn);
					break;
				case 4:printf("enter new address");
					scanf("%s",rec.addr);
					break;
				case 5:printf("Enter your Date of birth:");
					scanf("%s",rec.dob);
					break;
				case 6:printf("Enter Gender:");
					scanf("%s",rec.gender);
					break;
				case 7:printf("Enter your new phone number:");
					scanf("%s",rec.phn_no);
					break;
			}
			fseek(fp,ftell(fp)-sizeof(rec),0);
			fwrite(&rec,sizeof(rec),1,fp);
			printf("\n\t\t\tONE APPLICATION IS UPDATED SUCCESSFULLY!!:)");
		}
	}
	if(f==0)
		printf("\n\n\t\t\tAPPLICATION NOT FOUND :(");
	fclose(fp);
	getch();
	menu();
}
void header()
{
	clrscr();
	gotoxy(20,5);
	textcolor(YELLOW);
	cprintf("*******************************");
	gotoxy(10,6);
	textcolor(WHITE);
	cprintf("@@@@@@@@@@@@@@@....VIRTUAL AADHAR CARD GENERATION.... @@@@@@@@@@@@@@");
	gotoxy(20,7);
	textcolor(YELLOW);
	cprintf("********************************");
}