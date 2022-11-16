% Copyright @2022 Ankit Samaddar
clc
N=input('length of sequence :');
f1=input('frequency of the signal1 :');
f2=input('frequency of the signal2 :');
n=0:N-1;
y1=sin(2*pi*f1*n);
y2=sin(2*pi*f2*n);
subplot(5,1,1);
stem(n,y1);
title('signal1');
%xlabel('signal1');

subplot(5,1,2);
stem(n,y2);
title('signal2');
%xlabel('signal2');

AS1=(y1+y2);
subplot(5,1,3);
stem(n,AS1);
title('Addition');
%xlabel('signal1');

AS2=(y1-y2);
subplot(5,1,4);
stem(n,AS2);
title('Subtraction');
%xlabel('signal1');

AS3=(y1.*y2);
subplot(5,1,5);
stem(n,AS3);
title('Multiplication');
%xlabel('signal1');

%exponential;
figure;
a1=2;
y3=a1.^n;
subplot(5,1,1);
stem(n,y3);
title('signal1');

a2=3;
y4=a2.^n;
subplot(5,1,2);
stem(n,y4);
title('signal2');

ES1=(y3+y4);
subplot(5,1,3);
stem(n,ES1);
title('Addition');

ES2=(y3-y4);
subplot(5,1,4);
stem(n,ES2);
title('Subtraction');

ES3=y3.*y4;
subplot(5,1,5);
stem(n,ES3);
title('Multiplication');
