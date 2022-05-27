
def insere(lista, elemento, posicao):
    n = len(lista)
    meio = (n//2)
    list_copy = [ ] * n+1
    list_second = list_first = [None] * meio

    if lista[posicao] == None:
        lista[posicao] = elemento
    else:
        if lista[posicao] == lista[0]:
            for i in range(n):
                list_copy[0] = elemento
                list_copy[i+1] = lista[i]
                print(list_copy)
        else: 
            for i in range(meio):
                list_first[i] = lista[i:posicao-1]
                list_second[i] = lista[posicao+1:]

            list_copy[posicao] = elemento

            for k in range(n):
                list_copy[k] = list_first[:posicao-1] 
                list_copy[k] = list_second[posicao+1:]
    
    print(list_copy)



lista = [1,2,3,4,5]

insere(lista,100,1)