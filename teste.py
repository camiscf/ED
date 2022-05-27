from tkinter import N


lista = [1,2,3,4,5]

n = len(lista)

lista_copy = [None] * n


for i in range(len(lista)):
    lista_copy[i] = lista[i]

print(lista_copy)

"""
Recebe a posicao
vai ver se essa posicao n ta ocupada
se tiver{
    se essa posicao == index 0{
        faz a copia da lista antiga deixando index 0 vazia
        lista_copia[0] = elemento
    }
    senao{
        copia da lista antiga pra lista copia 1 antes da posicao
        copia da lista antiga para lista copia 2 depois da posicao
        lista copia geral 
        junta as duas listas com a 3a   
    }
    lista_antiga[posicao] = elemento
} 
senao {
    lista[posicao] = elemento
}
"""