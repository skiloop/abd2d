function vi=fvi(alpha_t)
vi =zeros(size(alpha_t));
p = 760;
ind1 = alpha_t<1e-12;
ind2 = find(alpha_t>=1e-12&alpha_t<30);
ind3 = find(alpha_t>=30&alpha_t<=54);
ind4 = find(alpha_t>54&alpha_t<=120);
ind5 = find(alpha_t>120);
vi(ind1) = 0;
vi(ind2) = (1.45+0.01*(alpha_t(ind2).^1.5)).*2.5e7.*exp(-208./alpha_t(ind2))*p;
vi(ind3) = (1.32+0.054.*alpha_t(ind3))*1e7.*exp(-208./alpha_t(ind3))*p;
vi(ind4) = (5.0+0.19*alpha_t(ind4)).*1e7.*exp(-273.8./alpha_t(ind4))*p;
vi(ind5) = 54.08e6*(alpha_t(ind5).^0.5).*exp(-359./alpha_t(ind5))*p;