% EXPERIMENT 5 - Simulation of step response and impulse response for Type
% 2 [T(s)=10(s+1)/(s^2(s+4))] system with unity feedback.

clc
z=[-1];
p=[0 0 -4];
k=[10];
g3 = zpk(z,p,k);
h3=tf(1,1);
sys2 = feedback(g3,h3);
figure(1);
subplot(211),step(sys2),title('Step Response'),grid on;
subplot(212),impulse(sys2),title('Impulse Response'),grid on;