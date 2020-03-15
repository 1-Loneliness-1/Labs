#define _CRT_SECURE_NO_WARNINGS
#define n 100
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static int tos = 0;
static char stack[n];

void push(char i)
{
    if (tos >= n)
    {
        std::cout << "Error!! Stack is full\n";
        return;
    }
    stack[tos] = i;
    tos++;
}

char pop(void)
{
    tos--;
    if (tos < 0)
    {
        std::cout << "Error!! Stack is empty!!!\n";
        return 0;
    }
    char s = stack[tos];
    stack[tos] = '\0';
    return s;
}

int opredelprior(char c)
{
    switch (c)
    {
        case '(':
            return 0;
            break;
        case ')':
        case '~':
            return 1;
            break;
        case '+':
        case '-':
        case '|':
            return 2;
            break;
        case '*':
        case '/':
        case '&':
            return 3;
            break;
        case '^':
            return 4;
            break;
    }
}

int main()
{
    std::cout << "Valid arithmetic operations: +,-,*,/,^\nValid logical operations: &,|,~\n";
    do
    {
        ofstream f0("input.txt");
        std::string input1;
        ofstream f("output.txt");
        std::cout << "Enter expression here: ";
        std::cin >> input1;
        f0 << input1;//Запись строки с консоли в файл
        f0.close();
        ifstream f01("input.txt");
        std::string input;
        ::getline(f01, input);
        f01.close();
        for (int i = 0; input[i] != '\0'; i++)
        {
            //1.1 Если символ операнд , то он перемещается в выходную строку
            if ((((int)input[i] >= (int)'a') && ((int)input[i] <= (int)'z')) || (((int)input[i] >= (int)'A') && ((int)input[i] <= (int)'Z')) || ((int)input[i] >= (int)'0') && ((int)input[i] <= (int)'9'))
            {
                f << input[i];
            }
            //1.2 Если символ операция и стек пуст, то он проталкивается в стек
            else if ((tos <= 0) && (((int)input[i] == (int)'+') || ((int)input[i] == (int)'-') || ((int)input[i] == (int)'*') || ((int)input[i] == (int)'/') || ((int)input[i] == (int)'^') || ((int)input[i] == (int)'|') || ((int)input[i] == (int)'&') || ((int)input[i] == (int)'~')))
            {
                push(input[i]);
            }
            //1.3 Если символ операция и стек не пуст, а приоритет символа операции меньше, чем у символа операции вершины стека,
            // то прочитанный символ проталкивается в стек
            else if ((tos > 0) && (((int)input[i] == (int)'+') || ((int)input[i] == (int)'-') || ((int)input[i] == (int)'*') || ((int)input[i] == (int)'/') || ((int)input[i] == (int)'^') || ((int)input[i] == (int)'|') || ((int)input[i] == (int)'&') || ((int)input[i] == (int)'~')) && (opredelprior(stack[tos - 1]) < opredelprior(input[i])))
            {
                push(input[i]);
            }
            //1.4 Если символ операция и
            else if ((tos > 0) && (((int)input[i] == (int)'+') || ((int)input[i] == (int)'-') || ((int)input[i] == (int)'*') || ((int)input[i] == (int)'/') || ((int)input[i] == (int)'^') || ((int)input[i] == (int)'|') || ((int)input[i] == (int)'&') || ((int)input[i] == (int)'~')) && (opredelprior(stack[tos - 1]) >= opredelprior(input[i])))
            {
                while ((((int)stack[tos - 1] == (int)'+') || ((int)stack[tos - 1] == (int)'-') || ((int)stack[tos - 1] == (int)'*') || ((int)stack[tos - 1] == (int)'/') || ((int)stack[tos - 1] == (int)'^') || ((int)stack[tos - 1] == (int)'|') || ((int)stack[tos - 1] == (int)'&') || ((int)stack[tos - 1] == (int)'~')) && (opredelprior(stack[tos - 1]) >= opredelprior(input[i])))
                {
                    f << pop();
                }
                push(input[i]);
            }
            else if ((int)input[i] == (int)'(')
            {
                push(input[i]);
            }
            else if ((int)input[i] == (int)')')
            {
                while ((int)stack[tos - 1] != (int)'(')
                {
                    f << pop();
                }
                pop();
            }
        }
        //Выталкивание всех символов, оставшихся в стеке в выходную строку
        while (tos > 0)
        {
            f << pop();
        }
        f.close();
        std::ifstream f1("output.txt");
        string output;
        ::getline(f1, output);
        std::cout << output << "\n";
        f1.close();
        std::cout << "Do you want to run the algorithm again?(yes/no)\n";
        char answer[10];
        std::cin >> answer;
        if (strcmp(answer, "no") == 0)
            break;
        else if (strcmp(answer, "yes") == 0)
            continue;
    } while (true);
    ::system("pause");
    return 0;
}

