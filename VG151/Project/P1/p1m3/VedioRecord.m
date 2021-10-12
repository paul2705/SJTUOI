function v=VedioRecord(v)
	% Record
	frame = getframe(gcf);
    frame.cdata=imresize(frame.cdata,[500 500]);
	writeVideo(v,frame);
end    
