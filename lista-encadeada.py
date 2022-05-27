#classe nó
from multiprocessing.sharedctypes import Value


class Node:
    #construtor
    # data -> dado
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        #cabeça
        self.head = None
        self._size = 0

    #adicionar o elemento no final da lista
    def append(self, elem):
        #se a lista tiver vazia, self.head é vazia
        if self.head:
            #tem elemento ali
            pointer = self.head
            #enquanto tiver um next avança pro prox e qnd isso for falso, ele vai estar no ultimo elemento e ai pode adicionar 
            while(pointer.next):
                pointer = pointer.next
            pointer.next = Node(elem)
        else:
            #primeira inserção de elemento da lista
            self.head = Node(elem)
        self._size += 1 
    
    def __len__(self):
        #retorna o tamanho da lista
        return self._size
    
    def _getnode(self, index):
            # a = lista.get(6)
        pointer = self.head

        for i in range(index):
            if pointer:
                pointer = pointer.next
            else:
                raise IndexError("list index out of range")
        
        return pointer

    def set(self, index, elem):
        #lista.set(5,9)
        pass

    def __getitem__(self,index):
        #a = lista[6]
        pointer = self._getnode(index)
        if pointer:
            return pointer.data
        else:
            raise IndexError("list index out of range")

    def __setitem__(self, index, elem):
        # lista[5] = 9
        
        pointer = self._getnode(index)

        if pointer:
            pointer.data = elem
        else:
            raise IndexError("list index out of range")
    
    #busca 
    def index(self, elem):
        """retorna o indice do elemento da lista """
        pointer = self.head
        i = 0
        while(pointer):
            if pointer.data == elem:
                return i
            else:
                pointer = pointer.next
                i+=1
        raise ValueError("{} is not in list".format(elem))

    #vai inserir na posição dada
    def insert(self, index, elem):
        #caso no começo da lista => é a cabeça da lista
        node = Node(elem) #criou o nó
        
        if index == 0:
            node.next = self.head 
            self.head = node
        else:
            #para inserir em uma posição diferente, precisa caminhar até ela
            pointer = self._getnode(index-1)
            node = Node(elem)
            node.next = pointer.next
            pointer.next = node
        self._size += 1

    def remove(self, elem):

        if self.head == None:
            raise ValueError("{} is not in list".format(elem))

        elif self.head.data == elem:
            self.head = self.head.next
            self._size -= 1
            return True
        else:
            ancestor = self.head
            pointer = self.head.next
            while(pointer):
                if pointer.data == elem:
                        ancestor.next = pointer.next
                        pointer.next = None
                ancestor = pointer
                pointer = pointer.next
            self._size -= 1
            return True
        raise ValueError("{} is not in list".format(elem))

    def __repr__(self):
        r = ""
        pointer = self.head
        while(pointer):
            r = r + str(pointer.data) + "->"
            pointer = pointer.next
        return r

    def __str__(self):
        return self.__repr__()


lista = LinkedList()
