function doubleTrigger(x,y,data,p)  %Triggers controller
    eval(p+"(x,y,data)");
end

function kbd(~,x,data)  %keyboard down
    if strcmp(x.Key,"shift")
        data.buttonclicked=1;
        keyboardChange(data);
    end
end
function krf(~,x,data)  %keyboard up
    if strcmp(x.Key,"shift")
        data.buttonclicked=0;
        keyboardChange(data);
    end
end
function tdebugger(~,~,data)    %debug
    debug(data);
end
function tgame(~,~,data)     %timer function(main)
    if data.ischanging
        return
    end
    set(data.gtimer,'String',round(data.timeela/30,1)); %set ingame timer
    set(data.wavedisplayer,'String',"Current Wave:"+data.currentwave);
    data.timeela=data.timeela+1;  %add time
    data.intimeela=data.intimeela+data.timegap;
    drawPlates(data);       %draw plates
    moveCars(data);         %move our cars
    keyboardChange(data);
    ifHell(data,data.game);           %judge if two cars are crashed
    if ~isvalid(data.game)
        return;
    end
    detectLight(data);      %change light
    ifCanStop(data);        %let cars stop
    checkSpeedup(data);     %check the speed
    judgeEnd(data,data.game);         %judge if the game can end
    if ~isvalid(data.game)
        return;
    end
end
function mouse(~,~,data)    %nouse trigger
    getMouse(data);
end
function restart(~,~,data)  %play music again
    if data.gamestop
        return
    else
        play(data.player);
    end
end
function closet(~,~,data)    %when user close the window
    data.gamestop=1;
    if isvalid(data.game)
        stop(data.game);
        delete(data.game);
    end
    if isvalid(data.player)
        stop(data.player);
    end
    if data.debug
        if isvalid(data.debugger)
            stop(data.debugger);
            delete(data.debugger);
        end
        close all;
    else
        close;
    end
end