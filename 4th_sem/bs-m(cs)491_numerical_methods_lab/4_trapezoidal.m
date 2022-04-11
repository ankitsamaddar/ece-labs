%Trapezoidal
clc, clear;
f = @(x)1/x;
x = [-4 -3 -2 -1 0 1 2];
y = [0 4 5 3 10 11 2];
n=length(x);
a=x(1);
b=x(n);
n=6;

h= b-a/n;

s= (1/2)*(y(1)+y(n));   % (1/2)*(f(a)+f(b))

for i=2:n-1
	s=s+y(i);   % s= s + f(a+i*h)
end

s=s*h
