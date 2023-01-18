function Done = IQ2wav(I_data,Q_data,FilterType, FS, fileName)
[S1,S2] = size(I_data);
if(S1 > S2)
    IND = (0:S1-1)';
else
    IND = (0:S2-1);
end    
    %% Filter components.................................
    N               = 512;
    Wpass           = 1;
    Wstop           = 20000;
    Fpass           = (FilterType+1)*1.3e3  / FS ;
    Fstop           = (FilterType+1)*1.5e3  / FS ;
    b               = firls(N, [0 Fpass Fstop 1/2]/(1/2), [1 1 0 0], [Wpass Wstop]);
    Hd              = dfilt.dffir(b);
    
    %% Raw IQ signal..............................................
    IQ_data                 = I_data + 1i*Q_data;
    %% Sİgnal is filtered before upconvertion
    IQ_data_filtered        = conv(IQ_data,Hd.Numerator,'same');
    %% Signal is upconverted to the positive side of the frequency spectrum................
    IQ_data_upconverted     = IQ_data_filtered.*exp(2*pi*1i*(((FilterType+1)*1.5e3)/FS).*IND);
    %% Signal is recorded.
    try
        audiowrite(fileName,real(IQ_data_upconverted),round(FS));
        Done = 1;
    catch
        warning('Problem during record.');
        Done = 0;        
    end
    
    %figure(2)
    %plot(linspace(-FS/2,FS/2,2^16),20*log10(abs(fftshift(fft((IQ_data_upconverted),2^16)))));
    
end