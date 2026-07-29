#!/bin/python3

import math
import os
import random
import re
import sys
import ast
import json

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Enter your code here. Read input from STDIN. Print output to STDOUT
def delete_node(root, key):
    # Write your code here
    target = None
    parent = None
    direction = None
    
    def recurse(node, p, d):
        nonlocal target, parent, direction
        
        if not node:
            return
        
        if node.val == key:
            target = node
            parent = p
            direction = d
            return
            
        recurse(node.left, node, "left")
        recurse(node.right, node, "right")
    
    recurse(root, parent, direction)
    
    def inorder(target):
        # leaf
        if not target.left and not target.right:
            successor = None
        # only right exist
        elif not target.left:
            successor = target.right
        # only left exists
        elif not target.right:
            successor = target.left
        # most complicated: both left and right exists
        else: 
            prev = None
            successor = target.right
            while successor.left:
                prev = successor
                successor = successor.left
            if successor == target.right:
                successor.left = target.left
            else:
                if successor.right:
                    prev.left = successor.right
                else:
                    prev.left = None
                successor.left = target.left
                successor.right = target.right
        return successor
    
    if target:
        if not parent:
            # removed root
            return inorder(root)
        else:
            successor = inorder(target)
            if direction == "left":
                parent.left = successor
            else:
                parent.right = successor
            
            return root
                        
          
        
    return root
        

def build_tree_from_list(lst):
    if not lst:
        return None

    nodes = [TreeNode(val) if val is not None else None for val in lst]
    kids = nodes[::-1]
    root = kids.pop()

    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    
    return root

def tree_to_list(root):
    if not root:
        return []
    
    result, queue = [], [root]
    while any(queue):
        node = queue.pop(0)
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)
    
    # Remove trailing None values
    while result and result[-1] is None:
        result.pop()
    
    return result

if __name__ == '__main__':
    input_data = sys.stdin.read().strip().splitlines()
    
    for data in input_data:
        tree_data, val = data.split('],')
        tree_data += ']'  
        val = int(val.strip())   
        
        tree_list = ast.literal_eval(tree_data)   
       
        root = build_tree_from_list(tree_list)
        result = delete_node(root, val)
        
        print(tree_to_list(result))
