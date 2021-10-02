function ex5()
    n=7.2; L=5047.3; % the data measured by Eratosthenes
    R=180*L/(pi*n); % L=\frac{n*2*pi*R}{360} \Rightarrow R=\frac{180*L}{n*pi}
    R=R*158.5/1000; % Unit conversion
    disp(40000); % 2*pi*R=4.0001e+04 roughly equal 40000
    disp(R);
end
