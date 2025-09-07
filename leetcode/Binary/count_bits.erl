%% https://leetcode.com/problems/counting-bits/

-module(count_bits).

-spec count_bits(N :: integer()) -> [integer()].
count_bits(N) ->
    count_bits(N, []).

count_bits(0, Arr) -> [0 | Arr];
count_bits(N, Arr) ->
    count_bits(N-1, [count_ones(N, 0) | Arr]).

count_ones(0, Sum) -> Sum;
count_ones(N, Sum) ->
    NewSum = case N rem 2 of
        1 -> Sum + 1;
        0 -> Sum
    end,
    count_ones(N div 2, NewSum).

