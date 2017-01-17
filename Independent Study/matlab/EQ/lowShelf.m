function [b,a] = lowShelf(G,wc,fs)
wc = wc/fs;
sqrtG = sqrt(G);
tWc = tan(wc/2);
% b = [1+G*tan(wc/2),-(1-G*tan(wc/2))];
% a = [1 + tan(wc/2),-(1-tan(wc/2))];
b= [G*tWc+sqrtG,G*tWc-sqrtG];
a = [tWc+sqrtG,tWc-sqrtG];
figure();
freqz(b,a);
title('Low Shelf');