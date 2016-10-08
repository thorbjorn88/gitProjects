function [b,a] = highShelf(G,fc)
wc = fc/48000;
b = [tan(wc/2)+G,tan(wc/2)-G];
a = [1+tan(wc/2),-(1-tan(wc/2))];
%figure(); freqz(b,a);