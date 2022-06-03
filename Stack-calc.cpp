#include <iostream> 

using namespace std;

#define TAM 100

class Stack {

    private:
        int topo; // define o too atual da pilha
        int stack[TAM]; // pilha que os dados


    public:
        Stack(){ topo = -1; }
        
        // INSERE NA PILHA
        bool push(int x){
            if(topo >= (TAM -1)){
                cout << "Overflow";
                return false;
            }
            else{
                stack[++topo] = x;
                //cout << x << " in!\n";
                return true;
            }
        }

        // TIRA DA PILHA
        int pop(){
            if(topo < 0){
                cout << "underflow\n";
                return 0;
            }
            else{
                int x = stack[topo--];
                return x;
        
            }
        }

        // RETORNA O OBJETO DO TOPO SEM MEXER
        int peek(){
            if(topo < 0){
                cout << "Empty Stack\n";
                return 0;
            }
            else{
                int x = stack[topo];
                return x;
            }
        }
        
        bool isEmpty(){
            return (topo < 0);
        }

        int size(){
            return topo+1;
        }

        void printStack(){
           for (int i=topo; i>-1;i--){
            cout << stack[i] << "\n";
            }
        }
};

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
    else{ return value1 / value2; }
}

int doingEquation(string equation){
    Stack Snumbers;
    Stack Soperators;

    int value = 0;
    int pos = 0;

    while (pos < equation.length()){
        // pegar o char naquela posicao
        char eqpot = equation[pos];

        if (isNumber(eqpot)){
            // cria o numero
            value = (value*10) + (int)(eqpot - '0');
        }
        else if(isOperator(eqpot)){

            if (eqpot == '('){
                Soperators.push(eqpot);
                value = 0;
            }
            else if(Snumbers.isEmpty()){
                Snumbers.push(value);
                Soperators.push(eqpot);
                value = 0;
            }
            else if (eqpot == ')'){
                Snumbers.push(value);

                while(Soperators.peek() != '('){
                    eqpot = Soperators.pop();
                    value = Snumbers.pop();
                    int ant = Snumbers.pop();
                    value = operations(ant, value, eqpot);
                    Snumbers.push(value);
                }
                Snumbers.pop();
                Soperators.pop();
            }
            else{
                char ant = Soperators.peek();
                if (precedence(eqpot) > precedence(ant)){
                    Snumbers.push(value);
                    Soperators.push(eqpot);
                    value = 0;
                }
                else{
                    int antvalue = Snumbers.pop();
                    int antop = Soperators.pop();

                    antvalue = operations(antvalue, value, antop);
                    
                    Snumbers.push(antvalue);
                    Soperators.push(eqpot);
                    value = 0;
                }
            }
        }
        pos ++;
    }
    while(!Soperators.isEmpty()){
        int ant = Soperators.pop();
        char eqpot = Soperators.pop();
        value = operations(ant, value, eqpot);
    }
    return value;
}


int main(void){
    // Stack pilha_teste;

    // pilha_teste.push(1);
    // pilha_teste.push(2);
    // pilha_teste.push(3);
    // pilha_teste.pop();

    // pilha_teste.printStack();

    cout << doingEquation("3 + 4 + 5") << endl;
    cout << doingEquation("3 * 4 + 5") << endl;
    
    return 0;

}