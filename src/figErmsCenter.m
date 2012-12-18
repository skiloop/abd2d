%% figure of Erms at 30ns along x= max_x/2

% Common parameters
dx	=	5.4509e-02; % mm


% Select Data

ix = 260:1750;
x  = dx*(ix-260);
% Erms_15ns_de2_np = er30n2(1005,ix);%Erms at 15ns De=8.73e-2 without plasma
% Erms_15ns_de2_n = er30_2(1005,ix);%Erms at 15ns De=8.73e-2  with plasma
% Erms_15ns_de3_np = er30n2(1005,ix);%Erms at 15ns De=8.73e-3 without plasma
% Erms_15ns_de3_n = er30_2(1005,ix);%Erms at 15ns De=8.73e-3  with plasma

% Erms_30ns_de2_np = er30n2(1005,ix);%Erms at 15ns De=8.73e-2 without plasma
% Erms_30ns_de2_n = er30_2(1005,ix);%Erms at 15ns De=8.73e-2  with plasma
% Erms_30ns_de3_np = er30n2(1005,ix);%Erms at 15ns De=8.73e-3 without plasma
% Erms_30ns_de3_n = er30_2(1005,ix);%Erms at 15ns De=8.73e-3  with plasma


%% for 15ns
% figure for De = 8.72e-2
figure('Name','Erms (De = 8.73e-2)')
plot(x,[Erms_15ns_de2_np;Erms_15ns_de2_n]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('Erms (De = 8.73e-2) at 15ns');
grid on
set(gca,'xlim',[0 max(x)]);
legend('Without Plasma','With Plasma')
% figure for De = 8.72e-3
figure('Name','Erms (De = 8.73e-3)')
plot(x,[Erms_15ns_de3_np;Erms_15ns_de3_n]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('Erms (De = 8.73e-3) at 15ns');
grid on
legend('Without Plasma','With Plasma')
set(gca,'xlim',[0 max(x)]);

%% for 30ns
% figure for De = 8.72e-2
figure('Name','Erms (De = 8.73e-2)')
plot(x,[Erms_30ns_de2_np;Erms_30ns_de2_n]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('Erms (De = 8.73e-2) at 30ns');
grid on
set(gca,'xlim',[0 max(x)]);
legend('Without Plasma','With Plasma')
% figure for De = 8.72e-3
figure('Name','Erms (De = 8.73e-3)')
plot(x,[Erms_30ns_de3_np;Erms_30ns_de3_n]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('Erms (De = 8.73e-3) at 30ns');
grid on
legend('Without Plasma','With Plasma')
set(gca,'xlim',[0 max(x)]);
