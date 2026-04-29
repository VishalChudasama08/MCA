"""
Q-1    Create a dictionary: 
  Key → Mobile Number 
  Value → Service Provider (based on starting digits) 
Example rule: 
  Starts with 98 or 99 → "Airtel" 
  Starts with 97 → "Jio" 
  Starts with 96 → "VI" 
  Otherwise → "Other" 
  Display all mobile numbers belonging to Airtel in a tuple. 
  Count how many numbers belong to each service provider. 
  Display mobile numbers in sorted order. 
[20] 
"""

# Function: Determine service provider
def get_provider(number):
    num = str(number)
    if num.startswith("98") or num.startswith("99"):
        return "Airtel"
    elif num.startswith("97"):
        return "Jio"
    elif num.startswith("96"):
        return "VI"
    else:
        return "Other"


# Function: Create dictionary
def create_dict(numbers):
    result = {}
    for num in numbers:
        result[num] = get_provider(num)
    return result


# Function: Airtel numbers (tuple)
def airtel_numbers(data):
    return tuple([num for num, provider in data.items() if provider == "Airtel"])


# Function: Count providers
def count_providers(data):
    count = {}
    for provider in data.values():
        count[provider] = count.get(provider, 0) + 1
    return count


# MAIN PROGRAM
n = int(input("Enter number of mobile numbers: "))
numbers = []

for i in range(n):
    num = input(f"Enter mobile number {i+1}: ")
    numbers.append(num)

mobile_dict = create_dict(numbers)

print("\nMobile Dictionary (Number → Provider):", mobile_dict)
print("\nAirtel Numbers (tuple):", airtel_numbers(mobile_dict))
print("\nCount of each provider:", count_providers(mobile_dict))
print("\nSorted mobile numbers:", sorted(numbers))


"""
Q-2  Write a Python program to manage Product Inventory System using file 
handling. Use functions to perform the given tasks 
1)  Accept details of 5 products: 
  Product ID 
  Product Name 
  Price 
  Quantity 
  Supplier Name 
1) Store in file Product_Inventory.txt. 
3) Perform: 
  Find most expensive product. 
  Display products with quantity less than 10. 
  Calculate total inventory value. 
  Count products supplied by each supplier. 
[20] 
"""

def store_products():
    file = open("Product_Inventory.txt", "w")
    products = []

    for i in range(5):
        print(f"\nEnter details of Product {i+1}:")
        pid = input("Product ID: ")
        name = input("Product Name: ")
        price = float(input("Price: "))
        qty = int(input("Quantity: "))
        supplier = input("Supplier Name: ")

        product = (pid, name, price, qty, supplier)
        products.append(product)

        file.write(f"{pid},{name},{price},{qty},{supplier}\n")

    file.close()
    return products


def analyze_products(products):
    max_product = max(products, key=lambda x: x[2])
    print("\n--- Most Expensive Product ---")
    print(max_product)

    print("\n--- Products with Quantity < 10 ---")
    for p in products:
        if p[3] < 10:
            print(p)

    total_value = 0
    for p in products:
        total_value += p[2] * p[3]

    print("\n--- Total Inventory Value ---")
    print(total_value)

    supplier_count = {}
    for p in products:
        supplier = p[4]
        supplier_count[supplier] = supplier_count.get(supplier, 0) + 1

    print("\n--- Products per Supplier ---")
    print(supplier_count)

products = store_products()
analyze_products(products)