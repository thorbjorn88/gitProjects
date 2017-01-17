function [b,a] = notchPeak(G,fc,B,fs)
wc = fc/fs;
B = B/fs;
sqrtG = sqrt(G);
b = [sqrtG+G*tan(B/2),-(2*sqrtG*cos(pi*wc)),sqrtG-G*tan(B/2)];
a = [sqrtG+tan(B/2),-2*sqrtG*cos(pi*wc),sqrtG-tan(B/2)];
figure();freqz(b,a)