#include <iostream> 
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> gent;
vector<bool> visited;
vector<int> ord;

int numVer=0; 
int numAres=0;

void GetGraph(){
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
}

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
    visited.resize(numVer+1);

    GetGraph();

    CalGent();

    while (ord.size() != numVer){
        for (int i=1;i<=numVer;i++){
            if (gent[i] == 0 && visited[i] == false){
                ord.push_back(i);
                visited[i] = true;
                for (int j=0;j<adj[i].size();j++){
                    gent[adj[i][j]]--;
                }
                break;
            }
        }
    }

    printOrd();

}
