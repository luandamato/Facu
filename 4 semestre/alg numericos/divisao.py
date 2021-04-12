def termopro(i, value, x): 
	pro = 1; 
	for j in range(i): 
		pro = pro * (value - x[j]); 
	return pro; 

def diftabela(x, y, n): 

	for i in range(1, n): 
		for j in range(n - i): 
			y[j][i] = ((y[j][i - 1] - y[j + 1][i - 1]) /
									(x[j] - x[i + j])); 
	return y; 


def aplicandoform(value, x, y, n): 

	sum = y[0][0]; 

	for i in range(1, n): 
		sum = sum + (termopro(i, value, x) * y[0][i]); 
	
	return sum; 

#diferença tabela

def printtabela(y, n): 

	for i in range(n): 
		for j in range(n - i): 
			print(round(y[i][j], 4), "\t", 
							end = " "); 

		print(""); 

# numero de entradas 

def ex1(value):
  n = 6; 
  y = [[0 for i in range(10)] 
      for j in range(10)]; 
  x = [ -2, -1, 0, 1, 2, 3 ]; 

  y[0][0] = 1
  y[1][0] = 4
  y[2][0] = 11
  y[3][0] = 16
  y[4][0] = 13
  y[5][0] = -4

  # diferença da divisão
  y=diftabela(x, y, n); 
  
  printtabela(y, n); 

  # interpolação
  #value = 4


  # Valor 
  print("\nValue at", value, "is", 
      round(aplicandoform(value, x, y, n), 2)) 

def ex2(value):
  n = 5; 
  y = [[0 for i in range(10)] 
      for j in range(10)]; 
  x = [ -2, -1, 0, 1, 2,]; 

  y[0][0] = -1
  y[1][0] = 3
  y[2][0] = 1
  y[3][0] = -1
  y[4][0] = 3

  # diferença da divisão
  y=diftabela(x, y, n); 
  
  printtabela(y, n); 

  # interpolação
  #value = 4


  # Valor 
  print("\nValue at", value, "is", 
      round(aplicandoform(value, x, y, n), 2)) 


print ("EXERCICIO 1")
ex1(-2)
ex1(-1)
ex1(0)
ex1(1)
ex1(2)
ex1(3)


print ("\n\n")
print ("EXERCICIO 2")
ex2(-2)
ex2(-1)
ex2(0)
ex2(1)
ex2(2)