function AnimationLog=IsCarBreakLaw(Car,CarCount,AnimationLog)
	% Output message through AnimationLog
	AnimationLog=ChangeAnimationLog(AnimationLog,"The Plates Of All The Cars That Did Not Stop At The Traffic Light:");    
    NoneCarBreakLaw=1;
	% Check if the status of breaking law is active
    for i=1:CarCount(5)
        if (Car(i).BreakLaw) 
            AnimationLog=ChangeAnimationLog(AnimationLog,Car(i).PlateName);
            NoneCarBreakLaw=0;
        end
    end
	% Special Judge
    if (NoneCarBreakLaw) 
        AnimationLog=ChangeAnimationLog(AnimationLog,"None Of The Cars Break Law!!");
    end
end
