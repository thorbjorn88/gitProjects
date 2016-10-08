function [b,a] = lowShelf(G,wc)
wc = wc/48000;
b = [1+G*tan(wc/2),-(1-G*tan(wc/2))];
a = [1 + tan(wc/2),-(1-tan(wc/2))];
figure();
%freqz(b,a);