%% https://leetcode.com/problems/missing-number/

-spec missing_number(Nums :: [integer()]) -> integer().
missing_number(Nums) ->
    Cmp = fun(A, B) -> A < B end,
    SortedNums = lists:sort(Cmp, Nums),
    case lists:nth(1, SortedNums) of
        0 -> find_missing(SortedNums);
        _ -> 0
    end.

% find_missing([]) -> heel;
find_missing([H | [] ]) -> H + 1;
find_missing([V1 | [V2 | T]]) ->
    case V2 - V1 of
        1 -> find_missing([V2 | T]);
        2 -> V1 + 1
    end.