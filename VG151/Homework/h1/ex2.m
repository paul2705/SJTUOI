function ex2()
	% Ex2.1 
	% Initialize
    [x,y]=init();
	% Output
    disp(x);
    disp(y);

	% Ex2.2
	% Reinitialize
    [x,y]=init();
	% Add Sum(x) At The End Of Y
    y(5)=sum(x);
	% Output
    disp(x);
    disp(y);

	% Ex2.3
	% Reinitialize
    [x,y]=init();
	% Calculate x^y;
    x=power(x,y);
	% Output
    disp(x);
    disp(y);

	% Ex2.4
	% Reinitialize
    [x,y]=init();
	% Calculate y/x;
    y=y./x;
	% Output
    disp(y);
    disp(x);

	% Ex2.5
	% Reinitialize
    [x,y]=init();
	% Calculate x*y, and save the answer in z;
    z=x.*y;
	% Output
    disp(x);
    disp(y);
    disp(z);

	% Ex2.6
	% Reinitialize
    [x,y]=init();
	% Calculate x*y
    z=x.*y;
	% Sum of z
    w=sum(z);
	% Output
    disp(z);
    disp(w);

	% Ex2.7
	% Reinitialize
    [x,y]=init();
	% Calculate x*y 
    z=x.*y;
	% Sum of z
    w=sum(z);
	% Output
    disp(x);
    disp(y);
    disp(w);
	% Calculate x'*y-w
    disp(x'*y-w); % It's the definition of Matrix Multiplication.
end

function [x,y]=init()
    x=[3 2 6 8]';
    y=[4 1 3 5]';
end