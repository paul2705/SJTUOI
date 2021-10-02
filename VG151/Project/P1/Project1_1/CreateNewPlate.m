function Plate=CreateNewPlate()
	% Create a pool with all possible char
	cnt=0;
    for i=48:57
        cnt=cnt+1;
        CharPool(cnt)=char(i);
    end
    for i=65:90
        cnt=cnt+1;
        CharPool(cnt)=char(i);
    end
	% Shuffle this pool
    CharPool=CharPool(randperm(cnt));
	% Create a new plate by taking the first five char
    Plate=strcat(char(floor(rand()*26)+65),' ',CharPool(1:5));
end
