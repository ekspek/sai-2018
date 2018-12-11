clear;
clc;

b1=input('Insert number of bits for integer part: ');
b2=input('Insert number of bits for fractional part: ');

fprintf("\n Total number of bits: %d\n",b1+b2);
% j=0;
% max_int_part = 0;
% for i=0:b1-1
%     j=j+1;
%     max_int_part = max_int_part + 2^i;
% end
% 
% max_frac_part = 0;
% for i=1:b2
%     j=j+1;
%     max_frac_part = max_frac_part + 2^-i;
% end

% fprintf("Max value: %f\n",max_int_part+max_frac_part);
fprintf("Max value: %f\n",2^b1);
fprintf("Resolution: %f\n",2^-b2);


simulation_max_pressure=1013.25; %Sea-level air pressure
sensor_max_pressure = 2^b1;

i=2;
pressure(1)=0;

while (pressure(i-1) <=simulation_max_pressure && pressure(i-1) < sensor_max_pressure)
    pressure(i)=pressure(i-1)+2^-b2; %Step increase
    i=i+1;
end


%Ideal sensor response to a continuously changing pressure

pressure_steps=pressure; %Rename variable for convenience

if sensor_max_pressure > 1013.25
    pressure=0:2^-b2/4:1013.25;
else
    pressure=0:2^-b2/4:sensor_max_pressure;
end



j=1;
for i=1:size(pressure,2)
    %Check what the pressure ADC value should be, due to discretization
    if pressure(i)>pressure_steps(j)
        j=j+1;
    end
    
    %Compute current pressure altitude
    h_real(i)=get_pressure_altitude(pressure(i));
    %Compute sensor reported pressure altitude from the model
    h_sensor(i)=get_pressure_altitude(pressure_steps(j));
    
    %Get altitude error
    h_error(i)=h_real(i)-h_sensor(i);
    
end

subplot(2,1,1),plot(get_pressure_altitude(pressure),h_error);
x_limits=xlim;
xlim([10,16000])
subplot(2,1,2),plot(pressure,h_real,pressure,h_sensor)
x_limits=xlim;
xlim([10,x_limits(2)])
