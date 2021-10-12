% Record
v=VideoWriter('project1.avi');
v.FrameRate=60;
open(v);
 
% Create a figure
clf(figure(1),'reset');
figure(1);
set(gcf,'menubar','none');
set(gcf,'unit','normalized','position',[0.2,0.2,0.6,0.6]);
set(gcf,'defaultuicontrolunits','normalized');
set(gcf,'defaultuicontrolhorizontal','left');
set(gcf,'defaultuicontrolfontsize',12);
% Create Title
uicontrol(gcf,'style','text','string','Car Animation',...
        'position',[0.41,0.9,0.2,0.05],'fontsize',18);
% Create Axis
h_axes=axes('position',[0.3,0.23,0.4,0.6]);
axis equal;
% Create the title of Axis
htitle=title('Car Simulation');
% Create mode
uicontrol(gcf,'style','text','string','Level',...
        'position',[0.01,0.85,0.2,0.1],'fontsize',14);
UIModeGroup=uibuttongroup('Visible','off','position',[0.07,0.89,0.16,0.08]);
UIEasyMode=uicontrol(UIModeGroup,'style','radiobutton',...
            'string','Easy',...
            'position',[0.1,0.1,0.6,0.8],...
            'HandleVisibility','off',...
            'callback',[...
            'set(UICarPossibilityOmitLight,"String","0");',...
            'set(UICarNumber,"String","30");']);
UIHardMode=uicontrol(UIModeGroup,'style','radiobutton',...
            'string','Hard',...
            'position',[0.5,0.1,0.6,0.8],...
            'HandleVisibility','off',...
            'callback',[...
            'set(UICarPossibilityOmitLight,"String","0.9");',...
            'set(UICarNumber,"String","500");']);
set(UIHardMode,'value',get(UIHardMode,'min'));
set(UIEasyMode,'value',get(UIEasyMode,'max'));
UIModeGroup.Visible='on';
% Create Initalization
uicontrol(gcf,'style','text','string','Initalization',...
        'position',[0.07,0.76,0.15,0.1],'fontsize',14);
uicontrol(gcf,'style','text','string','Width Of The Street (Range:(0,0.5))',...
        'position',[0.03,0.7,0.2,0.1],'fontsize',8);
UIStreetWidth=uicontrol(gcf,'style','edit','string','0.1',...
        'position',[0.03,0.71,0.2,0.03],'fontsize',8,...
        'callback',[...
        'set(UIPeriodChangeRedLight,"String",num2str(250*(str2double(get(UIStreetWidth,"string"))*2+0.1)));',...
        'set(UIPeriodChangeGreenLight,"String",num2str(150*(str2double(get(UIStreetWidth,"string"))*2+0.1)));',...
        'set(UIPeriodChangeYellowLight,"String",num2str(100*(str2double(get(UIStreetWidth,"string"))*2+0.1)));']);
uicontrol(gcf,'style','text','string','The Total Number Of Cars (Range:(10,1000))',...
        'position',[0.03,0.6,0.2,0.1],'fontsize',8);
UICarNumber=uicontrol(gcf,'style','edit','string','30',...
        'position',[0.03,0.61,0.2,0.03],'fontsize',8);
uicontrol(gcf,'style','text','string','The Length of Interval (Range:(0,0.1))',...
        'position',[0.03,0.5,0.2,0.1],'fontsize',8);
UIIntervalLength=uicontrol(gcf,'style','edit','string','0.01',...
        'position',[0.03,0.51,0.2,0.03],'fontsize',8);
uicontrol(gcf,'style','text','string','The Possibility Of Omitting Light (Range:[0,1])',...
        'position',[0.03,0.4,0.2,0.1],'fontsize',8);
UICarPossibilityOmitLight=uicontrol(gcf,'style','edit','string','0.1',...
        'position',[0.03,0.41,0.2,0.03],'fontsize',8);
uicontrol(gcf,'style','text','string','Switch For adding Car Manually',...
        'position',[0.03,0.335,0.19,0.06],'fontsize',8,'horizontal','center');
UIAddCarManuallyGroup=uibuttongroup('Visible','off','position',[0.05,0.31,0.15,0.05]);
UIAddCarManually=uicontrol(UIAddCarManuallyGroup,'style','radiobutton',...
            'string','ON',...
            'position',[0.1,0.1,0.6,0.8],...
            'HandleVisibility','off');
UIAddCarAutomatically=uicontrol(UIAddCarManuallyGroup,'style','radiobutton',...
            'string','OFF',...
            'position',[0.5,0.1,0.6,0.8],...
            'HandleVisibility','off');
set(UIAddCarManually,'value',get(UIAddCarManually,'min'));
set(UIAddCarAutomatically,'value',get(UIAddCarAutomatically,'max'));
UIAddCarManuallyGroup.Visible='on';
% Create Advanced Options
uicontrol(gcf,'style','text','string','Advanced Options',...
        'position',[0.75,0.76,0.2,0.1],'fontsize',14);
