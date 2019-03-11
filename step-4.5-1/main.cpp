/* main.cpp step-4.5-1
 *
 * На прошлом степе вы познакомились с реализацией паттерна посетитель. Теперь
 * пришло время воспользоваться этими знаниями. Ваш класс должен печатать 
 * (используя std::cout) текстовое представление арифметического выражения. 
 * Т.е. для объекта класса Number он должен напечатать число, которое в нем 
 * хранится, а для объекта класса BinaryOperation он должен напечатать левый 
 * операнд, затем операцию, а затем правый операнд.
 * 
 * Учтите, что операции + и - имеют меньший приоритет, чем операции * и /, 
 * т. е. возможно вам придется печатать дополнительные круглые скобки, чтобы 
 * сохранить правильный порядок операций.
 * 
 * Классы иерархии Expression и абстрактный класс Visitor приведены в 
 * комментарии в шаблоне для удобства.
 * 
 * При проверке задания лишние пробелы или лишние скобки будут игнорироваться, 
 * т.е. вывод "1+2" эквивалентен выводу "( ( 1 )  +   ( 2 ) )", а вот вывод 
 * "1 + 2 * 3" не эквивалентен выводу "((1 + 2) * 3)". Вы можете попытаться 
 * минимизировать количество скобок в выводе, но это не требуется.
 * 
 * Перед выполнением задания внимательно прочитайте содержимое предыдущего 
 * степа.
 * 
 * Требования к реализации: при выполнении задания вы можете заводить любые 
 * вспомогательные классы или функции, но не нужно реализовывать функцию main 
 * или менять реализацию классов иерархии Expression.
 */
#include <iostream> 
using namespace std;


struct Number;
struct BinaryOperation;


struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};


struct Expression {
    virtual ~Expression() {}
    virtual void visit(Visitor * vistitor) const = 0;
    virtual double evaluate() const = 0;
};


struct Number : Expression
{
    Number(double value)
            : value(value) {
    }

    double evaluate() const {
        return value;
    }

    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};


struct BinaryOperation : Expression
{
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

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};


/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        cout << "(";
        bop->get_left()->visit(this);
        cout << bop->get_op();
        bop->get_right()->visit(this);
        cout << ")";
    }
};


int main(void) {
    Expression * sube1 = new BinaryOperation(new Number(7.2), '/', new Number(8));
    Expression * sube2 = new BinaryOperation(sube1, '*', new Number(4.5));
    Expression * expr = new BinaryOperation(new Number(3), '+', sube2);

    PrintVisitor printVisitor;
    expr->visit(&printVisitor);
    cout << endl;
    cout << expr->evaluate() << endl;

    delete expr;
    return 0;
}