clc;
clear all;
close all;
%The frequency modulation(FM)waveform in time and frequency domain.
%fm=250HZ,fc=5KHZ,Vm=1V,Vc=1V,m=10,t=0:0.00001:0.09999
vc=1; % Carrier amplitude
vm=1; % Message Amplitude
fm=250; % Message frequency
fc=5000; % Carrier frequency
m=10; % beta
kf=100
t=0:0.00001:0.09999;
f=0:10:99990;
carrier=vc*cos(2*pi*fc*t);
message=vm*cos(2*pi*fm*t);
FM=vc*cos((2*pi*fc*t)+10*sin(2*pi*fm*t)); % FM wave
dem=(1/2*pi*10)*diff(10*sin(2*pi*fm*t))/0.2; %% Demodulation using PLL
vf=(fft(FM,10^4))/500;
figure(1);
subplot(211);plot(t,message);
xlabel('Time');ylabel('Amplitude');
title('FM modulating signal');grid
subplot(212);plot(t,carrier);
xlabel('Time');ylabel('Amplitude')
axis([0 0.01 -1.5 1.5]);
title('FM carrier signal');grid
figure(2);
subplot(211);plot(t,FM);hold on;
plot(t,message,'r');
axis([0 0.01 -1.5 1.5]);
xlabel('time(second)'),ylabel('amplitude');
title('FM time-domain');
grid on;
subplot(212)
plot(f,vf);
axis([ 0 10^4 0 4]);
xlabel('frequency'), ylabel('amplitude');
title('FM frequency-domain');
grid on;
figure(3)
plot(dem)
xlabel('Time'),ylabel('amplitude');
title('FM Demodulated signal');grid
grid on;