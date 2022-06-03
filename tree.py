import re


class Node: 
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    
    def __str__(self,data):
        return str(self.data)

class BinaryTree:
    def __init__(self, data):
        if node:
            self.root = node
        if data:
            node = Node(data)
        else:
            self.root = None
    
    #percorre a árvore em ordem simetrica: esq -> raiz -> dir
    def simetric_traversal(self, node=None):
        if node is None:
            node = self.root #percorra a partir da raiz
        if node.left:
            self.simetric_traversal(node.left)
        print(node)
        if node.right:
            self.simetric_traversal(node.right)