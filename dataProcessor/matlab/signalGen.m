%%
clear all;
%%Signal Generator.................................................
WRITE_ENABLE = 0;

SNR = 12;
Fs = 100e6;
Fc = 30020100;
SampleNumber = 2^21;
t  = 0:(1/Fs):(SampleNumber-1)/Fs;
sig = exp(2*pi*1i*Fc*t);
sig_n = awgn(real(sig),SNR,'measured');
sig_n = sig_n ./ (max(abs(sig_n))*1.01);
sig_fi = fi(sig_n , 1 , 16 , 15);


data     = str2num(sig_fi.sdec);

if(WRITE_ENABLE)
    dataFile = fopen('s_axis_data_tdata.txt' , 'w');
    for i = 1:SampleNumber
        fprintf(dataFile, '%d\n',  data(i));
    end
    fclose(dataFile);
end


load stage1_out_r.txt;
load stage1_out_i.txt;

load stage2_out_r.txt;
load stage2_out_i.txt;

load stage3_out_r.txt;
load stage3_out_i.txt;

coef_fi = fi(exp(2*pi*1i*(-30e6/Fs).*(0:SampleNumber-1)),1,16,14);

data_dc = coef_fi.double.*data;

L1 = (min(length(stage1_out_r),length(stage1_out_i)));

stage1 = stage1_out_r(1:L1) + 1i*stage1_out_i(1:L1);
stage2 = stage2_out_r + 1i*stage2_out_i;
stage3 = stage3_out_r + 1i*stage3_out_i;

figure(1)
subplot(411); plot(real(data));
subplot(412); plot(real(stage1)); hold on;
subplot(412); plot(imag(stage1)); hold off;
subplot(413); plot(real(stage2)); hold on;
subplot(413); plot(imag(stage2)); hold off;
subplot(414); plot(real(stage3)); hold on;
subplot(414); plot(imag(stage3)); hold off;


figure(2)
subplot(411); plot(linspace(-Fs/2,Fs/2,2^16),20*log10(abs(fftshift(fft(data,2^16)))));
subplot(412); plot(linspace(-Fs/128,Fs/128,2^16),20*log10(abs(fftshift(fft(stage1,2^16)))));
subplot(413); plot(linspace(-Fs/4096,Fs/4096,2^16),20*log10(abs(fftshift(fft(stage2,2^16)))));
subplot(414); plot(linspace(-Fs/8192,Fs/8192,2^16),20*log10(abs(fftshift(fft(stage3,2^16)))));
