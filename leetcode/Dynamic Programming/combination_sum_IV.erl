%% https://leetcode.com/problems/combination-sum-iv/

-module(combination_sum_IV).

-compile(export_all).

-spec combination_sum4(Nums :: [integer()], Target :: integer()) -> integer().
combination_sum4(Nums, Target) ->
    #{Target := Res} = inner(
        Nums,
        Target
    ),
    Res.

inner(Nums, Target) ->
    inner(1, Target, Nums, #{0 => 1}).

inner(CurrTarget, MaxTarget, _Nums, Map) when CurrTarget > MaxTarget -> Map;
inner(Target, MaxTarget, Nums, Map) ->
    Fun = fun(Num, Acc) -> Acc + maps:get(Target - Num, Map, 0) end,
    inner(Target+1, MaxTarget, Nums, Map#{Target => lists:foldl(Fun, 0, Nums)}).
    %% Map[Target] = 
    %%     iterate through Nums 
    %%     Acc += Map.get(Target - Num, 0)  
    %%      
