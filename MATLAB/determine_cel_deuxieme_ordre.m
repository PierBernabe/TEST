N=3;
B=3500;
fe=8000;
Amax=1;
[num,den]=cheby1(N,Amax,2*B/fe);
[Z,P,K]=tf2zp(num,den);
[SOS,G]=zp2sos(Z,P,K);
hd=dfilt.df2sos(SOS,G);
realizemdl(hd);