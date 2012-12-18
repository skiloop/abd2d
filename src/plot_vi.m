alpha = 52:0.001:56;
vi_c1 = 7.2397e+008*ones(size(alpha));
vi_c2 = ones(size(alpha))*6.7950e+008;
vi = fvi(alpha);
plot([vi;vi_c1;vi_c2]');
grid on
xlabel('alpha')
ylabel('vi')