uicontrol(gcf,'style','text','string','Switch For Various Car Sizes',...
        'position',[0.75,0.74,0.25,0.06],'fontsize',10);
uicontrol(gcf,'style','text','string','Period Of Changing Light (Range:(1,10000)) (Order:Red,Green,Yellow)',...
        'position',[0.75,0.57,0.2,0.1],'fontsize',10);
UIPeriodChangeRedLight=uicontrol(gcf,'style','edit','string','75',...
        'position',[0.75,0.55,0.065,0.03],'fontsize',8);
UIPeriodChangeGreenLight=uicontrol(gcf,'style','edit','string','45',...
        'position',[0.8175,0.55,0.065,0.03],'fontsize',8);
UIPeriodChangeYellowLight=uicontrol(gcf,'style','edit','string','30',...
        'position',[0.885,0.55,0.065,0.03],'fontsize',8);
UIVarifyCarSizeGroup=uibuttongroup('Visible','off','position',[0.75,0.68,0.16,0.08]);
UIVarifyCarSize=uicontrol(UIVarifyCarSizeGroup,'style','radiobutton',...
            'string','ON',...
            'position',[0.1,0.1,0.6,0.8],...
            'HandleVisibility','off');
UIClassicCarSize=uicontrol(UIVarifyCarSizeGroup,'style','radiobutton',...
            'string','OFF',...
            'position',[0.5,0.1,0.6,0.8],...
            'HandleVisibility','off');
set(UIVarifyCarSize,'value',get(UIVarifyCarSize,'min'));
set(UIClassicCarSize,'value',get(UIClassicCarSize,'max'));
UIVarifyCarSizeGroup.Visible='on';
uicontrol(gcf,'style','text','string','Add Cars Manually ',...
        'position',[0.75,0.43,0.2,0.1],'fontsize',10,'horizontal','center');
uicontrol(gcf,'style','text','string','Add A Car Towards Right: ',...
        'position',[0.75,0.385,0.2,0.1],'fontsize',8);
uicontrol(gcf,'style','text','string','Add A Car Towards Left: ',...
        'position',[0.75,0.335,0.2,0.1],'fontsize',8);
uicontrol(gcf,'style','text','string','Add A Car Towards Up: ',...
        'position',[0.75,0.285,0.2,0.1],'fontsize',8);
uicontrol(gcf,'style','text','string','Add A Car Towards Down: ',...
        'position',[0.75,0.235,0.2,0.1],'fontsize',8);
UIAddCarLimitRight=uicontrol(gcf,'style','pushbutton','string','ADD',...
        'position',[0.91,0.45,0.05,0.04],'fontsize',8,'horizontal','center',...
        'callback','UIAddCarLimitRight.UserData=1;');
UIAddCarLimitLeft=uicontrol(gcf,'style','pushbutton','string','ADD',...
        'position',[0.91,0.4,0.05,0.04],'fontsize',8,'horizontal','center',...
        'callback','UIAddCarLimitLeft.UserData=1;');
UIAddCarLimitUp=uicontrol(gcf,'style','pushbutton','string','ADD',...
        'position',[0.91,0.35,0.05,0.04],'fontsize',8,'horizontal','center',...
        'callback','UIAddCarLimitUp.UserData=1;');
UIAddCarLimitDown=uicontrol(gcf,'style','pushbutton','string','ADD',...
        'position',[0.91,0.3,0.05,0.04],'fontsize',8,'horizontal','center',...
        'callback','UIAddCarLimitDown.UserData=1;');
uicontrol(gcf,'style','text','string','Notice: Advanced Options Can Be Changed During The Animation!',...
        'position',[0.73,0.18,0.25,0.1],'fontsize',10,'ForegroundColor','red');
% Create a button of Starting The Game
GameStart=uicontrol(gcf,'style','pushbutton','string','Start!',...
        'position',[0.08,0.24,0.1,0.05],'fontsize',12,'horizontal','center',...
        'callback',[...
        'AnimationLog.String="CarLog: ";',...
        'cla;',...
        'Game(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,UIVarifyCarSize,UIAddCarManually,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown,AnimationLog);']);
uicontrol(gcf,'style','pushbutton','string','Pause',...
        'position',[0.05,0.18,0.08,0.05],'fontsize',12,'horizontal','center',...
        'callback','waitforbuttonpress;');
uicontrol(gcf,'style','pushbutton','string','Restart',...
        'position',[0.13,0.18,0.08,0.05],'fontsize',12,'horizontal','center');
% Create a dashboard
AnimationLog=uicontrol(gcf,'style','text','string',["CarLog:";" "],...
                        'position',[0.2,0,0.6,0.18],'backgroundcolor','white',...
                        'fontsize',8);
