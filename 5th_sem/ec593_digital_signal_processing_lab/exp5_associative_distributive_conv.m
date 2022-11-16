% Copyright @2022 Ankit Samaddar
clc
clear all
close all
% Define the signals
xn = [3 11 7 0 -1 4 2]; xn_s = -2; xn_e=4;
hn1 = [2 3 0 -5 2 1 0]; hn1_s = 0; hn1_e=6;
hn2 = [1 5 3 0 2 1 0]; hn2_s = 0; hn2_e=6;

% Set the origins for each signal
%distributive
y_s = xn_s+hn1_s;
y_e = xn_e+hn1_e;
yS = y_s:y_e;
% associative
y1_s = xn_s+hn1_s+hn2_s;
y1_e = xn_e+hn1_e+hn2_e;
y1S = y1_s:y1_e;

% Calculate convolution using distributive property
y1 = conv(xn, hn1 + hn2);
y2 = conv(xn, hn1) + conv(xn, hn2);

% Calculate convolution using associative property
y3 = conv(conv(xn, hn1), hn2);
y4 = conv(xn, conv(hn1, hn2));

% Display the results
%Distributive
subplot(2, 2, 1);
stem(yS,y1);
title('Distributive: Left Sequence');

subplot(2, 2, 2);
stem(yS,y2);
title('Distributive: Right Sequence');

%Associative
subplot(2, 2, 3);
stem(y1S,y3);
title('Associative: Left Sequence');

subplot(2, 2, 4);
stem(y1S,y4);
title('Associative: Right Sequence');


% Check if the results are equal 
if y1 == y2
    disp('The distributive property holds for convolution.');
else
    disp('The distributive property does not hold for convolution.');
end

if y3 == y4
    disp('The associative property holds for convolution.');
else
    disp('The associative property does not hold for convolution.');
end
