function [b,a] = highPass(wc)
wc = wc/48000;
b = [1, -1];
a = [1+tan(wc/2), -(1-tan(wc/2))];