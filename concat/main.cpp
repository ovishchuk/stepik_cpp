#include <iostream>

void strcat(char *to, const char *from) {
	for(;*to;to++);
	while((*to++ = *from++));
}


int main() {
	char str_1[100] = "String 1";
	const char *str_2 = "String 2";
	strcat(str_1, str_2);
	std::cout << str_1 << std::endl;
    return 0;
}
