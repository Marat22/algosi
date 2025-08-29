%% https://leetcode.com/problems/maximum-69-number/

-module(maximum_69_number).

-export([maximum69_number/1, get_first_six_and_last_nine/1]).

-spec maximum69_number (Num :: integer()) -> integer().
maximum69_number (Num) -> 
    {FirstSix, _} = get_first_six_and_last_nine(Num),
    case FirstSix of
        -1 -> Num;
        _ -> Num + 3 * round(math:pow(10, FirstSix))
    end.

get_first_six_and_last_nine(Num) ->
    get_first_six_and_last_nine(integer_to_list(Num), length(integer_to_list(Num)) - 1, -1, -1).
get_first_six_and_last_nine([], _, FirstSix, LastNine) -> {FirstSix, LastNine};
get_first_six_and_last_nine([Num | Other], MaxDigit, FirstSix, LastNine) when Num == 54 ->   % 54 == "6"
    case FirstSix of 
        -1 -> get_first_six_and_last_nine(Other, MaxDigit-1, MaxDigit, LastNine);
        _ -> get_first_six_and_last_nine(Other, MaxDigit-1, FirstSix, LastNine)
    end;
get_first_six_and_last_nine([Num | Other], MaxDigit, FirstSix, _) when Num == 57 ->  % 57   == "9"
    get_first_six_and_last_nine(Other, MaxDigit-1, FirstSix, MaxDigit)
;get_first_six_and_last_nine([Num | Other], MaxDigit, FirstSix, LastNine)  -> io:format("~p\n", {[Num | Other], MaxDigit, FirstSix, LastNine}), {-100, -100}. % 57   == "9"
