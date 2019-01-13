/* main.cpp step-3.7-1
 *
 * Добавьте в класс String реализацию конструктора копирования. Инвариант 
 * класса остается тем же (в size хранится размер строки без завершающего 0 
 * символа, str указывает на C-style строку, т. е. с завершающим нулевым 
 * символом).
 * 
 * Требования к реализации: вы можете заводить любые вспомогательные методы или 
 * функции, но не реализуйте заново методы из предыдущих заданий — они уже 
 * реализованы. При реализации не нужно вводить или выводить что-либо. 
 * Реализовывать main не нужно. Не используйте функции из cstdlib 
 * (malloc, calloc, realloc и free).
 */
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

struct String {
    String(const char *str = "") {
        this->size = strlen(str);
        char * copy_str = new char[this->size + 1];
        this->str = strcpy(copy_str, str);
    }
	
    String(size_t n, char c) {
        this->size = n;
        char * cStr = new char[n + 1];
        cStr[n+1] = '\0';

        for (size_t i = 0; i < n; ++i) {
            cStr[i] = c;
        }
        
        this->str = cStr;
    }

    /* Реализуйте конструктор копирования */
    String(const String &other) {
        this->size = other.size;
        this->str = new char[other.size + 1];

        for (size_t i = 0; i <= this->size; ++i) {
            this->str[i] = other.str[i];
        }
    }

    ~String(){
        delete [] str;
    }

    void append(String &other) {
        size_t newStrSize = this->size + other.size;
        char * tmpStr = new char[newStrSize + 1];
        tmpStr[newStrSize] = '\0';

        for (int i = 0; i < newStrSize; ++i) {
            if (i < this->size) {
                tmpStr[i] = this->str[i];
            } else {
                tmpStr[i] = other.str[i - this->size];
            }
        }
        delete [] str;
        this->size = newStrSize;
        this->str = tmpStr;
    }

	size_t size;
	char *str;
};

int main(void) {
    String origStr("The string");
    String copyStr(origStr);
    cout << origStr.str << "\n" << copyStr.str << endl;
    return 0;
}