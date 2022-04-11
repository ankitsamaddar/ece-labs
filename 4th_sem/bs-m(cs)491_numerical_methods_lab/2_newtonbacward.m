%Newton's Backward
clc
clear all; 
close all;
x = [1891 1901 1911 1921 1931];
y = [46 66 81 93 101];
n = length(x);
d = zeros(n-1);
x0 = input('Enter the value of x : ');
% Table
for i = 1:n-1
	d(i,1)=y(i+1)-y(i);
end

for j=2:n
	for i =1:n-j
		d(i,j) = d(i+1,j-1) - d(i,j-1);
	end
end
disp ('The Backward Difference Table is '),disp(d);
% Calculating F(x)
h = x(2)-x(1);
u = (x0-x(n))/h;

s = y(n);
t = u;

for i=1:n-1
	s=s+t*d(n-i,i);
	t =((u-i)/i+1)*t;
end
fprintf('The required value is f(%i)=%.4f\n',x0,s);