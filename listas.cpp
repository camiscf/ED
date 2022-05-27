#include <iostream>

using namespace std;

int busca(int *v, int n_elem, int x){

    int i  = 0;

    while (i < n_elem){
        if(v[i] !=x){
            i++;   
        }
        return i;
    }
}


int main()
{
    int v[] = {0,1,2,3,4};

    busca(v,5,2);
}
