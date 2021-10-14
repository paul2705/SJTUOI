function judgeEnd(data,game)     %judge if the game should end
	fl=0;
	data.violatecars=unique(data.violatecars);	%make unique
	if length(data.violatecarsdump)>0
		data.violatecarsdump=unique(data.violatecarsdump);
	end
	if data.carnum==0 || data.ischanging
		return;
	end
	for i=1:data.carnum
		ipos=get(data.allcarshandler(i),'Position');
		p1x=ipos(1);
		p1y=ipos(2)+ipos(4);
		p2x=ipos(1)+ipos(3);
		p2y=ipos(2);
		p3x=-data.len;
		p3y=data.len;
		p4x=data.len;
		p4y=-data.len;
		if p2y<=p3y && p1y>=p4y && p2x>=p3x && p1x<=p4x
			fl=1;
		end
	end
	if fl==0 && data.intimeela>10+data.currentwavestarttime
		if data.currentwave<data.allwaves || data.isinfinity
			%send violate cars to hell
			data.violatecars=[];
			data.ischanging=1;
			if data.difficulty<=20
				data.difficulty=data.difficulty+1;
			end
			if data.prob<=0.7
				data.prob=data.prob+0.01;
			end
			if data.velocity<=1
				data.velocity=data.velocity+0.05;
			end
			data.currentwave=data.currentwave+1;
			clearCars(data,game);
			pause(3);
			if ~isvalid(game)
				return;
			end
			text1=text(-100,0,"Final Wave");
			text2=text(-100,0,"A Huge Wave of Cars is Coming!");
			if data.currentwave==data.allwaves
				data.difficulty=2;
				data.velocity=data.velocity+0.1;
				data.prob=data.prob+0.02;
				text1.Position=[-10 0 0];
				text1.FontSize=18;
				sound(data.fwave,data.fwaveFs);
			else
				text2.Position=[-20 0 0];
				text2.FontSize=12;
				sound(data.hwave,data.hwaveFs);
			end
			pause(3);
			if ~isvalid(game)
				return;
			end
			set(data.wavedisplayer,'String',"Current Wave:"+data.currentwave);
			delete(text1);
			delete(text2);
			pause(0.5);
			sound(data.alarm,data.alarmFs);
			if ~isvalid(game)
				return;
			end
			pause(1.5);
			if ~isvalid(game)
				return;
			end
			if data.isinfinity
				reGenerateCars(data,20,game);
			else
				reGenerateCars(data,data.waves(data.currentwave),game);
			end
			data.currentwavestarttime=data.intimeela;
			data.ischanging=0;
			return;
		end
		data.ischanging=1;
		if length(data.violatecarsdump)>0
			%list cars
			msgstr="There is(are) "+length(data.violatecarsdump)+" car(s) that did not stop at the traffic light: ";
			for k=1:length(data.violatecarsdump)-1
				msgstr=msgstr+data.violatecarsdump(k)+",";
			end
			msgstr=msgstr+data.violatecarsdump(end)+".";
			msgbox({msgstr,"Your time is:"+round(data.timeela/30,3)+"s."});
		else
			msgbox("Congrats, your time is: "+round(data.timeela/30,3)+"s");
		end
		stop(game);
		delete(game);
		sound(data.winmusic,data.winFs);
		close;
		return;
	end
end