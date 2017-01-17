function [b,a] = highShelf(G,wc,fs)
wc = wc/fs;
sqrtG = sqrt(G);
tWc = tan(wc/2);
% b = [1+G*tan(wc/2),-(1-G*tan(wc/2))];
% a = [1 + tan(wc/2),-(1-tan(wc/2))];
b= [sqrtG*tWc+G,sqrtG*tWc-G];
a = [sqrtG*tWc+1,sqrtG*tWc-1];
figure();
freqz(b,a);
title('High Shelf');