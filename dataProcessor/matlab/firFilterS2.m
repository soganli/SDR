%%
N = 768;
CoefLength     = 16;
FractionLength = 21;
FS    = 100e6  / 64;
Fpass = 1.5e3  / FS;
Fstop = 10e3   / FS;
Wpass = 1;
Wstop = 1000;

Hd1 = filterDesign(N-1,Fpass,Fstop,Wpass,Wstop);
set(Hd1, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', CoefLength, ...
    'CoeffAutoScale', false, ...
    'NumFracLength', FractionLength, ...
    'Signed',         true, ...
    'FilterInternals',  'FullPrecision');
denormalize(Hd1);

Hd2 = filterDesign(N-1,2*Fpass,Fstop,Wpass,Wstop);
set(Hd2, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', CoefLength, ...
    'CoeffAutoScale', false, ...
    'NumFracLength', FractionLength, ...
    'Signed',         true, ...
    'FilterInternals',  'FullPrecision');
denormalize(Hd2);

Hd3 = filterDesign(N-1,3*Fpass,Fstop,Wpass,Wstop);
set(Hd3, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', CoefLength, ...
    'CoeffAutoScale', false, ...
    'NumFracLength', FractionLength, ...
    'Signed',         true, ...
    'FilterInternals',  'FullPrecision');
denormalize(Hd3);

Hd4 = filterDesign(N-1,4*Fpass,Fstop,Wpass,Wstop);
set(Hd4, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', CoefLength, ...
    'CoeffAutoScale', false, ...
    'NumFracLength', FractionLength, ...
    'Signed',         true, ...
    'FilterInternals',  'FullPrecision');
denormalize(Hd4);

Hd_full = filterDesign(N-1,4*Fpass,Fstop,Wpass,Wstop);
set(Hd_full, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', CoefLength, ...
    'CoeffAutoScale', false, ...
    'NumFracLength', FractionLength, ...
    'Signed',         true, ...
    'FilterInternals',  'FullPrecision');
denormalize(Hd_full);

Hd_full.Numerator = [Hd1.Numerator,Hd2.Numerator,Hd3.Numerator,Hd4.Numerator];

coewrite(Hd_full,10,'firCoefficientsS2');

plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft(Hd1.Numerator,2^16))))); hold on;
plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft(Hd2.Numerator,2^16))))); hold on;
plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft(Hd3.Numerator,2^16))))); hold on;
plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft(Hd4.Numerator,2^16))))); hold off;
