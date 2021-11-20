function plate = plates(l,plate)
     s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
     if l == 5
         plate = strcat(s(randi([1 26])),32,plate);
     elseif l < 5
         i = l+1;
         plate = strcat(s(randi([1 36])),plate);
         plate = plates(i,plate);
     end
end
     
    