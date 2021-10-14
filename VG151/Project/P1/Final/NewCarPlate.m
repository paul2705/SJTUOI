function [NewPlate,PlateStatus]=NewCarPlate(CarType,CarPosition,Plate)
	% Create Plate on the Screen
	DeltaX=0.01; DeltaY=0.025;
    if (CarType==3 || CarType==4) 
        DeltaX=0.02; DeltaY=0.015;
    end
    NewPlate=Plate();
    PlateStatus=text(CarPosition(1)+DeltaX,CarPosition(2)+DeltaY,NewPlate);
    PlateStatus.FontSize=5;
    if (CarType==3 || CarType==4) 
        PlateStatus.Rotation=90; 
    end
end
