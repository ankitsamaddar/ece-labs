% Copyright @2022 Ankit Samaddar
clc
% N=input('length of sequence :');
N=10;
% Unit Ramp
t = 0:N-1;
y = t;
subplot(3, 2, 1);
plot(t, y);
title('Unit Ramp');
xlabel('t');
ylabel('y');

% Unit Step
t = 0:N-1;
y = [1,ones(1,(N-1))];
subplot(3, 2, 2);
plot(t, y);
title('Unit Step');
xlabel('t');
ylabel('y');

% Unit Impulse
t = 0:N-1;
y = [1,zeros(1,(N-1))];
subplot(3, 2, 3);
stem(t, y);
title('Unit Impulse');
xlabel('t');
ylabel('y');

% Exponential Sequence
t = -1:0.1:N-1;
y = exp(t);
subplot(3, 2, 4);
plot(t, y);
title('Exponential Sequence');
xlabel('t');
ylabel('y');

%Sinusoidal Sequence
f = 0.1;
t = 0:N-1;
y = sin(2*pi*f*t) ;
subplot(3, 2, 5);
plot(t, y);
title('Sinusoidal Sequence');
xlabel('t');
ylabel('y');
