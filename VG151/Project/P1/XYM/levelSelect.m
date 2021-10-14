function y=levelSelect(obj,index)	%Different levels
	y=1;
	switch index
		case 1  %Custom
			carinput=inputdlg({'Please enter the number of cars','Width of the road?','Probability that a car does not stop at the red or orange light?','Green time?','Orange time?','Red time?','Velocity?','Distance between two adjacent cars?','Degree of difficulty?'},'Hello',[1 40;1 40;1 40;1 40;1 40;1 40;1 40;1 40;1 40],{'20','20','0.2','4','3','6','0.8','3','5'});
			if isempty(carinput)
				y=0;
				return;
			end
			obj.streetwidth=str2double(cell2mat(carinput(2,1)));
			obj.carmargin=obj.streetwidth/6;
			obj.carnum=str2double(cell2mat(carinput(1,1)));
			obj.gtime=str2double(cell2mat(carinput(4,1)));
			obj.otime=str2double(cell2mat(carinput(5,1)));
			obj.rtime=str2double(cell2mat(carinput(6,1)));
			obj.prob=str2double(cell2mat(carinput(3,1)));
			obj.velocity=str2double(cell2mat(carinput(7,1)));
			obj.carmargin=str2double(cell2mat(carinput(8,1)));
			obj.difficulty=str2double(cell2mat(carinput(9,1)));
			if isempty(cell2mat(carinput(1,1))) || isempty(cell2mat(carinput(2,1))) || isempty(cell2mat(carinput(3,1))) || isempty(cell2mat(carinput(4,1))) || isempty(cell2mat(carinput(5,1))) || isempty(cell2mat(carinput(6,1))) || isempty(cell2mat(carinput(7,1))) || isempty(cell2mat(carinput(8,1))) || isempty(cell2mat(carinput(9,1))) || obj.otime>=obj.rtime || obj.carnum<4 || obj.velocity>2 || obj.prob<0 || obj.prob>1 || fix(obj.carnum)~=obj.carnum || obj.streetwidth<15 || obj.streetwidth>35 || obj.carnum>10000 || obj.carmargin<1 || obj.carmargin>5 || obj.difficulty<2 || obj.difficulty>25
				msgbox('Invalid Parameter!');   %judge if the input is legal
				y=0;
				return;
			end
		case 2  %Easy
			obj.streetwidth=20;
			obj.carnum=40;
			obj.gtime=4;
			obj.otime=4;
			obj.rtime=7;
			obj.prob=0;
			obj.velocity=0.6;
			obj.carmargin=5;
		case 3  %Medium
			obj.streetwidth=20;
			obj.carnum=60;
			obj.gtime=4;
			obj.otime=3;
			obj.rtime=6;
			obj.prob=0.2;
			obj.velocity=0.6;
			obj.carmargin=4;
		case 4  %Hard
			obj.streetwidth=20;
			obj.carnum=70;
			obj.gtime=4;
			obj.otime=2.5;
			obj.rtime=6;
			obj.prob=0.5;
			obj.velocity=0.8;
			obj.difficulty=7;
		case 5  %Expert
			obj.streetwidth=20;
			obj.carnum=100;
			obj.gtime=4;
			obj.otime=2;
			obj.rtime=6;
			obj.prob=0.7;
			obj.velocity=0.9;
			obj.difficulty=8;
		case 6  %Perfect
			obj.streetwidth=20;
			obj.carnum=150;
			obj.gtime=4;
			obj.otime=2;
			obj.rtime=6;
			obj.prob=0.9;
			obj.velocity=1;
			obj.difficulty=10;
		case 7  %Infinite
			obj.streetwidth=20;
			obj.carnum=20;
			obj.gtime=4;
			obj.otime=3;
			obj.rtime=6;
			obj.prob=0.2;
			obj.velocity=0.8;
			obj.isinfinity=1;
	end
end