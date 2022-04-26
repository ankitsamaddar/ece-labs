clc;
clear all;
close all;

fm=20;
fc=500;
vm=1;
vc=1;
mu=1; % modulation index
% x-axis:Time(second)
t=0:0.00001:0.0999;
f=0:1:9999;
% y-axis:Voltage(volt)
V1=vc+mu*sin(2*pi*fm*t); %upper envelop
V2=-(vc+mu*sin(2*pi*fm*t)); % lower envelop
Vm=vm*sin(2*pi*fm*t);
Vc=vc*sin(2*pi*fc*t);
Vam=vc*(1+mu*sin(2*pi*fm*t)).*(sin(2*pi*fc*t)); %%AM signal
Vr=Vam.*Vc; % Synchronous detector
Vf=abs(fft(Vam,10000))/500; % Spectrum
[b a] = butter(3,0.002);
out= filter(b,a,Vr);
%Plot modulating,carrier signal
figure(1);
subplot(211)
plot(t,Vm);
title('AM modulating signal');
xlabel('time'), ylabel('amplitude');grid on;
subplot(212)
plot(t, Vc);
title('AM carrier signal');
xlabel('time'), ylabel('amplitude');grid on;
% Plot AM in time domain and Frequency domain 
figure(2);
subplot(211)
plot(t,Vam);
hold on;
plot(t,V1,'r'),plot(t,V2,'r');
title('AM waveform time-domain');
xlabel('time'), ylabel('amplitude');grid on;
subplot(212)
plot(f*10,Vf);
axis([(fc-6*fm) (fc+6*fm) 0 10]);
title('AM waveform frequency-domain');
xlabel('frequency'), ylabel('amplitude');grid on;
figure(3)
plot(t,1.81*out)
title('AM Demodulated signal');
xlabel('time'), ylabel('amplitude');
grid;