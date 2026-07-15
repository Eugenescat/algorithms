# Source: https://usaco.guide/general/io

"""
You're working at a deli, and need to count the layers of a sandwich to make 
sure you made the order correctly. Each layer is represented by a nested list. 
Given a list of lists sandwich where each list [] represents a sandwich layer,
 write a recursive function count_layers() that returns the total number of 
 sandwich layers.
"""

# Time: O(n)
# Space: O(1)
def count_layers(sandwich):
    if len(sandwich) == 1:
        return 1
    else:
        return count_layers(sandwich[1]) + 1

sandwich1 = ["bread", ["lettuce", ["tomato", ["bread"]]]]
sandwich2 = ["bread", ["cheese", ["ham", ["mustard", ["bread"]]]]]

# print(count_layers(sandwich1))
# print(count_layers(sandwich2))

"""
The deli counter is busy, and orders have piled up. To serve the last customer first, 
you need to reverse the order of the deli orders. Given a string orders where each 
individual order is separated by a single space, write a recursive function reverse_orders()
 that returns a new string with the orders reversed.
"""
# Time: O(n)
# Space: O(n) - could be improved to O(1) without splitting
def reverse_orders(orders):
    orders_list = orders.split(" ")

    return reverse_order_helper(orders_list, 0)
    
def reverse_order_helper(orders, index):
    if len(orders) - 1 == index:
        return orders[index]
    else:
        return reverse_order_helper(orders, index + 1) + " " + orders[index]

# print(reverse_orders("Bagel Sandwich Coffee"))

"""
The deli staff is in desperate need of caffeine to keep them going through their shift 
and has decided to divide the coffee supply equally among themselves. Each batch of coffee 
is stored in containers of different sizes. Write a recursive function can_split_coffee()
 that accepts a list of integers coffee representing the volume of each batch of coffee and 
 returns True if the coffee can be split evenly by volume among n staff and False otherwise.
"""

# Time: O(n)
# Space: O(1)
def can_split_coffee(coffee, n):
    total_coffee = can_split_coffee_helper(coffee, 0)

    return total_coffee % n == 0


def can_split_coffee_helper(coffee, index):
    if index == len(coffee):
        return 0
    else:
        return can_split_coffee_helper(coffee, index + 1) + coffee[index]



# print(can_split_coffee([4, 4, 8], 2))
# print(can_split_coffee([5, 10, 15], 4))

# True
# False


"""
A regular at the deli has requested a new order made by merging two different sandwiches 
on the menu together. Given the heads of two linked lists sandwich_a and sandwich_b where 
each node in the lists contains a sandwich layer, write a recursive function merge_orders() 
that merges the two sandwiches together in the pattern:

a1 -> b1 -> a2 -> b2 -> a3 -> b3 -> ...

Return the head of the merged sandwich.
"""

class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

# For testing
def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=" -> " if current.next else "\n")
        current = current.next

# Time: O(m + n)
# Space: O(1)
def merge_orders(sandwich_a, sandwich_b):
    if sandwich_a and sandwich_b is None:
        return sandwich_a
    elif sandwich_a is None and sandwich_b:
        return sandwich_b
    elif sandwich_a is None and sandwich_b is None:
        return sandwich_a
    else:
        next_a = sandwich_a.next
        next_b = sandwich_b.next

        sandwich_a.next = sandwich_b
        sandwich_b.next = merge_orders(next_a, next_b)
    
    return sandwich_a

    

sandwich_a = Node('Bacon', Node('Lettuce', Node('Tomato')))
sandwich_a2 = Node('Bacon', Node('Lettuce', Node('Tomato')))
sandwich_b = Node('Turkey', Node('Cheese', Node('Mayo')))
sandwich_c = Node('Bread')


# print_linked_list(merge_orders(sandwich_a, sandwich_b))
# print_linked_list(merge_orders(sandwich_a2, sandwich_c))


# Bacon -> Turkey -> Lettuce -> Cheese -> Tomato -> Mayo
# Bacon -> Bread -> Lettuce -> Tomato

"""
Given a string expression representing arbitrarily nested ternary expressions, evaluate the expression, 
and return its result as a string.

You can always assume that the given expression is valid and only contains digits, 
'?', ':', 'T', and 'F' where 'T' is True and 'F' is False. All the numbers in the expression are one-digit numbers (i.e., in the range [0, 9]).

Ternary expressions use the following syntax:

condition ? true_choice : false_choice

condition is evaluate first and determines which choice to make.
true_choice is taken if condition evaluates to True
false_choice is taken if condition evaluates to False
The conditional expressions group right-to-left, and the result of the expression will always evaluate to either a digit, 'T' or 'F'.
"""

def evaluate_ternary_expression_iterative(expression):
    stack = []
    
    # Traverse the expression from right to left
    for i in range(len(expression) - 1, -1, -1):
        char = expression[i]
        
        if stack and stack[-1] == '?':
            stack.pop()  # Remove the '?'
            true_expr = stack.pop()  # True expression
            stack.pop()  # Remove the ':'
            false_expr = stack.pop()  # False expression
            
            if char == 'T':
                stack.append(true_expr)
            else:
                stack.append(false_expr)
        else:
            stack.append(char)
    
    return stack[0]

def evaluate_ternary_expression_recursive(expression):
    pass

print(evaluate_ternary_expression_recursive("T?2:3"))
print(evaluate_ternary_expression_recursive("F?1:T?4:5"))
print(evaluate_ternary_expression_recursive("T?T?F:5:3"))
