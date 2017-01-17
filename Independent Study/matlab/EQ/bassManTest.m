low = 0.8;
mid = 0.4;
top = .9;
x = rand(1,1e4);
[y,B,A] = bassman(low,mid,top,x);
