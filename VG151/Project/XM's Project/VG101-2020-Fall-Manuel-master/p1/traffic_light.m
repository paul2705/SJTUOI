% Plot the traffic light
switch mod(t,(r+2*o+g_))
          case g_
          plot(-w,-w,'yo','MarkerFaceColor','y');hold on;
          plot(w,w,'yo','MarkerFaceColor','y');hold on;
          plot(w,-w,'yo','MarkerFaceColor','y');hold on;
          plot(-w,w,'yo','MarkerFaceColor','y');hold on;
          status = 'yello';
          case go
          plot(-w,-w,'ro','MarkerFaceColor','r');hold on;
          plot(w,w,'ro','MarkerFaceColor','r');hold on;
          plot(w,-w,'go','MarkerFaceColor','g');hold on;
          plot(-w,w,'go','MarkerFaceColor','g');hold on;
          status = 'reddd';
          case gor
          plot(-w,-w,'yo','MarkerFaceColor','y');hold on;
          plot(w,w,'yo','MarkerFaceColor','y');hold on;
          plot(w,-w,'yo','MarkerFaceColor','y');hold on;
          plot(-w,w,'yo','MarkerFaceColor','y');hold on;
          status = 'yello';
          case 0
          plot(w,w,'go','MarkerFaceColor','g');hold on;
          plot(-w,w,'ro','MarkerFaceColor','r');hold on;
          plot(w,-w,'ro','MarkerFaceColor','r');hold on;
          plot(-w,-w,'go','MarkerFaceColor','g');hold on;
          status = 'green';
 end
 