#include <stdio.h>
void write(FILE*);
void read(FILE*);
int freq(char, FILE*);
void encrypt(FILE*,FILE*);
void decrypt(FILE*,FILE*);
void write(FILE *fp)
{
	if(fp!=NULL)
	{
		printf("Enter data to encrypt\n");
		char str[100];
		scanf("\n%[^\n\t]", str);
		fputs(str,fp);
		fclose(fp);
	}
	else
		printf("File is not created\n");
}
void read(FILE *fp)
{
	if(fp!=NULL)
	{
		printf("Reading the data\n");
		char ch=fgetc(fp);
		while(ch!=EOF)
		{
			printf("%c",ch);
			ch=fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("File is not opened\n");
}
int freq(char ch,FILE *fp)
{
	int cnt=0;
	fseek(fp,0,SEEK_SET);
	char op=fgetc(fp);
	while(op!=EOF)
	{
		if(ch==op)
			cnt++;
		op=fgetc(fp);
	}
	return cnt;
}
void encrypt(FILE *fp1, FILE *fp2) //writes encrypted data of fp1 in fp2
{
	char ch=fgetc(fp1);
	while(ch!=EOF)
	{
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			int curPos=ftell(fp1);
			int cnt=freq(ch,fp1);
			fseek(fp1,curPos,SEEK_SET);
			char k= ch + cnt; //Case-sensitive encryption
			fputc(k,fp2);
		}
		else
			fputc(ch,fp2);
		ch=fgetc(fp1);
	}
	printf("\nEncryption is completed\n");
	fclose(fp1);
	fclose(fp2);
}
void decrypt(FILE *fp2, FILE *fp3)
{
	char ch=fgetc(fp2);
	while(ch!=EOF)
	{
		if(ch>'A')
		{
			int curPos=ftell(fp2);
			int cnt=freq(ch,fp2);
			fseek(fp2,curPos,SEEK_SET);
			char k= ch - cnt; //Case-sensitive decryption
			fputc(k,fp3);
		}
		else
			fputc(ch,fp3);
		ch=fgetc(fp2);
	}
	printf("\nDecryption is completed\n");
	fclose(fp2);
	fclose(fp3);
}
int main()
{
	printf("Warning: Decryption fails if the data contains the following symbols\n");
	printf("^ _ [ ] \\ { } |\n");
	printf("(Their ASCII value is above 65, so program decrypt them)\n");
	printf("It also fails for cases like Ex: aab\ncount(a)=2, a+2=c, count(b)=1, b+1=c\n");
	printf("Encrypt: ccc, Decrypt: ```\n\n");
	FILE *fp1=NULL, *fp2=NULL, *fp3=NULL;
	fp1=fopen("test.txt","w");
	write(fp1); //scans upto a newline as string with max 99 characters
	fp1=fopen("test.txt","r");
	fp2=fopen("encrypt.txt","w");
	encrypt(fp1,fp2); // fp1-->Source fp2-->Destination for encryption
	fp2=fopen("encrypt.txt","r");
	read(fp2); //reads encrypted file
	fp2=fopen("encrypt.txt","r");
	fp3=fopen("decrypt.txt","w");
	decrypt(fp2,fp3);
	fp3=fopen("decrypt.txt","r");
	read(fp3); //reads decrypted file
	return 0;
}