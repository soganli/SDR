%%
clear all; 
%close all;
FS     = 100e6;
FDOWN1 = 20E3;
FDOWN2 = 1000E3;

COEF1 = exp(-2i*pi*(FDOWN1/FS).*(0:8191)');
COEF2 = exp(-2i*pi*(FDOWN2/FS).*(0:8191)');


COEF1_fi = fi(COEF1,1,16,14);
fid_r = fopen('ddcCoefficients_real.mem','w');
fid_i = fopen('ddcCoefficients_imag.mem','w');

for i = 1:1:5000
    data_sel = real(COEF1_fi(i));
    fprintf(fid_r, '%s\n'   , data_sel.hex);
end

for i = 1:1:5000
    data_sel = imag(COEF1_fi(i));
    fprintf(fid_i, '%s\n'   , data_sel.hex);
end

fclose(fid_r);
fclose(fid_i);



subplot(311);stem(real(COEF1(1:8192)))
subplot(312);stem(real(COEF1(1:50:8192)))
subplot(313);stem(real(COEF2(1:8192)))