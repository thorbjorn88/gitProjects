function [b,a] = notchPeak(G,fc,B)
wc = fc/48000;
B = B/48000;
b = [1+G*tan(B/2),-(2*cos(wc)),1-G*tan(B/2)];
a = [1+tan(B/2),-2*cos(wc),1-tan(B/2)];
%figure();freqz(b,a)