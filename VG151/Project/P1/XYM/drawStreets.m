function drawStreets(len,streetwidth)
	line([-len -streetwidth/2],[-streetwidth/2 -streetwidth/2],'LineWidth',2,'color','black');
    line([streetwidth/2 len],[-streetwidth/2 -streetwidth/2],'LineWidth',2,'color','black');
    line([-streetwidth/2 -streetwidth/2],[streetwidth/2 len],'LineWidth',2,'color','black');
    line([streetwidth/2 streetwidth/2],[streetwidth/2 len],'LineWidth',2,'color','black');
    line([-len -streetwidth/2],[streetwidth/2 streetwidth/2],'LineWidth',2,'color','black');
    line([streetwidth/2 len],[streetwidth/2 streetwidth/2],'LineWidth',2,'color','black');
    line([-streetwidth/2 -streetwidth/2],[-len -streetwidth/2],'LineWidth',2,'color','black');
    line([streetwidth/2 streetwidth/2],[-len -streetwidth/2],'LineWidth',2,'color','black');
	cx=15;
    line([-len -streetwidth/2-cx],[0 0],'LineWidth',1,'color','#D3D3D3','LineStyle','--');
    line([len streetwidth/2+cx],[0 0],'LineWidth',1,'color','#D3D3D3','LineStyle','--');
    line([0 0],[len streetwidth/2+cx],'LineWidth',1,'color','#D3D3D3','LineStyle','--');
    line([0 0],[-len -streetwidth/2-cx],'LineWidth',1,'color','#D3D3D3','LineStyle','--');
end