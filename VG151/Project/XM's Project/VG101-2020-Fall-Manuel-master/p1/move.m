% Stablize the axis
axis square;
axis([-15 15 -15 15]);
switch cdirection(i)
       case 'w'
            cposition = (1/2)*(xw{i}(2)+xw{i}(3));
            xw{i} = xw{i} + (1/fps);
            yw{i} = [(1/2)*(w-csize(i)) (1/2)*(w-csize(i))...
                     (1/2)*(w-csize(i))+csize(i) (1/2)*(w-csize(i))+csize(i)];
            % Judge whether a car has passed the crossroad
            if cposition > -w
                pass(i) = 1;                     
            else
                pass(i) = 0;
            end
            if pass(i) == 0
                % Judge whether a car should stop
                if stopw == 0
                    if cposition >= -w-0.1 & cposition <= -w+0.1 & status == 'green'
                        % A posibiity where a car breaks the traffic rule
                        if rand < p
                           bad(i) = 1; 
                           stopw = 0;
                        else
                           xw{i} = xw{i}-(1/fps);
                           stopw = 1;
                        end
                    else
                        stopw = 0;
                    end
                else
                    if (cposition >= -w-0.1 & cposition <= -w+0.1) & (status == 'reddd'| status == 'yello')
                        stopw = 0;
                    else
                        stopw = 1;
                        xw{i} = xw{i}-(1/fps);
                    end
                end
            end
            Zx{i} = xw{i}; 
            Zy{i} = yw{i};
            % Plot the cars
            X = [xw{i} xw{i}(1)];
            Y = [yw{i} yw{i}(1)];
            plot(X,Y,'k-','linewidth',2);
            fill(X,Y,ccolor{i});
        case 'e'
            xe{i} = xe{i}-(1/fps);
            ye{i} = [-(1/2)*(w-csize(i)) -(1/2)*(w-csize(i))...
                     -(1/2)*(w-csize(i))-csize(i) -(1/2)*(w-csize(i))-csize(i)];
            cposition = (1/2)*(xe{i}(2)+xe{i}(3));
            if cposition < w
                pass(i) = 1;
            else
                pass(i) = 0;
            end
            if pass(i) == 0
                if stope == 0
                    if cposition >= w-0.1 & cposition <= w+0.1 & status == 'green'
                        if rand < p
                           bad(i) = 1; 
                           stope = 0;
                        else
                           xe{i} = xe{i}+(1/fps);
                           stope = 1;
                        end
                    else
                        stope = 0;
                    end
                else
                    if (cposition >= w-0.1 & cposition <= w+0.1) & (status == 'reddd'| status == 'yello') 
                        stope = 0;
                    else
                        stope = 1;
                        xe{i} = xe{i}+(1/fps);
                    end
                end
            end
            Zx{i} = xe{i}; 
            Zy{i} = ye{i};
            X = [xe{i} xe{i}(1)];
            Y = [ye{i} ye{i}(1)];
            plot(X,Y,'k-','linewidth',2);
            fill(X,Y,ccolor{i});
         case 'n'
            yn{i} = yn{i}-(1/fps);
            xn{i} = [(1/2)*(w-csize(i)) (1/2)*(w-csize(i))...
                     (1/2)*(w-csize(i))+csize(i) (1/2)*(w-csize(i))+csize(i)];
            cposition = (1/2)*(yn{i}(2)+yn{i}(3));
            if cposition < w
                pass(i) = 1;
            else
                pass(i) = 0;
            end
            if pass(i) == 0
                if stopn == 0
                    if cposition >= w-0.1 & cposition <= w+0.1 & status == 'reddd'
                        if rand < p
                           bad(i) = 1; 
                           stop = 0;
                        else
                           yn{i} = yn{i}+(1/fps);
                           stopn = 1;
                        end
                    else
                        stopn = 0;
                    end
                else
                    if (cposition >= w-0.1 & cposition <= w+0.1) & (status == 'green'| status == 'yello')
                        stopn = 0;
                    else
                        stopn = 1;
                        yn{i} = yn{i}+(1/fps);
                    end
                end
            end
            Zx{i} = xn{i}; Zy{i} = yn{i};
            X = [xn{i} xn{i}(1)];
            Y = [yn{i} yn{i}(1)];
            plot(X,Y,'k-','linewidth',2);
            fill(X,Y,ccolor{i});
         case 's'
            ys{i} = ys{i}+(1/fps);
            xs{i} = [-(1/2)*(w-csize(i)) -(1/2)*(w-csize(i))...
                     -(1/2)*(w-csize(i))-csize(i) -(1/2)*(w-csize(i))-csize(i)];
            cposition = (1/2)*(ys{i}(2)+ys{i}(3));
            if cposition > -w
                pass(i) = 1;
            else
                pass(i) = 0;
            end
            if pass(i) == 0
                if stops == 0
                    if cposition >= -w-0.1 & cposition <= -w+0.1 & status == 'reddd'
                        if rand < p
                           bad(i) = 1; 
                           stops = 0;
                        else
                            ys{i} = ys{i}-(1/fps);
                           stops = 1;
                        end
                    else
                        stops = 0;
                    end
                else
                    if (cposition >= -w-0.1 & cposition <= -w+0.1) & (status == 'green'| status == 'yello')
                        stops = 0;
                    else
                        stops = 1;
                        ys{i} = ys{i}-(1/fps);
                    end
                end
            end
            Zx{i} = xs{i}; 
            Zy{i} = ys{i};
            X = [xs{i} xs{i}(1)];
            Y = [ys{i} ys{i}(1)];
            plot(X,Y,'k-','linewidth',2);
            fill(X,Y,ccolor{i});
end

