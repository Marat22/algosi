%% https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

-module(find_minimum_in_rotated_sorted_array).

-spec find_min(Nums :: [integer()]) -> integer().
find_min(Nums) ->
    case lists:nth(1, Nums) < lists:last(Nums) of
        true -> lists:nth(1, Nums);
        false -> bin_search(Nums);
        _ -> wtf
    end.

bin_search(Nums) -> bin_search(Nums, 1, length(Nums)).

bin_search(Nums, Lower, Upper) ->
    Mid = (Upper + Lower) div 2,
    Item = lists:nth(Mid, Nums),
    PrevItem = get_prev(Mid, Nums),
    Last = lists:last(Nums),
    if
        PrevItem >= Item -> Item;
        Item =< Last -> bin_search(Nums, Lower, Mid - 1);
        true -> bin_search(Nums, Mid + 1, Upper)
    end.

get_prev(N, Arr) ->
    case N - 1 >= 1 of 
        true -> lists:nth(N - 1, Arr);
        false -> lists:last(Arr)
    end.
