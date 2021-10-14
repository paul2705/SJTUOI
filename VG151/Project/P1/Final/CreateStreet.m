function CreateStreet(StreetX,StreetY)
	% Create Street through coordinate (x,y)
	hold on;
    plot([StreetX,StreetX],[0,StreetX],'color','black','linewidth',2);
    plot([StreetX,StreetX],[StreetY,1],'color','black','linewidth',2);
    plot([StreetY,StreetY],[0,StreetX],'color','black','linewidth',2);
    plot([StreetY,StreetY],[StreetY,1],'color','black','linewidth',2);
    plot([0,StreetX],[StreetX,StreetX],'color','black','linewidth',2);
    plot([StreetY,1],[StreetX,StreetX],'color','black','linewidth',2);
    plot([0,StreetX],[StreetY,StreetY],'color','black','linewidth',2);
    plot([StreetY,1],[StreetY,StreetY],'color','black','linewidth',2);
    hold on; 
    
    plot([0.5,0.5],[0,StreetX],'--','color','black','linewidth',0.5);
    plot([0.5,0.5],[StreetY,1],'--','color','black','linewidth',0.5);
    plot([0,StreetX],[0.5,0.5],'--','color','black','linewidth',0.5);
    plot([StreetY,1],[0.5,0.5],'--','color','black','linewidth',0.5);
    hold on;
end
