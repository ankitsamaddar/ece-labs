%Newton's Forward
clc;
clear all;
format short g;
x = [0 0.001 0.002 0.003 0.004 0.005];
y = [1.121 1.123 1.1255 1.127 1.128 1.1285];
n = length(x);
d = zeros(n-1);
x0 = input('Enter the value of x : ');

%The Table

for i=1:n-1
	d(i,1) = y(i+1)-y(i);
end


for j=2:n
	for i=1:n-j
		d(i,j) = d(i+1,j-1) - d(i,j-1);
	end
end

disp('The Forward difference table is :');
disp(d);
% Calculating F(x)
h = x(2)-x(1);
u = (x0 -x(1))/h;
s = y(1);
p = u ;
for i = 1:n-1
	s= s+p*d(i);
	p=p*((u-i)/(i+1));
end

fprintf('The required value is f(%i)=%.4f\n',x0,s);
