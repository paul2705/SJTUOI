function v=MakeVideo()
	% Record
	v=VideoWriter('project1.avi');
    v.FrameRate=60;
    open(v);

    figure(1)
    axis equal;
    axis([0 1 0 1]);
    hold on;
    
end
