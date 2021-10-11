s=input('','s');
f=str2func(s);
x=input('');
l=x(1); r=x(2); mid=0;
while (r-l>=0.00001)
    mid=(r+l)/2;
    if (f(mid)*f(r)>=0) r=mid;
    else l=mid;
    end
end
format longg;
disp(roundn(r,-3));