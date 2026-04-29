"""
1. Read data from an Excel file containing: (Order ID, Customer Name, Product, Quantity, Price, Order Date) 
2. Save the data in the database file. 
3. Load data into a Pandas DataFrame. 
4. Perform and Display: 
	o Total revenue per product 
	o Number of orders per customer 
	o Filter orders placed after a specific date 
5. Plot: 
	o Pie chart of revenue contribution by product 
	o Bar chart of number of orders per customer 
"""

import mysql.connector
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime

conn = mysql.connector.connect(
	host="localhost", port=3306, user="root", password="", database="sales")
cursor = conn.cursor()	
cursor.execute("""
CREATE TABLE IF NOT EXISTS orders (
	order_id INTEGER,
	customer_name TEXT,
	product TEXT,
	quantity INTEGER,
	price REAL,
	order_date TEXT
)
""")

def insert_data_from_excel(file_path):
	df = pd.read_excel(file_path)
	for _, row in df.iterrows():
		data = (
			row['Order ID'],
			row['Customer Name'],
			row['Product'],
			row['Quantity'],
			row['Price'],
			row['Order Date'].strftime('%Y-%m-%d')
		)
		cursor.execute("INSERT INTO orders VALUES (%s, %s, %s, %s, %s, %s)", data)
	conn.commit()
	print("Data inserted from Excel successfully.")

def analyze_data():
	df = pd.read_sql_query("SELECT * FROM orders", conn)

	print("\n--- Complete Data ---")
	print(df)

	print("\n--- Total Revenue per Product ---")
	df['revenue'] = df['quantity'] * df['price']
	revenue_per_product = df.groupby('product')['revenue'].sum()
	print(revenue_per_product)

	print("\n--- Number of Orders per Customer ---")
	orders_per_customer = df.groupby('customer_name')['order_id'].count()
	print(orders_per_customer)

	specific_date = '2023-01-01'
	filtered_orders = df[df['order_date'] > specific_date]
	print(f"\n--- Orders Placed After {specific_date} ---")
	print(filtered_orders)

	revenue_per_product.plot(kind='pie', autopct='%1.1f%%')
	plt.title("Revenue Contribution by Product")
	plt.ylabel("")
	plt.show()
	
	orders_per_customer.plot(kind='bar')
	plt.title("Number of Orders per Customer")
	plt.xlabel("Customer")
	plt.ylabel("Number of Orders")
	plt.show()

insert_data_from_excel("orders.xlsx")
analyze_data()