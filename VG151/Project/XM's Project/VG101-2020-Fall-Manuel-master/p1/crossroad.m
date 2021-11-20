% Plot the crossroad
function crossroads = crossroad(w,status)
    % Plot the roads
    plot([-30 30], [0 0],'k:');hold on;
    plot([0 0], [-30 30],'k:');hold on;
    plot([-30 -w], [w w],'k-','linewidth',2);hold on;
    plot([w 30], [-w -w],'k-','linewidth',2);hold on;
    plot([-30 -w], [-w -w],'k-','linewidth',2);hold on;
    plot([w 30], [w w],'k-','linewidth',2);hold on;
    plot([w w], [w 30],'k-','linewidth',2);hold on;
    plot([w w], [-30 -w],'k-','linewidth',2);hold on;
    plot([-w -w], [w 30],'k-','linewidth',2);hold on;
    plot([-w -w], [-30 -w],'k-','linewidth',2);hold on;
    % Switch the traffic light status
    switch status
        case 'yello'
            plot(-w,-w,'yo','MarkerFaceColor','y');hold on;
            plot(w,w,'yo','MarkerFaceColor','y');hold on;
            plot(w,-w,'yo','MarkerFaceColor','y');hold on;
            plot(-w,w,'yo','MarkerFaceColor','y');hold on;
        case 'green'
            plot(w,w,'go','MarkerFaceColor','g');hold on;
            plot(-w,w,'ro','MarkerFaceColor','r');hold on;
            plot(w,-w,'ro','MarkerFaceColor','r');hold on;
            plot(-w,-w,'go','MarkerFaceColor','g');hold on;
        case 'reddd'
            plot(-w,-w,'ro','MarkerFaceColor','r');hold on;
            plot(w,w,'ro','MarkerFaceColor','r');hold on;
            plot(w,-w,'go','MarkerFaceColor','g');hold on;
            plot(-w,w,'go','MarkerFaceColor','g');hold on;
    end
end