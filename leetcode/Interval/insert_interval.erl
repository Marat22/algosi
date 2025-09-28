%% https://leetcode.com/problems/insert-interval/

-spec insert(Intervals :: [[integer()]], NewInterval :: [integer()]) -> [[integer()]].
insert(Intervals, NewInterval) ->
    insert(Intervals, NewInterval, []).

insert(Intervals=[Int=[IntStart, IntEnd] | IntTail], New=[NewStart, NewEnd], Res) ->
    if NewStart > IntEnd -> insert(IntTail, New, [Int | Res]);
        NewEnd < IntStart -> lists:reverse([New | Res]) ++ Intervals;
        true -> insert(IntTail, [min(IntStart, NewStart), max(IntEnd, NewEnd)], Res)
    end;
insert([], New, Res) ->
    lists:reverse([New | Res]).
