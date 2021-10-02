function ex3()
    % Claim variable time
	time=[1:1000];
	% Input time
    time=input('');
	% Unit converted from second to day 
    time=time/(60*60*24);
	% Output
    disp(time);
end
