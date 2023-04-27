% EXPERIMENT 4 - Simulation of step response and impulse response for Type I
% [G3(s)=10/(s(s+2)(s+4))] system with unity feedback.

clc
z=[];
p=[0 -2 -4];
k=[10];
sys1 = zpk(z,p,k);
sys2 = feedback(sys1,1);
figure(2);
subplot(211),step(sys2),title('Step Response'),grid on;
subplot(212),impulse(sys2),title('Impulse Response'),grid on;