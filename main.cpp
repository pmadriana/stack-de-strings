#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
//class nodo
//{
//    public:
//    string val;
//    nodo *next;
//    nodo(string x=NULL)
//    {
//        val=x;
//        next=NULL;
//    }
//};
class pila
{
    string val;
    pila *next;
    pila *n; //num elementos
public:
   bool isEmpty() {
    return n == 0;
    }

    void push(string valor) {
        pila *temp = n;
        n = new pila();
        n->val = valor;
        n->next = temp;
    }

    string pop() {
        string v = n->val;
        pila *pop = n;
        n = n->next;
        delete pop;
        return v;
    }

    void imprimir()
    {
        pila *temp=n;
        while(temp){
            cout<<temp->val<<endl;;
            temp=temp->next;
        }
    }
};

int main()
{
    pila *s= new pila();
    s->push("hola");
    s->push("que");
    s->pop();
    s->imprimir();
}
