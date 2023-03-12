import numpy as np
import matplotlib.pyplot as plt

def fun1(p):  # 1/(1-e^-p)
    return (1/(1-np.exp(-p)))

def fun2(p): # (1-e^-p)/(1+e^p)
    return (1-np.exp(-p))/(1+np.exp(p))

p = float(input("Enter value of p: "))
xlist = np.linspace(0.5,p,num=200)
ylist1 = fun1(xlist)
ylist2 = fun2(xlist)
#Plotting
plt.figure(num=0,dpi=120)
plt.plot(xlist,ylist1,label="f1(p)=1/(1-e^-p)")
plt.plot(xlist,ylist2,label="f2(p)=(1-e^-p)/(1+e^p)")
plt.title("Plotting Two Functions")
plt.xlabel("p")
plt.ylabel("f(x)")
plt.legend()
plt.show()
