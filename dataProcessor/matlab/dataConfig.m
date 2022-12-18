%%
data_config = 0:100000000;
COEF = 1/10000;
COEF_FI = fi(COEF, 0,32);
COEF_FI_VAL = str2num(COEF_FI.sdec);

DIVIDEND_REF = floor(data_config* COEF);
REMAINDER_REF = data_config - DIVIDEND_REF;

DIVIDEND = floor((data_config * COEF_FI_VAL) / 2^(COEF_FI.FractionLength));
REMAINDER = data_config - DIVIDEND;

%

subplot(211);plot(DIVIDEND_REF - DIVIDEND);
subplot(212);plot(REMAINDER_REF - REMAINDER);
