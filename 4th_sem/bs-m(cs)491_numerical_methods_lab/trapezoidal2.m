
%Trapezoidal
clc
clear all; 
close all;
x = [-4 -3 -2 -1 0 1 2]; 
y = [0 4 5 3 10 11 2]; 
j = length(x);
n = 6;
h = ((x(j)-x(1))/n);
s = (0.5*(y(1)+y(j)));

for i=2 : j-1
  s = s + y(i) ;
end
s = s* h;
fprintf('The required value is %.4f\n',s);
