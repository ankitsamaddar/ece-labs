clc;
clear all;
close all;

fm=20;
fc=500;
vm=1;
vc=1;
mu=0.1;
t=0:0.00001:0.0999;
f=0:1:9999;
m=vm*cos(2*pi*fm*t); %% message
mp=vm*sin(2*pi*fm*t);
c=vc*cos(2*pi*fc*t); %% carrier
cp=vc*sin(2*pi*fc*t);
ss1=m.*c;
ss2=mp.*cp;
upper=ss1-ss2; %% upper sideband signal
lower=ss1+ss2; %% lower sideband signal
Vfupper=abs(fft(upper,10000))/10000; %% upper frequency spectrum
Vflower=abs(fft(lower,10000))/10000; %% lower frequency spectrum
%%% demodulator using Synchronous detector %%%%
%% upper demodulated
vudemod=c.*upper;
[b a] = butter(2,0.002);
upperdemod= filter(b,a,vudemod);
%% lower demodulated
vldemod=c.*lower;
[b a]=butter(2,0.002);
lowerdemod=filter(b,a,vldemod);
figure(1)
subplot(211);plot(t,m)
xlabel('Time') ;ylabel('Amplitude');
title('Message signal');grid;
subplot(212);plot(t,c)
xlabel('Time');ylabel('Amplitude');
title('Carrier signal');grid;
figure(2)
subplot(211);plot(t,upper)
xlabel('Time');ylabel('Amplitude');
title('SSB Upper Sideband signal');grid
subplot(212);plot(t,lower)
xlabel('Time');ylabel('Amplitude');
title('SSB Lower Sideband signal');grid
figure(3)
subplot(211);plot(f*10,Vfupper)
axis([(fc-20*fm) (fc+20*fm) 0 0.6]);
xlabel('Frequency');ylabel('Power');
title('SSB Upper Sidebsnd signal spectrum');grid
subplot(212);plot(f*10,Vflower)
axis([(fc-20*fm) (fc+20*fm) 0 0.6]);
xlabel('Frequency');ylabel('Power');
title('SSB Lower Sidebsnd signal spectrum');grid
figure(4)
subplot(211);plot(t,upperdemod)
xlabel('Time') ;ylabel('Amplitude');
title('Upper sideband Demodulated signal');grid;
subplot(212);plot(t,lowerdemod)
xlabel('Time') ;ylabel('Amplitude');
title('Lower sideband Demodulated signal');grid;