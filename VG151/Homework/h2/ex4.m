function ex4()
	s=input('','s');
	f=str2func(s);
	x=input('');
	y=input('');
	dfs(f,x,y,2);
end

function dfs(f,x,y,i)
	if (abs(x(i)-x(i-1))<power(10,-y))
		format longg;
		disp(roundn(x(i),-y));
		return;
	end
	x(i+1)=(x(i-1)*f(x(i))-x(i)*f(x(i-1)))/(f(x(i))-f(x(i-1)));
	dfs(f,x,y,i+1);
end

function ex41()
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
end