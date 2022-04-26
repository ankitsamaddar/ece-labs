clc;
clear all;
close all;

%carrier signal
fc=6000;
Tc=1/fc;
Lc=100*Tc;
tc=0:0.001*Lc:Lc;
Ac=2;
c=cos(2*pi*fc*tc);

%normalized message signal
fm=2000;
Tm=1/fm;
Lm=10*Tm;
ts=0.001*Lm;
fs=1/ts;
tm=0:ts:Lm;
Am=2;
m=cos(2*pi*fm*tm);

grid on;
subplot(4,1,1);
plot(tm,c);
title('Carrier Signal');
subplot(4,1,2);
plot(tm,m);
title('Modulating Signal');

% Modulated signal
mu(1)=0; %initalize modulating index
for i=1:1:10
    x=mu(i);
    S=Ac*(1+x.*m).*c;
    mu(i+1)=mu(i)+0.1;  %increase modulating index by 0.1  m(prev)+0.1
    subplot(4,1,3),plot(tm,S),title('Modulated Signal');
    drawnow;
end

mu = [mu(end)]; % re-initialize modulating index with the last value
fprintf('m = %d\n', mu);
ma=mu*mu;
fprintf('m^2 = %d\n',ma);

% fm signal varing modulation index
b=7;
for i=0:0.5:b
    FM=Ac*cos((2*pi*fc*tc)+i*sin(2*pi*fm*tm));
    subplot(4,1,4);
    plot(tm,FM);
    title('Frequency Signal');
    drawnow;
end

%power calculation
sbp= (Ac*Ac*ma)/8;
dsb= sbp*2;
fprintf('Sideband Power of a Singleband = %d Watt \nDouble Sideband Power = %d Watt\n', sbp, dsb);
pc= (Ac*Ac)/2;
fprintf('Carrier Power = %d Watt \n', pc);
pt= pc*(1+ma/2);
fprintf('Total Power = %d watt\n', pt);
p_carrier=max(abs(pc));
p_carrier_dB=pow2db(pc);
p_sideband=max(abs(sbp));
p_sideband_dB=pow2db(sbp);
