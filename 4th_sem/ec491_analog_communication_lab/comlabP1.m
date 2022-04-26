clc
fc=6000;
Tc=1/fc;
Lc=100*Tc; %scale 
Ec=2; %amplitude of carrier
tc=0:.001*Lc:Lc;
c=cos(2*pi*fc*tc); %carrier signal
%plot(tc,c)
%normalized message signal
fm=2000;
Tm=1/fm;
Lm=10*Tm;
ts=.001*Lm;
fs=1/ts;
tm=0:ts:Lm;
M_t=cos(2*pi*fm*tm);
m(1)=0 ; %modulating index
a=[];
for i=1:1:21
    x=m(i);
    e=Ec+x.*M_t; %instanteneous amplitude of modulated waveform
    AM=e.*c;
    a=[a;AM];
    m(i+1)=m(i)+0.1; %increasing modulating index
end
s1=a(1,:);
s2=a(5,:);
s3=a(21,:); %should change with rang of for
subplot(3,1,1);
plot(tm,s1,'m');
subplot(3,1,2);
plot(tm,s2,'r');
subplot(3,1,3);
plot(tm,s3,'-c');
