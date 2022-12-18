%%

%%Signal Generator.................................................
Fs = 100e6;
Fc = 30.020e6;
SampleNumber = 2^20;
t  = 0:(1/Fs):(SampleNumber-1)/Fs;
sig = exp(2*pi*1i*Fc*t);

sig_fi = fi(real(sig)*0.4 , 1 , 16 , 15);

dataFile = fopen('s_axis_data_tdata.txt' , 'w');

data     = str2num(sig_fi.sdec);
for i = 1:SampleNumber
    fprintf(dataFile, '%d\n',  data(i));
end
fclose(dataFile);



load stage1_out_r.txt;
load stage1_out_i.txt;

coef_fi = fi(exp(2*pi*1i*(-30e6/Fs).*(0:SampleNumber-1)),1,16,14);

data_dc = coef_fi.double.*data;
data_down_converted = stage1_out_r + 1i*stage1_out_i;

figure(1)
subplot(311); plot(real(data));
subplot(312); plot(real(data_dc(1:9000))); 
subplot(313); plot(real(data_down_converted));

figure(2)
subplot(311); plot(linspace(-Fs/2,Fs/2,2^16),20*log10(abs(fftshift(fft(data,2^16)))));
subplot(312); plot(linspace(-Fs/2,Fs/2,2^16),20*log10(abs(fftshift(fft(data_dc,2^16)))));
subplot(313); plot(linspace(-Fs/2,Fs/2,2^16),20*log10(abs(fftshift(fft(data_down_converted,2^16)))));
