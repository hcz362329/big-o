#pragma once
#include <string>
bool IsReverseStr(char* text) {
	bool rev = true;
	int len = strlen(text);
	/*char ttt[] = "level";
	char ttt2[] = "1234567654321";
	char ttt5[] = "1234567754321";
	bool b1 = IsReverseStr(ttt);
	bool b2 = IsReverseStr(ttt2);
	bool b3 = IsReverseStr(ttt5);*/
	for (int i = 0; i < len / 2; i++) {
		/*char t = *(text + i);
		char q = *(text + len - i-1);*/
		if (*(text + i) != *(text + len - i - 1)) {
			rev = false;
			break;
		}
	}
	return rev;
}


int string_cmp(const char* src, const char* dst) {
	int ret = 0;
	while (!(ret = *src - *dst) && *dst && *src)
	{
		++src;
		++dst;
	}
		if ( ret < 0 )
			ret = -1 ;
		else if ( ret > 0 )
			ret = 1 ;
		return( ret );

}