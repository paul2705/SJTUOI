function keyboardChange(data)	%when keyboard is pressed
	if data.buttonclicked==1
		if data.slowmode==1 && (data.slowstart~=0 && data.timeela-data.slowstart>=30)
			data.velocity=data.velocity*5;
			data.timegap=1;
			data.slowmode=0;
			set(gca,'color','w'); 
			return;
		end
		if data.slowmode==1 || (data.slowstart~=0 && data.timeela-data.slowstart>=30)
			return;
		end
		data.slowstart=data.timeela;
		data.slowmode=1;
		data.velocity=data.velocity/5;
		data.timegap=0.2;
		set(gca,'color','#F5DA81'); 
	
	else
		if data.slowmode==0
			data.slowstart=0;
			return;
		end
		data.slowmode=0;
		data.slowstart=0;
		data.velocity=data.velocity*5;
		data.timegap=1;
		set(gca,'color','w'); 
		
end