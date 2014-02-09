/*
Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.
*/

# include <stdio.h>

typedef struct stack {
		int arr[100];
		int top;
} stack;

void init (stack* s) {
		s->top = -1;
}

int isEmpty(stack *s) {
		if (s->top < 0)
				return 1;
		return 0;
}

void push(stack *s, int x) {
		s->arr[++(s->top)] = x;
}

int pop(stack *s) {
		if (isEmpty(s))
				return -1;
		return s->arr[(s->top)--];
}

int peek(stack *s) {
		return s->arr[s->top];
}

stack sort(stack *s) {
		stack r;
		init(&r);
		while(!isEmpty(s)) {
				int tmp = pop(s);
				while(!isEmpty(&r) && peek(&r) > tmp) {
						push(s, pop(&r));
				}
				push(&r, tmp);
		}
		return r;
}

void main() {
		stack s;
		int i;
		init(&s);
		for (i=10 ; i>0 ; i--)
				push(&s, i);
		stack r = sort(&s);
		while (!isEmpty(&r))
				printf("%d\n", pop(&r));
}
