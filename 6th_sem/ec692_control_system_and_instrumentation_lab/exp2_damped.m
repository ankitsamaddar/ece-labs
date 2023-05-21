% EXPERIMENT 2 
% Observe the unit step response of the second order transfer
% function G1(s) using MATLAB. By observing the time domain response, proof
% that the transfer function is of an under damped control system. For the
% system if ?=0, then observe the unit step response by writing code.
clc
n=1;
d1=[1 0.6 1];
sys1=tf(n,d1);
d2=[1 10 1];
sys2=tf(n,d2);
subplot(211),step(sys1),title('UNDERDAMPED'),grid on;
subplot(212),step(sys2),title('UNDAMPED'),grid on;
