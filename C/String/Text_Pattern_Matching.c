/*[a-z] 
? - any one char
* - 0 or more chars

a*b

acdb

// pattern abc
// text abcd
*/

bool match(const char* text, int textindex, const char* pattern, int patternindex) {
	bool ret = false, ismatch;

	if(strlen(text)==textindex && strlen(pattern)==patternindex)
		return true;

	while (pattern[patternindex]!=’*’ &&
		   pattern[patternindex!=’?’ &&
		   patternindex<strlen(pattern) &&
		   textindex<strlen(text)) {
		if(text[textindex] != pattern[patternindex])
			return false;
		textindex++;
		patternindex++;
 	}
	// patternindex == strlen(pattern) => pattern[patternindex] == ‘\0’;
	if(pattern[patternindex] == ‘?’) {
		return match(text, textindex+1, pattern, patternindex+1);
  	}

	if (pattern[patternindex] == ‘*’) {
		ret = match(text, textindex, pattern, patternindex+1);
		if (ret)
			return true;
		ismatch = false;
		for (i=textindex+1; i<strlen(text); i++)
			ismatch = ismatch | match(text, i, pattern, patternindex+1);
		return ismatch;
 	}

	return false;
}

/*
----------------------------------------------------------------

internationalization  i18n

min a0c

aaaa 4 3a

acdb 3b
aecd 3d 	1e2

axcd  3d   1x2




*/
