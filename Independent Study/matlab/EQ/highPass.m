function [b,a] = highPass(wc,fs)
wc = wc/fs;
b = [1, -1];
a = [1+tan(wc/2), -(1-tan(wc/2))];