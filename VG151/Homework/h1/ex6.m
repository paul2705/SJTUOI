function ex6()
	% Input
	weight=input('');
    opt=input('','s');
	% Clarify how unit should be converted, and Calculate 
    if (opt(1)=='s'&&opt(11)=='p') 
        weight=weight*14;
    else if (opt(1)=='p'&&opt(11)=='k')
            weight=weight/14*6.35;
        else
            weight=weight/6.35;
        end
    end
	% Output
    disp(weight);
end
