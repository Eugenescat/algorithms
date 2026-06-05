

def transpose(matrix):
    # create a new matrix full of Null
    # traverse each rows, if the cube is still null:
    rows = len(matrix)
    cols = len(matrix[0])
    
    result = []
    
    for c in range(cols):
        new_row = []
        for r in range(rows):
            new_row.append(matrix[r][c])
        result.append(new_row)
    
    return result
        


# Output :
# # [
#     [1, 4, 7],
#     [2, 5, 8],
#     [3, 6, 9]
# ]
# List = [ list[], list[], list[]]
# print(transpose(matrix))

# matrix = [
#     [1, 2, 3],
#     [4, 5, 6]
# ]

if __name__ == "__main__":
        
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print(transpose(matrix))