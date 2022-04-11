%Gauss-Elemination
clc
close all;
clear all;

A = [1 1 -1; 1 -1 2; 2 1 1];
n = size(A,1);
X = zeros(n,1);
B = [7;3;9];


for j=2:n
    for i=j:n
        p = A(i,j-1)./A(j-1,j-1);
        A(i,:)= A (i,:) - p*A(j-1,:);
        B(i,:)= B (i,:) - p*B(j-1,:);
    end
end

s=0;
X = zeros(n,1);
X(end) = B(end)/A(end);
 for i=n-1:-1:1
    s=A(i,:)*X(:);
    X(i)= (B(i)-s)/A(i,i);
end

A
B
X
