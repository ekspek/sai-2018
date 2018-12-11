% SAI Lab 2 - Part 1

%% Initialization
%Prepare work environment
clear
clc
%format longg

%Input and sort data

input=importdata('inputdata.csv',",",1);

pressure=input.data(:,1);
out_minus45=input.data(:,2);
out_25=input.data(:,3);
out_125=input.data(:,4);

%Create aditional variable to handle temperatures
n=size(input,1);

T_minus45=ones(n,1)*(-45);
T_25=ones(n,1)*25;
T_125=ones(n,1)*125;

%% 1 - Get V(p) and V(T) relationships

plot(pressure,out_minus45);
hold on
plot(pressure,out_25);
plot(pressure,out_125);

p_minus45=polyfit(pressure,out_minus45,2);
p_25=polyfit(pressure,out_25,2);
p_125=polyfit(pressure,out_125,2);

plot(pressure,polyval(p_minus45,pressure,2));
plot(pressure,polyval(p_25,pressure,2));
plot(pressure,polyval(p_125,pressure,2));
ylabel("Voltage (V)");
xlabel("Pressure (mBar)");
title("V(p) and V(T)");
legend("Sensor data (-45ºC)","Sensor data (25ºC)","Sensor data (125ºC)",...
    "Model data (-45ºC)","Model data (25ºC)","Model data (125ºC)",'Location','northwest');

%Display model parameters
fprintf("The model for V(p,-45ºC) is given by: V = %d*p^2 + %d*p + %d\n",p_minus45(1),p_minus45(2),p_minus45(3));
fprintf("The model for V(p,25ºC) is given by: V = %d*p^2 + %d*p + %d\n",p_25(1),p_25(2),p_25(3));
fprintf("The model for V(p,125ºC) is given by: V = %d*p^2 + %d*p + %d\n",p_125(1),p_125(2),p_125(3));



%% 2 - Get V(p) and V(T) errors

err_V_minus45=out_minus45 - polyval(p_minus45,pressure,2);
err_V_25=out_25 - polyval(p_25,pressure,2);
err_V_125=out_125 - polyval(p_125,pressure,2);

hold on;
subplot(3,1,1),plot(pressure,err_V_minus45);
ylabel("Voltage (V)");
xlabel("Pressure (mBar)");
title("Model error for -45ºC");
subplot(3,1,2),plot(pressure,err_V_25);
ylabel("Voltage (V)");
xlabel("Pressure (mBar)");
title("Model error for 25ºC");
subplot(3,1,3),plot(pressure,err_V_125);
ylabel("Voltage (V)");
xlabel("Pressure (mBar)");
title("Model error for 125ºC");
hold off;

%% 3 - Obtain p(V,T) model
clf

%Plot the p(V,T) relationship for the experimental data
%surf([-45, 25, 125], pressure, [out_minus45 out_25 out_125]);
%surf([-45, 25, 125], pressure, [polyval(p_minus45, pressure, 2) polyval(p_25, pressure, 2) polyval(p_125, pressure, 2)]);

%Get p(V,T) relationship model
sf = fit([[out_minus45;out_25;out_125] [-45*ones(size(out_25));25*ones(size(out_25));125*ones(size(out_25))]], [pressure;pressure;pressure], 'poly42');
plot(sf,[[out_minus45;out_25;out_125] [-45*ones(size(out_25));25*ones(size(out_25));125*ones(size(out_25))]], [pressure;pressure;pressure]);
xlabel('Voltage [V]'); ylabel('Temperature [C]'); zlabel('Pressure [Pa]');


fprintf("The model for p(V,T) is given by: \n p(V,T) = p00 + p10*x + p01*y + p20*x^2 + p11*x*y + p02*y^2 + p30*x^3 + p21*x^2*y + p12*x*y^2 + p40*x^4 + p31*x^3*y + p22*x^2*y^2\n")
fprintf("The polinomial parameters are: \np00=%d\np10=%d\np01=%d\np20=%d\np11=%d\np02=%d\np30=%d\np21=%d\np12=%d\np40=%d\np31=%d\np22=%d\n",...
    sf.p00, sf.p10, sf.p01, sf.p20, sf.p11, sf.p02, sf.p30, sf.p21, sf.p12, sf.p40, sf.p31, sf.p22);
%% 4 - Obtain p(V,T) model error

