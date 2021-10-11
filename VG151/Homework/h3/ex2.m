function ex2()
    axis equal;
    axis([0,10,0,5]);
    rectangle('Position',[1 1 2 1]); hold on;
    fill([1,2,3,1],[2,3,2,2],'w');
    fill([5,5.5,7.5,8,5],[2,3,3,2,2],'w');
    rectangle('Position',[5 1 3 1]);
    scatter(5.8,1,500,'black'); scatter(7.2,1,500,'black');
end