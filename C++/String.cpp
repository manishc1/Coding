class myString {
	private:
		char *str;
		int *count;
	public:
		myString() {
			str = (char *)malloc(sizeof(char));
			count = (int *)malloc(sizeof(int));
			str[0] = ‘\0’;
			*count = 1;
		}

		myString(char *s) {
			int l = strlen(s) + 1;
			str = (char *)malloc(l*sizeof(char));
			count = (int *)malloc(sizeof(int));
			while(l>=0) {
				str[l] = s[l];
				l--;
			}
			*count = 1;
		}

		~myString() {
			if (*count == 1) {
				free(str);
				free(count);
			}
		}
};

myString & myString :: operator = (myString s) {
	int l = strlen(s.str) + 1;
	str = (char *) realloc (l*sizeof(char));
	while(l>=0) {
		str[l] = s.str[l];
		l--;
	}
}




myString & myString :: operator = (myString s) {
	if (*count == 1) {
free(str);
free(count);
}
else {
	(*count)--;
}
	str = s.str;
	count = s.count;
(*count)++;
}

int main() {
	char s[3] = “abc”, t[5] = “defgh”;
	myString s1(s), s2(t);
	s1 = s2;
	s1 = s3;
}
