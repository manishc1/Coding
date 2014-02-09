
// BreakStringIntoSentence.c : Defines the entry point for the console application.
//

# include <stdio.h>
# include <string.h>

char dict[100][10] = {"the","road","is","clear","a"};
int n=5;
char stack[10][10];
int top = -1;

int isdictword(char *word)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(strcmp(word,dict[i]) == 0)
			return 1;
	}
	return 0;
}

int breaker(char *str)
{
	unsigned int i;
	char word[100] = "";
	if (strlen(str)==0)
		return 1;
	for (i=0; i<strlen(str);i++)
	{
		word[i] = str[i];
		word[i+1] = '\0';
		if(isdictword(word) && breaker(&str[i+1]))
		{
			strcpy(stack[++top], word);
			return 1;
		}
	}
	return 0;
}
int main()
{
	char str[100] = "atheroadisclear";
	if(!breaker(str))
		printf("Not Possible");
	else
		while(top>=0)
			printf("%s ", stack[top--]);
	getchar();
	return 0;
}