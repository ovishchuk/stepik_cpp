/* Напишите функцию поиска первого вхождения шаблона в текст. В качестве
 * первого параметра функция принимает текст (C-style строка), в которой нужно
 * искать шаблон. В качестве второго параметра строку-шаблон (C-style строка),
 * которую нужно найти. Функция возвращает позицию первого вхождения
 * строки-шаблона, если он присутствует в строке (помните, что в C++ принято
 * считать с 0), и -1, если шаблона в тексте нет.
 *
 * Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.
 */

#include <iostream>


int strstr(const char *text, const char *pattern) {
    unsigned position = 0;
    unsigned pattern_length = 0;
    while (*pattern++) {pattern_length++};
    while (pattern_length) {
        if () {
        }
    }
}

int main() {
    const char * message = "Some pretty text";
    const char * pattern = "pretty";
    return 0;
}
