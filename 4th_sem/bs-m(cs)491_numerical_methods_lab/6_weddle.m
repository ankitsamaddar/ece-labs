%Weddle
clc
clear all; 
close all;
f = @(x)1/x;
a = 1;
b = 5;
n = 6;
h = (b-a)/n;
s = f(a)+f(b);

for i=2:2:n-2
  s=s+f(a+i*h);
end

for i=1:4:n-1
  s= s+5*f(a+i*h);
end

for i=3:3:n-3
  s= s+6*f(a+i*h);
end

s *= ((3*h)/10);
fprintf('The required value is %.4f\n',s);