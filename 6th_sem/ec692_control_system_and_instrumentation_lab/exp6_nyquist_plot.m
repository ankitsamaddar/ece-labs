% EXPERIMENT 6 - Obtain the nyquist plot for the transfer function T(s) =
% 10/{(s^2)+10s+9} using SISOTOOL in MATLAB.
clc
n =[10];
d=[1 10 9];
sys=tf(n,d);
nyquist(sys),grid on;