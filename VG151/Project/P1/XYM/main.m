function main   %Entrance of the game
    %constant set and input parameter
    warning off;
    data=dataHandle;    %initialize data
    if data.init==0
        return;
    end
    initWaves(data);                               %init waves
    initDist(data);                                %generate 4 random numbers that their sum=data.carnum
    initCarsPosition(data);                        %init cars in 4 directions
    createCars(data);       %create cars
    generatePlates(data);    %generate plates number
    initPlates(data);       %init plateshandler
    data.gtimer=text(data.len-10,data.len-2,"");    %ingame timer
    set(data.player,'StopFcn',@(x,y)doubleTrigger(x,y,data,"restart"));     %cycle
    play(data.player);
    pause(0.2);
    fps = 30;
    text(-data.len,data.len-2,"FPS:"+fps);   %show fps
    data.game = timer('ExecutionMode', 'FixedRate', 'Period',1/fps, 'TimerFcn', @(x,y)doubleTrigger(x,y,data,"tgame")); %Timer
    start(data.game);
    if data.debug
        data.debugger = timer('ExecutionMode', 'FixedRate', 'Period',0.5, 'TimerFcn', @(x,y)doubleTrigger(x,y,data,"tdebugger")); %Timer
        start(data.debugger);
    end
    set(gcf,'CloseRequestFcn', @(x,y)doubleTrigger(x,y,data,"closet"));         %Close function
    set(gcf,'WindowButtonDownFcn', @(x,y)doubleTrigger(x,y,data,"mouse"),'KeyPressFcn',@(x,y)doubleTrigger(x,y,data,"kbd"),'KeyReleaseFcn',@(x,y)doubleTrigger(x,y,data,"krf"))  %Mouse function
end