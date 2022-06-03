import re


class Node: 
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    
    def __str__(self,data):
        return str(self.data)

class BinaryTree:
    def __init__(self, data=None, node = None):
        if node:
            self.height = node
        elif data:
            node = Node(data)
            self.root = node
        else:
            self.root = None
    
    #percorre a árvore em ordem simetrica: esq -> raiz -> dir
    def simetric_traversal(self, node=None):
        if node is None:
            node = self.root #percorra a partir da raiz
        if node.left:
            print('(', end='')
            self.simetric_traversal(node.left)
        print(node, end='')
        if node.right:
            self.simetric_traversal(node.right)
            print(')', end='')
    
    #percorre a árvore em pós-ordem: esq -> dir -> raiz
    def postorder_traversal(self,node=None):
        if node is None:
            node = self.root
        if node.lef:
            self.postorder_traversal(node.left)
            print('(', end='')
        print(node, end='')
        if node.right:
            self.postorder_traversal(node.right)
            print('(',end='')
        print(node)
    
    #calcular a altura é ver a altura da esq e da direita é bom fazer isso com o pos ordem
    def height(self,node=None):
        if node is None:
            node = self.root
        hleft = hright = 0;
        if node.lef:
               hleft = self.height(node.left)
        print(node, end='')
        if node.right:
            hright = self.height(node.right)
        if hright > hleft:
            return hright+1
        return hleft+1

class BinarySearchTree(BinaryTree):
    def insert(self, value):
        parent = None
        x = self.root #auxiliar

        while(x): #enqt x!= empty
            parent = x
            if value < x.data:
                x = x.left
            else:
                x = x.right
        
        if parent is None:
            self.root = Node(value)
        elif value < parent.data:
                parent.left = Node(value)
        else:
                parent.right = Node(value)
    
    def search(self,value,node=0):
        if node == 0:
            node = self.root
        if node is None or node.data == value:
            return BinarySearchTree(node)
        if value < node.data:
            return self.search(value, node.left)
        return self.search(value, node.right)