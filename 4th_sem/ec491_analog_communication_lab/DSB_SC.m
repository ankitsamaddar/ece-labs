clear all;
close all;
clc;
t=0.001:0.00001:0.0999;
f=0:1:9999;
Vm= 1;
Vc= 1;
fm = 20;
fc= 500;
mu=1;


message = Vm*sin(2*pi*fm*t);
carrier = Vc*sin(2*pi*fc*t);
dsbsc = message.*carrier;
demod = dsbsc.*carrier;
Vf=abs(fft(dsbsc,10000))/500;
%%% Demodulator using synchronous detector
[b a]=butter(2,0.002);
mr= filter(b,a,demod);
figure(1)
subplot(211)
plot(t,message)
xlabel('Time') ;ylabel('Amplitude');
title('Message signal');grid;
subplot(212)
plot(t,carrier);
xlabel('Time') ;ylabel('Amplitude');
title('Carrier signal');grid;

figure(2)
subplot(211)
plot(t,dsbsc);
hold on;
plot(t,message,'r'),plot(t,-message,'r');
xlabel('Time') ;ylabel('Amplitude');
title('Modulated signal');grid;
subplot(212)
plot(f*10,Vf);
axis([(fc-16*fm) (fc+16*fm) 0 10]);
xlabel('Time') ;ylabel('Power');
title('Spectrum of DSB-SC Modulated signal');grid;
figure(3)
plot(t,mr);
xlabel('Time') ;ylabel('Amplitude');
title('Demodulated signal');grid;