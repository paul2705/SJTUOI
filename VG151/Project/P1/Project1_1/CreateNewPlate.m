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
    Use=zeros(cnt); PlatePool=[]; Plate=[];
    PlatePool=RecursionForPlate(1,PlatePool,Plate,CharPool,Use);
	% Create a new plate by taking the first five char
    Len=length(PlatePool);
    Plate=strcat(char(floor(rand()*26)+65),' ',PlatePool(floor(rand()*(Len-1))+1));
end

function PlatePool=RecursionForPlate(Step,PlatePool,Plate,Pool,Use)
    if (Step==6)
        PlatePool=[PlatePool string(char(Plate))];
        return;
    end
    if (length(PlatePool)>500) return; end
    for i=1:36
        if (Use(i)) continue; end
        Use(i)=1;
        Plate(Step)=char(Pool(i));
        PlatePool=RecursionForPlate(Step+1,PlatePool,Plate,Pool,Use);
        Use(i)=0;
    end
end