error_3dfit = [pressure;pressure;pressure] - feval(sf,[out_minus45;out_25;out_125],[-45*ones(size(out_25));25*ones(size(out_25));125*ones(size(out_25))]);
plotthis = sortrows([[out_minus45] [-45*ones(size(out_25))] error_3dfit(1:219)], 1);
subplot(3,1,1),plot(plotthis(:,1), plotthis(:,3));
ylabel("Pressure (mBar)");
xlabel("Voltage (V)");
title("Model error for -45ºC");
%xlim([0 5.5]);
plotthis = sortrows([[out_25] [25*ones(size(out_25))] error_3dfit(220:438)], 1);
subplot(3,1,2),plot(plotthis(:,1), plotthis(:,3));
ylabel("Pressure (mBar)");
xlabel("Voltage (V)");
title("Model error for 25ºC");
%xlim([0 5.5]);
plotthis = sortrows([[out_125] [125*ones(size(out_25))] error_3dfit(439:657)], 1);
subplot(3,1,3),plot(plotthis(:,1), plotthis(:,3));
ylabel("Pressure (mBar)");
xlabel("Voltage (V)");
title("Model error for 125ºC");
%xlim([0 5.5]);


%% 5 - Evaluate sensor model in altitude determination

clf

h_real=get_pressure_altitude(pressure);

h_model_minus45=get_pressure_altitude(feval(sf,out_minus45,-45));
h_model_25=get_pressure_altitude(feval(sf,out_25,25));
h_model_125=get_pressure_altitude(feval(sf,out_125,125));

plot(pressure,h_real/1000,pressure,h_model_minus45/1000,pressure,h_model_25/1000,pressure,h_model_125/1000);
hold on
y_lim=ylim;
line([1013.25 1013.25],[y_lim(1) y_lim(2)]);
line([178.7387 178.7387],[y_lim(1) y_lim(2)]);
legend("Real pressure","Modeled -45","Modeled 25","Modeled 125")
hold off

%% 5 - Evaluate sensor model error in altitude determination

subplot(3,1,1),plot(pressure,(h_real-h_model_minus45)/1000);
ylabel("Altitude error (km)");
xlabel("Pressure (mbar)");
title("Pressure altitude model error for -45ºC");
%plot(pressure,(h_real-h_model_minus45)/1000);
subplot(3,1,2),plot(pressure,(h_real-h_model_25)/1000);
ylabel("Altitude error (km)");
xlabel("Pressure (mbar)");
title("Pressure altitude model error for 25ºC");
%plot(pressure,(h_real-h_model_25)/1000)
subplot(3,1,3),plot(pressure,(h_real-h_model_125)/1000);
ylabel("Altitude error (km)");
xlabel("Pressure (mbar)");
title("Pressure altitude model error for 125ºC");
%plot(pressure,(h_real-h_model_125)/1000);

clf

%hold on
%y_lim=ylim;
%x_lim=xlim;
%line([1013.25 1013.25],[y_lim(1) y_lim(2)]);
%line([x_lim(1) x_lim(2)],[0.25 0.25]);
%line([x_lim(1) x_lim(2)],[-0.25 -0.25]);
%legend("Real pressure","Modeled -45","Modeled 25","Modeled 125")

b2=4; %Fractional bits

pressure_test=0:2^-b2/4:1013.25;

%assume 25ºC air temperature
test_voltage_output = polyval(p_25,pressure_test,2);

%get discretization stepping
i=2;
pressure_discrete(1)=0;
while (pressure_discrete(i-1) < 1013.25)
    pressure_discrete(i)=pressure_discrete(i-1)+2^-b2; %Step increase
    i=i+1;
end

j=1;
for i=1:size(pressure_test,2)
    %Check what the pressure ADC value should be, due to discretization
    if pressure_test(i)>pressure_discrete(j)
        j=j+1;
    end
    
    %Compute sensor reported pressure altitude from the model
    sensor_test_voltage_output(i) = polyval(p_25,pressure_discrete(j),2);
end

plot(pressure_test,test_voltage_output,pressure_test,sensor_test_voltage_output);

h_test=get_pressure_altitude(feval(sf,test_voltage_output,25));
h_sensor_test=get_pressure_altitude(feval(sf,sensor_test_voltage_output,25));

plot(pressure_test,h_test,pressure_test,h_sensor_test)

plot(get_pressure_altitude(pressure_test),h_test-h_sensor_test)
x_limits=xlim;
xlim([10,16000])