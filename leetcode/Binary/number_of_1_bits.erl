-module(humming_weight).

-compile(export_all).

-spec hamming_weight(N :: integer()) -> integer().
hamming_weight(N) ->
  inner(N, 0).

inner(0, Sum) -> Sum;
inner(N, Sum) ->
    NewSum = case N rem 2 of
        1 -> Sum + 1;
        0 -> Sum
    end,
    inner(N div 2, NewSum).
