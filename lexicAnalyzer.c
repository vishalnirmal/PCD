#include<stdio.h>
#include<string.h>
int accept(char bf[])
{
	FILE *fp;
	int i=0;
	fp=fopen("read.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%c",&bf[i++]);
	}
	fclose(fp);
	return i;
}
int isKeyword(char s[])
{
	char key[32][20]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
	int len=strlen(s);
	int i,j;
	for(i=0;i<32;i++)
	{
		if(strcmp(key[i],s)==0)
			return 1;
	}
	return 0;
}
int checkIdentifier(char input[])
{
	int i=0,len;
	len=strlen(input);
	if(!(input[0]>=65 && input[0]<=90 || input[0]>=97 && input[0]<=122))
		return 0;
	else if(len>1){
		for(i=1;i<len;i++){
			if(!((input[i]>=65 && input[i]<=90 || input[i]>=97 && input[i]<=122)||(input[i]>=48 && input[i]<=57)||(input[i]=='_')))
				return 0;
		}
	}
	return 1;
}
int isConstant(char input[])
{
	int i=0,len;
	len=strlen(input);
	if(!(input[0]>=48 && input[0]<=57))
		return 0;
	else if(len>1){
		for(i=1;i<len;i++){
			if(!((input[i]>=48 && input[i]<=57 || input[i]=='.')||(input[i]>=48 && input[i]<=57)||(input[i]=='_')))
				return 0;
		}
	}
	return 1;
}
int checkSeperator(char ch,char sep[])
{
	int i;
	for (i = 0; i < strlen(sep); ++i)
	{
		if(sep[i]==ch)
			return 1;
		if(ch=='\n')
			return 1;
		if(ch==' ')
			return 1;
	}
	return 0;
}
int checkConsecutive(char* input,int i)
{
	if(input[i]=='='&&input[i+1]=='=')
		return 1;
	if(input[i]=='!'&&input[i+1]=='=')
		return 1;
	if(input[i]=='>'&&input[i+1]=='=')
		return 1;
	if(input[i]=='<'&&input[i+1]=='=')
		return 1;
	if(input[i]=='>'&&input[i+1]=='>')
		return 1;
	if(input[i]=='<'&&input[i+1]=='<')
		return 1;
	if(input[i]=='|'&&input[i+1]=='|')
		return 1;
	if(input[i]=='&'&&input[i+1]=='&')
		return 1;
	if(input[i]=='+'&&input[i+1]=='+')
		return 1;
	if(input[i]=='-'&&input[i+1]=='-')
		return 1;
	return 0;
}
int main()
{
	char input[10000],buffer[100];
	char ss[]="+-*/%^&|=,;()[]{}><\'\"\"\'";
	int l = accept(input);
	int i,j,k=0,n,flag=1,comments=0,string=0;;
	for (i = 0; i < l; ++i)
	{
		if(input[i]=='\n')
			flag=1;
		if(input[i]=='/' && input[i+1]=='/'){
				flag=0;
				i++;
				comments++;
		}
		if((input[i]>=65 && input[i]<=90 || input[i]>=97 && input[i]<=122)||(input[i]>=48 && input[i]<=57)||(input[i]=='.'))
		{
			if(flag==1)
			buffer[k++]=input[i];
		}
		else if(checkSeperator(input[i],ss) && k!=0)
		{
			buffer[k]='\0';
			if(isKeyword(buffer))
				printf("<%s, keyword>\n",buffer);
			else if(checkIdentifier(buffer))
				printf("<%s, identifier>\n",buffer);
			else if(isConstant(buffer))
				printf("<%s, constant>\n",buffer);
			k=0;
		}
		if(input[i]==34)
		{
			printf("<%c, symbol>\n", input[i]);
			char buf[1000];
			int counter=0;
			i++;
			while(input[i]!='\"'){
				buf[counter++]=input[i++];
			}
			buf[counter]='\0';
			printf("<%s, constant>\n", buf);
		}
		if(input[i]=='\'')
		{
			printf("<%c, symbol>\n", input[i]);
			char buf[1000];
			int counter=0;
			i++;
			while(input[i]!='\''){
				buf[counter++]=input[i++];
			}
			buf[counter]='\0';
			printf("<%s, constant>\n", buf);
		}
		if(checkSeperator(input[i],ss) && checkConsecutive(input,i))
		{
			char temp[3];
			temp[0]=input[i];
			temp[1]=input[++i];
			temp[2]='\0';
			printf("<%s, symbol>\n", temp);
		}
		else{
		for(j=0;j<strlen(ss);j++)
		{
			if(input[i]==ss[j] && flag==1){
				printf("<%c , symbol>\n", ss[j]);
				break;
			}
		}
		}
	}
	printf("No. of comments: %d",comments);
	return 0;
}