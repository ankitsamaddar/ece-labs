clc;
clear all;
close all;
%A=input('enter a coefficient matrix A:');
%B=input('enter bourse vector B:');
A = [27 6 -1;6 15 2;1 1 54];
B = [85 ; 72; 110];
P=input('enter initial gauss vector:');
n=input('enter no. of iteration:');
e=input('enter your tolerence:');
N=length(B);
X=zeros(N,1);
Y=zeros(N,1);  %FOR STOPING CRITERIA
for j=1:n
    for i=1:N
        X(i)=(B(i)/A(i))-(A(1,[1:i-1,i+1:N]).*P([1:i-1,i+1:N]))/A(i,i);
        P(i)=X(i);
    end
    fprintf('Iteration no.%d\n',j);
    X
    if abs(Y-X)<e
        break
    end
    Y=X;
end
Y
