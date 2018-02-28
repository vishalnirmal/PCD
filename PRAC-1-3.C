#include<stdio.h>
int cmp(char[],char[]);
void check(char[],char[]);
void signup(char[],char[]);
int cmp(char s1[],char s2[])
{
	int i,s1l,s2l;
	s1l=sizeof(s1)-1;
	s2l=sizeof(s2)-1;
	if(s1l==s2l)
	{
		for(i=0;i<s1l;i++)
			if(s1[i]!=s2[i])
				break;
		if(i == s1l)
			return 1;
	}
	return 0;
}
void check(char name[],char pass[])
{
	FILE *secret;
	char nm[100],ps[100];
	int i,namef=1,passf=1;
	secret = fopen("secret.txt","r");
	while(!feof(secret))
	{
		fscanf(secret,"%s\t%s",&nm,&ps);
		if(cmp(name,nm))
		{
			namef=0;
			if(cmp(pass,ps)){
				printf("Signed in.");
				break;
			}
			else{
				printf("Password incorrect.");
				break;
			}
		}
	}
	if (namef==1)
	{
		printf("Username doesnot exist.");
	}
	fclose(secret);
}
void signup(char name[],char pass[])
{
	FILE *secret;
	secret = fopen("secret.txt","a+");
	//if(checkname(name,secret))
	fprintf(secret,"%s\t%s\n",name,pass);
	fclose(secret);
}
int main()
{
	char c[2];
	char name[100],pass[100];
	printf("1.Sign in\n2.Sign up\n");
	gets(c);
	printf("Enter name: ");
	gets(name);
	printf("Enter password: ");
	gets(pass);
	if(c[0]=='1')
		check(name,pass);
	else if(c[0]=='2')
		signup(name,pass);
	else
		printf("Wrong input.");
	return 0;
}