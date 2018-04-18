import numpy as np

import matplotlib.pyplot as plt


#cargar los datos para la grafica

datos=np.loadtxt('try.txt')

#para separar las columnas n, 

t=datos[:,0]
x=datos[:,1]
v=datos[:,1]



plt.plot(t,x,color='m')
plt.title("x vs t")
plt.xlabel("tiempo")
plt.ylabel("x")
plt.savefig('pos.png')

plt.figure()

plt.plot(t,v,color='c')
plt.title("v vs t")
plt.xlabel("tiempo")
plt.ylabel("velocidad")
plt.savefig('vel.png')

plt.figure()

plt.plot(x,v,color='c')
plt.title("v vs x")
plt.xlabel("x")
plt.ylabel("velocidad")
plt.savefig('phase.png')

