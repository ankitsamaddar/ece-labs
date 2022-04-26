clc
clear all;
close all;

fc = 5000;
Tc = 1/fc;    %Time period = 0.00016
Lc = 100 * Tc;    %0.016
tc = 0:0.001*Lc:Lc;
c = cos(2*pi*fc*tc);
%plot(tc,c);

fm = 2000;
Tm = 1/fm;    %0.0005
Lm = 10 * Tm;
%ts = 0.001*Lm;
%fs = 1/ts;
tm = 0:0.001*Lm:Lm;
M_t = cos(2*pi*fm*tm);
%plot(tm,M_t)

Ec = 2;
m(1) = 0
a = []
for i=1:1:10
    x = m(i);   %x = 0 0.1
    e = Ec+x.*M_t;    %e = 1+x.[M_t] e=[1 1 1 1.....1]
    AM = e.*c;    % Am = [1 0.8 ......]
    a = [a;AM];   % a = [ ; 1 0.8.....]   (Ec + x.M_t) * c
    m(i+1) = m(i) + 0.1;
end

s1 = a(1,:);
s2 = a(5,:);
s3 = a(10,:);
subplot(3,1,1)
plot(tm,s1)
subplot(3,1,2)
plot(tm,M_t)
subplot(3,1,3)
plot(tm,s3)
