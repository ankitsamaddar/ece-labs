%Lagrange
clc , clear ;
x = [0 1.2 2.4 3.7];
y = [3.14 2.68 1.37 -1.18];
x0 = input('Enter the value of x : ');

n = length(x);
sm=0;
for j=1:n
	pr=1; % for every product re initialized
	for i=1:n
		if i~=j
			pr=pr*(x0-x(i))/(x(j)-x(i));
		endif
	endfor
	sm=sm+pr*y(j); % adding l(x)  i.e.  l(j) = pr*y(j)
endfor

fprintf('The required value is f(%i)=%.4f\n',x0,sm);