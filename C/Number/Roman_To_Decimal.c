/*
Given a string representing roman numeral, find and return its numeric value. e.g. XXIV = 24 and so on.
 */

# include <stdio.h>
# include <string.h>

int getDecimal(char c) {
        switch(c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
        }
}

int convert(char* roman) {
        int total = 0, i;
        char previous = roman[strlen(roman)-1];
        for (i = strlen(roman)-1; i>=0; i--) {
				int prev = getDecimal(previous);
				int curr = getDecimal(roman[i]);
				if (prev > curr)
						total -= curr;
				else {
						total += curr;
						previous = roman[i];
				}
        }
        return total;
}

void main() {
        char roman[] = "XXIV";
        printf("%d\n", convert("MIM"));
}
