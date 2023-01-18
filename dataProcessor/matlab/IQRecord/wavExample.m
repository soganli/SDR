%%
clear all;
FS = 100E6/4096;    %% SAMPLING RATE OF SYSTEM ~24 kHz
% 0: synthetic sound
% 1: Laughter
% 2: Train
% 3: Gong
READ_EMBEDDED_FILE = 1;
%%
if(READ_EMBEDDED_FILE==0)
    % Test signal has two components.
    % 1. Constant frequency at 100 Hz.
    % 2. Increasing frequency from -1 kHz
    Fc1 = -1E3;     a  = 10.1;  %% Chirp rate
    Fc2 =  100;
    SNR = 10000000;             %% Noise of signal
    % Total time of record is SampleNumber*FS
    SampleNumber = 2^16;
    t  = (0:(1/FS):(SampleNumber-1)/FS)';
    % Signal Generation.............
    sig = exp(1i*(a*t.^2+2*pi*Fc1*t)) + exp(1i*(2*pi*Fc2*t));
    sig_n = awgn((sig),SNR,'measured');
    sig_n = sig_n / max(abs(sig_n)+0.1);
elseif(READ_EMBEDDED_FILE==1)
    load laughter;
    sig_n = interp(y,3).*exp(-2*pi*1i*(((0+1)*1.5e3)/FS).*(0:length(y)*3-1)');
elseif(READ_EMBEDDED_FILE==2)
    load train;
    sig_n = interp(y,3).*exp(-2*pi*1i*(((0+1)*1.5e3)/FS).*(0:length(y)*3-1)');
elseif(READ_EMBEDDED_FILE==3)
    load gong;
    sig_n = interp(y,3).*exp(-2*pi*1i*(((0+1)*1.5e3)/FS).*(0:length(y)*3-1)');
end

%plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft(sig_n,2^16)))));

%% RECORD PART.......................................................
I_data      = real(sig_n);       %% I component
Q_data      = imag(sig_n);       %% Q component
FilterType  = 0;             %% 0: 3 kHz , 1: 6 kHz, 2: 9 kHz, 3: 12 kHz
fileName    = 'record.wav';    %% Name of File
%% Record IQ signal to Wav format.
IQ2wav(I_data,Q_data,FilterType, FS, fileName);

%% Replay the sound.....
[Y,sampleRate] = audioread(fileName);

sound(Y,sampleRate);