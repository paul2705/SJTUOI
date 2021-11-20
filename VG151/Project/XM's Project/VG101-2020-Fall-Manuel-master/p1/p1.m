% Initialize all parameters and difficulty levels
clearvars;
parameter = initialize();
w = parameter(1); r = parameter(2); o = parameter(3); 
g = parameter(4); p = parameter(5); number = parameter(6);
fps = parameter(7);
% animation related variables
loops = 500;
% Traffic lights variables
g_ = g; go = g_+o; gor = g_+o+r;
status = 'green';
% Car appearance variables
for i = 1:number
    csize(i) = (1/3)*(rand+1)+(1/3);
    clength(i) = randi([1,3]);
end
for i = 1:number
    ccolor{i} = [rand rand rand];
end
% Car position variables
wnumber = 0; enumber = 0; nnumber = 0; snumber = 0;
csumw = 0; csume = 0; csumn = 0; csums = 0; 
cposition = 0; 
xw = cell(1,4); yw = cell(1,4); xe = cell(1,4); ye = cell(1,4);
xn = cell(1,4); yn = cell(1,4); xs = cell(1,4); ys = cell(1,4);
polyvec = []; 
Zx = cell(1,number); Zy = cell(1,number);
% Show whether the car had broken the rule
bad = zeros(1,number);
% Car status variables
stopw = 0; stope = 0; stopn = 0; stops = 0;
pass = zeros(1,number);
% Plot the crossroad
axis square;
axis([-15 15 -15 15]);
crossroad(w,status);
% Initialize the car position
for i = 1:number
    direction = ['w' 'e' 'n' 's'];
    cdirection(i) = direction(randi([1 4]));
    cplate{i} = plates(0,[]); % Assign a unique plate for each car
    switch cdirection(i)
           case 'w'
                wnumber = wnumber+1; % Calculate the total number of cars coming from west
                csumw = csumw+clength(i); % Calculate the total length of cars coming from west
                % Calculate the exact coordinate of each car
                xw{i} = [-15-csumw-(wnumber-1) -15+clength(i)-csumw-(wnumber-1)...
                    -15+clength(i)-csumw-(wnumber-1) -15-csumw-(wnumber-1)]; 
                yw{i} = [(1/2)*(w-csize(i)) (1/2)*(w-csize(i))...
                         (1/2)*(w-csize(i))+csize(i) (1/2)*(w-csize(i))+csize(i)];
                Zx{i} = xw{i}; 
                Zy{i} = yw{i}; 
           case 'e'
                enumber = enumber+1;
                csume = csume+clength(i);
                xe{i} = [15+csume+(enumber-1) 15-clength(i)+csume+(enumber-1)...
                    15-clength(i)+csume+(enumber-1) 15+csume+(enumber-1)];
                ye{i} = [-(1/2)*(w-csize(i)) -(1/2)*(w-csize(i))...
                         -(1/2)*(w-csize(i))-csize(i) -(1/2)*(w-csize(i))-csize(i)];
                Zx{i} = xe{i}; 
                Zy{i} = ye{i};
           case 'n'
                nnumber = nnumber+1;
                csumn = csumn+clength(i);
                yn{i} = [15+csumn+(nnumber-1) 15-clength(i)+csumn+(nnumber-1)...
                    15-clength(i)+csumn+(nnumber-1) 15+csumn+(nnumber-1)];
                xn{i} = [(1/2)*(w-csize(i)) (1/2)*(w-csize(i))...
                         (1/2)*(w-csize(i))+csize(i) (1/2)*(w-csize(i))+csize(i)];
                Zx{i} = xn{i}; 
                Zy{i} = yn{i};
           case 's'
                snumber = snumber+1;
                csums = csums+clength(i);
                ys{i} = [-15-csums-(snumber-1) -15+clength(i)-csums-(snumber-1)...
                         -15+clength(i)-csums-(snumber-1) -15-csums-(snumber-1)];
                xs{i} = [-(1/2)*(w-csize(i)) -(1/2)*(w-csize(i))...
                         -(1/2)*(w-csize(i))-csize(i) -(1/2)*(w-csize(i))-csize(i)];
                Zx{i} = xs{i}; 
                Zy{i} = ys{i};
    end 
end
% Main loop
 for t = 1:1/fps:loops
     traffic_light; % Plot the traffic lights
     % Judge whether a crash takes place
     for i = 1:number
         move;
         pit = polyshape(Zx{i},Zy{i});
         polyvec = [polyvec,pit];
     end
     TF = overlaps(polyvec);
     if isequal(TF,eye(number)) == 0
         disp('Crash! You fail!');
         break
     end
     % Judge whether all cars passed the crossroad safely
     for i =1:number
        switch cdirection(i)
           case 'w'
              win(i) = abs(Zx{i}(1));
           case 'e'
              win(i) = abs(Zx{i}(1));
           case 'n'
              win(i) = abs(Zy{i}(1));
           case 's'
              win(i) = abs(Zy{i}(1));
        end
     end
     judge = win>18;
     if isequal(judge,ones(1,number)) == 1
           disp('Congratulations! You win!');
           break
     end
     % pause, initialize and be prepared for the next loop
     pause(1/fps); 
     polyvec = [];
     clf
     crossroad(w,status);
end      
 % Display the plates of cars that violate traffic rules
 if bad == 0
    disp('No cars breaking rule');
 else
    disp('Cars breaking rules are listed as follows');
 end
 for i = 1:number
     if bad(i) == 1
        disp(cplate(i));
     end
 end