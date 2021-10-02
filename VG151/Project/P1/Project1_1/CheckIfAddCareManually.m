function [CarLimit,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown]=CheckIfAddCareManually(CarLimit,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown)
	% Check if user have pressed {Add Car Manually} button and clear the status of button
	if (UIAddCarLimitRight.UserData)
        CarLimit(1)=CarLimit(1)+1;
        UIAddCarLimitRight.UserData=0;
    end
    if (UIAddCarLimitLeft.UserData)
        CarLimit(2)=CarLimit(2)+1;
        UIAddCarLimitLeft.UserData=0;
    end
    if (UIAddCarLimitUp.UserData)
        CarLimit(3)=CarLimit(3)+1;
        UIAddCarLimitUp.UserData=0;
    end
    if (UIAddCarLimitDown.UserData)
        CarLimit(4)=CarLimit(4)+1;
        UIAddCarLimitDown.UserData=0;
    end
end
