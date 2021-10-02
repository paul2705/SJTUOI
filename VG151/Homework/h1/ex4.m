function ex4()
	% Input
	a=input('');
	% Calculate the number of complete round
    b=floor(a/400);
	% Calculate the rest 
    c=400-mod(a,400);
	% Output
    disp(b);
    disp(c);
end
