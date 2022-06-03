#include <iostream> 

using namespace std;

#define TAM 100

class Stack {

    private:
        int topo; // define o too atual da pilha
        int stack[TAM]; // pilha que os dados


    public:
        Stack(){ topo = -1; }
        bool push(int x);
        int pop();
        int check();
        int size();
        bool empty();
        void printStack();
};

// COLOCAR NA PILHA
bool Stack::push(int x){
    if (topo >= (TAM-1)){
        cout << "Overflow\n";
        return false;
    } 
    else{
        stack[++topo] = x;
        //cout << x << " colocado na lista\n";
        return true;
    }
}

// TIRAR DA PILHA
int Stack::pop(){
    if (topo <= -1){
        cout << "Underflow\n";
        return -1;
    }
    else{
        return stack[topo--];
    }
}
// RETORNA O TAMANHO DA PILHA
int Stack::size(){ return topo+1; }

// CONFERE SE A LISTA TA VAZIA
bool Stack::empty(){ return (topo < 0);}

int Stack::check(){
    if (topo < 0){
        cout << "Pilha vazia";
        return 0;
    } 
    else{
        int x = stack[topo];
        return x;
    }
}


// IMPRIME A LISTA
void Stack::printStack(){
    for (int i=topo; i>-1;i--){
        cout << stack[i] << "\n";
    }
}

bool isNumber(char character){
    if (character >= '0' && character <= '9'){ return true; }
    else{ return false; }
}

bool isOperator(char character){
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '(' || character == ')'){ return true; }

    else{ return false; }
}

int precedence(char character){
    if (character == '+' || character == '-'){ return 1; }
    else if (character == '*' || character == '/') { return 2; }
    else if (character == '(' || character == ')'){ return 3; }
    else{ return -1; }
} 

int operations (int value1, int value2, char character){
    if (character == '+'){ return value1 + value2; }
    else if (character == '-'){ return value1 - value2; }
    else if (character == '*'){ return value1 * value2; }
    else if (character == '/'){ return value1 / value2; }
    else { return -1;  }
}

int doingEquation(string equation){
    Stack pilha_numeros;
    Stack pilha_operadores;
    
    int value = 0;
    int pos = 0;
    
    while (pos <equation.length()){

        char equationPot = equation[pos];

        if(isNumber(equationPot)){
            value = (value*10) + (int(equationPot - '0'));
        }
        else if (isOperator(equationPot)){

            if (equationPot == '('){
                pilha_operadores.push(equationPot);
                value = 0;
            }
            //não faz sentido
            else if (pilha_numeros.empty()){
                pilha_numeros.push(value);
                pilha_operadores.push(equationPot);
                value = 0;
            }
            else if (equationPot == ')'){
                //olhar
                pilha_numeros.push(value);

                while (pilha_operadores.check() != '(' )
                {
                    equationPot = pilha_operadores.pop();
                    value = pilha_numeros.pop();
                    int ant = pilha_numeros.pop();
                    value = operations(ant, value, equationPot);
                    pilha_numeros.push(value);
                }
                //??
                
                pilha_operadores.pop();
                pilha_numeros.pop();
            }
            else{
                char ant = pilha_operadores.check();

                if (precedence(equationPot) > precedence(ant) ){
                    pilha_numeros.push(value);
                    pilha_operadores.push(equationPot);
                    value = 0;
                }
                else{
                    int antvalue = pilha_numeros.pop();
                    int antop = pilha_operadores.pop();

                    antvalue = operations(antvalue, value, antop);
                    
                    pilha_numeros.push(antvalue);
                    pilha_operadores.push(equationPot);
                    value = 0;
                }
            }
        }    
        pos++;
    }
    while(!pilha_operadores.empty()){
        int ant = pilha_numeros.pop();
        char equationPot = pilha_operadores.pop();
        value = operations(ant, value, equationPot);
    }
    return value;
}

int main(void){
    cout << doingEquation("3 + 4 + 5") << endl;
    cout << doingEquation("3 * 4 + 5") << endl;
    
}
