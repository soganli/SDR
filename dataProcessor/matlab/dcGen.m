%%
clear all; 
%close all;
FS1     = 100e6;
FS2     = FS1 / 2048;
FDOWN1 = 10E3;
FDOWN2 = 1;

DDC1_LEN = 10000;
DDC2_LEN = 50000;

COEF1 = exp(-2i*pi*(FDOWN1/FS1).*(0:(DDC1_LEN-1))');
COEF2 = exp(-2i*pi*(FDOWN2/FS2).*(0:(DDC2_LEN-1))');


COEF1_fi = fi(COEF1,1,16,14);
COEF2_fi = fi(COEF2,1,16,14);

fid1_r = fopen('ddcCoefficients1_real.mem','w');
fid1_i = fopen('ddcCoefficients1_imag.mem','w');

for i = 1:1:DDC1_LEN
    data_sel = real(COEF1_fi(i));
    fprintf(fid1_r, '%s\n'   , data_sel.hex);
end

for i = 1:1:DDC1_LEN
    data_sel = imag(COEF1_fi(i));
    fprintf(fid1_i, '%s\n'   , data_sel.hex);
end

fclose(fid1_r);
fclose(fid1_i);

fid2_r = fopen('ddcCoefficients2_real.mem','w');
fid2_i = fopen('ddcCoefficients2_imag.mem','w');

for i = 1:1:DDC2_LEN
    data_sel = real(COEF2_fi(i));
    fprintf(fid2_r, '%s\n'   , data_sel.hex);
end


for i = 1:1:DDC2_LEN
    data_sel = imag(COEF2_fi(i));
    fprintf(fid2_i, '%s\n'   , data_sel.hex);
end

fclose(fid2_r);
fclose(fid2_i);



subplot(311);stem(real(COEF2(1:DDC2_LEN-1)))
subplot(312);stem(imag(COEF2(1:DDC2_LEN-1)))