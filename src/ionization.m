clear all; clc; close all
E_rms = 6e06 /sqrt(2)
% E_rms = 5e06
omega = 110e09*2*pi
p = 760
nu_m = 5.3 * 10^9 * p
E_eff = E_rms / sqrt(1 + omega^2/nu_m^2)
alpha = (E_eff/100) / p 
if (alpha < 120)
    nu_i = (5.0 + 0.19 * alpha) * 10^7 * exp(-273.8/alpha) *760
else
    nu_i = 54.08e06 * sqrt(alpha) * exp(-208/alpha) *760
end
n_e0 = 1e13
t = 15e-09
n_e = n_e0 * exp (nu_i * t)