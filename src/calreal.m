omega	=	2*pi*110e9;
c = 3e8;
k = omega/c;
t = 15e-9;
E0 = 6e6;
dx = 5.4509e-05;%meter
ix = 26:176;
x  = dx*(0:150);
sz = length(ix);
%ezr=zeros(sz,sz);
ezr = E0*cos(omega*t-k*x);
ezc = ez30(100,ix);
%% figure of Ez
figure,plot(x,[ezr;ezc]);
legend('解析值','计算值')
grid on
set(gca,'xlim',[0 max(x)])
xlabel('mm','fontweight','bold','fontsize',12)
ylabel('V/m','fontweight','bold','fontsize',12)
title('Analytic and Numerical Ez','fontweight','bold','fontsize',12)
%% figure of Erms
lx = 260:1751;
Erms_c = er30(1005,lx);
Erms_r = E0/2^0.5;
rx = dx*(lx-260);
figure('Name','Erms')
plot(rx,[ones(1,size(lx,2))*Erms_r;Erms_c]);
legend('解析值','计算值')
grid on
set(gca,'xlim',[0 max(rx)])
xlabel('mm','fontweight','bold','fontsize',12)
ylabel('V/m','fontweight','bold','fontsize',12)
title('Analytic and Numerical Erms','fontweight','bold','fontsize',12)
%% Erms between if there is plasma or not
Erms_n = er30n(1005,lx);
figure('Name','Erms')
plot([Erms_n;Erms_c]');
legend('With Plasma','Without Plasma')
grid on
%set(gca,'xlim',[0 max(rx)])
xlabel('mm','fontweight','bold','fontsize',12)
ylabel('V/m','fontweight','bold','fontsize',12)
title('Erms with and without plasma','fontweight','bold','fontsize',12)