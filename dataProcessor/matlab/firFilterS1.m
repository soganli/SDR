%%
WRITE_ENABLE    = 0;
N               = 600;
CoefLength      = 16;
FractionLength  = 22;
FS              = 100e6;
Fpass           = 10e3  / FS;
Fstop           = 0.72e6/ FS;
Wpass           = 1;
Wstop           = 20;

Hd = filterDesign(N-1,Fpass,Fstop,Wpass,Wstop);
set(Hd, 'Arithmetic', 'fixed', ...
    'CoeffWordLength', CoefLength, ...
    'CoeffAutoScale', true, ...
    'Signed',         false, ...
    'FilterInternals',  'FullPrecision');
denormalize(Hd);
coewrite(Hd,10,'firCoefficientsS1');

if(WRITE_ENABLE)    
    coefFile = fopen('firCoefficients.mem' , 'wb');    
    filter_data     = fi((Hd.Numerator)' , 1 , CoefLength , FractionLength);
    data_bin = (filter_data.bin);
    data_dec = str2num(filter_data.sdec);
    for i = 1:N
        fprintf(coefFile, '%s\n',  data_bin(i,:));
    end
    fclose(coefFile);
end

figure(1)
plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft(Hd.Numerator,2^16)))));
