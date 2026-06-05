# problem5.py

def most_honey(heights):
    left = 0
    right = len(heights) - 1
    
    max_amount = 0
    
    while left < right:
        amount = (right - left) * min(heights[right], heights[left])
        max_amount = max(max_amount, amount)
        
        if heights[right] > heights[left]:
            left += 1
        else:
            right -= 1
    
    
    return max_amount


if __name__ == "__main__":
    height = [1, 1]
    print(most_honey(height))