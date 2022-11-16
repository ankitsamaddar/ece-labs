% Copyright @2022 Ankit Samaddar
clc
close all
% Generate two signals xn and hn
xn = [3 11 7 0 -1 4 2];
hn = [2 3 0 -5 2 1];

% Calculate the convolution of xn and hn
yn = conv(xn, hn);

% Calculate the convolution of hn and xn
yn_2 = conv(hn, xn);

% Plot the original signals and their convolutions
subplot(2, 2, 1);
stem(xn);
title('xn');

subplot(2, 2, 2);
stem(hn);
title('hn');

subplot(2, 2, 3);
stem(yn);
title('xn * hn');

subplot(2, 2, 4);
stem(yn_2);
title('hn * xn');

% Check if the convolutions are equal
if isequal(yn, yn_2)
    disp('Convolution is commutative');
else
    disp('Convolution is not commutative');
end
