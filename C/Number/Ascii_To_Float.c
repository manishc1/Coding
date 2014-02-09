/*
Please use this Google doc to code during your interview. To make hands free coding a little easier, we recommend that you use a headset or a phone with speaker option.

Best,
Google Staffing
*/

//Hi!!!
//atof

//“12.34” ⇒ 12.34

#define MAX 10

float (char *str) {

	char I[MAX] = “”, F[MAX] = ””;

	int i, j;
	float ret = 0;

	i=0;
	while (str[i]!=’.’ & str[i]!=’\0’) {
		I[i] = str[i];
		i++;
	}
	I[i] = ‘\0’;

	j=0; i++;
	while(i < strlen(str)) {
		F[j] = str[i];
		i++;
		j++;
	}

	ret = parse_the_integer(I);
	ret += parse_the_float(F);

	return ret;
}

// .123
int parse_the_integer(char *I) {
	int ret = 0, i=0, num;
	while(I[i] != ‘\0’) {
		num = I[i] - ‘0’;
		ret = ret * 10 + num;
		i++;
	}
	return ret;
}

// .123 = 1/10 + 2/100 + 3/1000
float parse_the_float(char * F) {
	float ret = 0;
	int i = 0 , num, p = 1;
	while (F[i] != ‘\0’) {
		num = F[i] - ‘0’;
		ret = ret + num / pow(10,p);		// ret = 0.1 + 2/100
i++;
p++; 
}
return ret;
}

/*
Q2:

isNumberGiven(n)
markNumberAsGiven(n)
getAFreeNumber()
123 124

.
|
1(1,99)	
|
2(1,1)
/\
3(1) 4(0)

*/
