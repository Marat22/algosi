-module(divisible_and_non_divisible).

-compile(export_all).

-spec difference_of_sums(N :: integer(), M :: integer()) -> integer().
difference_of_sums(N, M) ->
  inner(N, M, 0, 0).

inner(0, _, NotDivSum, DivSum) ->
    NotDivSum - DivSum;
inner(N, M, NotDivSum, DivSum) ->
    case N rem M of
        0 -> inner(N-1, M, NotDivSum, DivSum+N);
        _ -> inner(N-1, M, NotDivSum+N, DivSum)
    end.
