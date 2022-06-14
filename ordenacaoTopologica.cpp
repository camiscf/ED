#include <iostream> 
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> gent;
vector<bool> vis;
vector<int> ord;

int numVer=0; 
int numAres=0;

void printAdj(){
    for(int i = 1; i <= adj.size(); i++){
        for(int j  = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void printGent(){
    for(int i = 1; i < gent.size(); i++){
        cout << gent[i] << " ";
    }
    cout << "\n";
}

void printOrd(){
    for(int i = 0; i < ord.size(); i++){
        cout << ord[i] << " ";
    }
    cout << "\n";
}


void CalGent(){
    for(int i = 0; i < adj.size(); i++){
        for(int j  = 0; j < adj[i].size(); j++){
            gent[adj[i][j]]++;
        }
    }
}


int main(void){    

    cin >> numVer >> numAres;
    adj.resize(numVer+1);
    gent.resize(numVer+1);
    vis.resize(numVer+1);

    // Descarta a primeira linha
    string lixo;
    getline(cin, lixo);

    for (int i=1;i<=numVer;i++){
        string s;
        getline(cin, s);

        string tmp = "";
        for (int j=0;j<s.size();j++){
            if (s[j] == ' '){
                int x = stoi(tmp);
                tmp = "";
                adj[i].push_back(x);
                continue;
            }
            tmp += s[j];
        }

        if (tmp != ""){
            int x = stoi(tmp);
            adj[i].push_back(x);
        }
    }

    CalGent();

    while (ord.size() != numVer){
        for (int i=1;i<=numVer;i++){
            if (gent[i] == 0 && vis[i] == false){
                ord.push_back(i);
                vis[i] = true;
                for (int j=0;j<adj[i].size();j++){
                    gent[adj[i][j]]--;
                }
                break;
            }
        }
    }

    printOrd();
    // for(int i = 0; i < numVer; i++){
    //     cin >> adj[i];
    // }


    // if(adj.empty()){
    //     cout >> "Lista vazia";
    // }
    // else{

    // }
}

// Oi amor!
// oI AMOR!

/* O que a gente precisa fazer:

1. Ler a entrada, e guardar na estrutura de dados adequada (qual é a estrutura adequada? -> armazena na lista de adjacências)
cls   3.2. Eliminar a fonte (e todas as arestas que saem dela)
    3.3. Adicionar a fonte em uma lista
    3.4. Repetir até acabar
*/

// Tô só esperando ele acabar a história pra gente poder falar sobre o algortimo :) HDUASHUAHDA okay

/* 
1->2    
2->3
2->4
3->4

adj = [[2], [3, 4], [4], []]
gent = [0,0,1,2]

nós arestas
...

4 4
2
3 4
4

8 9
2 4
4
5 7
6
7 8
8

6 7
2
3
6
1 5
2 3


*/