%% https://leetcode.com/problems/power-of-four/
-module(power_of_four).

-export([is_power_of_four/1]).

-spec is_power_of_four(N :: integer()) -> boolean().
is_power_of_four(N) when N == 4; N == 1 ->
    true;
is_power_of_four(N) when N < 4, N > -4 ->
    false;
is_power_of_four(N) ->
    case N rem 4 == 0 of 
        true -> is_power_of_four(N div 4);
        false -> false
    end.

