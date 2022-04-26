clc;
am = input('am =');
fm = input('fm =');
ac= input('ac=');
fc= input('fc=');
m = am/ac;
t= 0 :pi/1000:2*pi;


subplot (3,1,1)
plot(t,am.*cos(fm*t));
grid on;


subplot(3,1,2);
xlabel('time');
plot(t, ac.*cos(fc*t));
title('c(t)');
grid on;


subplot(3,1,3) ;
xlabel('time');
x = ac*(1+m.*cos(fm*t)).*cos(fc*t);
plot(t, x);
title('AM SIGNAL');
grid on

L=length(x)
Fs=10*fc;
NFFT = 2^nextpow2(L);
pxx = fft(x,NFFT);
f = Fs/2*linspace(0,1,NFFT/2+1);
spec=2*abs(pxx(1:NFFT/8+1));
figure();
plot(f(1:NFFT/8+1),pow2db(spec));
title('Fourier Transform of Modulated Signal');

%power calculation

fprintf('m= %d\n', m);
ma=m*m;
fprintf('m^2= %d\n',m*m);
sbp= (ac*ac*ma)/8;
dsb= sbp*2;
fprintf('sideband power of a single band = %d Watt and that of double side band is %d \n', sbp, dsb)
pc= (ac*ac)/2;
fprintf('carrier power =%d watt \n', pc);
am_power= pc*(1+ma/2);
fprintf('am_power= %d watt\n', am_power);
p_carrier=max(abs(pc))
p_carrier_dB=pow2db(pc)
p_sideband=max(abs(sbp))
p_sideband_dB=pow2db(sbp)
