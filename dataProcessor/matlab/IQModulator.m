%%
[data, Fs] = audioread('rec.wav');
L = length(data);
plot(linspace(-Fs/2,Fs/2,L),20*log10(abs(fftshift(fft(data)))));


up_coeff = exp(2*pi*1i*(0*1e3/Fs)*(0:L-1)');

data_up = real(data.*up_coeff);

plot(linspace(-Fs/2,Fs/2,L),20*log10(abs(fftshift(fft(data_up)))));


%sound(data_up,Fs)