% compare Erms
dt	=	9.0909e-14; % in seconds
dx  =   5.4509e-02; % in mili meters
xindex = 260:1750;
x = (xindex-260)*dx;
%% for 15ns
figure('Name','Erms Comparision','NumberTitle','OFF')
plot(x,[Erms_15ns_de2_np;Erms_15ns_de2_n])
legend('Without Plasma','With Plasma');
grid on
set(gca,'xlim',[min(x),max(x)])
title('Erms Comparision (De = 8.72e-2) 15ns','fontweight','bold')
ylabel('V/m','fontweight','bold');
xlabel('mm','fontweight','bold');

% De = 8.73e-3
figure('Name','Erms Comparision','NumberTitle','OFF')
plot(x,[Erms_15ns_de3_np;Erms_15ns_de3_n])
legend('Without Plasma','With Plasma');
grid on
set(gca,'xlim',[min(x),max(x)])
title('Erms Comparision (De = 8.72e-3) 15ns','fontweight','bold')
ylabel('V/m','fontweight','bold');
xlabel('mm','fontweight','bold');


%% for 30ns 
figure('Name','Erms Comparision','NumberTitle','OFF')
plot(x,[Erms_30ns_de2_np;Erms_30ns_de2_n])
legend('Without Plasma','With Plasma');
grid on
set(gca,'xlim',[min(x),max(x)])
title('Erms Comparision (De = 8.72e-2) 30ns','fontweight','bold')
ylabel('V/m','fontweight','bold');
xlabel('mm','fontweight','bold');

% De = 8.73e-3
figure('Name','Erms Comparision','NumberTitle','OFF')
plot(x,[Erms_30ns_de3_np;Erms_30ns_de3_n])
legend('Without Plasma','With Plasma');
grid on
set(gca,'xlim',[min(x),max(x)])
title('Erms Comparision (De = 8.72e-3) 30ns','fontweight','bold')
ylabel('V/m','fontweight','bold');
xlabel('mm','fontweight','bold');