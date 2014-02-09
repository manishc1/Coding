# include <stdio.h>

typedef struct struct_stack {
		char arr[100];
		int top;
} struct_stack;

void init(struct_stack* stack) {
		stack->top = -1;
}

int isEmpty(struct_stack* stack) {
		if (stack->top == -1)
				return 1;
		return 0;
}

void push(struct_stack* stack, char ch) {
		stack->arr[(++stack->top)] = ch;
}

char pop(struct_stack* stack) {
		return stack->arr[(stack->top--)];
}

int isBalanced(char* str) {
		struct_stack stack;
		init(&stack);
		while(*str != '\0') {
				if (*str == '{' || *str == '(' || *str == '[') {
						push(&stack, *str);
				} else if (*str == '}') {
						if (isEmpty(&stack) || pop(&stack) != '{')
								return 0;
				} else if (*str == ')') {
						if (isEmpty(&stack) || pop(&stack) != '(')
								return 0;
				} else if (*str == ']') {
						if (isEmpty(&stack) || pop(&stack) != '[')
								return 0;
				}
				str++;
		}
		if (isEmpty(&stack))
				return 1;
		return 0;
}

void main() {
		char str[100];
		printf("String :: ");
		scanf("%s", str);
		if (isBalanced(str))
				printf("Is Balanced\n");
		else
				printf("Not Balanced\n");
}
