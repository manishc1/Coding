# include <stdio.h>

# define MAXSIZE 10
# define INVALID -1

int table[MAXSIZE] = {INVALID};

int gethash(int key) {
		return key % MAXSIZE;
}

void init () {
		int i;
		for (i=0 ; i<MAXSIZE ; i++)
				table[i] = INVALID;
}

void add(int key) {
		int hash = gethash(key), start;
		if (table[hash] == INVALID) {
				table[hash] = key;
				return;
		}
		start = (hash + 1) % MAXSIZE;
		while (table[start] != INVALID && start != hash)
				start = (start + 1) % MAXSIZE;
		if (start == hash)
				printf("Cannot insert");
		else
				table[start] = key;
}

int find(int key) {
		int hash = gethash(key) , start;
		if (table[hash] == key)
				return hash;
		start = (hash + 1) % MAXSIZE;
		while(start != hash) {
				if (table[start] == key)
						return start;
				start = (start + 1) % MAXSIZE;
		}
		return -1;
}

void print() {
		int i;
		for (i=0 ; i<MAXSIZE ; i++)
				printf("%d ",table[i]);
		printf("\n");
}

void main() {
		init();
		add(4);
		add(14);
		printf("At : %d\n",find(14));
		print();
}
