% Initialize all parameters and set up difficulty levels
function parameter = initialize(w, r, o, g, p, number)
    choice = input('"manual" or "automatic"' ,'s');
    if choice == "manual"
        disp('Integers are suggested in the following inputs');
        w = input('Road width:');
        r = input('Red light duration:');
        o = input('Orange light duration:');
        g = input('Green light duration:');
        p = input('Possibility of breaking traffic rules:');
        number = input('Total number of cars:');
        fps = 6;
        parameter = [w r o g p number fps];
    elseif choice == "automatic"
        level = input('input a difficulty level(from 1 to 3):');
        if level == 1
            w = 5; r = 40; o = 3; g = 40; p = 0.1; number = 10; fps = 6;
            parameter = [w r o g p number fps];
        elseif level == 2
            w = 5; r = 12; o = 1; g = 12; p = 0.25; number = 10; fps = 6;
            parameter = [w r o g p number fps];
        elseif level == 3
            w = 3; r = 30; o = 3; g = 30; p = 0.25; number = 20; fps = 6;
            parameter = [w r o g p number fps];
        else
        error('Please input an integer between 1 and 3');
        end
    else
        error('Please input "manual" or "automatic"');
    end
end