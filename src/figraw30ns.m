%% figure ne
figure
imagesc(ne_2)
colorbar
title('ne(De=8.73e-2) at 30ns','fontsize',12,'fontweight','bold');

figure
imagesc(ne_3)
colorbar
title('ne(De=8.73e-3) at 30ns','fontsize',12,'fontweight','bold');

figure
imagesc(nen2)
colorbar
title('ne(De=8.73e-2 , nonzero ne) at 30ns','fontsize',12,'fontweight','bold');

figure
imagesc(nen3)
colorbar
title('ne(De=8.73e-3 nonzero ne) at 30ns','fontsize',12,'fontweight','bold');

%% Erms
figure
imagesc(er30_2)
colorbar
title('er(De=8.73e-2) at 30ns','fontsize',12,'fontweight','bold');

figure
imagesc(er30_3)
colorbar
title('er(De=8.73e-3) at 30ns','fontsize',12,'fontweight','bold');

figure
imagesc(er30n2)
colorbar
title('er(De=8.73e-2 , nonzero ne) at 30ns','fontsize',12,'fontweight','bold');

figure
imagesc(er30n3)
colorbar
title('er(De=8.73e-3 nonzero ne) at 30ns','fontsize',12,'fontweight','bold');
