clc; clear all;
%close all;

%%
%Parameters................
Fs = 12e3;
Fc = 3e3;
Fm = 5;
Amplitude_ratio = 0.7;
t = 0:(1/Fs):1;
len = length(t);
SNR = 15;
%%
%PART 0 : Generating AM Modulated signal
signal_mod_base = 1+Amplitude_ratio*cos(2*pi*Fm*t);
signal_carrier  = exp(1i*2*pi*Fc*t);
signal_modulated= signal_carrier.*signal_mod_base;
signal_modulated_noisy = awgn(signal_modulated,SNR,'measured');

subplot(411);
plot(real(signal_modulated)); hold on;
plot(imag(signal_modulated)); hold off;
title('Modulated IQ signal');


%%
%PART 1 : Calculating absolute value of the signal........
signal_modulated_real_square = real(signal_modulated_noisy).*real(signal_modulated_noisy);
signal_modulated_imag_square = imag(signal_modulated_noisy).*imag(signal_modulated_noisy);
signal_modulated_square      = signal_modulated_real_square + signal_modulated_imag_square;
signal_modulated_abs         = sqrt(signal_modulated_square);
subplot(412);
plot(signal_modulated_abs);
title('Magnitude of Modulated Signal');


%%
%PART 2 : Envelope detector Filter Gen
%% Filter components.................................
N               = 32;
Wpass           = 1;
Wstop           = 80;
Fpass           = 1e3;
Fstop           = 2e3;
b               = firls(N, [0 Fpass Fstop Fs/2]/(Fs/2), [1 1 0 0], [Wpass Wstop]);
Hd              = dfilt.dffir(b);
subplot(413);
plot(linspace(-Fs/2,Fs/2,2^16),20*log10(abs(fftshift(fft(Hd.Numerator,2^16)))));
title('Frequency Response of Env Filter');
%%
%PART 3 : Envelope detection
signal_demodulated = conv(signal_modulated_abs,Hd.Numerator,'same');
subplot(414);
plot(signal_mod_base,       'LineWidth',2);    hold on;
plot(signal_demodulated,'-','LineWidth',1);    hold off;
legend('Original Mod', 'Reconstructed Mod')



