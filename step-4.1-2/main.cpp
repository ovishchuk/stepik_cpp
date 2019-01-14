/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
 * Не нужно его расскоментировать и/или менять.
 */
#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};

struct Bar : Foo {
    Bar(const char *msg) : Foo(msg), msg(msg) { }
private:
    const char *msg;
};

void foo_says(const Foo &foo) { 
    foo.say(); 
}

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));
Foo get_foo(const char *msg) {
    Bar bar(msg);
    return bar; 
}

int main(int argc, char const *argv[]) {
    foo_says(get_foo("Hello!"));
    return 0;
}