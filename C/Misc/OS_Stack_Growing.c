# include <stdio.h>

void foo() {
		int b;
		printf("\nb : %x", &b);
}

void main() {
		int a;
		printf ("a : %x", &a);
		foo();
}
