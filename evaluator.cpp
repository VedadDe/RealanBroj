#include <iostream>
#include <stack>
#include <cmath>
#include "realni_1.h"
using namespace std;

bool jeLiBroj(char znak){
    return znak>='0' && znak<='9';
}

bool jeLiOtvorena(char znak){
    return znak=='(' || znak=='[' || znak=='{';
}

bool jeLiZatvorena(char znak){
    return znak==')' || znak==']' || znak=='}';
}

char dajOtvorenu(char zagrada){
    switch (zagrada){
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    }

    return '0';
}

int prioritet(char op){
    if (op=='+' || op=='-')
        return 1;
    if (op=='*')
        return 2;
    if (op=='^')
        return 4;
    return 0;
}

bool unarni(char op){
    return prioritet(op)==3;
}

Realni rezultat(Realni operand1, Realni operand2, char operacija){
    switch (operacija){
    case '+':
        return operand1+operand2;
    case '-':
        return operand1-operand2;
    case '*':
        return operand1*operand2;
    case '^':
        return operand1^operand2;
    }
    return 0;
}

void izvrsiOperaciju(stack<char>& znakovi, stack<Realni>& brojevi){
    if (znakovi.empty() || prioritet(znakovi.top())==0)
        throw "Izraz nije validan";

    char operacija(znakovi.top());
    znakovi.pop();

    if (unarni(operacija)){
        if (brojevi.empty())
            throw "Izraz nije validan";

        Realni operand(brojevi.top());
        brojevi.pop();
        brojevi.push(rezultat(operand, operacija));
    } else {
        if (brojevi.size()<2)
            throw "Izraz nije validan";

        Realni operand2(brojevi.top());
        brojevi.pop();
        Realni operand1(brojevi.top());
        brojevi.pop();
        brojevi.push(rezultat(operand1, operand2, operacija));
    }
}

void evaluator(){
    enum Simbol {otvorenaZ, zatvorenaZ, unarniOp, binarniOp, broj};
    while (true){
        try{
            if (cin.peek()=='\n')
                break;

            while (cin.peek()==' ')
                    cin.get();

            stack<char> znakovi;
            stack<Realni> brojevi;
            Simbol prethodni(otvorenaZ);

            while (cin.peek()!='\n'){
                if (jeLiOtvorena(cin.peek())){
                    if (prethodni==broj || prethodni==zatvorenaZ)
                        throw "Ne moze otvorena zagrada nakon broja ili zatvorene zagrade";

                    znakovi.push(cin.get());
                    prethodni=otvorenaZ;
                } else if (jeLiZatvorena(cin.peek())){
                    if (prethodni==otvorenaZ || prethodni==unarniOp || prethodni==binarniOp)
                        throw "Ne moze zatvorena zagrada nakon operacije ili otvorene zagrade";

                    while (!znakovi.empty() && !jeLiOtvorena(znakovi.top())){
                        izvrsiOperaciju(znakovi, brojevi);
                        if (znakovi.empty())
                            throw "Zatvorena zagrada nema odgovarajucu otvorenu";
                    }
                    if (dajOtvorenu(cin.peek())!=znakovi.top())
                        throw "Zatvorena zagrada nema odgovarajucu otvorenu";

                    prethodni=zatvorenaZ;
                    znakovi.pop();
                    cin.get();
                } else if (jeLiBroj(cin.peek())){
                    if (prethodni==zatvorenaZ)
                        throw "Ne moze broj poslije zatvorene zagrade";

                    Realni b;
                    cin>>b;
                    brojevi.push(b);
                    prethodni=broj;
                } else {
                    if (prioritet(cin.peek())==0)
                        throw "Nedozvoljen znak";

                    char znak(cin.get());

                    /*if (unarni(znak)){
                        if (znak=='s'){
                            if (cin.get()!='i' || cin.get()!='n')
                                throw "Nedozvoljen znak";

                            if (prethodni==broj || prethodni==zatvorenaZ)
                                throw "Ne moze sin nakon broja ili zatvorene zagrade";
                        }
                        if (znak=='c'){
                            if (cin.get()!='o' || cin.get()!='s')
                                throw "Nedozvoljen znak";

                            if (prethodni==broj || prethodni==zatvorenaZ)
                                throw "Ne moze cos nakon broja ili zatvorene zagrade";
                        }

                        znakovi.push(znak);
                        prethodni=unarniOp;
                    } else */{
                        if (znak=='-' && prethodni==otvorenaZ)
                            brojevi.push(0);
                        else if (prethodni==otvorenaZ || prethodni==unarniOp || prethodni==binarniOp)
                            throw "Ne moze operator poslije otvorene zagrade ili operatora";

                        while (!znakovi.empty() && prioritet(znakovi.top())>=prioritet(znak))
                            izvrsiOperaciju(znakovi, brojevi);

                        znakovi.push(znak);
                        prethodni=binarniOp;
                    }
                }
            }
            while (!znakovi.empty()){
                if (jeLiOtvorena(znakovi.top()))
                    throw "Nedostaje zatvorena zagrada";
                izvrsiOperaciju(znakovi, brojevi);
            }

            if (brojevi.size()!=1)
                    throw "Izraz nije balansiran";

            cout<<brojevi.top()<<endl;
            cin.ignore(1000, '\n');
        } catch (const char poruka[]){
            cout<<poruka<<endl;
            cin.ignore(1000, '\n');
        }
    }
}


int main(){
    evaluator();

    return 0;
}

