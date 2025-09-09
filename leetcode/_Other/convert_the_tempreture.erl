-module(convert_the_tempreture).

-spec convert_temperature(Celsius :: float()) -> [float()].
convert_temperature(Celsius) ->
  [Celsius + 273.15, Celsius * 1.8 + 32].
