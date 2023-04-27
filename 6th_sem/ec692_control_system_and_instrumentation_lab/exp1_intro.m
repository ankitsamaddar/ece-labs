% EXPERIMENT 1
% familiarization with MATLAB control system toolbox(Simulink,sisotool) and
% representation of pole zero and transfer function of control system.
clc
n=1;
d=[1 0.6 1];
sys = tf(n,d);
step(sys),grid on