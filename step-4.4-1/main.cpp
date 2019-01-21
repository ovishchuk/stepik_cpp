/* main.cpp step-4.3-2
 * 
 * (Задание повышенной сложности) Предполагаемое решение этого задания не 
 * переносимо с точки зрения стандарта, однако оно проверено на различных 
 * версиях компиляторов g++/clang++/msvc. Решение этого задания не обязательно 
 * для получения диплома по этому курсу, однако мы считаем его полезным, чтобы 
 * лучше понять как устроены виртуальные функции внутри.
 * 
 * Вам требуется реализовать функцию, которая принимает на вход два указателя 
 * на базовый класс Expression, и возвращает true, если оба указателя указывают 
 * на самом деле на объекты одного и того же класса, и false в противном случае 
 * (т.е. если оба указателя указывают на BinaryOperation, то возвращается true, 
 * а если один из них указывает на Number, а второй на BinaryOperation, то 
 * false).
 * 
 * Требования к реализации: пользоваться typeid и dynamic_cast запрещено. 
 * Вызывать методы по переданным указателям запрещено.
 */
#include <iostream> 
using namespace std;


struct Expression {
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

struct Number : Expression {
    Number(double value)
            : value(value) {
    }
    double evaluate() const {
        return value;
    } 

private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }

    ~BinaryOperation() {
        delete right;
        delete left;
    }

    double evaluate() const {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
                break;
            case '-':
                return left->evaluate() - right->evaluate();
                break;
            case '*':
                return left->evaluate() * right->evaluate();
                break;
            case '/':
                return left->evaluate() / right->evaluate();
                break;
        }
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right) {
    return (*((int**)left) == *((int**)right)) ? true : false;
}

int main(void) {
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);
    Expression * num = new Number(3);

    cout << expr->evaluate() << endl;
    cout << *((int**)sube) << endl;
    cout << *((int**)expr) << endl;
    cout << *((int**)num) << endl;
    cout << ((check_equals(sube, expr)) ? '1' : '0') << endl;
    cout << ((check_equals(sube, num)) ? '1' : '0') << endl;

    delete expr;
    return 0;
}