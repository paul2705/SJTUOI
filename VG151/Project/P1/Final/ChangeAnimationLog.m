function AnimationLog=ChangeAnimationLog(AnimationLog,AddLogText)
	% Roll up the AnimationLog in order to add the new log text
	% the width of AnimationLog is 7
	if (length(AnimationLog.String)>=7) 
        AnimationLog.String=[AnimationLog.String(2:length(AnimationLog.String));AddLogText];
    else 
        AnimationLog.String=[AnimationLog.String;AddLogText];
    end
end
