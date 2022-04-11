clc;
clear all;
% AX=B
a =[1 1 1;2 1 -1;-1 2 2] % cofficient matrix
b = [6; 9; 1]; %function matrix

%a =[4,1,2;1,3,1;1,2,5];
%b =[16;10;12];
n = length(b);
%[n,~]=size(A); %only get rows, ~ to ignore column
A = [a b];
for i=1:n-1
   j=i+1; 
   f=A(j,i)/A(i,i);
   a(j,:)=a(j,:)-f.*a(i,:);  
   b(j,:)=b(j,:)-f.*b(i,:);      
end
a
b
%Backward Substitution
x=zeros(n,1);
x(n,:)= b(n,:)/a(n,n);
for i=n-1:-1:1
    x(i,:)= (b(i,:) - A(i,i+1:n)*x(i+1:n,:))/A(i,i);
%  fprintf('\nThe Value of x(%d)=%.2f',i,x(i));
end
x

