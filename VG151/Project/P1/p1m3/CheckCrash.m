function [IFStop,AnimationLog]=CheckCrash(Car,CarCount,AnimationLog)
	% Create a variable to return whether Cars Crashed
	IFStop=0;
	% Check whether Cars Crashed
    for i=1:CarCount(5)
        for j=1:CarCount(5)
            if (i==j) continue; end
			% Traverse all possible car pairs (i,j) to check whether Car_i and Car_j crashed
			% Use Former and Later to replace Car(x).Status.Position to simplify expressions
            Former=Car(i).Status.Position;
            Later=Car(j).Status.Position;
			% Abstract four corners of Later, check if these corners are interwaved with Former
            if (Former(1)<=Later(1) && Later(1)<=Former(1)+Former(3) && Former(2)<=Later(2) && Later(2)<=Former(2)+Former(4)) 
                IFStop=1;
                if (i>j) AnimationLog=ChangeAnimationLog(AnimationLog,strcat(Car(i).PlateName," and ",Car(j).PlateName," crashed!!")); end
            end
            if (~IFStop && Former(1)<=Later(1) && Later(1)<=Former(1)+Former(3) && Former(2)<=Later(2)+Later(4) && Later(2)+Later(4)<=Former(2)+Former(4)) 
                IFStop=1;
                if (i>j) AnimationLog=ChangeAnimationLog(AnimationLog,strcat(Car(i).PlateName," and ",Car(j).PlateName," crashed!!")); end
            end
            if (~IFStop && Former(1)<=Later(1)+Later(3) && Later(1)+Later(3)<=Former(1)+Former(3) && Former(2)<=Later(2) && Later(2)<=Former(2)+Former(4)) 
                IFStop=1;
                if (i>j) AnimationLog=ChangeAnimationLog(AnimationLog,strcat(Car(i).PlateName," and ",Car(j).PlateName," crashed!!")); end
            end
            if (~IFStop && Former(1)<=Later(1)+Later(3) && Later(1)+Later(3)<=Former(1)+Former(3) && Former(2)<=Later(2)+Later(4) && Later(2)+Later(4)<=Former(2)+Former(4)) 
                IFStop=1;
                if (i>j) AnimationLog=ChangeAnimationLog(AnimationLog,strcat(Car(i).PlateName," and ",Car(j).PlateName," crashed!!")); end
            end
        end
    end
end
