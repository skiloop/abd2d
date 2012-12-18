

%%
ne_index_y = 260:1760;
Erms_index_y = 26:176;

ne_index_x = dx*(ne_index_y-260)/10;
Erms_index_x = dx*(Erms_index_y-26);
% Erms along y center
Erms_x = Erms_index_x;
Erms_center = Erms(100,Erms_index_y);
max_Er_center = max(Erms_center);
% ne along y center
ne_x = ne_index_x;
ne_center = ne(1005,ne_index_y);
%% Draw Erms and ne in one figure
figure('Name','Erms and ne','NumberTitle','off')
line_handle_Erms = line(Erms_x,Erms_center,'Color','r');
Erms_axis = gca;
set(Erms_axis,'XColor','r','YColor','r')
set(Erms_axis,'ylim',[0 max_Er_center],'xlim',[0 max(Erms_x)])
ne_axis = axes('Position',get(Erms_axis,'Position'),...
'XAxisLocation','bottom',...
'YAxisLocation','right',...
'Color','none',...
'XColor','b','YColor','b');
line_handle_ne = line(ne_x,ne_center,'Color','b','Parent',ne_axis);
xlabel(Erms_axis,'mm','fontweight','bold','fontsize',12)
ylabel(Erms_axis,'V/m','fontweight','bold','fontsize',12)
set(ne_axis,'xlim',[0 max(ne_x)])
%grid on
ylabel(ne_axis,'m^{-3}','fontweight','bold','fontsize',12)
title('Erms and ne','fontweight','bold','fontsize',12)

%% imagesc(Erms)
figure('name','Erms');
imagesc(Erms_x,Erms_x,Erms(Erms_index_y,Erms_index_y))
title('Erms at 15ns','fontweight','bold','fontsize',12)
xlabel('mm','fontweight','bold','fontsize',12)
ylabel('mm','fontweight','bold','fontsize',12)
set(gca,'YDir','normal')
colorbar
%% imagesc(ne£©
figure('name','ne');
imagesc(ne_index_x,ne_index_x,ne(ne_index_y,ne_index_y))
title('ne at 15ns','fontweight','bold','fontsize',12)
xlabel('mm','fontweight','bold','fontsize',12)
ylabel('mm','fontweight','bold','fontsize',12)
set(gca,'YDir','normal')
colorbar