function CarNewStatus=MoveThisCar(CarIsNotDone,ThisCarStatus,MovePosition)
	% Move the car by changing its position
	if (~CarIsNotDone) return; end
    ThisCarStatus.Position=ThisCarStatus.Position+MovePosition;
    CarNewStatus=ThisCarStatus;
end
