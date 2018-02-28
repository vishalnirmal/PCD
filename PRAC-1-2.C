#include<stdio.h>
#include<conio.h>
void main()
{
	char str[300];
	int j,i=0,d=0,v=0,s=0;
	clrscr();
	printf("Enter the string: ");
	for(j=0;;j++)
	{
		scanf("%c",&str[j]);
		if(str[j]==10)
		break;
	}
	while(str[i]!='\0')
	{
		if(str[i]>=48 && str[i]<=57)
			d++;
		else if(((str[i]>=65 && str[i]<=90) || (str[i]>=97&&str[i]<=122)))
		{
			if(str[i]==97||str[i]==101||str[i]==105||str[i]==117||str[i]==65||str[i]==69||str[i]==73||str[i]==79||str[i]==85)
				v++;
		}
		else if(str[i]==' '||str[i]==10);
		else
			s++;
		i++;
	}
	printf("Vowels: %d\n",v);
	printf("Digits: %d\n",d);
	printf("Symbols: %d\n",s);
	getch();
}