clc
close all;
clear all;

A = [1 1 1; 2 1 -1; -1 2 2];
X = zeros(size(A,1),1);
B = [6;1;9];

mat = A;

for j=2:size(A,1)
    for i=j:size(A,1)
        ratio = mat(i,j-1)/mat(j-1,j-1)
        mat(i,:) = mat(i,:).-(ratio)*mat(j-1,:);
        B(i) = B(i) .- (ratio)*B(j-1);
    end
end

s=0;
X(end) = B(end)/mat(end);

for i=length(X)-1:-1:1
    s = mat(i,:)*X;
    X(i) = (B(i)-s)/mat(i,i);
end

A
mat
B
X