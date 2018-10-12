#include<iostream.h>
#include<stdio.h>
#include<conio.h>

int strRemoveAll(char *src,char *key)
{
	while( *src )
	{
		char *k=key,*s=src;
		while( *k && *k==*s )
		{
			++k,++s;
		}
		if( !*k )
		{
			cout<<"\n\t---\n";
			while( *s )
			{
				*src++=*s++;
			}
			*src=0;
			cout<<"\n\t---/\n";

		}
		cout<<endl<<++src;
	}
	return 0;
}
int main()
{
	clrscr();
	char s[]="foo bar foo";
	puts(s);
	while( strRemoveAll(s,"foo") );
	puts(s);
	getch();
}