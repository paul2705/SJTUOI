% Produce a plate for each car
function plate = plate(s)
    s = [randi([1 26]) randi([1 26]) randi([1 26]) randi([1 26]) randi([1 26])];
    for i = 1:5
        if s(i)<=10
            s(i) = s(i)+47;
        else
            s(i) = s(i)+64;
        end
    end
    plate = strcat(char(randi([1 26])+64),32,s);
end