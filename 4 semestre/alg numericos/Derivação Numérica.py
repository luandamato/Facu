from math import sin, cos, log

# f(x)
def f(x):
    return pow(x, 2) - log(x)

# f'(x)
def f_(x):
    return (2 * x) - (1 / x)

# 3f(1)
def f3():
    return 3 * f(1)

# 4f(1+h)
def f4(x):
    return 4 * f(1 + x)

# f(1 + 2h)
def f2h(x):
    return f(1 + (2 * x))

# f'*(x)
def ft(x):
    return (1 / (2 * x)) * (- f3() + f4(x) - f2h(x))

print("Maior")
print(f3())
print(f4(0.1), f4(0.01), f4(0.001), f4(0.0001))
print(f2h(0.1), f2h(0.01), f2h(0.001), f2h(0.0001))
print(ft(0.1), ft(0.01), ft(0.001), ft(0.0001))
print(f_(1))
x0 = abs(f_(1) - ft(0.1) / f_(1))
x1 = abs(f_(1) - ft(0.01) / f_(1))
x2 = abs(f_(1) - ft(0.001) / f_(1))
x3 = abs(f_(1) - ft(0.0001) / f_(1))
print(x0, x1, x2, x3)
print()
print("Menor")


# f(1 - 2h)
def f_2h(x):
    return f(1 - (2 * x))

# 4f(1-h)
def f4_h(x):
    return 4 * f(1 - x)

# f'*(x)
def ft(x):
    return (1 / (2 * x)) * (f_2h(x) - f4_h(x) + f3())


print(f_2h(0.1), f_2h(0.01), f_2h(0.001), f_2h(0.0001))
print(f4_h(0.1), f4_h(0.01), f4_h(0.001), f4_h(0.0001))
print(ft(0.1), ft(0.01), ft(0.001), ft(0.0001))

x0 = abs(f_(1) - ft(0.1) / f_(1))
x1 = abs(f_(1) - ft(0.01) / f_(1))
x2 = abs(f_(1) - ft(0.001) / f_(1))
x3 = abs(f_(1) - ft(0.0001) / f_(1))
print(x0, x1, x2, x3)

# f(1+h)
def fh(x):
    return f(1 + x)

# f(1 - h)
def f_h(x):
    return f(1 - x)

# f'*(h)
def ft(x):
    return (1 / (x * 2)) * (fh(x) - f_h(x))



print()
print("centro")
print(fh(0.1), fh(0.01), fh(0.001), fh(0.0001))
print(f_h(0.1), f_h(0.01), f_h(0.001), f_h(0.0001))
print(ft(0.1), ft(0.01), ft(0.001), ft(0.0001))
x0 = abs(f_(1) - ft(0.1) / f_(1))
x1 = abs(f_(1) - ft(0.01) / f_(1))
x2 = abs(f_(1) - ft(0.001) / f_(1))
x3 = abs(f_(1) - ft(0.0001) / f_(1))
print(x0, x1, x2, x3)