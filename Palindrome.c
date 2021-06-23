//Palindrome

#include<stdio.h>

int isPalindrome(char*,int);

int main()
{
	char s[25];
	int size=0;
	printf("\nEnter a String: ");
	do
	{
		s[size]=getchar();
	}while(s[size++]!='\n');
	size--;
	s[size]='\0';
	
	if(isPalindrome(s,size))
	{
		printf("\n'%s' is a palindrome\n",s);
	}
	else
	{
		printf("\n'%s' is NOT a palindrome\n",s);
	}
}

int isPalindrome(char *s, int size)
{
	for(int i=0,j=size-1; i<j; i++,j--)
	{
		if(s[i]!=s[j])
		{
			return 0;
		}
	}
	return 1;
}