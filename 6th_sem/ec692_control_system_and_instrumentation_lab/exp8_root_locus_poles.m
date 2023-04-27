% EXPERIMENT 8
%  Find the root locus and values of poles for the following transfer
%  function (s+1)/(s^4+3s^3+2s^2+4) using sisotool and MATLAB.

clc
n =[1,1];
d=[1 3 2 0 4];
sys=tf(n,d);

% Plot the root locus
rlocus(sys);

% Use rlocfind to find the gain and poles
[k, poles] = rlocfind(sys);

% Print the results
disp('Gain is : ');
disp(k);
disp('The poles are : ');
disp(poles);
