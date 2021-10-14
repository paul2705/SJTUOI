function initWaves(data)
	if data.carnum<=30
		data.allwaves=1;
		data.waves=[data.carnum];
	end
	if data.carnum>30
		mr=mod(data.carnum,20);
		q=floor(data.carnum/20);
		if mr<=10
			data.waves=ones(1,q-1)*20;
			data.waves=[data.waves,20+mr];
		else
			data.waves=ones(1,q-1)*20;
			data.waves=[data.waves,10];
			data.waves=[data.waves,10+mr];
		end
		data.allwaves=length(data.waves);
		data.carnum=20;
	end
end