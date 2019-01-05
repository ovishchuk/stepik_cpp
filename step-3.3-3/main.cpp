/* main.cpp step-3.3-3
 *
 * Реализованные в предыдущих заданиях конструкторы и деструктор берут на себя 
 * работу по управлению ресурсами. Теперь можно дополнить структуру String 
 * различными полезными методами. 
 * 
 * Для работы со строками можно придумать множество полезных методов 
 * (подумайте, какие методы пригодились бы вам, и чего вам не хватает для их 
 * реализации). Примером такого метода может послужить метод append — он 
 * добавляет копию строки-аргумента в конец текущей строки (т.е. в конец 
 * строки, у которой он был вызван).
 * 
 *      String s1("Hello,");
 *      String s2(" world!");
 * 
 *      s1.append(s2); // теперь s1 хранит "Hello, world!"
 * 
 * Ваша задача реализовать метод append.
 * 
 * При выполнении задания будьте аккуратны при работе с памятью — при вызове 
 * метода не должно возникать утечек памяти. Кроме того, не забудьте, что size 
 * хранит размер без учета завершающего 0 символа.
 * 
 * Требования к реализации: при реализации вы можете заводить любые 
 * вспомогательные функции и методы. В шаблоне вы увидите объявления уже 
 * известных вам конструкторов и деструкторов, реализовывать их заново не 
 * нужно, они уже реализованы. Вводить или выводить что-либо не нужно. 
 * Реализовывать main не нужно. Для работы с памятью не используйте функции из 
 * cstdlib (malloc, realloc, calloc и free).
 * 
 * Кроме того, ваша реализация должна корректно работать в следующем тесте:
 * 
 *      String s("Hello");
 *      s.append(s); // теперь s хранит "HelloHello"
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
	
    ~String(){
        delete [] str;
    }

    /* Реализуйте этот метод. */
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
    String str1("Hello");
    String str2(" world!");
    str1.append(str1);
    cout << str1.str << endl;
    return 0;
}