%% plot source comparision
dt_F	=	9.0909e-03; % in ns
% S_15ns_De2 = maxne_2(:,2);%S in time De=8.73e-2
% S_15ns_De3 = maxne_3(:,2);%S in time De=8.73e-3
% S_30ns_De2 = maxne_2(:,2);%S in time De=8.73e-2
% S_30ns_De3 = maxne_3(:,2);%S in time De=8.73e-3
%% for 15ns
tx  =   (0:1650)*dt_F;
% plot Maximum ne
figure('Name','Maximum ne','NumberTitle','Off');
plot(tx,[ Max_ne_15ns_De2, Max_ne_15ns_De3]);
set(gca,'xlim',[0 max(tx)]);
xlabel('ns','fontsize',12);
ylabel('m^{-3}','fontsize',12);
title('Maximum ne Comparision to 30ns','fontsize',12,'fontweight','bold')
grid on
legend('De = 8.72e-2','De = 8.72e-3')

% S
figure('Name','S of Maximum ne','NumberTitle','Off');
plot(tx,[ S_15ns_De2, S_15ns_De3]);
ylabel('m^{-3}s^{-1}','fontsize',12);
xlabel('ns','fontsize',12);
set(gca,'xlim',[0 max(tx)]);
title('S of Maximum ne Comparision 30ns','fontsize',12,'fontweight','bold')
grid on
legend('De = 8.72e-2','De = 8.72e-3')

%% for 30ns

tx  =   (0:3300)*dt_F;
% plot Maximum ne
figure('Name','Maximum ne','NumberTitle','Off');
plot(tx,[ Max_ne_30ns_De2, Max_ne_30ns_De3]);
set(gca,'xlim',[0 max(tx)]);
xlabel('ns','fontsize',12);
ylabel('m^{-3}','fontsize',12);
title('Maximum ne Comparision to 30ns','fontsize',12,'fontweight','bold')
grid on
legend('De = 8.72e-2','De = 8.72e-3')

% S
figure('Name','S of Maximum ne','NumberTitle','Off');
plot(tx,[ S_30ns_De2, S_30ns_De3]);
ylabel('m^{-3}s^{-1}','fontsize',12);
xlabel('ns','fontsize',12);
set(gca,'xlim',[0 max(tx)]);
title('S of Maximum ne Comparision to 30ns','fontsize',12,'fontweight','bold')
grid on
legend('De = 8.72e-2','De = 8.72e-3')