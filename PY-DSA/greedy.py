<<<<<<< HEAD
def fractional_knapsack(capacity, items):
    items.sort(key=lambda x: x[1]/x[0], reverse=True)
    total = 0.0
    
    for weight, value in items:
        if capacity >= weight:
            total += value
            capacity -= weight
        else:
            total += value * (capacity / weight)
            break
    return total

# Example usage
items = [(10, 100), (40, 280), (20, 120)]  # (weight, value)
print("Max Value:", fractional_knapsack(60, items))  # Output: 440.0
=======
def fractional_knapsack(capacity, items):
    items.sort(key=lambda x: x[1]/x[0], reverse=True)
    total = 0.0
    
    for weight, value in items:
        if capacity >= weight:
            total += value
            capacity -= weight
        else:
            total += value * (capacity / weight)
            break
    return total

# Example usage
items = [(10, 100), (40, 280), (20, 120)]  # (weight, value)
print("Max Value:", fractional_knapsack(60, items))  # Output: 440.0
>>>>>>> bc7dcdb (Initial commit)
