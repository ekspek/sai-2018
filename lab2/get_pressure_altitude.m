function [h] = get_pressure_altitude(pressure)
%GET_PRESSURE_ALTITUDE Summary of this function goes here
%   Detailed explanation goes here

h=0.3048.*145366.45.*(1-(pressure./1013.25).^0.190284);

end

