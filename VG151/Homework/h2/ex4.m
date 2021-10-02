s=input('','s');
f=str2func(s);
x=input('');
y=input('');
i=2;
while (abs(x(i)-x(i-1))>=power(10,-y))
    x(i+1)=(x(i-1)*f(x(i))-x(i)*f(x(i-1)))/(f(x(i))-f(x(i-1)));
    i=i+1;
end
format longg;
disp(roundn(x(i),-y));