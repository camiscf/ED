from contextlib import nullcontext


def busca(lista, elemento):
    """ Retorna o índice do elemento se ele tiver na lista """
    for i in range(len(lista)):
        if lista[i] == elemento:
            return i
    return None


lista = [8, "2", 0, 420, "ola"]
elemento = 0

# indice = busca(lista,elemento)
# if indice is not None:
#     print("O indice do elemento {} é {}".format(elemento, indice))
# else:
#     print("O elemento {} não é presente".format(elemento))

def insere(lista, elemento, posicao):

    lista_copy = [None] * len(lista)+1
    # no começo da lista
    # random
    for indice in range(len(lista)):
        if lista[indice] != None:
            lista_copy[indice] = lista[indice]
    
    lista[posicao] = elemento

    

    # final da lista

