class Node:
    #construtor
    # data -> dado
    def __init__(self, data):
        self.data = data
        self.next = None

#inserir na pilha
#remover da pilha
#ver o primeiro elemento da pilha

class Stack:
    
    def __init__(self):
        self.top = None
        self._size = 0

    def push(self, elem):

        node = Node(elem)
        node.next = self.top
        self.top = node
        self._size +=1


    def pop(self):
        #remove o elemento da pilha

        if self._size > 0:
            node = self.top
            #move o topo uma posição abaixo
            self.top = self.top.next
            self._size -=1
            return node.data
        else:
            raise IndexError("the stack is empty")


    def peek(self):
        #remove o topo da pilha sem remover
        if self._size > 0:
            return self.top.data
        else:
            raise IndexError("the stack is empty")


    def __len__(self):
        return self._size
        


    def __repr__(self):
        r = ""
        pointer = self.top
        while(pointer):
            r = r + str(pointer.data) + "\n"
            pointer = pointer.next
        return r

    def __str__(self):
        return self.__repr__()

    