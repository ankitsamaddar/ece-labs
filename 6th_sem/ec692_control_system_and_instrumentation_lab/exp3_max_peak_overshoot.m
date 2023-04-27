% EXPERIMENT 3 - Open loop transfer function of a control system G2(s) =
% 1/(s(s+0.6)). Observe the closed loop system response (for unit step
% input) using unity feedback by Simulink diagram in MATLAB. Also find the
% maximum peak overshoot using formula.

clc 
n = 1;
d1 = [1 0.6 0];
sys = tf(n, d1);

% Add a pole at the origin to stabilize the system
sys_cl = feedback(sys, 1);
step(sys_cl),grid on;

% Obtain step response information and calculate maximum peak overshoot
info = stepinfo(sys_cl);
mpo = (info.Peak - 1) * 100;

% Display maximum peak overshoot
fprintf('Maximum Peak Overshoot: %f%%\n', mpo);
