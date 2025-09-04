%% https://leetcode.com/problems/container-with-most-water/submissions/1759831194/

-spec max_area(Height :: [integer()]) -> integer().
max_area(Height) ->
  inner(Height, lists:reverse(Height), length(Height)-1, 0).

inner(_, _, InxDiff, Max) when InxDiff < 0 ->
    Max;
inner([H1 | T1], [H2 | T2], InxDiff, Max) ->
    {NextArr1, NextArr2} = case H1 < H2 of 
        true -> {T1, [H2 | T2]};
        false -> {[H1 | T1], T2}
    end,
    inner(NextArr1, NextArr2, InxDiff-1, max(InxDiff * min(H1, H2), Max));
inner(_, _, InxDiff, Max) ->
    Max.