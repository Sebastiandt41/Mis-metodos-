#La matriz de covarianza

import numpy as np 
import matplotlib.pyplot 

datos= np.genfromtxt("room-temperature.txt",delimiter =',',skip_header = 1, usecols = (1,2,3,4))

M = np.size(datos[:,0])
n = np.size(datos[0])

Cov = np.identity(n)

for i in range(n):
	for j in range(n):
		b= 0
		for k in range(M):				
			b += (datos[k,i]-np.mean(datos[:,i]))*(datos[k,j]-np.mean(datos[:,j]))/(M-1)
		
		Cov[i][j] = b
	
print Cov

Covreal = np.cov(datos)

print Covreal
#Sacar los eigen , ordenarlos de mayor a menor , mirar la varianza, PC1 , PC2 , agrupaciones, X mayor varianza, Y segunda mayor varianza. 



			 
		
		


