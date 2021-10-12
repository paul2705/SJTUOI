function CarNewPlate=MoveItsPlate(CarIsNotDone,ThisCarPlate,MovePosition)
	% Move the plate while moving the car
	if (~CarIsNotDone) return; end
    ThisCarPlate.Position=ThisCarPlate.Position+[MovePosition(1) MovePosition(2) 0];
    CarNewPlate=ThisCarPlate;
end
