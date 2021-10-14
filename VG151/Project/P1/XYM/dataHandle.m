classdef dataHandle < handle	%store data
	properties
		debug=0;							%if you want to debug, change this
		debugger;							%debugger for debug use
		game;								%game timer
		gtimer;								%ingame timer
		deleft=0;							%variables used in debug mode
		deright=0;							%variables used in debug mode
		dedown=0;							%variables used in debug mode
		difficulty=5;						%difficulty
    	carmargin=3;						%distance between adjacent cars
		streetwidth=0;						%street width
		carnum=0;							%number of cars
		buttonclicked=0;					%flag used to judge if shift is pressed(some PC has problem with keyboard playback function so I use this to fix them)
		cans=1.1;							%constant used to define small distance between cars and streets
		timeconst=20;						%time unit
		slowmode=0;							%if it is in slow mode
		timegap=1;							%time gap
		slowstart=0;						%time when slow mode is started
		gamestop=0;							%if game has stopped
		allwaves=2;							%number of all waves
		waves=[];							%matrix of waves
		currentwave=1;						%current wave number
		currentwavestarttime=0;				%current wave start time
		ischanging=0;						%if now is between waves
		gtime=0;							%green light time
		otime=0;							%orange light time
		rtime=0;							%red light time
		timeela=0;							%time stamp in the game
		intimeela=0;						%ingame time stamp
		len=50;								%half of the map length
		lightradius=2;						%light radius
		carx=0;   							%the length of the car
		cary=0;     						%the width of the car
		carlength=[];						%the set of car length
		prob=0;								%probability
		velocity=0;							%global velocity
		yt=0;Fs=0;							%music related
		winmusic=0;winFs=0;					%music related
		alarm=0;alarmFs=0;					%music related
		fail=0;failFs=0;					%music related
		hwave=0;hwaveFs=0;					%music related
		fwave=0;fwaveFs=0;					%music related
		player=0;							%music related
		light19;							%light handle
		light91;							%light handle
		light73;							%light handle
		light37;							%light handle
		carsdist=[];						%car distribution information
		speedlist=[];						%cars that are dashing
		violatecars=[];						%violated cars in current wave
		violatecarsdump=[];					%all violated cars
		allcars=[];							%set of all cars in this wave
		allcarshandler=[];					%car handle
		carsplate=[];						%plate
		platehandler=[];					%plate handle
		status19=2;							%status of the light
		status73=0;							%status of the light
		wavedisplayer=0;					%text that show current wave
		isinfinity=0;						%if it is infinity mode
	end
	methods
		function y=init(obj,~)
			y=1;
			modelist={'Custom','Easy','Medium','Hard','Expert','Perfect','Infinite'};
			[index,choice] = listdlg('PromptString',{'Select a difficulty'},'SelectionMode','single','ListString',modelist,'ListSize',[150,100],'InitialValue',3);
			if choice==0
				y=0;
				return;
			end
			if levelSelect(obj,index)==0
				y=0;
				return;
			end
			obj.gtime=obj.gtime*obj.timeconst;
			obj.otime=obj.otime*obj.timeconst;
			obj.rtime=obj.rtime*obj.timeconst;
			figure(1);	%main figure
			set(gcf,'position',[200,200,600,600],'MenuBar','None','NumberTitle', 'off','Name','Small Game');
			set(gca,'pos',[0 0 1 1]);
			movegui(gcf,'center'); 
			axis equal;  %square
			set(gca,'xtick',[],'ytick',[],'xcolor','w','ycolor','w');    %delete axis
			set(gca,'color','w');    %set color=white
			axis([-obj.len,obj.len,-obj.len,obj.len]);
			hold on;
			streetwidth=obj.streetwidth;
			lightradius=obj.lightradius;
			obj.carx=streetwidth*0.8;   	%the length of the car
			obj.cary=streetwidth/3;     	%the width of the car
			obj.carlength=ones(1,obj.carnum)*obj.carx;    %length of cars, default carx
			drawStreets(obj.len,obj.streetwidth);
			obj.light19=rectangle('Position',[streetwidth/2-lightradius,streetwidth/2-lightradius,2*lightradius,2*lightradius],'curvature',[1,1],'edgecolor','red','facecolor','red');
			obj.light91=rectangle('Position',[-streetwidth/2-lightradius,-streetwidth/2-lightradius,2*lightradius,2*lightradius],'curvature',[1,1],'edgecolor','red','facecolor','red');
			obj.light37=rectangle('Position',[streetwidth/2-lightradius,-streetwidth/2-lightradius,2*lightradius,2*lightradius],'curvature',[1,1],'edgecolor','green','facecolor','green');
			obj.light73=rectangle('Position',[-streetwidth/2-lightradius,streetwidth/2-lightradius,2*lightradius,2*lightradius],'curvature',[1,1],'edgecolor','green','facecolor','green');
			[obj.yt,obj.Fs] = audioread('./assets/audio/music.mp3');   %init music
			[obj.winmusic,obj.winFs] = audioread('./assets/audio/win.mp3');
			[obj.alarm,obj.alarmFs] = audioread('./assets/audio/alarm.mp3');
			[obj.fail,obj.failFs] = audioread('./assets/audio/fail.mp3');
			[obj.hwave,obj.hwaveFs] = audioread('./assets/audio/hugewave.mp3');
			[obj.fwave,obj.fwaveFs] = audioread('./assets/audio/finalwave.mp3');
			obj.player = audioplayer(obj.yt,obj.Fs);
			obj.wavedisplayer=text(obj.len-22,-obj.len+2,"Current Wave:");
			if obj.debug
				initDebug(obj);	%make debug mode on
			end
        end
    end
end