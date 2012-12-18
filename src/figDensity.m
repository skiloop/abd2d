%% figure of ne at 30ns along x= max_x/2

% Common parameters
dx	=	5.4509e-02; % mm

% Select Data

ix = 260:1750;
x  = dx*(ix-260);


% ne0 = neo(1005,ix);% ne at 0ns along x=x_center
% ne_2_15ns_wp = ne_2(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 with plasma
% ne_3_15ns_wp = ne_3(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 with plasma
% ne_2_15ns_np = nen2(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 no plasma
% ne_3_15ns_np = nen3(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 no plasma
% ne_2_30ns_wp = ne_2(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 with plasma
% ne_3_30ns_wp = ne_3(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 with plasma
% ne_2_30ns_np = nen2(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 no plasma
% ne_3_30ns_np = nen3(1005,ix);%ne at 15ns along x = x_center de =8.73e-2 no plasma
% figure for De = 8.72e-2

%% for 15ns
figure('Name','ne (De = 8.73e-2)')
plot(x,[ne0;ne_2_15ns_np;ne_2_15ns_wp]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('ne (De = 8.73e-2) 15ns');
grid on
legend('Orignal','Without Plasma','With Plasma')
% figure for De = 8.72e-3
figure('Name','ne (De = 8.73e-3)')
plot(x,[ne0;ne_3_15ns_np;ne_3_15ns_wp]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('ne (De = 8.73e-3) 15ns');
grid on
legend('Orignal','Without Plasma','With Plasma')

%% for 30ns
figure('Name','ne (De = 8.73e-2)')
plot(x,[ne0;ne_2_30ns_np;ne_2_30ns_wp]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('ne (De = 8.73e-2) 30ns');
grid on
legend('Orignal','Without Plasma','With Plasma')
% figure for De = 8.72e-3
figure('Name','ne (De = 8.73e-3)')
plot(x,[ne0;ne_3_30ns_np;ne_3_30ns_wp]);
xlabel('mm','fontsize',12);
ylabel('V/m','fontsize',12);
title('ne (De = 8.73e-3) 30ns');
grid on
legend('Orignal','Without Plasma','With Plasma')
