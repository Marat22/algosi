%% https://leetcode.com/problems/longest-harmonious-subsequence/

-module(longest_harmonious_subsequence).

-compile(export_all).
-spec find_lhs(Nums :: [integer()]) -> integer().
find_lhs(Nums) ->
  inner(Nums, #{}, 0).


  inner([], _, MaxQty) -> MaxQty;
inner([H | T], ValsInfo = #{}, MaxQty) ->
    {NewValsInfo, NewMaxQty} = update_vals_info(H, MaxQty, ValsInfo, true),
    {NewValsInfo2, NewMaxQty2} = update_vals_info(H+1, NewMaxQty, NewValsInfo, false),
    inner(T, NewValsInfo2, NewMaxQty2).


update_vals_info(Inx, MaxQty, ValsInfo = #{}, IsFirst) ->
    case {IsFirst, ValsInfo} of
        {true, #{Inx := {Qty, _, Second = true}}} when MaxQty < Qty + 1 ->
            {ValsInfo#{Inx => {Qty + 1, true, Second}}, Qty + 1};
        {true, #{Inx := {Qty, _, Second}}} ->
            {ValsInfo#{Inx => {Qty + 1, true, Second}}, MaxQty};
        {true, _} ->
            {ValsInfo#{Inx => {1, true, false}}, MaxQty};

        {false, #{Inx := {Qty, First=true, _}}} when MaxQty < Qty + 1 ->
            {ValsInfo#{Inx => {Qty + 1, First, true}}, Qty + 1};
        {false, #{Inx := {Qty, First, _}}} ->
            {ValsInfo#{Inx => {Qty + 1, First, true}}, MaxQty};
        {false, _} ->
            {ValsInfo#{Inx => {1, false, true}}, MaxQty}
    end.
