%% https://leetcode.com/problems/maximum-subarray/

-module(maximum_subarray_DP).

-compile(export_all).

-spec max_sub_array(Nums :: [integer()]) -> integer().
max_sub_array([Num | T]) ->
  max_sub_array(T, Num, Num).

max_sub_array([], Best, _) ->
    Best;
max_sub_array([Num | T], Best, Cur) -> %% 4 4 
    case Cur =< 0 of
        true -> max_sub_array(T, max(Num, Best), Num);
        false -> max_sub_array(T, max(Cur+Num, Best), Cur+Num)
    end.
