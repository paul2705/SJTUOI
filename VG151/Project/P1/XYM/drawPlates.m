function drawplates(data)
	for i=1:data.carnum
		pos=get(data.platehandler(i),'Position');
		carpos=get(data.allcarshandler(i),'Position');
		if i<=data.carsdist(1)+data.carsdist(2)
			%left/right
			set(data.platehandler(i),'Position',[carpos(1)+data.cary/3,carpos(2)+data.cary/2,0]);
		else
			%up/down
			set(data.platehandler(i),'Position',[carpos(1)+data.cary/2,carpos(2)+data.cary/3,0]);
		end
	end
end