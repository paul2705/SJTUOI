function initDebug(data)
    set(gcf,'position',[471,260,560,560]);
    figure(2);
    set(gcf,'position',[18,47,400,500],'MenuBar','None','NumberTitle', 'off','Name','Parameters');
    data.deleft = annotation('textbox');
    data.deleft.FontSize= 12;
    data.deleft.Position=[0,0,1,1];
    data.deleft.BackgroundColor=[1 1 1];
    data.deleft.EdgeColor=[1 1 1];
    figure(3);
    set(gcf,'position',[1100,47,400,500],'MenuBar','None','NumberTitle', 'off','Name','Parameters');
    data.deright = annotation('textbox');
    data.deright.FontSize= 12;
    data.deright.Position=[0,0,1,1];
    data.deright.BackgroundColor=[1 1 1];
    data.deright.EdgeColor=[1 1 1];
    figure(4);
    set(gcf,'position',[420,57,670,140.2],'MenuBar','None','NumberTitle', 'off','Name','Parameters');
    data.dedown = annotation('textbox');
    data.dedown.FontSize= 12;
    data.dedown.Position=[0,0,1,1];
    data.dedown.BackgroundColor=[1 1 1];
    data.dedown.EdgeColor=[1 1 1];
    figure(1);
end