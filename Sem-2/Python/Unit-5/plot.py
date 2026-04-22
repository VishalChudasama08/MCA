# Unit-5
"""
plot 
"""

import matplotlib.pyplot as pl

x = [2, 9]
y = [2, 5]

# pl.plot(x, y)

# point only
pl.plot(x, y, 'o')
pl.show()

# plot multiple points
x = [1, 4, 6, 9]
y = [8, 5, 3, 1]

pl.plot(x, y)

pl.show()


# mark color and size
x = [3, 5, 7, 2, 8, 3]
y = [5, 8, 5, 7, 7, 5]

pl.plot(x, y, marker="*", ms=12, mec="g")
pl.show()


x = [2, 3, 5, 7]
y = [3, 4, 5, 6]

m = [1, 2, 3, 4]
z = [5, 6, 7, 8]
pl.xlabel("x axis")
pl.ylabel("y axis")
pl.title("Student data", loc="right")
pl.plot(x, y)
pl.plot(m, z)
pl.show()


x = [2, 3, 4, 5]
y = [1, 3, 6, 9]
pl.scatter(x, y)
m = [1, 2, 3, 4]
z = [5, 6, 7, 8]
pl.scatter(m, z)
pl.show()
